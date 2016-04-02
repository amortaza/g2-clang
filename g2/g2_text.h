#pragma once

namespace g2 {
	void font(char* name, int height);
	void text(int x, int y, char* str);
	void text_flow(char* str);
	int* font_metric(char* str);
	int  font_height();
	void font_color(unsigned char r, unsigned char g, unsigned char b);

	namespace Internal {
		int _text(int x, int y, char* str);
	}
}