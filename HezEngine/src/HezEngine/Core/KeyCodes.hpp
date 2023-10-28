#pragma once

#include <ostream>

namespace HezEngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	enum class KeyState
	{
		None = -1,
		Pressed,
		Held,
		Released
	};

	enum class CursorMode
	{
		Normal = 0,
		Hidden = 1,
		Locked = 2
	};

	typedef enum class MouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	} Button;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, MouseButton button)
	{
		os << static_cast<int32_t>(button);
		return os;
	}
}

// From glfw3.h
#define HEZ_KEY_SPACE           ::HezEngine::Key::Space
#define HEZ_KEY_APOSTROPHE      ::HezEngine::Key::Apostrophe    /* ' */
#define HEZ_KEY_COMMA           ::HezEngine::Key::Comma         /* , */
#define HEZ_KEY_MINUS           ::HezEngine::Key::Minus         /* - */
#define HEZ_KEY_PERIOD          ::HezEngine::Key::Period        /* . */
#define HEZ_KEY_SLASH           ::HezEngine::Key::Slash         /* / */
#define HEZ_KEY_0               ::HezEngine::Key::D0
#define HEZ_KEY_1               ::HezEngine::Key::D1
#define HEZ_KEY_2               ::HezEngine::Key::D2
#define HEZ_KEY_3               ::HezEngine::Key::D3
#define HEZ_KEY_4               ::HezEngine::Key::D4
#define HEZ_KEY_5               ::HezEngine::Key::D5
#define HEZ_KEY_6               ::HezEngine::Key::D6
#define HEZ_KEY_7               ::HezEngine::Key::D7
#define HEZ_KEY_8               ::HezEngine::Key::D8
#define HEZ_KEY_9               ::HezEngine::Key::D9
#define HEZ_KEY_SEMICOLON       ::HezEngine::Key::Semicolon     /* ; */
#define HEZ_KEY_EQUAL           ::HezEngine::Key::Equal         /* = */
#define HEZ_KEY_A               ::HezEngine::Key::A
#define HEZ_KEY_B               ::HezEngine::Key::B
#define HEZ_KEY_C               ::HezEngine::Key::C
#define HEZ_KEY_D               ::HezEngine::Key::D
#define HEZ_KEY_E               ::HezEngine::Key::E
#define HEZ_KEY_F               ::HezEngine::Key::F
#define HEZ_KEY_G               ::HezEngine::Key::G
#define HEZ_KEY_H               ::HezEngine::Key::H
#define HEZ_KEY_I               ::HezEngine::Key::I
#define HEZ_KEY_J               ::HezEngine::Key::J
#define HEZ_KEY_K               ::HezEngine::Key::K
#define HEZ_KEY_L               ::HezEngine::Key::L
#define HEZ_KEY_M               ::HezEngine::Key::M
#define HEZ_KEY_N               ::HezEngine::Key::N
#define HEZ_KEY_O               ::HezEngine::Key::O
#define HEZ_KEY_P               ::HezEngine::Key::P
#define HEZ_KEY_Q               ::HezEngine::Key::Q
#define HEZ_KEY_R               ::HezEngine::Key::R
#define HEZ_KEY_S               ::HezEngine::Key::S
#define HEZ_KEY_T               ::HezEngine::Key::T
#define HEZ_KEY_U               ::HezEngine::Key::U
#define HEZ_KEY_V               ::HezEngine::Key::V
#define HEZ_KEY_W               ::HezEngine::Key::W
#define HEZ_KEY_X               ::HezEngine::Key::X
#define HEZ_KEY_Y               ::HezEngine::Key::Y
#define HEZ_KEY_Z               ::HezEngine::Key::Z
#define HEZ_KEY_LEFT_BRACKET    ::HezEngine::Key::LeftBracket   /* [ */
#define HEZ_KEY_BACKSLASH       ::HezEngine::Key::Backslash     /* \ */
#define HEZ_KEY_RIGHT_BRACKET   ::HezEngine::Key::RightBracket  /* ] */
#define HEZ_KEY_GRAVE_ACCENT    ::HezEngine::Key::GraveAccent   /* ` */
#define HEZ_KEY_WORLD_1         ::HezEngine::Key::World1        /* non-US #1 */
#define HEZ_KEY_WORLD_2         ::HezEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define HEZ_KEY_ESCAPE          ::HezEngine::Key::Escape
#define HEZ_KEY_ENTER           ::HezEngine::Key::Enter
#define HEZ_KEY_TAB             ::HezEngine::Key::Tab
#define HEZ_KEY_BACKSPACE       ::HezEngine::Key::Backspace
#define HEZ_KEY_INSERT          ::HezEngine::Key::Insert
#define HEZ_KEY_DELETE          ::HezEngine::Key::Delete
#define HEZ_KEY_RIGHT           ::HezEngine::Key::Right
#define HEZ_KEY_LEFT            ::HezEngine::Key::Left
#define HEZ_KEY_DOWN            ::HezEngine::Key::Down
#define HEZ_KEY_UP              ::HezEngine::Key::Up
#define HEZ_KEY_PAGE_UP         ::HezEngine::Key::PageUp
#define HEZ_KEY_PAGE_DOWN       ::HezEngine::Key::PageDown
#define HEZ_KEY_HOME            ::HezEngine::Key::Home
#define HEZ_KEY_END             ::HezEngine::Key::End
#define HEZ_KEY_CAPS_LOCK       ::HezEngine::Key::CapsLock
#define HEZ_KEY_SCROLL_LOCK     ::HezEngine::Key::ScrollLock
#define HEZ_KEY_NUM_LOCK        ::HezEngine::Key::NumLock
#define HEZ_KEY_PRINT_SCREEN    ::HezEngine::Key::PrintScreen
#define HEZ_KEY_PAUSE           ::HezEngine::Key::Pause
#define HEZ_KEY_F1              ::HezEngine::Key::F1
#define HEZ_KEY_F2              ::HezEngine::Key::F2
#define HEZ_KEY_F3              ::HezEngine::Key::F3
#define HEZ_KEY_F4              ::HezEngine::Key::F4
#define HEZ_KEY_F5              ::HezEngine::Key::F5
#define HEZ_KEY_F6              ::HezEngine::Key::F6
#define HEZ_KEY_F7              ::HezEngine::Key::F7
#define HEZ_KEY_F8              ::HezEngine::Key::F8
#define HEZ_KEY_F9              ::HezEngine::Key::F9
#define HEZ_KEY_F10             ::HezEngine::Key::F10
#define HEZ_KEY_F11             ::HezEngine::Key::F11
#define HEZ_KEY_F12             ::HezEngine::Key::F12
#define HEZ_KEY_F13             ::HezEngine::Key::F13
#define HEZ_KEY_F14             ::HezEngine::Key::F14
#define HEZ_KEY_F15             ::HezEngine::Key::F15
#define HEZ_KEY_F16             ::HezEngine::Key::F16
#define HEZ_KEY_F17             ::HezEngine::Key::F17
#define HEZ_KEY_F18             ::HezEngine::Key::F18
#define HEZ_KEY_F19             ::HezEngine::Key::F19
#define HEZ_KEY_F20             ::HezEngine::Key::F20
#define HEZ_KEY_F21             ::HezEngine::Key::F21
#define HEZ_KEY_F22             ::HezEngine::Key::F22
#define HEZ_KEY_F23             ::HezEngine::Key::F23
#define HEZ_KEY_F24             ::HezEngine::Key::F24
#define HEZ_KEY_F25             ::HezEngine::Key::F25

/* Keypad */
#define HEZ_KEY_KP_0            ::HezEngine::Key::KP0
#define HEZ_KEY_KP_1            ::HezEngine::Key::KP1
#define HEZ_KEY_KP_2            ::HezEngine::Key::KP2
#define HEZ_KEY_KP_3            ::HezEngine::Key::KP3
#define HEZ_KEY_KP_4            ::HezEngine::Key::KP4
#define HEZ_KEY_KP_5            ::HezEngine::Key::KP5
#define HEZ_KEY_KP_6            ::HezEngine::Key::KP6
#define HEZ_KEY_KP_7            ::HezEngine::Key::KP7
#define HEZ_KEY_KP_8            ::HezEngine::Key::KP8
#define HEZ_KEY_KP_9            ::HezEngine::Key::KP9
#define HEZ_KEY_KP_DECIMAL      ::HezEngine::Key::KPDecimal
#define HEZ_KEY_KP_DIVIDE       ::HezEngine::Key::KPDivide
#define HEZ_KEY_KP_MULTIPLY     ::HezEngine::Key::KPMultiply
#define HEZ_KEY_KP_SUBTRACT     ::HezEngine::Key::KPSubtract
#define HEZ_KEY_KP_ADD          ::HezEngine::Key::KPAdd
#define HEZ_KEY_KP_ENTER        ::HezEngine::Key::KPEnter
#define HEZ_KEY_KP_EQUAL        ::HezEngine::Key::KPEqual

#define HEZ_KEY_LEFT_SHIFT      ::HezEngine::Key::LeftShift
#define HEZ_KEY_LEFT_CONTROL    ::HezEngine::Key::LeftControl
#define HEZ_KEY_LEFT_ALT        ::HezEngine::Key::LeftAlt
#define HEZ_KEY_LEFT_SUPER      ::HezEngine::Key::LeftSuper
#define HEZ_KEY_RIGHT_SHIFT     ::HezEngine::Key::RightShift
#define HEZ_KEY_RIGHT_CONTROL   ::HezEngine::Key::RightControl
#define HEZ_KEY_RIGHT_ALT       ::HezEngine::Key::RightAlt
#define HEZ_KEY_RIGHT_SUPER     ::HezEngine::Key::RightSuper
#define HEZ_KEY_MENU            ::HezEngine::Key::Menu

// Mouse
#define HEZ_MOUSE_BUTTON_LEFT    ::HezEngine::Button::Left
#define HEZ_MOUSE_BUTTON_RIGHT   ::HezEngine::Button::Right
#define HEZ_MOUSE_BUTTON_MIDDLE  ::HezEngine::Button::Middle
