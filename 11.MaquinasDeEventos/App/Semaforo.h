#ifndef SEMAFORO_H
#define SEMAFORO_H

#define VERDE 0u
#define AMBAR_1 1u
#define AMBAR_2 2u
#define AMBAR_3 3u
#define ROJO 4u

void IniciaSemaforo();

const char* Verde(void);
const char* Ambar1(void);
const char* Ambar2(void);
const char* Ambar3(void);
const char* Rojo(void);

#endif /* SEMAFORO_H */
