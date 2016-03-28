#include "stdafx.h"

#include "AceRgbRect.hpp"
#include "AceProgram.hpp"
#include "AceTexture.hpp"

#include "g2_stack.h"

namespace g2 {

	namespace Internal {

		float red;
		float green;
		float blue;

		glm::mat4 WinOrtho;

		Stack stack;

		// quad
		int quadIndex;

		float quadRed[4];
		float quadGreen[4];
		float quadBlue[4];

		float quadLeft;
		float quadBottom;
		float quadWidth;
		float quadHeight;

		//
		AceRgbRect* ace_rgb_rect;
		AceProgram* ace_rgb_prog;		
	}
}

