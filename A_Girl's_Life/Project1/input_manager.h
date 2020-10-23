#pragma once

class InputManager
{
public:
	char keyBuffer[256];
	char prevKeyBuffer[256];
	char prevMouseWheel;
	char mouseWheel;

	void Update()
	{
		for (int i = 0; i < 256; ++i)
		{
			prevKeyBuffer[i] = keyBuffer[i];
		}
		mouseWheel = 0;
	}
};