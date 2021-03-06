/* Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2013-2018  Keyboard.io, Inc.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// System control mappings

#define System_PowerDown Key(HID_SYSTEM_POWER_DOWN, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_Sleep Key(HID_SYSTEM_SLEEP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_WakeUp Key(HID_SYSTEM_WAKE_UP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_ContextMenu Key(HID_SYSTEM_CONTEXT_MENU, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_MainMenu Key(HID_SYSTEM_MAIN_MENU, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_AppMenu Key(HID_SYSTEM_APP_MENU, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_MenuHelp Key(HID_SYSTEM_MENU_HELP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_MenuExit Key(HID_SYSTEM_MENU_EXIT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_MenuSelect Key(HID_SYSTEM_MENU_SELECT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_MenuRight Key(HID_SYSTEM_MENU_RIGHT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_RTC)
#define System_MenuLeft Key(HID_SYSTEM_MENU_LEFT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_RTC)
#define System_MenuUp Key(HID_SYSTEM_MENU_UP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_RTC)
#define System_MenuDown Key(HID_SYSTEM_MENU_DOWN, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_RTC)
#define System_ColdRestart Key(HID_SYSTEM_COLD_RESTART, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_WarmRestart Key(HID_SYSTEM_WARM_RESTART, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DPadUp Key(HID_D_PAD_UP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OOC)
#define System_DPadDown Key(HID_D_PAD_DOWN, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OOC)
#define System_DPadRight Key(HID_D_PAD_RIGHT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OOC)
#define System_DPadLeft Key(HID_D_PAD_LEFT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OOC)

#define System_Dock Key(HID_SYSTEM_DOCK, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_Undock Key(HID_SYSTEM_UNDOCK, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_Setup Key(HID_SYSTEM_SETUP, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_Break Key(HID_SYSTEM_BREAK, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DebuggerBreak Key(HID_SYSTEM_DEBUGGER_BREAK, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_ApplicationBreak Key(HID_APPLICATION_BREAK, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_ApplicationDebuggerBreak Key(HID_APPLICATION_DEBUGGER_BREAK, KEY_FLAGS | HID_TYPE_OSC)
#define System_SpeakerMute Key(HID_SYSTEM_SPEAKER_MUTE, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_Hibernate Key(HID_SYSTEM_HIBERNATE, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)

#define System_DisplayInvert Key(HID_SYSTEM_DISPLAY_INVERT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayInternal Key(HID_SYSTEM_DISPLAY_INTERNAL, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayExternal Key(HID_SYSTEM_DISPLAY_EXTERNAL, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayBoth Key(HID_SYSTEM_DISPLAY_BOTH, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayDual Key(HID_SYSTEM_DISPLAY_DUAL, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayToggleIntSlashExt Key(HID_SYSTEM_DISPLAY_TOGGLE_INT_SLASH_EXT, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplaySwapPrimarySlashSecondary Key(HID_SYSTEM_DISPLAY_SWAP_PRIMARY_SLASH_SECONDARY, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
#define System_DisplayLCDAutoscale Key(HID_SYSTEM_DISPLAY_LCD_AUTOSCALE, KEY_FLAGS | SYNTHETIC|IS_SYSCTL | HID_TYPE_OSC)
