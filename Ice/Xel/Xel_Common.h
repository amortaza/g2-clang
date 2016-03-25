#pragma once

namespace Xel {

    void Init();
    
	void Swap();

    void Loop(void(*TickCallback)());

	void Close();
}

