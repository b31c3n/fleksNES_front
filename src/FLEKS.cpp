//============================================================================
// Name        : FLEKS.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <signal.h>
#include <omp.h>

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

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            while(!cpu_shutdown)
            {
                fleks_step();
            }
        }
        #pragma omp section
        {
            while(!cpu_shutdown)
            {
                display_draw();
                capture_events();
            }
        }
    }

    display_destroy();
}
