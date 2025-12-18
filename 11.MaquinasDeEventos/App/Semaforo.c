#include "Semaforo.h"
#include "MaquinaDeEventos.h"

void IniciaSemaforo()
{
    set_Estado(VERDE);
    set_Evento(Verde, VERDE);
    set_Evento(Ambar, AMBAR);
    set_Evento(Rojo, ROJO);    
}

const char* Verde(void)
{
    set_Estado(AMBAR);
    return "VERDE\0";
}

const char* Ambar(void)
{
    set_Estado(ROJO);
    return "AMBAR\0";
}

const char* Rojo(void)
{
    set_Estado(VERDE);
    return "ROJO\0";
}
