#include "MaquinaDeEventos.h"
#include "Semaforo.h"

#include <stdio.h>

int main(void)
{
    const char *Valor = NULL;

    uint8_t true = 1u;
    uint32_t tiempo = 5000ul;

    IniciaSemaforo();
    uint32_t tickstart = milliseconds();

    Valor = MaquinaDeEventos();
    printf("%s\n", Valor);

    while (true)
    {
        if (milliseconds() - tickstart >= tiempo)
        {
            tickstart = milliseconds();
            Valor = MaquinaDeEventos();
            printf("%s\n", Valor);
            if (get_Estado() == AMBAR_2)
            {
                tiempo = 1000ul;
            }
            else if (get_Estado() == VERDE)
            {
                tiempo = 5000ul;
            }
        }
    }

    return 0;
}
