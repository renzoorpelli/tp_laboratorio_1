#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"
#define ASIGNADO 1

/** \brief mostrar el menu de opciones
 * \param
 * \return retorna el valor de la variable opcion
 *
 */

int menu();

/** \brief Se encarga de mostrar las opciones del menu aclarando las operaciones a realizar
 * \param pide un valor para la opcion
 * \return retorna el valor asignado
 *
 */

float pedirNumeros();

int main()
{
	setbuf(stdout, NULL);
    int seguir = 's';
    int banderaPrimerOperando = 0;
    float primerOperandoX;
    float segundoOperandoY;
    //funcion sumar
    float validarSuma;
    float resultadoSuma;
    float banderaSuma=0;
    //funcion restar
    float validarResta;
    float resultadoResta;
    float banderaResta = 0;
    //funcion Multiplicar
    float validarMultiplicacion;
    float resultadoMultiplicacion;
    float banderaMultiplicar = 0;
    //funcion Dividir
    float validarDivision;
    float resultadoDivision;
    float banderaDivision = 0;
    //funcion Factorial OperandoX
    float validarFactorialX;
    float resultadoFactorialX;
    float banderaFactorialX = 0;
    //funcion Factiral OperandoY
    float validarFactorialY;
    float resultadoFactorialY;
    float banderaFactorialY = 0;



    do
    {
        switch(menu())
        {
            case 1:
                banderaPrimerOperando = ASIGNADO;
                primerOperandoX = pedirNumeros();
                printf("Usted le asigo a X= %.2f\n", primerOperandoX);

            break;
            case 2:
                if(banderaPrimerOperando == ASIGNADO)
                {
                    segundoOperandoY = pedirNumeros();
                    printf("Usted le asigo a Y= %.2f\n", segundoOperandoY);
                }
                else
                {
                    printf("Error no asigno el primer operando\n");
                }
            break;
            case 3:
                validarSuma = sumarNumeros(primerOperandoX, segundoOperandoY, &resultadoSuma);
                if (validarSuma==1)
                {
                    printf("La operacion SUMA pudo ser calculada\n");
                    banderaSuma = 1;
                }
                validarResta = restarNumeros(primerOperandoX, segundoOperandoY, &resultadoResta);
                if (validarResta == 1)
                {
                    printf("La operacion RESTA pudo ser calculada\n");
                    banderaResta = 1;
                }
                validarMultiplicacion = multiplicarNumeros(primerOperandoX, segundoOperandoY, &resultadoMultiplicacion);
                if (validarMultiplicacion == 1)
                {
                    printf("La operacion MULTIPLICAR pudo ser calculada\n");
                    banderaMultiplicar = 1;
                }
                validarDivision = dividirNumeros(primerOperandoX, segundoOperandoY, &resultadoDivision);
                if(validarDivision == 1)
                {
                    printf("La operacion DIVIDIR pudo ser calculada\n");
                    banderaDivision = 1;
                }
                validarFactorialX = factorialOperandoX(primerOperandoX, &resultadoFactorialX);
                if (validarFactorialX == 1)
                {
                    printf("La operacion FACTORIAL DE X pudo ser calculada\n");
                    banderaFactorialX = 1;
                }
                validarFactorialY = factorialOperandoY(segundoOperandoY, &resultadoFactorialY);
                if (validarFactorialY == 1)
                {
                    printf("La operacion FACTORIAL DE Y pudo ser calculada\n");
                    banderaFactorialY = 1;
                }


            break;
            case 4:
                if(banderaSuma == 1)
                {
                    printf("La suma de X= %.2f e Y = %.2f da como resultado %.2f\n", primerOperandoX, segundoOperandoY, resultadoSuma);

                }
                if (banderaResta == 1)
                {
                    printf("La resta de X= %.2f e Y = %.2f da como resultado %.2f\n", primerOperandoX, segundoOperandoY, resultadoResta);
                }
                if (banderaMultiplicar == 1)
                {
                      printf("La multiplicacion de X= %.2f e Y = %.2f da como resultado %.2f\n", primerOperandoX, segundoOperandoY, resultadoMultiplicacion);
                }
                if (banderaDivision == 1)
                {
                    printf("La division de X= %.2f e Y = %.2f da como resultado %.2f\n", primerOperandoX, segundoOperandoY, resultadoDivision);
                }
                if (banderaFactorialX == 1)
                {
                    printf("El factorial de X= %.2f  da como resultado %.2f\n", primerOperandoX, resultadoFactorialX);
                }
                if (banderaFactorialY == 1)
                {
                    printf("El factorial de Y= %.2f  da como resultado %.2f\n", segundoOperandoY, resultadoFactorialY);
                }
            break;
            case 5:
                seguir = 'n';
            break;
        }
        system("pause");


        /*printf("Desea seguir?");
        fflush(stdin);
        scanf("%d", &seguir);*/
    }while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;
    printf("MENU DE OPCINES\n\n");
    printf("1. Ingresar primer operando A=X\n");
    printf("2. Ingresar el segundo operando B=Y\n");
    printf("3. Calcular Operaciones\n");
    printf("4. Informar Resultados\n");
    printf("5. Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

float pedirNumeros()
{
    float num1;

    printf("Ingresar un numero: ");
    scanf("%f", &num1);

    return num1;
}

