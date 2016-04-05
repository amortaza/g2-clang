#include "stdafx.h"

#include "free_font/free_font.h"
#include "g2.h"

using namespace g2;
using namespace g2::Internal;

void g2::font(char* name, int height) {
	if (height > 64) {
		printf("currently fonts are limited to height of 64 pixels");
		font(name, 64);
		return;
	}

	if (height < 10) {
		printf("currently fonts are limited to height of 10 pixels");
		font(name, 10);
		return;
	}

	std::string key(name + height);

	auto element = atlasMap.find(key);

	if (element != atlasMap.end()) {
		current_atlas = element->second;

		auto e2 = atlasRefMap.find(key);
		if (e2 == atlasRefMap.end()) throw "unexpected g2_text.cpp line ~21";
		current_atlas_ref = e2->second;

		return;
	}

	std::string path("C:\\_c\\c_lib\\lib\\");
	std::string fontname(name);
	std::string full(path + fontname + ".ttf");

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	current_atlas = new Atlas(&full[0]);
	current_atlas->load(height);

	current_atlas_ref = g2::loadTextureAlpha(current_atlas->buffer, current_atlas->atlasWidth, current_atlas->atlasHeight);

	atlasMap[key] = current_atlas;
	atlasRefMap[key] = current_atlas_ref;
}

// letter height = font_height() + coords[ oddIndex ]
int g2::font_height() {
	return current_atlas->atlasHeight;
}

int* g2::font_metric(char* str) {
	CoreDraw core;
	int * coords;
	coords = new int[strlen(str) * 2];
	core.core2(str, 0, 0, current_atlas, coords, '\0');
	return coords;
}

int g2::Internal::_text(int x, int y, char* str) {	
	CoreDraw core;
	int * coords;

	int slen = strlen(str);	

	coords = new int[slen * 2];
	core.core2(str, x, y, current_atlas, coords, last_font_c);

	int len = slen * 2;
	AceTexture* texture = current_atlas_ref->ace_texture;

	int fx = 0;

	for (int i = 0; i < len; ) {
		char c = str[i / 2];

		fx = coords[i++];
		int fy = coords[i++];

		g2::Internal::ace_texture_rect->drawAtlasChar(
			g2::Internal::ace_atlas_prog,
			texture, 
			current_atlas->charX[c], 
			current_atlas->charWidth[c], texture->h, 
			texture->w,
			fx, fy,
			&WinOrtho,
			red1, green1, blue1,
			alpha1_effective);
	}

	texture->deactivate();

	delete[] coords;

	last_font_c = str[slen - 1];

	return fx;
}

void g2::text(int x, int y, char* str) {
	last_font_c = '\0';
	last_font_y = y;
	last_font_x = _text(x, y, str);
}

void g2::text_flow(char* str) {
	last_font_x = _text(last_font_x, last_font_y, str);
}

namespace g2 {
	namespace Internal {
		int last_font_x = 0, last_font_y = 0;
		char last_font_c;
	}
}