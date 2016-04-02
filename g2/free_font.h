#pragma once

void SaveImage(char* szPathName, void* lpBits, int w, int h);

class AceType {
	FT_Library  library;

public:
	int advance;
	int glyph_index;

	FT_Face face;

	AceType(const char *fontpath) {
		FT_Init_FreeType(&library);
		FT_New_Face(library, fontpath, 0, &face);
	}

	~AceType() {
		printf("~ freeing face, library\n");

		FT_Done_Face(face);
		FT_Done_FreeType(library);
	}

	FT_Bitmap* draw(char c, int height) {
		FT_Set_Pixel_Sizes(face, 0, height);

		glyph_index = FT_Get_Char_Index(face, c);

		FT_Load_Glyph(face, glyph_index, 0);

		FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);

		advance = face->glyph->metrics.horiAdvance >> 6;

		return &face->glyph->bitmap;
	}
};

class CharAtlas {
public:
	int width, height;
	unsigned char* buffer;

	CharAtlas(FT_Bitmap *bitmap) {
		width = bitmap->width;
		height = bitmap->rows;

		unsigned int size = width * height;

		buffer = new unsigned char[size];

		std::memcpy(buffer, bitmap->buffer, size);
	}

	~CharAtlas() {
		delete[] buffer;
	}
};

class Atlas {
public:
	int atlasWidth, atlasHeight;

	int charX[128];
	int charWidth[128];
	int charHeight[128];
	int charGlyphIndex[128];

	int charAdvance[128];

	int charBitmapTop[128];
	int charBitmapLeft[128];

	unsigned char* buffer;
	AceType* ace;

private:
	int charCount;
	int next;
	CharAtlas ** charatlases;
	char* alpha;
	char *fontpath;

public:
	int getKerning(char a, char b) {
		int i1 = charGlyphIndex[a];
		int i2 = charGlyphIndex[b];

		FT_Vector delta;

		FT_Get_Kerning(ace->face, i1, i2, FT_KERNING_DEFAULT, &delta);

		return delta.x >> 6;
	}

	Atlas(char* fontpath) {
		this->fontpath = fontpath;
		alpha = " 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
		next = 0;
		charCount = std::strlen(alpha);
		charatlases = new CharAtlas*[charCount];
		atlasWidth = atlasHeight = 0;
		buffer = 0;

		for (int i = 0; i<charCount; i++)
			charatlases[i] = 0;

		ace = new AceType(fontpath);
	}

	~Atlas() {
		for (int i = 0; i<charCount; i++) {
			if (charatlases[i]) delete charatlases[i]; 
			
		}

		delete[] charatlases;

		if (buffer) {
			delete[] buffer;
		}

		delete ace;
	}

public:
	void load(int height) {
		for (int i = 0; i<charCount; i++) {
			char c = alpha[i];

			FT_Bitmap *bitmap = ace->draw(c, height);

			charGlyphIndex[c] = ace->glyph_index;
			charAdvance[c] = ace->advance;
			charBitmapTop[c] = ace->face->glyph->bitmap_top;
			charBitmapLeft[c] = ace->face->glyph->bitmap_left;

			charWidth[c] = bitmap->width;
			charHeight[c] = bitmap->rows;

			add(c, bitmap);
		}

		allocate();
	}

	void toFile(char* filename) {
		SaveImage(filename, buffer, atlasWidth, atlasHeight);
	}

private:

	int getMaxHeight() {
		int max = -1;

		for (int i = 0; i<charCount; i++) {
			CharAtlas * charatlas = charatlases[i];
			if (charatlas->height > max) max = charatlas->height;
		}

		return max;
	}

	void copy(CharAtlas * charatlas, unsigned char* buffer, int bufferWidth, int startX, int height) {
		for (int y = 0; y<height; y++) {
			for (int x = 0; x<charatlas->width; x++) {
				int bufferMem = (startX + x) + y * bufferWidth;

				if (y >= charatlas->height) {
					buffer[bufferMem] = 0;
					continue;
				}

				int mem = x + y * charatlas->width;
				int data = charatlas->buffer[mem];

				buffer[bufferMem] = data;
			}
		}
	}

	void allocate() {
		atlasHeight = getMaxHeight();

		buffer = new unsigned char[atlasWidth * atlasHeight];
		memset(buffer, 0, atlasWidth * atlasHeight);

		int x = 0;

		for (int i = 0; i<charCount; i++) {
			CharAtlas * charatlas = charatlases[i];

			copy(charatlas, buffer, atlasWidth, x, atlasHeight);

			x += charatlas->width;
		}
	}

	void add(char c, FT_Bitmap *bitmap) {
		charX[c] = atlasWidth;

		atlasWidth += bitmap->width;

		CharAtlas *charatlas = new CharAtlas(bitmap);

		charatlases[next++] = charatlas;
	}
};

class CoreDraw {
public:
	// for when rendering to buffer
	void core(char* str, int x, int y, Atlas* atlas, int* coords) {
		int len = strlen(str);

		int index = 0;

		int penX = x, penY;

		for (int i = 0; i < len; i++) {
			char c = str[i];

			if (c == ' ') {
				penX += atlas->charAdvance[c];
				index += 2;
				continue;
			}

			penY = y - atlas->charBitmapTop[c];

			int nudgeX = atlas->charBitmapLeft[c];

			int a = penX + nudgeX, b = penY;
			coords[index++] = a;
			coords[index++] = b;

			if (i < len - 1) {
				penX += atlas->getKerning(c, str[i + 1]) + atlas->charAdvance[c];
			}
		}
	}

	// for when rendering to texture
	void core2(char* str, int x, int y, Atlas* atlas, int* coords, char phantomChar) {
		int len = strlen(str);

		int index = 0;

		int penX = x, penY;

		if (len>0 && phantomChar != '\0') {
			penX += atlas->getKerning(phantomChar, str[0]) + atlas->charAdvance[phantomChar];
		}

		for (int i = 0; i < len; i++) {
			char c = str[i];

			if (c == ' ') {
				index += 2;
			}
			else {

				// if ortho is ever flipped vertically where 0,0 is at bottom-left, then use this formula
				//penY = y + atlas->charBitmapTop[c] - atlas->atlasHeight;
				penY = y - atlas->charBitmapTop[c];

				int nudgeX = atlas->charBitmapLeft[c];

				int a = penX + nudgeX, b = penY;
				coords[index++] = a;
				coords[index++] = b;
			}

			if (i < len - 1) {
				penX += atlas->getKerning(c, str[i + 1]) + atlas->charAdvance[c];
			}
		}
	}
};

