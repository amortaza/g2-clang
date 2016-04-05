#include "stdafx.h"

#include "g2/g2.h"

g2::TextureRef* ref;

void Init_OnGL() {
	g2::init();

	//ref = g2::loadTextureRgb("c:\\_c\\g2\\a.jpg");	
	ref = g2::loadTextureRgb("c:\\_c\\g2\\jet.png");
}

void UnInit() {
	delete ref;

	g2::uninit();
}