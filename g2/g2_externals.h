#pragma once

#include <map>

#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceProgram.hpp"

#include "free_font.h"

namespace g2 {

	namespace Internal {

		extern float red;
		extern float green;
		extern float blue;

		extern float red2;
		extern float green2;
		extern float blue2;

		extern glm::mat4 WinOrtho;

		extern AceProgram* ace_rgb_prog;
		extern AceProgram* ace_texture_prog;
		extern AceProgram* ace_atlas_prog;

		extern AceRgbRect* ace_rgb_rect;
		extern AceTextureRect* ace_texture_rect;

		extern AceTexture* current_ace_texture;

		extern Atlas *current_atlas;
		extern TextureRef* current_atlas_ref;

		extern std::map<std::string, Atlas*> atlasMap;
		extern std::map<std::string, TextureRef*> atlasRefMap;
	}
}
