/**
 * --------------------------------------------------------------------------
 *  Copyright [2023] [Darie-Dragos Mitoiu]
 *
 * Licensed under the Compeus License, Version 1.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http ://www.dmitoiu.com/licenses/LICENSE-1.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * --------------------------------------------------------------------------
 */

#pragma once

#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include "Listener.h"
#include "Snapshot.h"
#include "Document.h"
#include <Windows.h>
#include "logger/Logger.h"
#include "Command.h"
#include "InfiniteThread.h"

class System
{
public:
	static void refresh();
	static void lock();
	static void run();
	static void system(std::string command);
	static void clean(bool &running);
	static void snapshot(bool& running);
	static std::string command();
};
