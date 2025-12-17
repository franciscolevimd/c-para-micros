#include "MaquinaContra.h"

/**
 * Diseña un programa que lea una contraseña de 3 números e imprima un mensaje de
 * "Puerta Abierta" si todos los números fueron escritos correctamente, o un mensaje
 * de "Error, intente de nuevo" si algún número fue escrito de manera incorrecta.
 *
 * El programa deberá seguir la lógica de una máquina de estados y repetirse un
 * número ilimitado de veces.
 */
uint8_t MaquinaDeEstados(uint8_t Estado, uint8_t Digito)
{
    uint8_t Resultado;
    const uint8_t Pass[3] = {1, 0, 5};

    switch (Estado)
    {
        case IDEAL:
            Resultado = DIGITO_1;
            break;

        case DIGITO_1:
            if (Pass[DIGITO_1 - 1u] == Digito)
            {
                Resultado = DIGITO_2;
            }
            else
            {
                Resultado = ERROR;
            }
            break;

        case DIGITO_2:
            if (Pass[DIGITO_2 - 1u] == Digito)
            {
                Resultado = DIGITO_3;
            }
            else
            {
                Resultado = ERROR;
            }
            break;

        case DIGITO_3:
            if (Pass[DIGITO_3 - 1u] == Digito)
            {
                Resultado = VALIDO;
            }
            else
            {
                Resultado = ERROR;
            }
            break;

        case VALIDO:
            Resultado = IDEAL;
            break;

        case ERROR:
            Resultado = DIGITO_1;
            break;

        default:
            break;
    }

    return Resultado;
}
