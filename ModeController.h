#pragma once
ref class ModeController
{
public:
	enum class ModeType {RoomEditing, RayCasting};
	static ModeController^ getInstance();

	ModeType getMode();

	void setMode(ModeType mode);

private:
	ModeController();

	static ModeController^ instance;

	ModeType mode;

};

