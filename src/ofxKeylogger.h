#ifndef OFXKEYLOGGERH
#define OFXKEYLOGGERH
#include "ofMain.h"
#include "ofxKeyloggerEvent.h"
extern ofEvent<ofxKeyloggerEvent> ofxKeyloggerEventDispatcher;

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
 *
 * Simple usage:
 * -----------------------------------------------------------------------------
 *
 * // create keylogger event listener in testApp.h
 * #include "ofxKeylogger.h"
 * class testApp : public ofBaseApp {
 * 		void onKeyloggerEvent(ofxKeyloggerEvent& ev)
 * }
 *
 * 
 * // implementation in testApp.cpp
 * void testApp::setup() {
 *  	ofxKeylogger::addListener(this, &testApp::onkeyloggerEvent);
 * }
 *
 *  
 * void testApp::onKeyloggerEvent(ofxKeyloggerEvent& ev) {
 * 		cout << "got key:" << (char)ev.key << endl;
 * }
 */
class ofxKeylogger {
public:
	static ofxKeylogger& getInstance();
	
	template <typename ArgumentsType, class ListenerClass>
	static void addListener(
					ListenerClass* listener
					,void (ListenerClass::*listenerMethod)(ArgumentsType&))
	{
		ofxKeylogger::create();
		ofAddListener(ofxKeyloggerEventDispatcher, listener, listenerMethod);
	}
private:
	static void create();
	ofxKeylogger();
	static ofxKeylogger* instance;

};
#endif
