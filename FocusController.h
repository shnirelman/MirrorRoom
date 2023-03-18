#pragma once
#include "Focusable.h"
#include "Room.h"
#include "Corner.h"
#include "Mirror.h"

ref class FocusController
{
public:
	static FocusController^ getInstance();

	void onMouseDown(System::Windows::Forms::MouseEventArgs^ e);

	void onMouseUp(System::Windows::Forms::MouseEventArgs^ e);

	void onMouseMove(System::Windows::Forms::MouseEventArgs^ e);

	Corner^ getFocusedCorner();

	Mirror^ getFocusedMirror();

	bool isMouseDown();

private:
	FocusController();


	static FocusController^ instance;
	bool mouseDown;
	Corner^ momentFocusedCorner;
	Mirror^ momentFocusedMirror;

	Corner^ longFocusedCorner;
	Mirror^ longFocusedMirror;

};

