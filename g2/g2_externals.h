#pragma once

#include "AceRgbRect.hpp"
#include "AceProgram.hpp"

#include "g2_stack.h"

namespace g2 {

	namespace Internal {

		extern float red;
		extern float green;
		extern float blue;

		extern glm::mat4 WinOrtho;

		// 0:none, 1:quad, 2:texture
		extern Stack stack;

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
