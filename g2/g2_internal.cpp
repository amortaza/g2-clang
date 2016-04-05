#include "stdafx.h"

#include <map>

#include "g2/AceRgbRect.hpp"
#include "g2/AceProgram.hpp"
#include "g2/AceTextureRect.hpp"
#include "g2/AceTextureGlyph.hpp"

#include "g2/g2_texture.h"
#include "g2/g2_opacity.h"

namespace g2 {

	namespace flags {
		int G2_TEXTURE = 1 << 0;

		int G2_RGB_SOLID = 1 << 2;
		int G2_RGB_HORIZ_GRADIENT = 1 << 3;
		int G2_RGB_VERT_GRADIENT = 1 << 4;

		int G2_RGB_ANY = G2_RGB_SOLID | G2_RGB_HORIZ_GRADIENT | G2_RGB_VERT_GRADIENT;

		int G2_ALPHA_SOLID = 1 << 5;
		int G2_ALPHA_HORIZ_GRADIENT = 1 << 6;
		int G2_ALPHA_VERT_GRADIENT = 1 << 7;
		int G2_ALPHA_NONE = 1 << 8;
	}

	namespace Internal {

		float red1 = 1.f, green1 = 1.f, blue1 = 1.f;
		float red2 = 1.f, green2 = 1.f, blue2 = 1.f;

		glm::mat4 WinOrtho;

		AceProgram* ace_rgb_prog;
		AceProgram* ace_texture_prog;
		AceProgram* ace_atlas_prog;

		AceRgbRect* ace_rgb_rect;
		AceTextureRect* ace_texture_rect;
		AceTextureGlyph* ace_texture_glyph;

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

