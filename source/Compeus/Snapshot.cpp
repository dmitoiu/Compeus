#include "Snapshot.h"

std::condition_variable Snapshot::condition_variable;

Snapshot::Snapshot(){}

void Snapshot::run(bool& running)
{
	// milliseconds
	short refresh = 17;
	std::mutex mutex;
	std::unique_lock<std::mutex> unique_lock(mutex);
	while(running)
	{
		Snapshot::snapshot();
		Snapshot::condition_variable.wait_for(unique_lock, std::chrono::seconds(refresh));
		Logger::info(Command::SNAPSHOT);
	}
}

void Snapshot::snapshot()
{
	try
	{
		INPUT commands[2];
		commands[0].type = INPUT_KEYBOARD;
		commands[0].ki.wScan = MapVirtualKey(VK_CONTROL, 0);
		commands[0].ki.time = 0;
		commands[0].ki.dwExtraInfo = 0;
		commands[0].ki.wVk = VK_CONTROL;
		commands[0].ki.dwFlags = 0;
		commands[1].type = INPUT_KEYBOARD;
		commands[1].ki.wScan = MapVirtualKey(VK_CONTROL, 0);
		commands[1].ki.time = 0;
		commands[1].ki.dwExtraInfo = 0;
		commands[1].ki.wVk = VK_CONTROL;
		commands[1].ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(2, commands, sizeof(INPUT));
	} catch (std::exception &exception)
	{
		Logger::info(exception.what());
	}
}
