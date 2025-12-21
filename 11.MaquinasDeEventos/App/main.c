#include "main.h"
#include "MaquinaDeEventos.h"

#include <stdio.h>
#include <string.h>

uint32_t tickstart;
uint32_t tiempo;

int main(void)
{
    uint8_t true = 1u;

    IniciaSemaforo();

    Semaforo S1;
    S1.Estado = VERDE;
    (void)memset(S1.ID, 0, 3);
    (void)strcpy(S1.ID, "S1");

    Semaforo S2;
    S2.Estado = ROJO;
    (void)memset(S2.ID, 0, 3);
    (void)strcpy(S2.ID, "S2");

    (void)printf("%s: %s\n", S1.ID, get_Luz(S1.Estado));
    (void)printf("%s: %s\n", S2.ID, get_Luz(S2.Estado));

    tiempo = 5000u;
    tickstart = milliseconds();

    while (true)
    {
        if ((milliseconds() - tickstart) >= tiempo)
        {
            tickstart = milliseconds();

            if (S1.Estado != ROJO)
            {
                ControlaSemaforo(&S1, &S2);
            }
            else if (S2.Estado != ROJO)
            {
                ControlaSemaforo(&S2, &S1);
            }
            else
            {
            }
        }
    }

    return 0;
}

void ControlaSemaforo(Semaforo *S1, Semaforo *S2)
{
    S1->Estado = MaquinaDeEventos(S1->Estado);
    (void)printf("%s: %s\n", S1->ID, get_Luz(S1->Estado));

    if (S1->Estado == AMBAR_1)
    {
        tiempo = 1000u;
    }
    else if (S1->Estado == ROJO)
    {
        tiempo = 5000u;
        S2->Estado = MaquinaDeEventos(S2->Estado);
        (void)printf("%s: %s\n", S2->ID, get_Luz(S2->Estado));
    }
    else
    {
    }
}
