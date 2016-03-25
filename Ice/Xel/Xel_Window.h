#pragma once

namespace Xel {

    namespace Window {

        extern int width, height;

        void SetPosition(int x, int y);

        void SetSize(int w, int h);

        void SetTitle(char *title);

        void SetCallbacks(
                void (*OnResize)(int w, int h),
                void (*OnAfterGLCreated)(),
                void(*OnBeforeGLDeleted)()
        );

        namespace Internal {
            extern unsigned int g_ResizeCount;
            extern void (*g_OnResize)(int w, int h);
            extern void(*g_OnBeforeGLDeleted)();
        }
    }
}