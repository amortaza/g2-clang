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
    
    //g2::rgb(0, 100, 0);
    //g2::rectRgb(2, 2, winW - 4, winH - 4);
	
    //g2::rgb(200, 100, 0);
    //g2::rectRgb(20, 200, 400, 300);

	//g2::texture(ref);
	//g2::rectTexture(100, 100, 800, 600);

	g2::font("arial", 24);
	g2::text(120,200,"Welcome to the Circus");
	g2::text_flow(", now full of happiness!");
	g2::text_flow("But wait");

	g2::font("arial", 30);
	g2::text(220, 300, "Welcome to the Circus");
	g2::text_flow(", now full of happiness!");
	g2::text_flow("But wait");

	//g2::font("arial", 10);
	//g2::text(220, 300, "Welcome to the Circus, filled with funny big Clowns!");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
