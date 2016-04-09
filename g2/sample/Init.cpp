#include "stdafx.h"

#include "g2/g2.h"

g2::TextureRef* guitar;
g2::TextureRef* jet;
g2::TextureRef* prof;

void Init_OnGL() {
	g2::init();

	guitar = g2::loadTextureRgb("c:\\_c\\g2\\a.jpg");	
	prof = g2::loadTextureRgba("c:\\_c\\g2\\prof.png");
	jet = g2::loadTextureRgba("c:\\_c\\g2\\jet.png");
}

void UnInit() {
	delete guitar;
	delete jet;
	delete prof;

	g2::uninit();
}