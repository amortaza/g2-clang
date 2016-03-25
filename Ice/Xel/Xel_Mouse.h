#pragma once

namespace Xel {
    namespace Mouse {
        enum Button {
            Left, Right, Middle, X1, X2
        };

        enum Action {
            Down, Up
        };

        namespace Internal {
            extern void (*g_OnMove)(int x, int y);
            extern void (*g_OnButton)(Button button, Action action, int x, int y);
            extern void (*g_OnScroll)(int amount);
        }

        void SetCallbacks(  void (*OnMove)(int x, int y),
                            void (*OnButton)(Mouse::Button button, Mouse::Action action, int x, int y),
                            void (*OnScroll)(int amount));

        void Capture();
        void Release();
    }
}