#include <stdio.h>
#include <stdint.h>

#define DIGITO_1 0
#define DIGITO_2 1
#define DIGITO_3 2

#define VALIDO 4
#define ERROR 5

#define TAMPASS 3

/**
 * Diseña un programa que lea una contraseña de 3 números e imprima un mensaje de
 * "Puerta Abierta" si todos los números fueron escritos correctamente, o un mensaje
 * de "Error, intente de nuevo" si algún número fue escrito de manera incorrecta.
 *
 * El programa deberá seguir la lógica de una máquina de estados y repetirse un
 * número ilimitado de veces.
 */
int main(void)
{
    int Estado = DIGITO_1;
    uint8_t Digito;
    uint8_t Pass[TAMPASS] = {1, 0, 5};

    printf("...::: BIENVENIDO :::...\n");
    printf("------------------------\n");
    printf("...Maquina de estados...\n");
    printf("------------------------\n\n");

    while (1)
    {
        switch (Estado)
        {
            case DIGITO_1:
                printf(">: ");
                scanf("%hhu", &Digito);
                while (getchar() != '\n')
                    ;
                if (Pass[DIGITO_1] == Digito)
                {
                    Estado = DIGITO_2;
                }
                else
                {
                    Estado = ERROR;
                }
                break;

            case DIGITO_2:
                printf(">: ");
                scanf("%hhu", &Digito);
                while (getchar() != '\n')
                    ;
                if (Pass[DIGITO_2] == Digito)
                {
                    Estado = DIGITO_3;
                }
                else
                {
                    Estado = ERROR;
                }
                break;

            case DIGITO_3:
                printf(">: ");
                scanf("%hhu", &Digito);
                while (getchar() != '\n')
                    ;
                if (Pass[DIGITO_3] == Digito)
                {
                    Estado = VALIDO;
                }
                else
                {
                    Estado = ERROR;
                }
                break;

            case VALIDO:
                printf("Puerta Abierta\n");
                Estado = DIGITO_1;
                break;

            case ERROR:
                printf("Error, intente de nuevo.\n");
                Estado = DIGITO_1;
                break;
        }
    }

    return 0;
}
