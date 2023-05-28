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

#include "Document.h"

#include <iostream>
#include <fstream>
#include <string>

void Document::header()
{
    std::string data;
    std::string path = "./resources/Compeus.txt";
    data = read_file(path);
    std::cout << data << std::endl;
}

void Document::operations()
{
    std::string data;
    std::string path = "./resources/Operations.txt";
    data = read_file(path);
    std::cout << data << std::endl;
}

std::string Document::read_file(std::string path)
{
    std::string data;
    std::string line;
    std::ifstream compeus(path);
    while (std::getline(compeus, line))
    {
         data += line + "\n";
    }
    return data;
}

