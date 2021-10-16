#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "validarEntero.h"
#include "validarCadena.h"
#include "validarFlotante.h"

int getIntFloat (float* pResultado)
    {
        int retorno = -1;
        char buffer[4096];


        if (myGetsFloat(buffer, sizeof(buffer)) && esNumericoFlotante(buffer))
        {
            retorno = 0;
            *pResultado = atof(buffer);
        }
        return retorno;
    }




    int myGetsFloat(char* cadena, int longitud)
    {
        char buffer[4096];
        fflush(stdin);
        scanf("%s", buffer);
        strncpy(cadena, buffer,longitud);
        return -1;
    }



    int validarEnteroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
    {
        int retorno = -1;
        float buffer;

        if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
        {
            do
            {
                printf("%s", mensaje);

                if (getIntFloat(&buffer)== 0 && buffer >= minimo && buffer <= maximo)
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


    int esNumericoFlotante(char str[])
    {
        int i = 0;
        int cantidadPuntos = 0;
        while (str[i] != '\0')
        {
            if (i == 0 && str[i] == '-')
            {
                i++;
                continue;
            }
            if (str[i] == '.' && cantidadPuntos == 0)
            {
                cantidadPuntos++;
                i++;
                continue;

            }
            if (str[i] < '0' || str[i] > '9')
                return 0;
            i++;
        }
        return 1;
    }
