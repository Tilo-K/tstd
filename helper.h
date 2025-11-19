//
// Created by tilok on 19.11.2025.
//

#ifndef TSTD_HELPER_H
#define TSTD_HELPER_H
#include <stdio.h>

#define OOM(ptr) { \
    if(ptr == NULL) { \
        puts("Out of memory\n"); \
        exit(137); \
    } \
}

#endif //TSTD_HELPER_H