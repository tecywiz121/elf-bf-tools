# Copyright (c) <year> <copyright holders>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

cmake_minimum_required(VERSION 2.6)
project(elf-bf-tools)

#set (elf-bf-tools_VERSION_MAJOR 1)
#set (elf-bf-tools_VERSION_MINOR 0)



set(CMAKE_C_FLAGS "-g -Wall -I /usr/local/libelfsh/include -DERESI64 -I /usr/local/libaspect/include -I /usr/local/libasm/include")

set(ELFBF_LIBS elf_bf elfsh64 aspect64 asm64)
add_subdirectory(libelf_bf)
add_subdirectory(elf_bf_compiler)
add_subdirectory(ping_backdoor)
add_subdirectory(syscall/getchar)
add_subdirectory(syscall/putchar)
add_subdirectory(demo)
