#include "stdafx.h"

#include "g2.h"

extern g2::TextureRef* ref;
extern g2::TextureRef* atlasRef;

void Draw() {
	// Enable blending
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
	

	g2::Internal::ace_texture_rect->draw(
		g2::Internal::ace_atlas_prog, 
		atlasRef->ace_texture, 
		20, 450, 1075, 24, &g2::Internal::WinOrtho);

	atlasRef->ace_texture->deactivate();


	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
