#pragma once

#include "AceFramebuffer.hpp"

namespace g2 {
	class CanvasRef {
	public:
		AceFramebuffer* ace_frame_buffer;

		CanvasRef(int w, int h) {
			ace_frame_buffer = new AceFramebuffer(w, h);
		}

		~CanvasRef() {
			delete ace_frame_buffer;
		}
	};

	CanvasRef* createCanvas(int w, int h);

	void paintCanvas(CanvasRef*);
	void endCanvas();
}
