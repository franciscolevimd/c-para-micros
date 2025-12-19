#include "Semaforo.h"
#include "MaquinaDeEventos.h"

void IniciaSemaforo()
{
    set_Estado(VERDE);
    set_Evento(Verde, VERDE);
    set_Evento(Ambar1, AMBAR_1);
    set_Evento(Ambar2, AMBAR_2);
    set_Evento(Ambar3, AMBAR_3);
    set_Evento(Rojo, ROJO);
}

const char* Verde(void)
{
    set_Estado(AMBAR_1);
    return "VERDE\0";
}

const char* Ambar1(void)
{
    set_Estado(AMBAR_2);
    return "AMBAR\0";
}

const char* Ambar2(void)
{
    set_Estado(AMBAR_3);
    return "AMBAR\0";
}

const char* Ambar3(void)
{
    set_Estado(ROJO);
    return "AMBAR\0";
}

const char* Rojo(void)
{
    set_Estado(VERDE);
    return "ROJO\0";
}
