#include "MaquinaDeEventos.h"
#include <time.h>

uint8_t Estado;
uint8_t (*ptr_ArrayEstados[TOTAL_EVENTOS])(void);

uint32_t milliseconds(void)
{
    return clock() / (CLOCKS_PER_SEC / 1000);
}

uint8_t MaquinaDeEventos(uint8_t Estado)
{
    return ptr_ArrayEstados[Estado]();
}

void set_Evento(uint8_t (*ptr_Estado)(void), uint8_t Estado)
{
    ptr_ArrayEstados[Estado] = ptr_Estado;
}
