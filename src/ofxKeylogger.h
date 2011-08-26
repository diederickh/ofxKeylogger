#ifndef OFXKEYLOGGERH
#define OFXKEYLOGGERH
#include "ofMain.h"

/**
 * Keylogger, gets key stroke events (system wide).
 *
 * Windows version:
 * ----------------
 * - you need to add this define to your defines: POCO_NO_UNWINDOWS
 * - I need to figure out a way to get the modifier keys
 *
 * Mac version:
 * -----------
 * - make sure you link against the Keylogger_Mac.a lib.
 *
 *
 */
class ofxKeylogger {
public:
	static ofxKeylogger& getInstance();
	void enable();
private:
	ofxKeylogger();
	static ofxKeylogger* instance;

};
#endif
