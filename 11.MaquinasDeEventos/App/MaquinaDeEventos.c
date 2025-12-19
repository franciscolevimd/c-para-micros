#include "MaquinaDeEventos.h"
#include <time.h>

uint8_t Estado;
const char* (*ptr_ArrayEstados[TOTAL_EVENTOS])(void);

uint32_t milliseconds(void)
{
    return clock() / (CLOCKS_PER_SEC / 1000);
}

const char* MaquinaDeEventos(void)
{
    return ptr_ArrayEstados[Estado]();
}

void set_Evento(const char* (*ptr_Estado)(void), uint8_t indice)
{
    ptr_ArrayEstados[indice] = ptr_Estado;
}

void set_Estado(uint8_t n_Estado)
{
    Estado = n_Estado;
}

uint8_t get_Estado(void)
{
    return Estado;
}
