#include "stdafx.h"

#include "AceProgram.hpp"
#include "AceImageRect.hpp"
#include "AceRgbRect.hpp"
#include "AceTexRect.hpp"
#include "AceFramebuffer.hpp"
#include "AceScreen.hpp"

#include "g2.h"

extern AceProgram* ProgCol;
extern AceProgram* ProgTex;
extern AceProgram* ProgScreen;

extern AceRgbRect*   RectRgb;
extern AceTexRect*   RectTex;
extern AceImageRect* RectImg;

extern AceScreen* Screen;

// test
extern AceTexture* testTexture;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    g2::viewport(winW, winH);

    g2::clear();

    g2::ortho(winW, winH);
    
    //g2::rgb(0, 100, 0);
    //g2::rect(2, 2, winW - 4, winH - 4);
	/*
    g2::beginQuad();
    {
        g2::rgb(200, 0, 0);
        g2::rgb(0, 0, 0);
        g2::rgb(0, 0, 0);
        g2::rgb(0, 0, 255);
        g2::rect(20, 50, 400, 300);
    }
    g2::end();
	*/

}
