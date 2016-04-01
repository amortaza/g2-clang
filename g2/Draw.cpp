#include "stdafx.h"

#include "g2.h"

#include "free_font.h"

extern g2::TextureRef* ref;
extern g2::TextureRef* atlasRef;
extern Atlas *atlas;
extern char* message;
extern int* coords;

void Draw() {
	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
	

	/*g2::Internal::ace_texture_rect->draw(
		g2::Internal::ace_atlas_prog, 
		atlasRef->ace_texture, 
		20, 450, atlasRef->ace_texture->w, atlasRef->ace_texture->h, 
		&g2::Internal::WinOrtho);*/

	int len = strlen(message)*2;

	for (int i = 0; i < len; ) {
		char c = message[i/2];
		int x = coords[i++];
		int y = coords[i++];

		printf("char %c, x %i, y %i\n", c, x, y);

		g2::Internal::ace_texture_rect->drawAtlasSub(
			g2::Internal::ace_atlas_prog,
			atlasRef->ace_texture, atlas->charX[c], atlas->charWidth[c] , atlasRef->ace_texture->h, atlasRef->ace_texture->w,
			x, y,
			&g2::Internal::WinOrtho);
	}

	atlasRef->ace_texture->deactivate();

	printf("----------------------\n");

	//g2::texture(atlasRef);
	//g2::rectTexture(20, 450, 500, 100);	
}
