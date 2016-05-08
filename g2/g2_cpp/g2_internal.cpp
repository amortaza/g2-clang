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
		unsigned int G2_TEXTURE = 1 << 0;

		unsigned int G2_PAD = 1 << 9;

		unsigned int G2_MASK = 1 << 1;

		unsigned int G2_COLOR_SOLID = 1 << 2;
		unsigned int G2_COLOR_HORIZ_GRADIENT = 1 << 3;
		unsigned int G2_COLOR_VERT_GRADIENT = 1 << 4;
		unsigned int G2_COLOR_ANY = G2_COLOR_SOLID | G2_COLOR_HORIZ_GRADIENT | G2_COLOR_VERT_GRADIENT;

		unsigned int G2_ALPHA_SOLID = 1 << 5;
		unsigned int G2_ALPHA_HORIZ_GRADIENT = 1 << 6;
		unsigned int G2_ALPHA_VERT_GRADIENT = 1 << 7;
		unsigned int G2_ALPHA_NONE = 1 << 8;
		unsigned int G2_ALPHA_ANY = G2_ALPHA_SOLID | G2_ALPHA_HORIZ_GRADIENT | G2_ALPHA_VERT_GRADIENT;
	}

	namespace Internal {

		float red1 = 1.f, green1 = 1.f, blue1 = 1.f;
		float red2 = 1.f, green2 = 1.f, blue2 = 1.f;

		int padding_left = 0, padding_top = 0, padding_right = 0, padding_bottom = 0;

		glm::mat4 WinOrtho;

		AceProgram* ace_color_prog;
		AceRgbRect* ace_color_rect;

		AceProgram* ace_texture_prog;
		AceTextureRect* ace_texture_rect;

		AceProgram* ace_atlas_prog;
		AceTextureGlyph* ace_texture_glyph;

		AceProgram* ace_mask_color_prog;
		AceProgram* ace_mask_texture_prog;
		AceMaskRgbRect* ace_mask_color_rect;

		Atlas *current_atlas = 0;
		TextureRef* current_atlas_ref = 0;
		TextureRef* current_mask_ref = 0;

		AceTexture* current_ace_texture = 0;

		map<string, Atlas*> atlasMap;
		map<string, TextureRef*> atlasRefMap;

		stack<glm::mat4> orthoStack;
		stack<int> viewportStack2;

		int viewportWidth, viewportHeight;
	}
}

void g2::Internal::_getAlphas(int flags, float* alphas, float alpha1, float alpha2) {
	if (flags & G2_ALPHA_NONE) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = 1.f;
	}
	else if (flags & G2_ALPHA_SOLID) {
		alphas[0] = alphas[1] = alphas[2] = alphas[3] = alpha1;
	}
	else if (flags & G2_ALPHA_HORIZ_GRADIENT) {
		alphas[0] = alpha1;
		alphas[1] = -1;
		alphas[2] = alpha2;
		alphas[3] = -1;
	}
	else if (flags & G2_ALPHA_VERT_GRADIENT) {
		alphas[0] = -1;
		alphas[1] = alpha1;
		alphas[2] = -1;
		alphas[3] = alpha2;
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

	if (flags & G2_COLOR_SOLID) {
		reds[0] = reds[1] = reds[2] = reds[3] = red1;
		greens[0] = greens[1] = greens[2] = greens[3] = green1;
		blues[0] = blues[1] = blues[2] = blues[3] = blue1;
	}
	else if (flags & G2_COLOR_HORIZ_GRADIENT) {
		reds[0] = reds[1] = red1;
		greens[0] = greens[1] = green1;
		blues[0] = blues[1] = blue1;

		reds[2] = reds[3] = red2;
		greens[2] = greens[3] = green2;
		blues[2] = blues[3] = blue2;
	}
	else if (flags & G2_COLOR_VERT_GRADIENT) {
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
