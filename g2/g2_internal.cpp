#include "stdafx.h"

#include <map>

#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceProgram.hpp"
#include "AceTexture.hpp"

#include "free_font.h"

#include "g2_texture.h"
#include "g2_opacity.h"

namespace g2 {

	int FLAG_TEXTURE = 1 << 0;

	int FLAG_RGB_SOLID = 1 << 2;
	int FLAG_RGB_HORIZ_GRADIENT = 1 << 3;
	int FLAG_RGB_VERT_GRADIENT = 1 << 4;

	int FLAG_RGB_ANY = FLAG_RGB_SOLID | FLAG_RGB_HORIZ_GRADIENT | FLAG_RGB_VERT_GRADIENT;

	int FLAG_ALPHA_SOLID = 1 << 5;
	int FLAG_ALPHA_HORIZ_GRADIENT = 1 << 6;
	int FLAG_ALPHA_VERT_GRADIENT = 1 << 7;
	int FLAG_ALPHA_NONE = 1 << 8;

	namespace Internal {

		float red1 = 1.f, green1 = 1.f, blue1 = 1.f;
		float red2 = 1.f, green2 = 1.f, blue2 = 1.f;

		glm::mat4 WinOrtho;

		AceProgram* ace_rgb_prog;
		AceProgram* ace_texture_prog;
		AceProgram* ace_atlas_prog;

		AceRgbRect* ace_rgb_rect;
		AceTextureRect* ace_texture_rect;

		Atlas *current_atlas = 0;
		TextureRef* current_atlas_ref = 0;

		AceTexture* current_ace_texture = 0;

		std::map<std::string, Atlas*> atlasMap;
		std::map<std::string, TextureRef*> atlasRefMap;

		std::stack<glm::mat4> orthoStack;
		std::stack<int> viewportStack2;

		int viewportWidth, viewportHeight;
	}
}

