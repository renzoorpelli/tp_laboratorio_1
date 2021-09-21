/*
 * funcionesCalculadora.c
 *
 *  Created on: 21 sep. 2021
 *      Author: renzo
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

float sumarNumeros(float x, float y, float* pSumarNumeros) //float* pSumarNumeros
{
    float resultadoSuma;
    float sumaRealizada = 0;

    if(sumaRealizada == 0)
    {
        resultadoSuma = x + y;
        sumaRealizada = 1;
    }

    *pSumarNumeros = resultadoSuma;
    return sumaRealizada;
}

float restarNumeros(float x, float y, float* pRestarNumeros)  //float* pRestarNumeros
{
    float resultadoResta;
    float restaRealizada = 0;

    if (restaRealizada == 0)
    {
        resultadoResta = x - y;
        restaRealizada = 1;
    }

    *pRestarNumeros = resultadoResta;

    return restaRealizada;

}

float multiplicarNumeros(float x, float y, float* pMultiplicacionNumeros)
{
    float resultadoMultiplicar;
    float multiplicacionRealizada = 0;

    if(multiplicacionRealizada== 0)
    {
        resultadoMultiplicar = x * y;
        multiplicacionRealizada = 1;
    }

    *pMultiplicacionNumeros = resultadoMultiplicar;

    return multiplicacionRealizada;
}


float dividirNumeros(float x, float y, float* pResDiv)
{
    float resultadoDividir;
    int verificacionDivision = 0;

    if (y == 0)
    {
        printf("La division de los numeros no se pudo calculada\n");
    }
    else
    {
        resultadoDividir = x / y;
        verificacionDivision = 1;
    }

    *pResDiv = resultadoDividir;

    return verificacionDivision;
}

float factorialOperandoX(float x, float *pResFactorialX)
{
    float rta = 0;
    float verificacionFactorialX = 0;

    if (x < 0 ||x > 12)
    {
        printf("El factorial de X = %.2f no se pudo calcular\n", x);
    }else
    {
        if (x>= 0)
            {
                rta = 1;
                for (int i = 1; i<=x;i++)
                {
                    rta = rta * i;
                    verificacionFactorialX = 1;
                }
            }
    }

     *pResFactorialX = rta;

    return verificacionFactorialX;
}

float factorialOperandoY(float y, float *pResFactorialY)
{
    float rta = 0;
    float verificacionFactorialY = 0;

    if (y < 0 ||y > 12)
    {
        printf("El factorial de Y= %.2f no se pudo calcular\n", y);
    }else
    {
        if (y>= 0)
            {
                rta = 1;
                for (int i = 1; i<=y;i++)
                {
                    rta = rta * i;
                    verificacionFactorialY = 1;
                }
            }
    }

     *pResFactorialY = rta;

    return verificacionFactorialY;
}



