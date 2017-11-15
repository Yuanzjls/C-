/*
 * tv.h
 *
 *  Created on: Jul 23, 2017
 *      Author: scott
 */

#ifndef TV_H_
#define TV_H_

class Tv;

class Remote
{
private:
	enum {Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};
	enum {interactive=0, normal=1};
	int mode;
	bool controlmode;
public:
	friend class Tv;
	Remote(int m = TV): mode(m), controlmode(interactive){};
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_chan(Tv & t, int c);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void show_controlmode();
};


class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

public:
	friend class Remote;
	enum {Off, On};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc =125):state(s), volume(5), maxchannel(mc),
			channel(2), mode(Cable), input(TV){}
	void onoff(){state = (state == On)? Off : On;}
	bool ison() const{return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode(){mode = (mode == Antenna)? Cable:Antenna;}
	void set_input(){input = (input == TV) ? DVD : TV;}
	void settings() const;
	void toggle_controlmode(Remote & R);
};

inline bool Remote::volup(Tv & t) { return t.volup();}
inline bool Remote::voldown(Tv & t) { return t.voldown();}
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) {t.chandown();}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}
#endif /* TV_H_ */
