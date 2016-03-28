#include "stdafx.h"

#include "g2.h"

extern g2::TextureRef* ref;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    g2::viewport(winW, winH);

    g2::clear();

    g2::ortho(winW, winH);
    
    g2::rgb(0, 100, 0);
    g2::rect(2, 2, winW - 4, winH - 4);
	
    g2::rgb(200, 0, 0);
    g2::rect(20, 50, 400, 300);

	g2::texture(ref);
	g2::rect(200, 200, 400, 300);
	g2::endTexture();

	g2::rgb(0, 200, 0);
	g2::rect(20, 450, 400, 300);
}
