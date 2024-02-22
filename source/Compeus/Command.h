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

#include <iostream>

class Command
{
public:
	static std::string HELP;
	static std::string GENERAL;
	static std::string TERMINATE;
	static std::string INSTRUCTION;
	static std::string TIMEOUT;
	static std::string REFRESH;
	static std::string SNAPSHOT;
	static std::string LOCK;
	static std::string EXIT;
};
