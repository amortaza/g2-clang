#pragma once

extern class AceFramebuffer;

namespace g2 {
	class CanvasRef {
	public:
		AceFramebuffer* ace_frame_buffer;

		CanvasRef(int w, int h);
		~CanvasRef();
	};
}