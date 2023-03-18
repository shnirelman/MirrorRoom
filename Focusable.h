#pragma once
ref class Focusable
{
public:
	Focusable();

	bool isFocused();

	void setFocus(bool focused);

private:
	bool focused;
};

