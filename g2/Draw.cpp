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
    
    g2::rgb(0, 40, 60);
    g2::rectRgb(2, 2, winW - 4, winH - 4);
	
	/*g2::opacity(.299f);
	g2::rgb(255, 0, 0);
	g2::rectRgb(20, 200, 320, 240);
	
	g2::opacity(.29925f);
	g2::rgb(0, 255, 0);
	g2::rectRgb(260, 250, 320, 240);*/

	g2::rgb(200, 100, 0);
	g2::rgb2(200, 100, 200);
    g2::rect(g2::FLAG_RGB_HORIZ_GRADIENT, 20, 200, 320, 240);
	g2::rect(g2::FLAG_RGB_VERT_GRADIENT, 340, 200, 320, 240);

	/*g2::opacity(.1f);
	g2::texture(ref);
	g2::rectTexture(300, 100, 400, 300);
	
	g2::opacity(.41f);
	g2::texture(ref);
	g2::rectTexture(400, 200, 400, 300);*/

	/*
	g2::opacity(.9925f);
	g2::font("arial", 40);
	g2::rgb(255, 0, 0);	
	g2::text(420, 300, "Welcome");

	g2::opacity(.49925f);
	g2::rgb(255, 0, 0);
	g2::text(480, 350, "Welcome");
	*/
	/*
	g2::font_color(255, 255, 0);
	g2::text_flow(" to");

	g2::font_color(0, 255, 0);
	g2::text_flow(" The");

	g2::font_color(255, 0, 255);
	g2::text_flow(" Circus!");*/

	//g2::font("arial", 10);
	//g2::text(220, 300, "Welcome to the Circus, filled with funny big Clowns!");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
