#ifndef KEYLOGGER_KEYCODESH
#define KEYLOGGER_KEYCODESH
enum KeyloggerModifiers {
	 KM_NONE 	= 1 << 0
	,KM_SHIFT	= 1 << 1
	,KM_CONTROL	= 1 << 2
	,KM_ALT		= 1 << 3
	,KM_COMMAND	= 1 << 4  // mac
};
#endif
