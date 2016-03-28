#include "stdafx.h"

#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceProgram.hpp"
#include "AceTexture.hpp"

#include "g2_texture.h"
#include "g2_stack.h"

namespace g2 {

	namespace Internal {

		float red;
		float green;
		float blue;

		glm::mat4 WinOrtho;

		Stack stack;

		//
		AceRgbRect* ace_rgb_rect;
		AceTextureRect* ace_texture_rect;
		AceProgram* ace_rgb_prog;		
		AceProgram* ace_texture_prog;
	}
}

