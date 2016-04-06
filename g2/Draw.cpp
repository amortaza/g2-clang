#include "stdafx.h"

#include "g2/g2.h"
#include "g2/g2_externals.h"

using namespace g2::flags;
using namespace g2::Internal;

extern g2::TextureRef* jet;
extern g2::TextureRef* guitar;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    g2::viewport(winW, winH);
	g2::ortho(winW, winH);

    g2::clear();   

    //g2::color(200, 0, 200);
    //g2::rect(G2_RGB_SOLID | G2_ALPHA_NONE, 2, 2, winW - 4, winH - 4);

	/*float reds[4], greens[4], blues[4];
	g2::Internal::_getRgbs(G2_RGB_SOLID, reds, greens, blues, 1, 0.5f, 0.3f, 0, 0, 0);
	float alphas[4];
	g2::Internal::_getAlphas(G2_ALPHA_NONE, alphas, 1.f, 1.f);

	ace_mask_rgb_rect->draw(ace_mask_rgb_prog, ref->ace_texture, 100,100,600,480, &WinOrtho, alphas, reds, greens, blues);*/

	g2::mask(jet);
	//g2::texture(guitar);
	g2::color(45, 32, 90);
	g2::rect(G2_RGB_SOLID|G2_ALPHA_NONE|G2_MASK, 100,100,640,480);


	g2::color(45, 90, 32);
	g2::rect(G2_RGB_SOLID | G2_ALPHA_NONE, 400, 400, 640, 480);
	//ace_texture_rect->draw(ace_texture_prog, ref->ace_texture, 10, 600, 300, 200, &WinOrtho, alphas, 0.f);
	
	//g2::opacity(.5f);
		/*g2::rgb(255, 255, 255);
		g2::rect(G2_RGB_SOLID | G2_ALPHA_NONE, 20, 200, 320, 240);

		g2::opacity(.0499f);
		g2::opacity2(1.f);
		g2::texture(ref);
		g2::rect(G2_TEXTURE | G2_ALPHA_HORIZ_GRADIENT, 360, 100, 320, 240);*/
		

	/*g2::opacity(0.f);
	g2::opacity2(1.f);
	g2::texture(ref);
	g2::rect(G2_TEXTURE | G2_ALPHA_HORIZ_GRADIENT, 360, 300, 320, 240);

	g2::texture(ref);
	g2::rect(G2_TEXTURE | G2_ALPHA_NONE, 30, 300, 320, 240);*/
	
	/*g2::opacity(.4f);
	g2::color(0, 100, 0);
	g2::color2(100, 0, 0);
    g2::rect(G2_RGB_HORIZ_GRADIENT, 21, 21, 178, 178);*/
	//g2::rect(G2_RGB_SOLID, 400, 200, 320, 240);

	//g2::color(100, 0, 0);
	//g2::border(G2_BORDER_LEFT | G2_ALPHA_NONE, 10, 10, 100, 100, 10);
	//g2::border(G2_BORDER_RIGHT | G2_ALPHA_NONE, 10, 10, 100, 100, 10);
	//g2::border(G2_BORDER_BOTTOM | G2_BORDER_RIGHT | G2_BORDER_LEFT | G2_BORDER_TOP | G2_ALPHA_SOLID, 10, 10, 200, 200, 10);
	//g2::border(G2_BORDER_BOTTOM | G2_ALPHA_NONE, 10, 10, 100, 100, 10);

	//g2::texture(ref);
	//g2::rect(G2_TEXTURE | G2_ALPHA_NONE, 1, 1, ref->ace_texture->w, ref->ace_texture->h);

	//g2::padding(20, 20, 20, 20);
	//g2::rect(G2_TEXTURE | G2_ALPHA_NONE | G2_PAD_LEFT | G2_PAD_RIGHT | G2_PAD_TOP | G2_PAD_BOTTOM, 320, 240, 320, 240);
	
	/*g2::opacity(.199f);
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
	g2::color(255, 0, 0);	

	g2::color(255, 0, 0);
	g2::text(480, 350, "Welcome");
	
	g2::color(255, 255, 0);
	g2::text_flow(" to");

	g2::color(0, 255, 0);
	g2::text_flow(" The");

	g2::color(255, 0, 255);
	g2::text_flow(" Circus!");*/
	
	//g2::font("arial", 30);
	//g2::rgb(255, 255, 255);
	//g2::text(200, 200, "Welcome to the Circus, filled with funny big Clowns!");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
