#include "stdafx.h"

#include "g2.h"

extern g2::TextureRef* ref;

extern g2::TextureRef* atlasRef;

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
	g2::rectTexture(100, 100, 400, 300);

	g2::text(120,200,"Welcome to the Circus, filled with funny Clowns!");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
