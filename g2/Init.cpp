#include "stdafx.h"

#include "g2.h"

g2::TextureRef* ref;

void Init_OnGL() {
	g2::init();

	ref = g2::loadTextureRgb("c:\\_c\\g2\\a.jpg");	
}

void UnInit() {
	delete ref;

	g2::uninit();
}