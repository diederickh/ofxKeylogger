#include "main.h"

#include <iostream>
using namespace std;

bool shift_pressed = false;
HHOOK hook = NULL;
HINSTANCE hinstance = NULL;
HWND hwnd = NULL;
KBDLLHOOKSTRUCT kbd;
keylogger_callback the_callback_function(0);


// thanks: http://jakash3.wordpress.com/2010/11/18/windows-keylogger-using-keyboard-hook/
char translate_vkcode_to_ascii(int vk, bool shiftPressed, bool&is_ascii) {
	is_ascii = false;
	// characters
	if(isalpha(vk)) {
		is_ascii = true;
		if(!shiftPressed) {
			return (vk+32);
		}
		else {
			return vk;
		}
	}
	else if(vk < 0x29) {
		switch(vk) {
			case 0x0D:	{	is_ascii = true;  	return 0x0D; 	} // carriage return
			case 0x08:	{	is_ascii = true;	return 0x08; 	} // backspace
		}
	}
	else {
		switch(vk) {
			case '0': {return (shiftPressed) ? ')' : '0'; is_ascii = true; break; }
			case '1': {return (shiftPressed) ? '!' : '1'; is_ascii = true; break; }
			case '2': {return (shiftPressed) ? '@' : '2'; is_ascii = true; break; }
			case '3': {return (shiftPressed) ? '#' : '3'; is_ascii = true; break; }
			case '4': {return (shiftPressed) ? '$' : '4'; is_ascii = true; break; }
			case '5': {return (shiftPressed) ? '%' : '5'; is_ascii = true; break; }
			case '6': {return (shiftPressed) ? '^' : '6'; is_ascii = true; break; }
			case '7': {return (shiftPressed) ? '&' : '7'; is_ascii = true; break; }
			case '8': {return (shiftPressed) ? '*' : '8'; is_ascii = true; break; }
			case '9': {return (shiftPressed) ? '(' : '9'; is_ascii = true; break; }
			case 0xba: { return (shiftPressed) ? ':' : ';'; is_ascii = true; break; }
			case 0xbb: { return (shiftPressed) ? '+' : '='; is_ascii = true; break; }
			case 0xbc: { return (shiftPressed) ? '<' : ','; is_ascii = true; break; }
			case 0xbd: { return (shiftPressed) ? '_' : '-'; is_ascii = true; break; }
			case 0xbe: { return (shiftPressed) ? '>' : '.'; is_ascii = true; break; }
			case 0xbf: { return (shiftPressed) ? '?' : '/'; is_ascii = true; break; }
			case 0xc0: { return (shiftPressed) ? '~' : '`'; is_ascii = true; break; }
			case 0xdb: { return (shiftPressed) ? '{' : '['; is_ascii = true; break; }
			case 0xdc: { return (shiftPressed) ? '|' : '\\'; is_ascii = true; break; }
			case 0xdd: { return (shiftPressed) ? '}' : ']'; is_ascii = true; break; }
			case 0xde: { return (shiftPressed) ? '\"' : '\''; is_ascii = true; break; }
		}
	}
	return vk;
}


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
// wparam holds: http://msdn.microsoft.com/en-us/library/ms646280(v=vs.85).aspx
DLL_EXPORT LRESULT CALLBACK keylogger_hook_callback(
	int ncode
	,WPARAM wparam
	,LPARAM lparam
)
{
	if( ncode > 0
		&& (ncode == HC_ACTION)
		&& ((wparam == WM_SYSKEYDOWN))
		|| (wparam == WM_KEYDOWN)
		|| (wparam == WM_KEYUP)
	)
	{
		unsigned int result_code = 0;

		// @todo create OFX related key codes
		// @todo figure out how to get modifier key
		kbd = *((KBDLLHOOKSTRUCT*)lparam);

		int vk = kbd.vkCode;
		bool handle_key = true;
		if(wparam == WM_KEYUP) {
			if ((vk==0x10)||(vk==0xa0)||(vk==0xa1)) {
				shift_pressed = false;
			}
			handle_key = false;
		}
		else if((vk==0x10)||(vk==0xa0)||(vk==0xa1)) {
			shift_pressed = true;
			handle_key = false;
		}

		// try to convert to ascii.
		if(handle_key) {
			bool is_ascii = false;
			char translated_key = translate_vkcode_to_ascii(
									vk
									,shift_pressed
									,is_ascii
			);

			// when key isnt ascii, figure out what key was pressed.
			// keycodes: http://msdn.microsoft.com/en-us/library/ms927178.aspx
			if(!is_ascii) {
				switch(vk) {
					// printscreen.
					case VK_SNAPSHOT: {
						break;
					}

					// pause
					case VK_PAUSE: {
						break;
					}

					// left control
					case VK_LCONTROL: {
						break;
					}

					// right control
					case VK_RCONTROL: {
						break;
					}

					// left alt key
					case VK_LMENU: {
						break;
					}

					// right alt key
					case VK_RMENU: {
						break;
					}

					// left windows key
					case VK_LWIN: {
						break;
					}

					// scroll lock
					case VK_SCROLL: {
						break;
					}

					// space bar.
					case VK_SPACE: {
						break;
					}

					// tab key
					case VK_TAB: {
						break;
					}

					// escape key
					case VK_ESCAPE: {
						break;
					}
					default:break;
				}
			}

			//unsigned int key = (unsigned int)kbd.vkCode;
			//cout << "key: " << key << ", translated: " << translated_key << endl;
			the_callback_function((int)translated_key,0);
		} // handle key
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
