﻿/**
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

#include "InfiniteThread.h"

void InfiniteThread::run(bool &running)
{

    while (running)
    {
        InfiniteThread::refresh();
    }

}

void InfiniteThread::refresh()
{
    // milliseconds
    short refresh = 25 * 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(refresh));
    std::system("cls");
    Document::header();
    Document::operations();
}


