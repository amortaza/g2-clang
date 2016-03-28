#include "stdafx.h"

#include "g2.h"

g2::TextureRef* ref;
g2::CanvasRef* can;

void Init_OnGL() {
	g2::init();

	ref = g2::loadTexture("c:\\_c\\g2\\a.jpg");
	can = g2::createCanvas(400, 400);

	g2::paintCanvas(can);
	{
		g2::ortho(0, 0, 800, 800);
		g2::rgb(200, 000, 200);
		g2::rectRgb(0, 0, 300, 300);
	}
	g2::endCanvas();
}

void UnInit() {
	delete ref;
	delete can;

	g2::uninit();
}