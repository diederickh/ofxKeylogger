#ifndef KEYLOGGERMACH
#define KEYLOGGERMACH
extern "C" {
	typedef void(*keylogger_callback)(int key, int modifier);
	void keylogger_set_callback(keylogger_callback);
	void keylogger_init();
	void keylogger_shutdown();
}
#endif
