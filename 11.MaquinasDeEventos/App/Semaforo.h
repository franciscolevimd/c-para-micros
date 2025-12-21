#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <stdint.h>

#define VERDE 0u
#define AMBAR_1 1u
#define AMBAR_2 2u
#define AMBAR_3 3u
#define ROJO 4u

typedef struct
{
    uint8_t Estado;
    char ID[3];
} Semaforo;

void IniciaSemaforo(void);

uint8_t Verde(void);
uint8_t Ambar1(void);
uint8_t Ambar2(void);
uint8_t Ambar3(void);
uint8_t Rojo(void);

const char* get_Luz(uint8_t Estado);

#endif /* SEMAFORO_H */
