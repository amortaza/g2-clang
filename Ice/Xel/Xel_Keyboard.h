#pragma once

namespace Xel {

    namespace Keyboard {

        namespace Internal {
            extern void (*g_OnDown)(unsigned long long xcode);
            extern void (*g_OnUp)(unsigned long long xcode);

            unsigned long long VirtualCodeToXCode(unsigned long long vcode);
        }

        void SetCallbacks(  void (*OnDown)(unsigned long long xcode),
                            void (*OnUp)(unsigned long long xcode));

        char* XCodeToString(unsigned long long xcode);
    }
}