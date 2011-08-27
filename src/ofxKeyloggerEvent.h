#ifndef OFXKEYLOGGEREVENTH
#define OFXKEYLOGGEREVENTH
class ofxKeyloggerEvent {
public:
	ofxKeyloggerEvent(int k, int m):key(k),modifier(m) 
	{
	}
	int key;
	int modifier;
};
#endif