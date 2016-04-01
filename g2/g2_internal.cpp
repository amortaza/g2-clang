#include "stdafx.h"

#include <map>

#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceProgram.hpp"
#include "AceTexture.hpp"

#include "free_font.h"

#include "g2_texture.h"

namespace g2 {

	namespace Internal {

		float red;
		float green;
		float blue;

		glm::mat4 WinOrtho;

		AceProgram* ace_rgb_prog;
		AceProgram* ace_texture_prog;
		AceProgram* ace_atlas_prog;

		AceRgbRect* ace_rgb_rect;
		AceTextureRect* ace_texture_rect;

		Atlas *current_atlas = 0;
		TextureRef* current_atlas_ref = 0;

		std::map<std::string, Atlas*> atlasMap;
		std::map<std::string, TextureRef*> atlasRefMap;
	}
}

