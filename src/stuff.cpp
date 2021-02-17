/*
 * stuff.cpp
 *
 *  Created on: Feb 16, 2021
 *      Author: David Jonsson
 */

#include "stuff.h"

char
    nes_mem[0x66456],
    mapper_mem[0x20000000],
    *pixels = nullptr,
    *ram = nullptr,
    *ctrl_buffer = nullptr;

bool
    cpu_shutdown   = 0,
    cpu_pause      = 0,
    cpu_save       = 0,
    cpu_load       = 0;
