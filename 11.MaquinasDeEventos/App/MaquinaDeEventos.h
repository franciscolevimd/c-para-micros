#ifndef MAQUINA_DE_EVENTOS_H
#define MAQUINA_DE_EVENTOS_H

#include <stdint.h>

#define TOTAL_EVENTOS 5u

uint32_t milliseconds(void);
const char* MaquinaDeEventos(void);

void set_Evento(const char* (*ptr_Estado)(void), uint8_t indice);
void set_Estado(uint8_t n_Estado);
uint8_t get_Estado(void);

#endif /* MAQUINA_DE_EVENTOS_H */
