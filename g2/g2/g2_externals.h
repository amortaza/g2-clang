#pragma once

#include <map>

#include "AceProgram.hpp"

#include "AceMaskRgbRect.hpp"
#include "AceRgbRect.hpp"
#include "AceTextureRect.hpp"
#include "AceTextureGlyph.hpp"

#include "free_font/free_font.h"

#include "g2_texture.h"
#include "g2_opacity.h"

namespace g2 {
	namespace flags {
		extern int G2_TEXTURE;

		extern int G2_RGB_SOLID;
		extern int G2_RGB_HORIZ_GRADIENT;
		extern int G2_RGB_VERT_GRADIENT;

		extern int G2_ALPHA_NONE;
		extern int G2_ALPHA_SOLID;
		extern int G2_ALPHA_HORIZ_GRADIENT;
		extern int G2_ALPHA_VERT_GRADIENT;

		extern int G2_PAD_LEFT;
		extern int G2_PAD_TOP;
		extern int G2_PAD_RIGHT;
		extern int G2_PAD_BOTTOM;

		extern int G2_BORDER_LEFT;
		extern int G2_BORDER_TOP;
		extern int G2_BORDER_RIGHT;
		extern int G2_BORDER_BOTTOM;

		extern int G2_MASK;

		extern int G2_RGB_ANY;
		extern int G2_PAD_ANY;
	}

	namespace Internal {

		extern float red1, green1, blue1;
		extern float red2, green2, blue2;

		extern int padding_left, padding_top, padding_right, padding_bottom;

		extern glm::mat4 WinOrtho;

		extern AceProgram* ace_rgb_prog;
		extern AceProgram* ace_texture_prog;
		extern AceProgram* ace_atlas_prog;
		extern AceProgram* ace_mask_rgb_prog;
		extern AceProgram* ace_mask_texture_prog;

		extern AceRgbRect* ace_rgb_rect;
		extern AceTextureRect* ace_texture_rect;
		extern AceTextureGlyph* ace_texture_glyph;
		extern AceMaskRgbRect* ace_mask_rgb_rect;

		extern AceTexture* current_ace_texture;

		extern Atlas *current_atlas;
		extern TextureRef* current_atlas_ref;
		extern TextureRef* current_mask_ref;

		extern std::map<std::string, Atlas*> atlasMap;
		extern std::map<std::string, TextureRef*> atlasRefMap;

		extern std::stack<glm::mat4> orthoStack;
		extern std::stack<int> viewportStack2;

		extern int viewportWidth, viewportHeight;

		void _freeMaps();
		void _rect(int flags, int left, int top, int width, int height, float topTextureCoord);

		void _getRgbs(int flags,
			float* reds, float *greens, float *blues,
			float red1, float green1, float blue1,
			float red2, float green2, float blue2);

		void _getAlphas(int flags, float* alphas, float alpha1_effective, float alpha2_effective);
	}
}
