#include "stdafx.h"

#include <map>

#include "g2/AceRgbRect.hpp"
#include "g2/AceProgram.hpp"
#include "g2/AceTextureRect.hpp"
#include "g2/AceTextureGlyph.hpp"

#include "g2/g2_externals.h"
#include "g2/g2_texture.h"
#include "g2/g2_opacity.h"

using namespace g2;
using namespace g2::Internal;
using namespace g2::flags;

namespace g2 {

	namespace flags {
		int G2_TEXTURE = 1 << 0;

		int G2_MASK = 1 << 1;

		int G2_RGB_SOLID = 1 << 2;
		int G2_RGB_HORIZ_GRADIENT = 1 << 3;
		int G2_RGB_VERT_GRADIENT = 1 << 4;

		int G2_ALPHA_SOLID = 1 << 5;
		int G2_ALPHA_HORIZ_GRADIENT = 1 << 6;
		int G2_ALPHA_VERT_GRADIENT = 1 << 7;
		int G2_ALPHA_NONE = 1 << 8;

		int G2_PAD_LEFT = 1 << 9;
		int G2_PAD_TOP = 1 << 10;
		int G2_PAD_RIGHT = 1 << 11;
		int G2_PAD_BOTTOM = 1 << 12;

		int G2_BORDER_LEFT = 1 << 13;
		int G2_BORDER_TOP = 1 << 14;
		int G2_BORDER_RIGHT = 1 << 15;
		int G2_BORDER_BOTTOM = 1 << 16;

		int G2_RGB_ANY = G2_RGB_SOLID | G2_RGB_HORIZ_GRADIENT | G2_RGB_VERT_GRADIENT;
		int G2_PAD_ANY = G2_PAD_LEFT | G2_PAD_TOP | G2_PAD_RIGHT | G2_PAD_BOTTOM;
	}

	namespace Internal {

		float red1 = 1.f, green1 = 1.f, blue1 = 1.f;
		float red2 = 1.f, green2 = 1.f, blue2 = 1.f;

		int padding_left = 0, padding_top = 0, padding_right = 0, padding_bottom = 0;

		glm::mat4 WinOrtho;

		AceProgram* ace_rgb_prog;
		AceProgram* ace_texture_prog;
		AceProgram* ace_atlas_prog;
		AceProgram* ace_mask_rgb_prog;
		AceProgram* ace_mask_texture_prog;

		AceRgbRect* ace_rgb_rect;
		AceTextureRect* ace_texture_rect;
		AceTextureGlyph* ace_texture_glyph;
		AceMaskRgbRect* ace_mask_rgb_rect;

		Atlas *current_atlas = 0;
		TextureRef* current_atlas_ref = 0;
		TextureRef* current_mask_ref = 0;

		AceTexture* current_ace_texture = 0;

		std::map<std::string, Atlas*> atlasMap;
		std::map<std::string, TextureRef*> atlasRefMap;

		std::stack<glm::mat4> orthoStack;
		std::stack<int> viewportStack2;

		int viewportWidth, viewportHeight;
	}
}

void g2::Internal::_getAlphas(int flags, float* alphas, float alpha1_effective, float alpha2_effective) {
	if (flags & G2_ALPHA_NONE) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = 1.f;
	}
	else if (flags & G2_ALPHA_SOLID) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1_effective;
	}
	else if (flags & G2_ALPHA_HORIZ_GRADIENT) {
		alphas[0] = alpha1_effective;
		alphas[1] = -1;
		alphas[2] = alpha2_effective;
		alphas[3] = -1;
	}
	else if (flags & G2_ALPHA_VERT_GRADIENT) {
		alphas[0] = -1;
		alphas[1] = alpha1_effective;
		alphas[2] = -1;
		alphas[3] = alpha2_effective;
	}
	else {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = 1.f;
	}
}

// [0] is color of left-bottom
// [1] is color of left-top
// [2] is color of right-top
// [3] is color of right-bottom
void g2::Internal::_getRgbs(int flags,
	float* reds, float *greens, float *blues,
	float red1, float green1, float blue1,
	float red2, float green2, float blue2) {

	if (flags & G2_RGB_SOLID) {
		reds[0] = reds[1] = reds[2] = reds[3] = red1;
		greens[0] = greens[1] = greens[2] = greens[3] = green1;
		blues[0] = blues[1] = blues[2] = blues[3] = blue1;
	}
	else if (flags & G2_RGB_HORIZ_GRADIENT) {
		reds[0] = reds[1] = red1;
		greens[0] = greens[1] = green1;
		blues[0] = blues[1] = blue1;

		reds[2] = reds[3] = red2;
		greens[2] = greens[3] = green2;
		blues[2] = blues[3] = blue2;
	}
	else if (flags & G2_RGB_VERT_GRADIENT) {
		reds[2] = reds[1] = red1;
		greens[2] = greens[1] = green1;
		blues[2] = blues[1] = blue1;

		reds[0] = reds[3] = red2;
		greens[0] = greens[3] = green2;
		blues[0] = blues[3] = blue2;
	}
	else {
		reds[0] = reds[1] = reds[2] = reds[3] = red1;
		greens[0] = greens[1] = greens[2] = greens[3] = green1;
		blues[0] = blues[1] = blues[2] = blues[3] = blue1;
	}
}
