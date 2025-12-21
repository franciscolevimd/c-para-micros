#ifndef MAQUINA_DE_EVENTOS_H
#define MAQUINA_DE_EVENTOS_H

#include <stdint.h>

#define TOTAL_EVENTOS 5u

uint32_t milliseconds(void);
uint8_t MaquinaDeEventos(uint8_t Estado);

void set_Evento(uint8_t (*ptr_Estado)(void), uint8_t Estado);

#endif /* MAQUINA_DE_EVENTOS_H */
