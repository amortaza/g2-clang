#pragma once

namespace g2 {
	void font(char* name, int height);

	int* font_metric(char* str);
	int  font_height();

	void text(int x, int y, char* str, float alpha);
	void text_flow(char* str, float alpha);

	namespace Internal {
		extern int last_font_x, last_font_y;

		extern char last_font_c;

		int _text(int x, int y, char* str, float alpha);
	}
}