#include "stdafx.h"

#include "g2.h"

g2::TextureRef* ref;
g2::CanvasRef* can;

g2::CanvasRef* can2;

void Init_OnGL() {
	g2::init();

	ref = g2::loadTexture("c:\\_c\\g2\\a.jpg");
	can = g2::createCanvas(400, 400);
	can2 = g2::createCanvas(200, 200);


	g2::paintCanvas(can); {	
		g2::paintCanvas(can2); {
			g2::rgb(200, 200, 20);
			g2::rectRgb(10, 10, 100, 100);
		}
		g2::endCanvas();

		g2::rgb(200, 000, 200);
		g2::rectRgb(0, 0, 300, 300);

		g2::texture(can2);
		g2::rectTexture(10, 45, 200, 200);
	}
	g2::endCanvas();
}

void UnInit() {
	delete ref;
	delete can;
	delete can2;

	g2::uninit();
}