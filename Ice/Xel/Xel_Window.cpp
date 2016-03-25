#include "stdafx.h"

#include "WinOs/WinOs.h"
#include "Xel/Xel.h"

namespace Xel {

    namespace Window {

        int width, height;

        namespace Internal {
            unsigned int g_ResizeCount = 0;

            void (*g_OnResize)(int w, int h) = 0;
            void (*g_OnBeforeGLDeleted)() = 0;
        }

        void SetPosition(int x, int y) {
            WinOs::Window::SetPosition(x, y);
        }

        void SetSize(int w, int h) {
            if (Internal::g_OnResize != 0)
                WinOs::Window::SetSize(w, h);

            else {
                std::cout << "Must call Xel::Window::SetCallbacks BEFORE calling SetSize.  Its just good manners :)" << std::endl;
                Xel::Close();
            }
        }

        void SetTitle(char *title) {
            WinOs::Window::SetTitle(title);
        }

        void SetCallbacks(
                void (*OnResize)(int w, int h),
                void (*OnAfterGLCreated)(),
                void (*OnBeforeGLDeleted)() ) {

            Internal::g_OnResize = OnResize;
            Internal::g_OnBeforeGLDeleted = OnBeforeGLDeleted;

            OnAfterGLCreated();
        }
    }
}
