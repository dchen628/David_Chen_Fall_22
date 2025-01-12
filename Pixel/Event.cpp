#include "pch.h"
#include "Event.h"


namespace Ekko
{
	KeyPressedEvent::KeyPressedEvent(int codeOfKey) : mKeyCode(codeOfKey)
	{
	}

	int KeyPressedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleasedEvent::KeyReleasedEvent(int codeOfKey) : mKeyCode(codeOfKey)
	{
	}

	int KeyReleasedEvent::GetKeyCode() const
	{
		return mKeyCode;
	}
}