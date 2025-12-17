#include <stdio.h>

unsigned char Saludar(const char *Nombre)
{
    printf("Que tranza %s.\n", Nombre);
    return 1;
}

unsigned char Despedir(const char *Nombre)
{
    printf("Adios %s.\n", Nombre);
    return 2;
}

int main(void)
{
    // Puntero a función.
    unsigned char (*ptrFuncion)(const char *Nombre);
    unsigned char Resultado;

    ptrFuncion = Saludar;
    Resultado = ptrFuncion("Leví");
    printf("Resultado = %hhu.\n", Resultado);

    ptrFuncion = Despedir;
    Resultado = ptrFuncion("Dua Lipa");
    printf("Resultado = %hhu.\n", Resultado);

    return 0;
}
