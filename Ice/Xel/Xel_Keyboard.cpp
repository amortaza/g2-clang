#include "stdafx.h"

#include "Xel/Xel_Keyboard_Def.h"

namespace Xel {

    namespace Keyboard {

        namespace Internal {
            void (*g_OnDown)(unsigned long long xcode);
            void (*g_OnUp)(unsigned long long xcode);

            unsigned long long VirtualCodeToXCode(unsigned long long vcode) {
//                std::cout << "vcode " << vcode << std::endl;

                if (vcode == VK_BACK)
                    return Xel_Key_Back;

                else if (vcode == VK_TAB)
                    return Xel_Key_Tab;

                else if (vcode == VK_RETURN)
                    return Xel_Key_Return;

                else if (vcode == VK_PAUSE)
                    return Xel_Key_Pause;

                else if (vcode == VK_CAPITAL)
                    return Xel_Key_CapsLock;

                else if (vcode == VK_ESCAPE)
                    return Xel_Key_Escape;

                else if (vcode == VK_SPACE)
                    return Xel_Key_Space;

                else if (vcode == VK_PRIOR)
                    return Xel_Key_PageUp;

                else if (vcode == VK_NEXT)
                    return Xel_Key_PageDown;

                else if (vcode == VK_END)
                    return Xel_Key_End;

                else if (vcode == VK_HOME)
                    return Xel_Key_Home;

                else if (vcode == VK_LEFT)
                    return Xel_Key_Left;

                else if (vcode == VK_UP)
                    return Xel_Key_Up;

                else if (vcode == VK_RIGHT)
                    return Xel_Key_Right;

                else if (vcode == VK_DOWN)
                    return Xel_Key_Down;

                else if (vcode == VK_SNAPSHOT)
                    return Xel_Key_PrintScreen;

                else if (vcode == VK_INSERT)
                    return Xel_Key_Insert;

                else if (vcode == VK_DELETE)
                    return Xel_Key_Delete;

                else if (vcode == 0x30)
                    return Xel_Key_0;

                else if (vcode == 0x31)
                    return Xel_Key_1;

                else if (vcode == 0x32)
                    return Xel_Key_2;

                else if (vcode == 0x33)
                    return Xel_Key_3;

                else if (vcode == 0x34)
                    return Xel_Key_4;

                else if (vcode == 0x35)
                    return Xel_Key_5;

                else if (vcode == 0x36)
                    return Xel_Key_6;

                else if (vcode == 0x37)
                    return Xel_Key_7;

                else if (vcode == 0x38)
                    return Xel_Key_8;

                else if (vcode == 0x39)
                    return Xel_Key_9;

                else if (vcode == 0x41)
                    return Xel_Key_A;

                else if (vcode == 0x42)
                    return Xel_Key_B;

                else if (vcode == 0x43)
                    return Xel_Key_C;

                else if (vcode == 0x44)
                    return Xel_Key_D;

                else if (vcode == 0x45)
                    return Xel_Key_E;

                else if (vcode == 0x46)
                    return Xel_Key_F;

                else if (vcode == 0x47)
                    return Xel_Key_G;

                else if (vcode == 0x48)
                    return Xel_Key_H;

                else if (vcode == 0x49)
                    return Xel_Key_I;

                else if (vcode == 0x4A)
                    return Xel_Key_J;

                else if (vcode == 0x4B)
                    return Xel_Key_K;

                else if (vcode == 0x4C)
                    return Xel_Key_L;

                else if (vcode == 0x4D)
                    return Xel_Key_M;

                else if (vcode == 0x4E)
                    return Xel_Key_N;

                else if (vcode == 0x4F)
                    return Xel_Key_O;

                else if (vcode == 0x50)
                    return Xel_Key_P;

                else if (vcode == 0x51)
                    return Xel_Key_Q;

                else if (vcode == 0x52)
                    return Xel_Key_R;

                else if (vcode == 0x53)
                    return Xel_Key_S;

                else if (vcode == 0x54)
                    return Xel_Key_T;

                else if (vcode == 0x55)
                    return Xel_Key_U;

                else if (vcode == 0x56)
                    return Xel_Key_V;

                else if (vcode == 0x57)
                    return Xel_Key_W;

                else if (vcode == 0x58)
                    return Xel_Key_X;

                else if (vcode == 0x59)
                    return Xel_Key_Y;

                else if (vcode == 0x5A)
                    return Xel_Key_Z;

                else if (vcode == VK_NUMPAD0)
                    return Xel_Key_Num_0;

                else if (vcode == VK_NUMPAD1)
                    return Xel_Key_Num_1;

                else if (vcode == VK_NUMPAD2)
                    return Xel_Key_Num_2;

                else if (vcode == VK_NUMPAD3)
                    return Xel_Key_Num_3;

                else if (vcode == VK_NUMPAD4)
                    return Xel_Key_Num_4;

                else if (vcode == VK_NUMPAD5)
                    return Xel_Key_Num_5;

                else if (vcode == VK_NUMPAD6)
                    return Xel_Key_Num_6;

                else if (vcode == VK_NUMPAD7)
                    return Xel_Key_Num_7;

                else if (vcode == VK_NUMPAD8)
                    return Xel_Key_Num_8;

                else if (vcode == VK_NUMPAD9)
                    return Xel_Key_Num_9;

                else if (vcode == VK_MULTIPLY)
                    return Xel_Key_Multiply;

                else if (vcode == VK_ADD)
                    return Xel_Key_Add;

                else if (vcode == VK_SUBTRACT)
                    return Xel_Key_Subtract;

                else if (vcode == VK_DECIMAL)
                    return Xel_Key_Decimal;

                else if (vcode == VK_DIVIDE)
                    return Xel_Key_Divide;

                else if (vcode == VK_F1)
                    return Xel_Key_F1;

                else if (vcode == VK_F2)
                    return Xel_Key_F2;

                else if (vcode == VK_F3)
                    return Xel_Key_F3;

                else if (vcode == VK_F4)
                    return Xel_Key_F4;

                else if (vcode == VK_F5)
                    return Xel_Key_F5;

                else if (vcode == VK_F6)
                    return Xel_Key_F6;

                else if (vcode == VK_F7)
                    return Xel_Key_F7;

                else if (vcode == VK_F8)
                    return Xel_Key_F8;

                else if (vcode == VK_F9)
                    return Xel_Key_F9;

                else if (vcode == VK_F10)
                    return Xel_Key_F10;

                else if (vcode == VK_F11)
                    return Xel_Key_F11;

                else if (vcode == VK_F12)
                    return Xel_Key_F12;

                else if (vcode == VK_NUMLOCK)
                    return Xel_Key_NumLock;

                else if (vcode == VK_SCROLL)
                    return Xel_Key_ScrollLock;

                else if (vcode == VK_SHIFT)
                    return Xel_Key_Shift;

                else if (vcode == VK_CONTROL)
                    return Xel_Key_Control;

                else if (vcode == 192)
                    return Xel_Key_Tilde;

                else if (vcode == 219)
                    return Xel_Key_Left_Square;

                else if (vcode == 221)
                    return Xel_Key_Right_Square;

                else if (vcode == 220)
                    return Xel_Key_Back_Slash;

                else if (vcode == 189)
                    return Xel_Key_Dash;

                else if (vcode == 187)
                    return Xel_Key_Equal;

                else if (vcode == 186)
                    return Xel_Key_SemiColon;

                else if (vcode == 222)
                    return Xel_Key_Quote;

                else if (vcode == 188)
                    return Xel_Key_Comma;

                else if (vcode == 190)
                    return Xel_Key_Dot;

                else if (vcode == 191)
                    return Xel_Key_ForwardSlash;

                return Xel_Key_Unrecognized;
            }
        }

        // Alt keys are not handled
        // PrintScreen only fires UP event
        // F10 not handled
        void SetCallbacks(  void (*OnDown)(unsigned long long xcode),
                            void (*OnUp)(unsigned long long xcode) ) {

            Internal::g_OnDown  = OnDown;
            Internal::g_OnUp    = OnUp;
        }

        char * XCodeToString(unsigned long long xcode) {
//            std::cout << "xcode " << xcode << std::endl;
            if (xcode == Xel_Key_Back)
                return "Xel_Key_Back";

            else if (xcode == Xel_Key_Tab)
                return "Xel_Key_Tab";

            else if (xcode == Xel_Key_Return)
                return "Xel_Key_Return";

            else if (xcode == Xel_Key_Pause)
                return "Xel_Key_Pause";

            else if (xcode == Xel_Key_CapsLock)
                return "Xel_Key_CapsLock";

            else if (xcode == Xel_Key_Escape)
                return "Xel_Key_Escape";

            else if (xcode == Xel_Key_Space)
                return "Xel_Key_Space";

            else if (xcode == Xel_Key_PageUp)
                return "Xel_Key_PageUp";

            else if (xcode == Xel_Key_PageDown)
                return "Xel_Key_PageDown";

            else if (xcode == Xel_Key_End)
                return "Xel_Key_End";

            else if (xcode == Xel_Key_Home)
                return "Xel_Key_Home";

            else if (xcode == Xel_Key_Left)
                return "Xel_Key_Left";

            else if (xcode == Xel_Key_Up)
                return "Xel_Key_Up";

            else if (xcode == Xel_Key_Right)
                return "Xel_Key_Right";

            else if (xcode == Xel_Key_Down)
                return "Xel_Key_Down";

            else if (xcode == Xel_Key_PrintScreen)
                return "Xel_Key_PrintScreen";

            else if (xcode == Xel_Key_Insert)
                return "Xel_Key_Insert";

            else if (xcode == Xel_Key_Delete)
                return "Xel_Key_Delete";

            else if (xcode == Xel_Key_0)
                return "Xel_Key_0";

            else if (xcode == Xel_Key_1)
                return "Xel_Key_1";

            else if (xcode == Xel_Key_2)
                return "Xel_Key_2";

            else if (xcode == Xel_Key_3)
                return "Xel_Key_3";

            else if (xcode == Xel_Key_4)
                return "Xel_Key_4";

            else if (xcode == Xel_Key_5)
                return "Xel_Key_5";

            else if (xcode == Xel_Key_6)
                return "Xel_Key_6";

            else if (xcode == Xel_Key_7)
                return "Xel_Key_7";

            else if (xcode == Xel_Key_8)
                return "Xel_Key_8";

            else if (xcode == Xel_Key_9)
                return "Xel_Key_9";

            else if (xcode == Xel_Key_A)
                return "Xel_Key_A";

            else if (xcode == Xel_Key_B)
                return "Xel_Key_B";

            else if (xcode == Xel_Key_C)
                return "Xel_Key_C";

            else if (xcode == Xel_Key_D)
                return "Xel_Key_D";

            else if (xcode == Xel_Key_E)
                return "Xel_Key_E";

            else if (xcode == Xel_Key_F)
                return "Xel_Key_F";

            else if (xcode == Xel_Key_G)
                return "Xel_Key_G";

            else if (xcode == Xel_Key_H)
                return "Xel_Key_H";

            else if (xcode == Xel_Key_I)
                return "Xel_Key_I";

            else if (xcode == Xel_Key_J)
                return "Xel_Key_J";

            else if (xcode == Xel_Key_K)
                return "Xel_Key_K";

            else if (xcode == Xel_Key_L)
                return "Xel_Key_L";

            else if (xcode == Xel_Key_M)
                return "Xel_Key_M";

            else if (xcode == Xel_Key_N)
                return "Xel_Key_N";

            else if (xcode == Xel_Key_O)
                return "Xel_Key_O";

            else if (xcode == Xel_Key_P)
                return "Xel_Key_P";

            else if (xcode == Xel_Key_Q)
                return "Xel_Key_Q";

            else if (xcode == Xel_Key_R)
                return "Xel_Key_R";

            else if (xcode == Xel_Key_S)
                return "Xel_Key_S";

            else if (xcode == Xel_Key_T)
                return "Xel_Key_T";

            else if (xcode == Xel_Key_U)
                return "Xel_Key_U";

            else if (xcode == Xel_Key_V)
                return "Xel_Key_V";

            else if (xcode == Xel_Key_W)
                return "Xel_Key_W";

            else if (xcode == Xel_Key_X)
                return "Xel_Key_X";

            else if (xcode == Xel_Key_Y)
                return "Xel_Key_Y";

            else if (xcode == Xel_Key_Z)
                return "Xel_Key_Z";

            else if (xcode == Xel_Key_Num_0)
                return "Xel_Key_Num_0";

            else if (xcode == Xel_Key_Num_1)
                return "Xel_Key_Num_1";

            else if (xcode == Xel_Key_Num_2)
                return "Xel_Key_Num_2";

            else if (xcode == Xel_Key_Num_3)
                return "Xel_Key_Num_3";

            else if (xcode == Xel_Key_Num_4)
                return "Xel_Key_Num_4";

            else if (xcode == Xel_Key_Num_5)
                return "Xel_Key_Num_5";

            else if (xcode == Xel_Key_Num_6)
                return "Xel_Key_Num_6";

            else if (xcode == Xel_Key_Num_7)
                return "Xel_Key_Num_7";

            else if (xcode == Xel_Key_Num_8)
                return "Xel_Key_Num_8";

            else if (xcode == Xel_Key_Num_9)
                return "Xel_Key_Num_9";

            else if (xcode == Xel_Key_Multiply)
                return "Xel_Key_Multiply";

            else if (xcode == Xel_Key_Add)
                return "Xel_Key_Add";

            else if (xcode == Xel_Key_Subtract)
                return "Xel_Key_Subtract";

            else if (xcode == Xel_Key_Decimal)
                return "Xel_Key_Decimal";

            else if (xcode == Xel_Key_Divide)
                return "Xel_Key_Divide";

            else if (xcode == Xel_Key_F1)
                return "Xel_Key_F1";

            else if (xcode == Xel_Key_F2)
                return "Xel_Key_F2";

            else if (xcode == Xel_Key_F3)
                return "Xel_Key_F3";

            else if (xcode == Xel_Key_F4)
                return "Xel_Key_F4";

            else if (xcode == Xel_Key_F5)
                return "Xel_Key_F5";

            else if (xcode == Xel_Key_F6)
                return "Xel_Key_F6";

            else if (xcode == Xel_Key_F7)
                return "Xel_Key_F7";

            else if (xcode == Xel_Key_F8)
                return "Xel_Key_F8";

            else if (xcode == Xel_Key_F9)
                return "Xel_Key_F9";

            else if (xcode == Xel_Key_F10)
                return "Xel_Key_F10";

            else if (xcode == Xel_Key_F11)
                return "Xel_Key_F11";

            else if (xcode == Xel_Key_F12)
                return "Xel_Key_F12";

            else if (xcode == Xel_Key_NumLock)
                return "Xel_Key_NumLock";

            else if (xcode == Xel_Key_ScrollLock)
                return "Xel_Key_ScrollLock";

            else if (xcode == Xel_Key_Shift)
                return "Xel_Key_Shift";

            else if (xcode == Xel_Key_Control)
                return "Xel_Key_Control";

            else if (xcode == Xel_Key_Tilde)
                return "Xel_Key_Tilde";

            else if (xcode == Xel_Key_Left_Square)
                return "Xel_Key_Left_Square";

            else if (xcode == Xel_Key_Right_Square)
                return "Xel_Key_Right_Square";

            else if (xcode == Xel_Key_Back_Slash)
                return "Xel_Key_Back_Slash";

            else if (xcode == Xel_Key_Dash)
                return "Xel_Key_Dash";

            else if (xcode == Xel_Key_Equal)
                return "Xel_Key_Equal";

            else if (xcode == Xel_Key_SemiColon)
                return "Xel_Key_SemiColon";

            else if (xcode == Xel_Key_Quote)
                return "Xel_Key_Quote";

            else if (xcode == Xel_Key_Comma)
                return "Xel_Key_Comma";

            else if (xcode == Xel_Key_Dot)
                return "Xel_Key_Dot";

            else if (xcode == Xel_Key_ForwardSlash)
                return "Xel_Key_ForwardSlash";

            else if (xcode == Xel_Key_Unrecognized)
                return "Xel_Key_Unrecognized";

            return "Forgot to label XCode to String?";
        }
    }
}