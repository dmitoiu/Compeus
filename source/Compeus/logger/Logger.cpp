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
#include <stdio.h>
#include <Windows.h>
#include "Logger.h"
#include "../util/Timestamp.h"

std::string COMPEUS     = "[COMPEUS]";
std::string INSTRUCTION = "[INSTRUCTION]";
std::string COMMAND     = "[COMMAND]";
std::string DEBUG       = "[DEBUG]";
std::string INFO        = "[INFO]";
std::string WARN        = "[WARN]";
std::string EROARE      = "[ERROR]";
std::string COLUMN      = ":";
std::string START       = "[";
std::string END         = "]";
std::string DASH        = " - ";
std::string SPACE       = " - ";

void Logger::info(std::string log)
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << INFO << DASH << log << std::endl;
}

void Logger::warn(std::string log)
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << WARN << DASH << log << std::endl;
}

void Logger::error(std::string log)
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << EROARE << DASH << log << std::endl;
}

void Logger::debug(std::string log)
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << DEBUG << DASH << log << std::endl;
}

void Logger::instruction(std::string log)
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << INSTRUCTION << DASH << log << std::endl;
}

void Logger::command()
{
	std::string timestamp = Timestamp::get_current_time();
	std::cout << COMPEUS << START << timestamp << END << COMMAND << COLUMN;
}
