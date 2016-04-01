#include "stdafx.h"

#include "g2.h"

#include "free_font.h"

g2::TextureRef* ref;
g2::TextureRef* atlasRef;

Atlas *atlas;
int * coords;
char* message = "Welcome to the Circus! Home of the FUNNY CLOWNS {0123456789}";

// 1075 x 24
void Init_OnGL() {
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	atlas = new Atlas("C:\\_c\\c_lib\\lib\\arial.ttf");
	atlas->load(32);
	//atlas->toFile("c:\\temp\\atlas.data");
	printf("atlas width %i, height%i\n", atlas->atlasWidth, atlas->atlasHeight);

	g2::init();

	ref = g2::loadTextureRgb("c:\\_c\\g2\\a.jpg");
	atlasRef = g2::loadTextureAlpha(atlas->buffer, atlas->atlasWidth, atlas->atlasHeight);



	CoreDraw core;

	coords = new int[strlen(message) * 2];

	core.core2(message, 100, 100, atlas, coords);
}

void UnInit() {
	delete ref;
	delete atlasRef;
	delete atlas;
	delete[] coords;

	g2::uninit();
}