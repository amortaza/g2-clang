#include "stdafx.h"

#include "AceProgram.hpp"
#include "AceImageRect.hpp"
#include "AceColRect.hpp"
#include "AceTexRect.hpp"
#include "AceFramebuffer.hpp"
#include "AceScreen.hpp"

#include "g2.h"

extern AceProgram* ProgCol;
extern AceProgram* ProgTex;
extern AceProgram* ProgScreen;

extern AceColRect*   RectCol;
extern AceTexRect*   RectTex;
extern AceImageRect* RectImg;

extern AceScreen* Screen;

// test
extern AceTexture* testTexture;

void Draw() {
    int winW = Xel::Window::width;
    int winH = Xel::Window::height;

    //Screen->resize(winW, winH);

    g2::viewport(winW, winH);

    g2::clear();

    g2::ortho(winW, winH);
    
    g2::rgb(10, 200, 0);
    g2::rect(2, 2, winW - 4, winH - 4);

    g2::beginQuad();
    {
        g2::rgb(200, 0, 0);
        g2::rgb(0, 0, 0);
        g2::rgb(0, 0, 0);
        g2::rgb(0, 0, 255);
        g2::rect(20, 50, 400, 300);
    }
    g2::end();

    //RectCol->draw(ProgCol, 2, 2, winW - 4, winH - 4, &WinOrtho);

    //imgRect->draw(210, 310, 300, 300, &Projection);

    //Screen->framebuffer->glBegin();
    //{
    //    RectCol->draw(ProgCol, 2, 2, winW - 4, winH - 4, &WinOrtho);
    //    RectCol->draw(ProgCol, 150, 250, 128, 128, &WinOrtho);
    //    //texRect->draw(texProg, gTexture, -10, 250, 128, 128, &p2);
    //    RectImg->draw(10, 10, 128, 128, &WinOrtho);
    //}
    //Screen->framebuffer->glEnd();

    //Screen->render();
}
