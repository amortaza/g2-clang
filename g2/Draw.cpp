#include "stdafx.h"

#include "g2.h"

using namespace g2::flags;

extern g2::TextureRef* ref;
extern g2::TextureRef* atlasRef;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    g2::viewport(winW, winH);
	g2::ortho(winW, winH);

    g2::clear();   

    g2::rgb(200, 0, 200);
    g2::rectRgb(2, 2, winW - 4, winH - 4);

	g2::opacity(.5f);
	g2::pushOpacity();
		g2::rgb(255, 255, 255);
		g2::rectRgb(20, 200, 320, 240);

		g2::opacity(.0499f);
		g2::opacity2(1.f);
		g2::texture(ref);
		g2::rect(G2_TEXTURE | G2_ALPHA_HORIZ_GRADIENT, 360, 100, 320, 240);
		
	g2::popOpacity();

	/*g2::opacity(0.f);
	g2::opacity2(1.f);
	g2::texture(ref);
	g2::rect(G2_TEXTURE | G2_ALPHA_HORIZ_GRADIENT, 360, 300, 320, 240);

	g2::texture(ref);
	g2::rect(G2_TEXTURE | G2_ALPHA_NONE, 30, 300, 320, 240);*/
	

	/*g2::rgb(0, 100, 0);
	g2::rgb2(100, 0, 0);
    g2::rect(G2_RGB_HORIZ_GRADIENT, 20, 200, 320, 240);
	g2::rect(G2_RGB_VERT_GRADIENT, 400, 200, 320, 240);*/

	/*g2::texture(ref);
	g2::rectTexture(320, 240, 320, 240);
	
	g2::opacity(.199f);
	g2::texture(ref);
	g2::rectTexture(0, 0, 320, 240);
	g2::opacity(1.f);*/


	/*g2::opacity(.0299f);
	g2::opacity2(.930f);
	g2::texture(ref);
	g2::rect(g2::FLAG_TEXTURE | g2::FLAG_ALPHA_HORIZ_GRADIENT, 340, 240, 320, 240);

	g2::opacity(.99f);
	g2::opacity2(.030f);
	g2::texture(ref);
	g2::rect(g2::FLAG_TEXTURE | g2::FLAG_ALPHA_VERT_GRADIENT, 0, 500, 320, 240);

	g2::opacity(.099f);
	g2::opacity2(.9030f);
	g2::texture(ref);
	g2::rect(g2::FLAG_TEXTURE | g2::FLAG_ALPHA_VERT_GRADIENT, 0, 500, 320, 240);
	*/
	/*
	g2::opacity(.41f);
	g2::texture(ref);
	g2::rectTexture(400, 200, 400, 300);*/

	
	/*g2::font("arial", 40);
	g2::rgb(255, 0, 0);	

	g2::rgb(255, 0, 0);
	g2::text(480, 350, "Welcome");
	
	g2::rgb(255, 255, 0);
	g2::text_flow(" to");

	g2::rgb(0, 255, 0);
	g2::text_flow(" The");

	g2::rgb(255, 0, 255);
	g2::text_flow(" Circus!");
	*/
	//g2::font("arial", 30);
	//g2::rgb(255, 255, 255);
	//g2::text(200, 200, "Welcome to the Circus, filled with funny big Clowns!");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
