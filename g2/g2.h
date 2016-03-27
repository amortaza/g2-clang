#pragma once

#include "AceRgbRect.hpp"
#include "AceProgram.hpp"

#include "g2_texture.h"

namespace g2 {
	void init();
	void uninit();

    void ortho(int width, int height);

    void viewport(int width, int height);

    void clear();

    void rgb(unsigned char red, unsigned char green, unsigned char blue);

    void rect(int left, int bottom, int width, int height);

    void quad();

    void end();

    namespace Internal {
        extern float red;
        extern float green;
        extern float blue;

        extern glm::mat4 WinOrtho;

        extern int beginType;

        // quad
        extern int quadIndex;

        extern float quadRed[4];
        extern float quadGreen[4];
        extern float quadBlue[4];

        extern float quadLeft;
        extern float quadBottom;
        extern float quadWidth;
        extern float quadHeight;

		//
		extern AceRgbRect* ace_rgb_rect;
		extern AceProgram* ace_rgb_prog;
    }
}