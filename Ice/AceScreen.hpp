#pragma once

#include "AceTexRect.hpp"
#include "AceFramebuffer.hpp"

class AceScreen {

public:
    AceFramebuffer* framebuffer;
    int winW, winH;

private:
    AceTexRect* TexRect;
    AceProgram* ScreenProg;

public:

    AceScreen(AceTexRect* TexRect, AceProgram* ScreenProg) {
        winW = -1;
        winH = -1;

        this->TexRect = TexRect;
        this->ScreenProg = ScreenProg;
    }

    ~AceScreen() {
        if (framebuffer)
            delete framebuffer;
    }

    void resize(int w, int h) {
        if (w == winW && h == winH)
            return;

        if (framebuffer)
            delete framebuffer;

        winW = w;
        winH = h;

        framebuffer = new AceFramebuffer(winW, winH);
    }

    void render() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        
        glViewport(0, 0, winW, winH);

        glm::mat4 WinOrtho = glm::ortho(0.f, (float)winW, 0.f, (float)winH);
        TexRect->draw(ScreenProg, framebuffer->texture, 4, 4, winW - 8, winH - 8, &WinOrtho);
    }
};