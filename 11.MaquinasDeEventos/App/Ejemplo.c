#include <stdio.h>
#include <string.h>

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

unsigned char Preguntar(const char *Nombre)
{
    printf("¿%s estas ahí?\n", Nombre);
    return 3;
}

unsigned char (*PunterosFunciones[])(const char *Nombre) = {Saludar, Despedir, Preguntar};

void Interactuar(int Opcion, const char *Nombre)
{
    unsigned char Resultado = PunterosFunciones[Opcion](Nombre);
    printf("Resultado = %hhu.\n", Resultado);
}

unsigned char scanf_uc(void)
{
    unsigned char Resultado;
    (void)scanf("%hhu", &Resultado);
    while (getchar() != '\n')
        ;
    return Resultado;
}

int main(void)
{
    unsigned char Opcion;
    char Nombre[20];

    memset(Nombre, 0, 20);

    printf("Ingresa una opción menor a 3: ");
    Opcion = scanf_uc();

    printf("Ingresa tu nombre: ");
    fgets(Nombre, 20, stdin);
    strtok(Nombre, "\n");

    Interactuar(Opcion, Nombre);
    
    return 0;
}
