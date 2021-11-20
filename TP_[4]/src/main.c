/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include <ctype.h>
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
            if(!controller_loadFromBinary("data.bin", listaEmpleados))
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
            if(!controller_ListEmployee(listaEmpleados))
            {
                printf("ERROR AL LISTAR\n");
            }
            break;

        case 7:
            system("cls");
            if(!controller_sortEmployee(listaEmpleados))
            {
                printf("ERROR AL ORDENAR\n");
            }
            break;
        case 8:
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("ERROR AL GUARDAR\n");
            }
            break;
        case 9:
            if(!controller_saveAsBinary("data.bin", listaEmpleados))
            {
                printf("ERROR AL GUARDAR\n");
            }
            break;
        case 10:
            if(!controller_replaceEmployee(listaEmpleados))
            {
                 printf("ERROR AL MODIFICAR\n");
            }
            break;
        case 11:
            if(!controller_clearList(listaEmpleados))
            {
                 printf("ERROR AL ELIMINAR LA LISTA\n");
            }
            break;
        case 12:
            if(!controller_deleteList(listaEmpleados))
            {
                printf("ERROR AL ELIMINAR EL LINKEDLIST\n");
            }
            listaEmpleados = NULL;
            break;
        case 13:
            if(!controller_findEmployee(listaEmpleados))
            {
                 printf("ERROR AL BUSCAR OTRO EMPLEADO\n");
            }
            break;
        case 14:
            if(!controller_generateNewList(listaEmpleados))
            {
                printf("ERROR AL GENERAR EL LINKEDLIST\n");
            }
            break;
        case 15:
            if(!controller_cloneLinkedList(listaEmpleados))
            {
                printf("ERROR AL  CLONAR LA NUEVA LISTA\n");
            }
            break;
        case 20:
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
    printf("10- Reemplazar empleado segun id\n");
    printf("11- Borrar empleados\n");
    printf("12- Borrar lista\n");
    printf("13- Buscar indice empleado\n");
    printf("14- Generar nueva lista\n");
    printf("20- SALIR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}




// ******FUNCIONES UTILIZADAS

/*
        //ll_newLinkedList ---->UTILIZADA          UTILIZADO EN EL LINKEDLIST.C
        // ll_len-------------->UTILIZADA          USO EN LAS FUNCIONES controller_addEmployee Y VARIAS
        // ll_add-------------->UTILIZADA          USO EN LA FUNCION controller_addEmployee
        // ll_get-------------->UTILIZADA          USO EN LAS FUNCIONES controller_editEmployee Y controller_removeEmployee Y controller_ListEmployee Y controller_saveAsText Y controller_replaceEmployee Y controller_findEmployee
        // ll_set-------------->UTILIZADA          USO EN LA FUNCION controller_replaceEmployee
        // ll_remove----------->UTILIZADA          USO DENTOR DE LA FUNCION LL_POP
        // ll_clear------------>UTILIZADA          USO EN LA FUNCION controller_clearList
        // ll_deleteLinkedList->UTILIZADA          USO EN LA FUNCION controller_deleteList
        // ll_indexOf---------->UTILIZADA          USO EN LA FUNCION controller_findEmployee
        // ll_isEmpty---------->UTILIZADA          USO EN LA FUNCION controller_ListEmployee
        // ll_push------------->UTILIZADA          USO EN LA FUNCION controller_addEmployee
        // ll_pop-------------->UTILIZADA          USO EN LA FUNCION controller_removeEmployee
        // ll_contains--------->UTILIZADA          USO EN LA FUNCION controller_removeEmployee
        // ll_containsAll------>UTILIZADA          USO EN LA FUNCION controller_generateNewList Y controller_cloneLinkedList
        // ll_subList---------->UTILIZADA          USO EN LA FUNCION controller_generateNewList
        // ll_clone------------>UTILIZADA          USO EN LA FUNCION controller_cloneLinkedList;
        // ll_sort ------------>UTILIZADA          USO EN LA FUNCION controller_sortEmployee
*/




/*int main(void)
{
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort

    return 0;
}

*/































