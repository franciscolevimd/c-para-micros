#ifndef MAQUINA_CONTRA_H
#define MAQUINA_CONTRA_H

#include <stdint.h>

#define IDEAL 0u
#define DIGITO_1 1u
#define DIGITO_2 2u
#define DIGITO_3 3u
#define VALIDO 4u
#define ERROR 5u

uint8_t MaquinaDeEstados(uint8_t Estado, uint8_t Digito);

#endif /* MAQUINA_CONTRA_H */
