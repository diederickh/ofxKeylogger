#include "Keylogger_Mac.h"
//#include "../../shared/include/Keylogger_Constants.h"
#include "../../../src/ofxKeyloggerKeyCodes.h" // updated, not tested yet
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

// keyboard callback; gets called
keylogger_callback the_callback_function(0);

// sets the callback.
void keylogger_set_callback(keylogger_callback kc) {
	the_callback_function = kc;
	NSLog(@"Callback function set!!");
}

void handleKeyDownEvent(NSEvent* event) {
	int modifier = KM_NONE;
	if([event modifierFlags] & NSShiftKeyMask) {
		modifier |= KM_SHIFT;
	}
	if([event modifierFlags] & NSCommandKeyMask) {
		modifier |= KM_COMMAND;
	}
	if([event modifierFlags] & NSAlternateKeyMask) {
		modifier |= KM_ALT;
	}
	if([event modifierFlags] & NSControlKeyMask) {
		modifier |= KM_CONTROL;
	}
	
	int key = 0;
	key = [[event characters] characterAtIndex:0];
	the_callback_function(key, modifier);
}


// initializes the keyboard listener.
void keylogger_init() {
	[NSEvent 	addLocalMonitorForEventsMatchingMask:NSKeyDownMask
				handler:^(NSEvent* event) 
	{
			handleKeyDownEvent(event);
			return event;
	 }];
	
	[NSEvent 	addGlobalMonitorForEventsMatchingMask:NSKeyDownMask
				handler:^(NSEvent* event) 
	{
			handleKeyDownEvent(event);
	}];
}


void keylogger_shutdown() {
}

