#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validarEntero.h"
#include "validarCadena.h"
int getInt (int* pResultado)
{
    int retorno = -1;
    char buffer[4096];


    if (myGets(buffer, sizeof(buffer)) && esNumerica (buffer))
    {
        retorno = 0;
        *pResultado = atoi(buffer);
    }
    return retorno;
}




int myGets(char* cadena, int longitud)
{
    char buffer[4096];
    fflush(stdin);
    scanf("%s", buffer);
    strncpy(cadena, buffer ,longitud);
    return -1;
}



int validarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno = -1;
    int buffer;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            if (getInt(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }
        while (reintentos >= 0);
    }

    return retorno;
}


int esNumerica(char* cadena)
{
    int retorno = 1;

    for(int i =0; cadena[i] != '\0'; i++)
    {
        if (cadena[0] == '-')
        {
            i = 1;
        }
        if (cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;


}
