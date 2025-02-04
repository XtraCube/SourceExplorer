/*
MIT License

Copyright (c) 2019 LAK132

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "imgui_impl_lak.h"
#include <imgui_memory_editor.h>
#include <imgui_stdlib.h>

#include "explorer.h"
#include "tostring.hpp"

namespace se = SourceExplorer;

#include <lak/strconv.hpp>
#include <lak/tinflate.hpp>

#include <atomic>
#include <exception>
#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <queue>
#include <stdint.h>
#include <thread>
#include <unordered_set>
#include <vector>

namespace fs = std::filesystem;

#include "git.hpp"

#define APP_VERSION GIT_TAG "-" GIT_HASH

#define APP_NAME "Source Explorer " STRINGIFY(LAK_ARCH) " " APP_VERSION

#ifndef MAIN_H
#	define MAIN_H

void credits()
{
	ImGui::PushID("Credits");
	if (ImGui::TreeNode("ImGui"))
	{
		ImGui::Text(R"(https://github.com/ocornut/imgui

The MIT License (MIT)

Copyright (c) 2014-2018 Omar Cornut

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.)");
		ImGui::TreePop();
	}
	if (ImGui::TreeNode("gl3w"))
	{
		ImGui::Text("https://github.com/skaslev/gl3w");
		ImGui::TreePop();
	}
#	ifdef LAK_USE_SDL
	if (ImGui::TreeNode("SDL2"))
	{
		ImGui::Text("https://www.libsdl.org/");
		ImGui::TreePop();
	}
#	endif
	if (ImGui::TreeNode("tinflate"))
	{
		ImGui::Text("http://achurch.org/tinflate.c");
		ImGui::Text("Fork: https://github.com/LAK132/tinflate");
		ImGui::TreePop();
	}
	if (ImGui::TreeNode("stb_image_write"))
	{
		ImGui::Text(
		  "https://github.com/nothings/stb/blob/master/stb_image_write.h");
		ImGui::TreePop();
	}
	if (ImGui::TreeNode("Anaconda/Chowdren"))
	{
		ImGui::Text(R"(https://github.com/Matt-Esch/anaconda

http://mp2.dk/anaconda/

http://mp2.dk/chowdren/

Anaconda is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Anaconda is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Anaconda.  If not, see <http://www.gnu.org/licenses/>.)");
		ImGui::TreePop();
	}
	ImGui::PopID();
}

#endif