#pragma once

namespace Xel {

    void Init();

    void Close();

    void Loop(void(*TickCallback)());
}

