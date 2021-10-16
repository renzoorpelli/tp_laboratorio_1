#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "validarEntero.h"
#include "validarCadena.h"


int findError(char vec[])
{
    int todoOk = 1;

    for (int i = 0; i < strlen(vec); i++)
    {
        if(!(isalpha(vec[i])))
        {
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

int setMayus(char vec[], int len)
{
    int checkStatus = 0;
    int i = 0;
    strlwr(vec);
    vec[0] = toupper(vec[0]);

    while(vec[i]!= '\0')
    {
        if (vec[i] == ' ')
        {
            vec[i + 1] = toupper(vec[i+1]);
            checkStatus = 1;
        }
        i++;
    }

    return checkStatus;
}

