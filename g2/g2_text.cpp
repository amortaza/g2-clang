#include "stdafx.h"

#include "free_font.h"
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
	core.core2(str, 0, 0, current_atlas, coords);
	return coords;
}

void g2::text(int x, int y, char* str) {
	CoreDraw core;
	int * coords;

	coords = new int[strlen(str) * 2];
	core.core2(str, x, y, current_atlas, coords);

	int len = strlen(str) * 2;
	AceTexture* texture = current_atlas_ref->ace_texture;

	for (int i = 0; i < len; ) {
		char c = str[i / 2];
		int x = coords[i++];
		int y = coords[i++];

		g2::Internal::ace_texture_rect->drawAtlasChar(
			g2::Internal::ace_atlas_prog,
			texture, 
			current_atlas->charX[c], 
			current_atlas->charWidth[c], texture->h, 
			texture->w,
			x, y,
			&WinOrtho);
	}

	texture->deactivate();

	delete[] coords;
}