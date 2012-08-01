/* Copyright (c) 2012 Rebecca (bx) Shapiro

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

#include <stdio.h>
#include "elf_bf_utils.h"
#include "elf_bf_debug_config.h"
void create_relas();

int main(int argv, char *argc[])
{

  if ((argv != 5) && (argv != 6)){
    fprintf(stderr, "usage: %s <input exec> <out name> <brainfuck source file> <tape length> [debugging config name]\n",argc[0]);
    exit(-1);
  }

  char *inexec, *outexec, *bf, *config;
  unsigned int tapelen = atoi(argc[4]);
  inexec = argc[1];
  outexec = argc[2];
  bf = argc[3];
  config = argc[5];
  elf_bf_env_t e;
  elfutils_setup_env(bf, inexec, outexec, tapelen,
		     0x5555555688dc, /*ifunc .. __sigsetjmp*/ //we might be able to find this elsewhere in the exectuable's text (at compile time)
		     &e);
  compile_bf_instructions(&e);
  elfutils_save_env(&e);
  elf_bf_write_debug(&e, config);
  return 0;
}
