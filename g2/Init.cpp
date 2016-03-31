#include "stdafx.h"

#include "g2.h"

#include "free_font.h"

g2::TextureRef* ref;
g2::TextureRef* atlasRef;

Atlas *atlas;
// 1075 x 24
void Init_OnGL() {
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	atlas = new Atlas("C:\\_c\\c_lib\\lib\\arial.ttf");
	atlas->load(26);
	//atlas->toFile("c:\\temp\\atlas.data");
	printf("atlas width %i, height%i\n", atlas->atlasWidth, atlas->atlasHeight);

	g2::init();

	ref = g2::loadTextureRgb("c:\\_c\\g2\\a.jpg");
	atlasRef = g2::loadTextureAlpha(atlas->buffer, atlas->atlasWidth, atlas->atlasHeight);
}

void UnInit() {
	delete ref;
	delete atlasRef;
	delete atlas;

	g2::uninit();
}