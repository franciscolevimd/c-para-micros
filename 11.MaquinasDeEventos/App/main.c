#include "MaquinaDeEventos.h"
#include "Semaforo.h"

#include <stdio.h>

int main(void)
{
    const char *Valor = NULL;
    uint8_t true = 1u;

    IniciaSemaforo();
    uint32_t tickstart = milliseconds();

    while (true)
    {
        if (milliseconds() - tickstart >= 2000)
        {
            tickstart = milliseconds();
            Valor = MaquinaDeEventos();
            printf("%s\n", Valor);
        }
    }

    return 0;
}
