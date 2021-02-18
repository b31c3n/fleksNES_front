/*
 * stuff.h
 *
 *  Created on: Feb 16, 2021
 *      Author: David Jonsson
 */

#ifndef STUFF_H_
#define STUFF_H_

extern char
    nes_mem[0x66456],
    mapper_mem[0x20000000],
    *pixels,
    *ram,
    *ctrl_buffer;

extern unsigned short
    *scanline;

extern bool
    cpu_shutdown,
    cpu_pause,
    cpu_save,
    cpu_load;

#endif /* STUFF_H_ */
