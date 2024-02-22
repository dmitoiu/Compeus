#pragma once

#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include "Command.h"
#include "logger/Logger.h"

class Snapshot
{
public:
	Snapshot();
	static std::condition_variable condition_variable;
	static void run(bool& running);
	static void snapshot();
};
