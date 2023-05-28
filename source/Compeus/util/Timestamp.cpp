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

#include "Timestamp.h"

std::string Timestamp::get_current_time()
{
	auto current_time = std::chrono::zoned_time(std::chrono::current_zone(), std::chrono::system_clock::now());
	std::string current_time_string = std::format( "{:%d-%m-%Y %H:%M:%OS}" , current_time);
	return current_time_string;
}
