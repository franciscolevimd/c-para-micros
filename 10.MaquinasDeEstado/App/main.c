#include "MaquinaContra.h"

#include <stdio.h>
#include <stdint.h>

uint8_t scanf_uint8(void);

int main(void)
{
    uint8_t Estado = IDEAL;
    uint8_t Digito = 0u;

    (void)printf("...::: BIENVENIDO :::...\n");
    (void)printf("------------------------\n");
    (void)printf("...Maquina de estados...\n");
    (void)printf("------------------------\n\n");

    while (1)
    {
        switch (Estado)
        {
            case IDEAL:
                (void)printf("Puerta Cerrada\n");
                break;

            case VALIDO:
                (void)printf("Puerta Abierta\n");
                break;

            case ERROR:
                (void)printf("Error, intente de nuevo.\n");
                break;

            default:
                (void)printf("[%hhu]>: ", Estado);
                Digito = scanf_uint8();
                break;
        }

        Estado = MaquinaDeEstados(Estado, Digito);
    }

    return 0;
}

uint8_t scanf_uint8(void)
{
    uint8_t Resultado;
    (void) scanf("%hhu", &Resultado);
    while (getchar() != '\n')
        ;
    return Resultado;
}
