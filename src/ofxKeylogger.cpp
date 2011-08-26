#include "ofxKeylogger.h"
ofxKeylogger* ofxKeylogger::instance = NULL;

#ifdef _WIN32
	typedef void (*dll_keylogger_callback)(int, int);
	typedef void (*dll_keylogger_init)(HINSTANCE);
	typedef void (*dll_keylogger_set_callback)(dll_keylogger_callback);
#endif

// modifier not working yet on windows
void the_keylogger_callback(int key, int modifier) {
	cout << "CB:" << key << endl;
}

ofxKeylogger::ofxKeylogger()
{
	#ifdef _WIN32

		// Here we copy the dll from the addons dir to the bin dir.
		string dll_source = ofToDataPath("../Keylogger_Win.dll",true);
		ofFile dll_path(dll_source);
		if(!dll_path.exists()) {
			cout << "dll does not exists there" << endl;
			ofFile curr_file(__FILE__);
			string curr_path = curr_file.getEnclosingDirectory();
			ofFile dll_source_path(curr_path +"../libs/win/Keylogger_Win.dll");
			if(dll_source_path.exists()) {
				string dp = ofToDataPath(".", true);
				dll_source_path.copyTo("../Keylogger_Win.dll", true);
			}
			else {
				cout << "Cannot copy source Keylogger_Win.dll, not found in addon dir." << endl;
				cout << "Tried:" << dll_source_path << endl;
			}
		}

		// import some functions.
		HINSTANCE dll;
		dll = LoadLibrary(dll_source.c_str());
		if(dll != 0) {
			// get the install_keylogger_hook function
			dll_keylogger_init keylogger_init(0);
			dll_keylogger_set_callback keylogger_set_callback(0);
			keylogger_init = (dll_keylogger_init)GetProcAddress(dll, "keylogger_init");
			if(keylogger_init == 0){
				printf("install_keylogger_hook function not found in dll.\n");
			}
			else {
				keylogger_set_callback = (dll_keylogger_set_callback)GetProcAddress(dll, "keylogger_set_callback");
				if(keylogger_set_callback == 0) {
					printf("keylogger_set_callback not found in dll.\n");
				}
				else {
					keylogger_set_callback(&the_keylogger_callback);
					keylogger_init(dll);
				}
			}
		}
		else {
			printf("not loaded: '%s'\n", dll_source.c_str());
		}

	#endif
}

void ofxKeylogger::enable() {
	cout << "enable" << endl;

}

ofxKeylogger& ofxKeylogger::getInstance() {
	if(instance == NULL) {
		instance = new ofxKeylogger();
	}
	return *instance;
}

