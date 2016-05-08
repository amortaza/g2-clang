#pragma once

extern class AceTexture;

namespace g2 {
	class TextureRef {
	public:
		AceTexture* ace_texture;

		~TextureRef();
	};
}
