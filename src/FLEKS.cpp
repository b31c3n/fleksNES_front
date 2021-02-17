//============================================================================
// Name        : FLEKS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <signal.h>

#include "libapi.h"
#include "stuff.h"
#include "display.h"

void sigint(int signal)
{
    cpu_shutdown = 1;
    puts("Interrupted!");
}

void sigsegv(int signal)
{
    cpu_shutdown = 1;
    puts("Segfault!");
}

int main(int argc, char **argv)
{

    signal(SIGINT, sigint);
    signal(SIGSEGV, sigsegv);

    fleks_init( argv[1],
                nes_mem,
                mapper_mem,
                &pixels,
                &ram,
                &ctrl_buffer);

    display_init();

    while(!cpu_shutdown)
    {
        for(int i = 0; i < 29780; ++i)
            fleks_step();
        display_draw();
        capture_events();
    }

    display_destroy();
}
