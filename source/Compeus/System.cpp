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

#include "System.h"


void System::refresh()
{
    bool running = true, * runningPointer;
    runningPointer = &running;
    std::thread listenThread(Listener::listen, std::ref(running));
    std::thread instructionsThread(Listener::input, std::ref(running));
    std::thread cleanThread(System::clean, std::ref(running));
	listenThread.join();
    instructionsThread.join();
    cleanThread.join();
}

void System::lock()
{
    LockWorkStation();
}


void System::run()
{
    bool running = true, *runningPointer;
    std::string command;
    runningPointer = &running;
    Document::header();
    Document::operations();
    while(running)
    {
        Logger::command();
        command = System::command();
        System::system(command);
    }
}

void System::system(std::string command)
{
	if(command._Equal(Command::REFRESH))
	{
        System::refresh();
	}
    else if (command._Equal(Command::LOCK))
    {
        System::lock();
    }
    else if (command._Equal(Command::EXIT))
    {
        Logger::info(Command::TERMINATE);
        exit(1);
    }
    else
    {
        Logger::warn(Command::HELP);
    }
}

std::string System::command()
{
    std::string data;
    std::cin >> data;
    return data;
}

void System::clean(bool &running)
{
    InfiniteThread::run(running);
}


