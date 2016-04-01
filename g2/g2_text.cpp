#include "stdafx.h"
#include "free_font.h"
#include "g2.h"

using namespace g2;
using namespace g2::Internal;

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