/* -*- mode: c++ -*-
 * Kaleidoscope-Hardware-Keyboardio-Imago -- Imago hardware support for Kaleidoscope
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef ARDUINO_AVR_KEYBOARDIO_IMAGO

#include "kaleidoscope/Runtime.h"
#include "kaleidoscope/driver/keyscanner/Base_Impl.h"

extern "C" {
#include "twi.h"
}

#define ELEMENTS(arr)  (sizeof(arr) / sizeof((arr)[0]))

#define LED_DRIVER_ADDR 0x30

namespace kaleidoscope {
namespace device {
namespace keyboardio {

constexpr uint8_t ImagoLEDDriverProps::key_led_map[] PROGMEM;

#ifndef KALEIDOSCOPE_VIRTUAL_BUILD

static constexpr uint8_t CMD_SET_REGISTER = 0xFD;
static constexpr uint8_t CMD_WRITE_ENABLE = 0xFE;
static constexpr uint8_t WRITE_ENABLE_ONCE = 0b11000101;

static constexpr uint8_t LED_REGISTER_PWM0 = 0x00;
static constexpr uint8_t LED_REGISTER_PWM1 = 0x01;
static constexpr uint8_t LED_REGISTER_DATA0 = 0x02;
static constexpr uint8_t LED_REGISTER_DATA1 = 0x03;
static constexpr uint8_t LED_REGISTER_CONTROL = 0x04;

static constexpr uint8_t LED_REGISTER_PWM0_SIZE = 0xB4;
static constexpr uint8_t LED_REGISTER_PWM1_SIZE = 0xAB;
static constexpr uint8_t LED_REGISTER_DATA0_SIZE = 0xB4;
static constexpr uint8_t LED_REGISTER_DATA1_SIZE = 0xAB;

static constexpr uint8_t LED_REGISTER_DATA_LARGEST = LED_REGISTER_DATA0_SIZE;

ATMEGA_KEYSCANNER_BOILERPLATE

bool ImagoLEDDriver::isLEDChanged = true;
cRGB ImagoLEDDriver::led_data[];

void ImagoLEDDriver::setup() {
  setAllPwmTo(0xFF);
  selectRegister(LED_REGISTER_CONTROL);
  twiSend(LED_DRIVER_ADDR, 0x01, 0xFF); //global current
  twiSend(LED_DRIVER_ADDR, 0x00, 0x01); //normal operation
}

void ImagoLEDDriver::twiSend(uint8_t addr, uint8_t Reg_Add, uint8_t Reg_Dat) {
  uint8_t data[] = {Reg_Add, Reg_Dat };
  uint8_t result = twi_writeTo(addr, data, ELEMENTS(data), 1, 0);
}

void ImagoLEDDriver::unlockRegister(void) {
  twiSend(LED_DRIVER_ADDR, CMD_WRITE_ENABLE, WRITE_ENABLE_ONCE); //unlock
}

void ImagoLEDDriver::selectRegister(uint8_t page) {
  // Registers automatically get locked at startup and after a given write
  // It'd be nice to disable that.
  unlockRegister();
  twiSend(LED_DRIVER_ADDR, CMD_SET_REGISTER, page);
}

void ImagoLEDDriver::setCrgbAt(uint8_t i, cRGB crgb) {
  if (!Runtime.device().LEDs().isValid(i))
    return;

  cRGB oldColor = getCrgbAt(i);
  isLEDChanged |= !(oldColor.r == crgb.r && oldColor.g == crgb.g && oldColor.b == crgb.b);

  led_data[i] = crgb;
}

cRGB ImagoLEDDriver::getCrgbAt(uint8_t i) {
  if (!Runtime.device().LEDs().isValid(i))
    return {0, 0, 0};

  return led_data[i];
}

void ImagoLEDDriver::syncLeds() {
//  if (!isLEDChanged)
//   return;

  uint8_t data[LED_REGISTER_DATA_LARGEST + 1];
  data[0] = 0;// the address of the first byte to copy in
  uint8_t last_led = 0;

  // Write the first LED bank
  selectRegister(LED_REGISTER_DATA0);

  for (auto i = 1; i < LED_REGISTER_DATA0_SIZE; i += 3) {
    data[i] = led_data[last_led].b;
    data[i + 1] = led_data[last_led].g;
    data[i + 2] = led_data[last_led].r;
    last_led++;
  }

  twi_writeTo(LED_DRIVER_ADDR, data, LED_REGISTER_DATA0_SIZE + 1, 1, 0);

  // Don't reset "Last LED", because this is just us picking up from the last bank
  // TODO - we don't use all 117 LEDs on the Imago, so we can probably stop writing earlier
  // Write the second LED bank

  // For space efficiency, we reuse the LED sending buffer
  // The twi library should never send more than the number of elements
  // we say to send it.
  // The page 2 version has 180 elements. The page 3 version has only 171.

  selectRegister(LED_REGISTER_DATA1);

  for (auto i = 1; i < LED_REGISTER_DATA1_SIZE; i += 3) {
    data[i] = led_data[last_led].b;
    data[i + 1] = led_data[last_led].g;
    data[i + 2] = led_data[last_led].r;
    last_led++;
  }

  twi_writeTo(LED_DRIVER_ADDR, data, LED_REGISTER_DATA1_SIZE + 1, 1, 0);

  isLEDChanged = false;
}


void ImagoLEDDriver::setAllPwmTo(uint8_t step) {
  selectRegister(LED_REGISTER_PWM0);

  uint8_t data[0xB5] = {};
  data[0] = 0;
  // PWM Register 0 is 0x00 to 0xB3
  for (auto i = 1; i <= 0xB4; i++) {
    data[i] = step;

  }
  twi_writeTo(LED_DRIVER_ADDR, data, 0xB5, 1, 0);

  selectRegister(LED_REGISTER_PWM1);
  // PWM Register 1 is 0x00 to 0xAA
  for (auto i = 1; i <= LED_REGISTER_PWM1_SIZE; i++) {
    data[i] = step;

  }
  twi_writeTo(LED_DRIVER_ADDR, data, 0xAC, 1, 0);
}

void Imago::setup() {
  digitalWrite(MOSI, HIGH);
  digitalWrite(SS, HIGH);
  uint8_t twi_uninitialized = 1;
  if (twi_uninitialized--) {
    twi_init();
  }
  TWBR = 10;

  kaleidoscope::device::ATmega32U4Keyboard<ImagoProps>::setup();
}

#endif // ifndef KALEIDOSCOPE_VIRTUAL_BUILD

}
}
}

#endif
