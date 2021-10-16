
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validarEntero.h"
#include "validarCadena.h"

#define TAM 1000

int menu();

int main()
{
	setbuf(stdout, NULL);
	char seguir = 's';
	    int defaultId = 20000;
	    Employee list [TAM];// vector socios
	    float fullSalary;//guarda el promedio de salario
	    int flagInicio = 0;

	    if(!initEmployees(list, TAM))
	    {
	        printf("Problemas al inicializar");
	    }

	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            if (newEmployee(list, TAM, &defaultId))
	            {
	                printf("No se pudo realizar el alta\n");
	            }
	            else
	            {
	                printf("Alta realizada con exito\n");
	                flagInicio = 1;
	            }
	            break;
	        case 2:
	            if (!flagInicio)
	            {
	                printf("No ingreso ningun empleado\n");
	            }
	            else
	            {
	                if (!modifyEmployee(list, TAM))
	                {
	                    printf("No se pudo realizar la modificacion\n");

	                }
	            }
	            break;
	        case 3:
	            if (!flagInicio)
	            {
	                printf("No ingreso ningun empleado\n");
	            }
	            else
	            {
	                if (removeSearch(list, TAM) == 0)
	                {
	                    printf("Baja del sistema realizada con exito\n");
	                }

	            }
	            break;
	        case 4:
	            if (!flagInicio)
	            {
	                printf("No ingreso ningun empleado\n");
	            }
	            else
	            {
	                if (sortEmployees(list, TAM))
	                {
	                    printf("No se pudo realizar el orden de personas\n");
	                }
	                else
	                {
	                    printf("Orden realizado con exito\n");
	                }
	            }
	            break;
	        case 5:
	            if (!flagInicio)
	            {
	                printf("No ingreso ningun empleado\n");
	            }
	            else
	            {
	                printEmployees(list, TAM);
	            }
	            break;
	        case 6:
	            if (!flagInicio)
	            {
	                printf("No ingreso ningun empleado\n");
	            }
	            else
	            {
	                if (salaryEmployees(list, TAM, &fullSalary))
	                {
	                    printf("No se pudo promediar el salario de  las personas\n");
	                }
	                else
	                {
	                    printf("el promedio de salario es de : %.2f\n", fullSalary);
	                    cobranBien(list, TAM,fullSalary);
	                }
	            }
	            break;
	        case 7:
	            printf("7. Salir\n");
	            seguir = 'x';
	            break;
	        default:
	            printf("Opcion invalida\n");
	            printf("Ingrese otra opcion:\n");
	        }
	        system("pause");
	    }
	    while(seguir == 's');
	    return 0;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***ABM Personas***\n");
    printf("1- ALTA PERSONA\n");
    printf("2- MODIFICAR PERSONA\n");
    printf("3- BAJA PERSONA\n");
    printf("4- ORDENAR PERSONA\n");
    printf("5- LISTAR PERSONA\n");
    printf("6. INFORMACION SALARIOS\n");
    printf("7- SALIR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
