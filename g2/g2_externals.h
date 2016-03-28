#pragma once

#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceProgram.hpp"

namespace g2 {

	namespace Internal {

		extern float red;
		extern float green;
		extern float blue;

		extern glm::mat4 WinOrtho;

		extern AceProgram* ace_rgb_prog;
		extern AceProgram* ace_texture_prog;

		extern AceRgbRect* ace_rgb_rect;
		extern AceTextureRect* ace_texture_rect;
	}
}
