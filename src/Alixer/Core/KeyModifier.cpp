#include "pch.h"

#include "KeyModifier.h"

namespace Alixer
{
#define KEY_MODIFIER_TO_CASE(mod) case KeyModifier::mod: return std::string(#mod);

#define ADD_KEY_MODIFIER_TO_STRING(mod)\
	if ((static_cast<uint8_t>(modifier) & static_cast<uint8_t>(KeyModifier::mod)) == static_cast<uint8_t>(KeyModifier::mod))\
	{\
		if (str.length() > 0) { str += ", "; }\
		str += #mod;\
	}

	std::string GetKeyModifierName(const KeyModifier modifier)
	{
		switch(modifier)
		{
			KEY_MODIFIER_TO_CASE(None)
			KEY_MODIFIER_TO_CASE(Shift)
			KEY_MODIFIER_TO_CASE(Control)
			KEY_MODIFIER_TO_CASE(Alt)
			KEY_MODIFIER_TO_CASE(Super)
			KEY_MODIFIER_TO_CASE(CapsLock)
			KEY_MODIFIER_TO_CASE(NumLock)
		}

		std::string str;

		ADD_KEY_MODIFIER_TO_STRING(Shift);
		ADD_KEY_MODIFIER_TO_STRING(Control);
		ADD_KEY_MODIFIER_TO_STRING(Alt);
		ADD_KEY_MODIFIER_TO_STRING(Super);
		ADD_KEY_MODIFIER_TO_STRING(CapsLock);
		ADD_KEY_MODIFIER_TO_STRING(NumLock);

		return str;
	}
}
