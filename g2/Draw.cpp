#include "stdafx.h"

#include "g2.h"

extern g2::TextureRef* ref;
extern g2::CanvasRef* can;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    g2::viewport(winW, winH);
	g2::ortho(0,0,winW, winH);

    g2::clear();    
    
    g2::rgb(0, 100, 0);
    g2::rectRgb(2, 2, winW - 4, winH - 4);
	
    g2::rgb(200, 0, 0);
    g2::rectRgb(20, 50, 400, 300);

	g2::texture(ref);
	g2::rectTexture(200, 200, 400, 300);
	
	g2::rgb(0, 200, 0);
	g2::rectRgb(20, 450, 400, 300);

	
	
	g2::rgb(0, 200, 0);
	g2::rectRgb(190, 190, 400 + 20, 400 + 20);
	
	g2::texture(ref);
	g2::rectTexture(200, 200, 400, 400);
	
	g2::rgb(200, 0, 0);
	g2::rectRgb(390, 140, 420, 420);

	g2::texture(can);
	g2::rectTexture(400, 150, 400, 400);
}
