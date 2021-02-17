/*
 * api.h
 *
 *  Created on: Feb 9, 2021
 *      Author: David Jonsson
 */

#ifndef SRC_API_H_
#define SRC_API_H_

#ifdef __cplusplus
extern "C"{
#endif

    void fleks_init
    (
        char *game,
        char *nes_mem,
        char *mapper_mem,
        char **pixels,
        char **ram_mem,
        char **ctrl_buffer
    );
    void fleks_step();
    void fleks_destroy();

#ifdef __cplusplus
}
#endif

#endif /* SRC_API_H_ */
