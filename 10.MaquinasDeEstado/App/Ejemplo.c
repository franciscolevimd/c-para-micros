#include <stdio.h>

#define IDEAL 0
#define PRESIONADO 1

int main(void)
{
    // Siempre debe iniciarse en su estado ideal.
    int Estado = IDEAL;
    int Boton = 0;

    // Una máquina de estado siempre se encuentra en ejecución.
    while (1)
    {
        switch (Estado)
        {
            case IDEAL:
                printf("¿Botón presionado?\n");
                scanf("%d", &Boton);
                if (Boton == 1)
                {
                    Estado = PRESIONADO;
                }
                break;

            case PRESIONADO:
                printf("BOTON PRESIONAD\n");
                Boton = 0;
                Estado = IDEAL;
                break;
        }
    }

    return 0;
}
