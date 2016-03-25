#include "stdafx.h"

#include "AceProgram.hpp"
#include "AceImageRect.hpp"
#include "AceRgbRect.hpp"
#include "AceTexRect.hpp"
#include "AceScreen.hpp"

AceProgram* ProgTex;
AceProgram* ProgRgb;
AceProgram* ProgScreen;

AceRgbRect*   RectRgb;
AceTexRect*   RectTex;
AceImageRect* RectImg;

AceScreen* Screen;

// test
AceTexture* testTexture;

void Init() {
    glClearColor(0.0f, 1.0f, 0.0f, 0.5f);

    glActiveTexture(GL_TEXTURE0);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_CULL_FACE);

    ProgTex = new AceProgram("c:/_c/ice/shader/tex_rect.vertex.txt", "c:/_c/ice/shader/tex_rect.fragment.txt");
    ProgRgb = new AceProgram("c:/_c/ice/shader/col_rect.vertex.txt", "c:/_c/ice/shader/col_rect.fragment.txt");
    ProgScreen = new AceProgram("c:/_c/ice/shader/screen.vertex.txt", "c:/_c/ice/shader/screen.fragment.txt");

    RectImg = new AceImageRect("c:/_c/ice/a.jpg", 1280, 940, ProgTex);
	RectRgb = new AceRgbRect();
    RectTex = new AceTexRect();

    Screen = new AceScreen(RectTex, ProgScreen);

    // test
    testTexture = new AceTexture(1280, 940);
    testTexture->load("c:/_c/ice/a.jpg");
}

void UnInit() {
    delete testTexture;

    delete Screen;

    delete RectImg;
    delete RectRgb;
    delete RectTex;

    delete ProgTex;
    delete ProgRgb;
    delete ProgScreen;
}