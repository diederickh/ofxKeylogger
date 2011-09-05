#ifndef KEYLOGGER_KEYCODESH
#define KEYLOGGER_KEYCODESH
enum KeyloggerModifiers {
	 KM_NONE 	= 1 << 0
	,KM_SHIFT	= 1 << 1
	,KM_CONTROL	= 1 << 2
	,KM_ALT		= 1 << 3
	,KM_COMMAND	= 1 << 4  // mac
};
// list of VK keys: http://www.kbdedit.com/manual/low_level_vk_list.html
// translating VK keys: http://jakash3.wordpress.com/2010/11/18/windows-keylogger-using-keyboard-hook/
// source ascii: http://www.asciitable.com/
// source names: http://wason21cn.blogspot.com/2008/01/english-name-for-character-in-keyboard.html
enum KeyloggerCodes {

	 KC_BACKSPACE			= 0x08
	,KC_CARRIAGE_RETURN 	= 0x0D // carriage return
	,KC_LINE_FEED			= 0x0A // line feed

	,KC_0	= 0x30
	,KC_1	= 0x31
	,KC_2	= 0x32
	,KC_3	= 0x33
	,KC_4	= 0x34
	,KC_5	= 0x35
	,KC_6	= 0x36
	,KC_7	= 0x37
	,KC_8	= 0x38
	,KC_9	= 0x39

	,KC_COLON	= 0x3A

	,KC_A	= 0x41 // A
	,KC_B	= 0x42 // B
	,KC_C	= 0x43 // C
	,KC_D	= 0x44 // ..
	,KC_E	= 0x45
	,KC_F	= 0x46
	,KC_G	= 0x47
	,KC_H	= 0x48
	,KC_I	= 0x49
	,KC_J	= 0x4A
	,KC_K	= 0x4B
	,KC_L	= 0x4C
	,KC_M	= 0x4D
	,KC_N	= 0x4E
	,KC_O	= 0x4F
	,KC_P	= 0x50
	,KC_Q	= 0x51
	,KC_R	= 0x52
	,KC_S	= 0x53
	,KC_T	= 0x54
	,KC_U	= 0x55
	,KC_V	= 0x56
	,KC_W	= 0x57
	,KC_X	= 0x58
	,KC_Y	= 0x59
	,KC_Z	= 0x5A
	,KC_SQUARE_BRACKET_OPEN	= 0x5B // [
	,KC_BACKSLASH 	= 0x5C // \
	,KC_SQUARE_BRACKET_CLOSE = 0x5D //
	,KC_CARET = 0x5E // ^
	,KC_UNDERSCORE = 0x5F // _

	// @todo we need some extra characters

	,KC_a	= 0x61 // a
	,KC_b	= 0x62 // b
	,KC_c	= 0x63 // c
	,KC_d	= 0x64 // d
	,KC_e	= 0x65 // ...
	,KC_f 	= 0x66
	,KC_g 	= 0x67
	,KC_h 	= 0x68
	,KC_i 	= 0x69
	,KC_j 	= 0x6A
	,KC_k 	= 0x6B
	,KC_l 	= 0x6C
	,KC_m 	= 0x6D
	,KC_n 	= 0x6E
	,KC_o 	= 0x6F
	,KC_p	= 0x70
	,KC_q	= 0x71
	,KC_r	= 0x72
	,KC_s	= 0x73
	,KC_t	= 0x74
	,KC_u	= 0x75
	,KC_v	= 0x76
	,KC_w	= 0x77
	,KC_x	= 0x78
	,KC_y	= 0x79
	,KC_z	= 0x7A
};
#endif
