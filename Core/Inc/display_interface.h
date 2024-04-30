#ifndef __DISPLAY_INTERFACE_H
#define __DISPLAY_INTERFACE_H
#include "main.h"

void interface_init(void);
void set_cpu_temp(uint32_t temp);
void set_gpu_temp(uint32_t temp);
void set_cpu_load(uint32_t load, uint32_t load_old);
void set_gpu_load(uint32_t load, uint32_t load_old);
#endif