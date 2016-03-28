#include "stdafx.h"

#include "g2.h"

g2::TextureRef* ref;
g2::CanvasRef* can;

void Init_OnGL() {
	g2::init();

	ref = g2::loadTexture("c:\\_c\\g2\\a.jpg");
	can = g2::createCanvas(400, 400);
}

void UnInit() {
	delete ref;
	delete can;

	g2::uninit();
}