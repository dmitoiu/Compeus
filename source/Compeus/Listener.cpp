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

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Listener.h"
#include "Command.h"
#include "logger/Logger.h"

#define ES_CONTINUOUS       0x80000000
#define ES_DISPLAY_REQUIRED 0x00000002
#define ES_SYSTEM_REQUIRED  0x00000001

std::string CLOSE = "close";
std::condition_variable condition_variable;

void Listener::listen(bool &running)
{
    // milliseconds
    short refresh = 14 * 1000;
    while (running)
    {
        SetThreadExecutionState(ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED | ES_CONTINUOUS);
        std::this_thread::sleep_for(std::chrono::milliseconds(refresh));
        Logger::info(Command::GENERAL);
    }
}

void Listener::close(bool &running)
{
    running = false;
}

void Listener::get_input(std::string data, bool &running)
{
    while(running)
    {
        std::cin >> data;
        if (data == CLOSE)
        {
            close(running);
        }
        condition_variable.notify_one();
    }
}

void Listener::input(bool &running)
{
    std::string data;
    std::mutex mutex;
    std::unique_lock<std::mutex> unique_lock(mutex);
    std::thread inputThread(get_input, data, std::ref(running));
    while(running)
    {
        while (condition_variable.wait_for(unique_lock, std::chrono::seconds(5)) == std::cv_status::timeout)
        {
            Logger::info(Command::TIMEOUT);
            Logger::info(Command::INSTRUCTION);
        }
    }
    inputThread.join();
}