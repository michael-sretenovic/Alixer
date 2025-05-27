#pragma once

#include <string>

namespace Alixer
{
	enum class KeyCode : uint16_t
	{
		None = 0,

		// From glfw3.h
		Space      = 32, // ' '
		Apostrophe = 39, // ', 34 "
		Comma      = 44, // ,, 60 <
		Minus      = 45, // -, 95 _
		Period     = 46, // ., 62 >
		Slash      = 47, // /, 63 ?

		D0         = 48, // 0, 41 )
		D1         = 49, // 1, 33 !
		D2         = 50, // 2, 64 @
		D3         = 51, // 3, 35 #
		D4         = 52, // 4, 36 $
		D5         = 53, // 5, 37 %
		D6         = 54, // 6, 94 ^
		D7         = 55, // 7, 38 &
		D8         = 56, // 8, 42 *
		D9         = 57, // 9, 40 (

		Semicolon  = 59, // ;, 58 :
		Equal      = 61, // =, 43 +

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

		// ReSharper disable CppInconsistentNaming
		a =  97,
		b =  98,
		c =  99,
		d = 100,
		e = 101,
		f = 102,
		g = 103,
		h = 104,
		i = 105,
		j = 106,
		k = 107,
		l = 108,  // NOLINT(misc-confusable-identifiers)
		m = 109,
		n = 110,
		o = 111,
		p = 112,
		q = 113,
		r = 114,
		s = 115,
		t = 116,
		u = 117,
		v = 118,
		w = 119,
		x = 120,
		y = 121,
		z = 122,
		// ReSharper restore CppInconsistentNaming

		LeftBracket = 91,  // [, 123 {
		Backslash = 92,    // \, 124 |

		RightBracket = 93, // ], 125 }
		GraveAccent = 96,  // `, 126 ~

		World1 = 161, // non-US #1
		World2 = 162, // non-US #2

		// Function
		Escape      = 256,
		Enter       = 257,
		Tab         = 258,
		Backspace   = 259,
		Insert      = 260,
		Delete      = 261,
		Right       = 262,
		Left        = 263,
		Down        = 264,
		Up          = 265,
		PageUp      = 266,
		PageDown    = 267,
		Home        = 268,
		End         = 269,
		CapsLock    = 280,
		ScrollLock  = 281,
		NumLock     = 282,
		PrintScreen = 283,
		Pause       = 284,

		// F Keys
		F1  = 290,
		F2  = 291,
		F3  = 292,
		F4  = 293,
		F5  = 294,
		F6  = 295,
		F7  = 296,
		F8  = 297,
		F9  = 298,
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

		// Keypad
		Kp0        = 320,
		Kp1        = 321,
		Kp2        = 322,
		Kp3        = 323,
		Kp4        = 324,
		Kp5        = 325,
		Kp6        = 326,
		Kp7        = 327,
		Kp8        = 328,
		Kp9        = 329,
		KpDecimal  = 330,
		KpDivide   = 331,
		KpMultiply = 332,
		KpSubtract = 333,
		KpAdd      = 334,
		KpEnter    = 335,
		KpEqual    = 336,

		// Modifiers
		LeftShift    = 340,
		LeftControl  = 341,
		LeftAlt      = 342,
		LeftSuper    = 343,
		RightShift   = 344,
		RightControl = 345,
		RightAlt     = 346,
		RightSuper   = 347,
		Menu         = 348
	};

	std::string KeyCodeValueToString(KeyCode value);

	std::string GetKeyCodeName(KeyCode keyCode);
}
