#include "stdafx.h"

#include "AceProgram.hpp"
#include "AceImageRect.hpp"
#include "AceColRect.hpp"
#include "AceTexRect.hpp"
#include "AceScreen.hpp"

AceProgram* ProgTex;
AceProgram* ProgCol;
AceProgram* ProgScreen;

AceColRect*   RectCol;
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
    ProgCol = new AceProgram("c:/_c/ice/shader/col_rect.vertex.txt", "c:/_c/ice/shader/col_rect.fragment.txt");
    ProgScreen = new AceProgram("c:/_c/ice/shader/screen.vertex.txt", "c:/_c/ice/shader/screen.fragment.txt");

    RectImg = new AceImageRect("c:/_c/ice/a.jpg", 1280, 940, ProgTex);
    RectCol = new AceColRect();
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
    delete RectCol;
    delete RectTex;

    delete ProgTex;
    delete ProgCol;
    delete ProgScreen;
}