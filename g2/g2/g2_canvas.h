#pragma once

#include "AceFramebuffer.hpp"

namespace g2 {

	extern class CanvasRef;

	CanvasRef* createCanvas(int w, int h);

	void paintCanvas(CanvasRef*);
	void endCanvas();
}
