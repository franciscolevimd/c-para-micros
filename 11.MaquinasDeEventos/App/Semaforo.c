#include "Semaforo.h"
#include "MaquinaDeEventos.h"

#include <string.h>

void IniciaSemaforo(void)
{
    set_Evento(Verde, VERDE);
    set_Evento(Ambar1, AMBAR_1);
    set_Evento(Ambar2, AMBAR_2);
    set_Evento(Ambar3, AMBAR_3);
    set_Evento(Rojo, ROJO);
}

uint8_t Verde(void)
{
    return AMBAR_1;
}

uint8_t Ambar1(void)
{
    return AMBAR_2;
}

uint8_t Ambar2(void)
{
    return AMBAR_3;
}

uint8_t Ambar3(void)
{
    return ROJO;
}

uint8_t Rojo(void)
{
    return VERDE;
}

/**
 * Se devuelve el color de luz anterior al estado actual.
 */
const char* get_Luz(uint8_t Estado)
{
    static char Resultado[6];
    (void)memset(Resultado, 0, 6);

    switch (Estado)
    {
        case VERDE:
            (void)strcpy(Resultado, "VERDE");
            break;
        case AMBAR_1:
            (void)strcpy(Resultado, "AMBAR");
            break;
        case AMBAR_2:
            (void)strcpy(Resultado, "AMBAR");
            break;
        case AMBAR_3:
            (void)strcpy(Resultado, "AMBAR");
            break;
        case ROJO:
            (void)strcpy(Resultado, "ROJO");
            break;
        default:
            (void)strcpy(Resultado, "");
            break;
    }

    return Resultado;
}
