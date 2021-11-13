#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menu();

int main()
{
	setbuf(stdout,NULL);
    char salir;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();

    if (listaEmpleados == NULL)
    {
        printf("No se pudo crear el linkedList\n");
        exit(1);

    }
    do
    {
        switch(menu())
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaEmpleados))
            {
                printf("Error durante la llamada\n");
            }
            break;
        case 2:
            if(!controller_loadFromBinary("dateas.bin", listaEmpleados))
            {
                printf("Error durante la carga de archivo\n");
            }
            break;
        case 3:
            if(!controller_addEmployee(listaEmpleados))
            {
                printf("Error durante el alta empleado\n");
            }
            break;
        case 4:
            if(!controller_editEmployee(listaEmpleados))
            {
                printf("Error al realizar la modificacion\n");
            }
            break;
        case 5:
            if(!controller_removeEmployee(listaEmpleados))
            {
                printf("Error durante la baja empleado\n");
            }
            break;
        case 6:
            system("cls");
            controller_ListEmployee(listaEmpleados);
            break;

        case 7:
            system("cls");
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            if(controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Guardado exitoso!\n");
            }
            break;
        case 9:
            if(controller_saveAsBinary("dateas.bin", listaEmpleados))
            {
                printf("Guardado binario!\n");
            }
            break;
        case 10:
            printf("Esta seguro que quiere salir? S o N \n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
            printf("Ingrese otra opcion:\n");
        }
        system("pause");
    }
    while(seguir == 's');

    free(listaEmpleados);
    return 0;
}

int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***ABM Personas***\n");
    printf("1- Cargar los datos de los empleados desde el archivo en modo csv \n");
    printf("2- Cargar los datos de los empleados desde el archivo en modo binario\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados desde el archivo en modo csv\n");
    printf("9- Guardar los datos de los empleados desde el archivo en modo binario\n");
    printf("10- SALIR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
