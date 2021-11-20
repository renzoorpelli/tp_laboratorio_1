#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "../inc/LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "validarCadena.h"
#include "validarEntero.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayListEmployee != NULL )
    {

        pFile = fopen( path, "r");
        if ( pFile == NULL )
        {
            printf("ERROR NO SE PUDO ABRIR EL ARCHIVO\n");
        }
        else
        {
            if ( parser_EmployeeFromText( pFile, pArrayListEmployee ) )
            {
                printf( "LA CARGA FUE EXITOSA\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("CARGA DE DATOS DESDE ARCHIVO BINARIO\n");

        pFile = fopen( path, "rb");
        if ( pFile == NULL )
        {
            printf("ERROR NO SE PUDO ABRIR EL ARCHIVO\n");
        }
        else
        {
            if ( parser_EmployeeFromBinary( pFile, pArrayListEmployee ) )
            {
                printf( "LA CARGA FUE EXITOSA\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmployee = NULL;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    int indice;
    int posicion;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        auxEmployee = employee_new();

        auxId = buscarMayorId(pArrayListEmployee);
        auxId++;
        printf("El id asignado sera %d\n", auxId);

        printf("Ingrese nombre del empleado:\n");
        fflush(stdin);
        scanf("%s", auxNombre);
        setMayus(auxNombre, 50);
        while(!findError(auxNombre))
        {
            printf("ERROR...Ingrese nombre del empleado:\n");
            fflush(stdin);
            scanf("%s", auxNombre);
        }
        validarEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas del empleado:\n", "ERROR... Ingrese las horas trabajadas del empleado:\n", 2, 2000, 10);
        validarEntero(&auxSueldo, "Ingrese el sueldo  del empleado:\n", "ERROR... Ingrese el sueldo  del empleado:\n", 10000, 60000, 10);

        if(!(employee_setId(auxEmployee, auxId) &&
                employee_setNombre(auxEmployee, auxNombre) &&
                employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas )&&
                employee_setSueldo(auxEmployee, auxSueldo)))
        {
            free(auxEmployee);
            auxEmployee = NULL;
        }
        else
        {
            indice = ll_len(pArrayListEmployee) -1;
            printf("Ingrese la posicion que quiere ingresar el empleado desde 0  a  %d", indice );
            scanf("%d", &posicion);
            while(posicion <= 0 || posicion > indice)
            {
                printf("ERROR...Ingrese la posicion que quiere ingresar el empleado desde 0  a  %d", indice );
                scanf("%d", &posicion);

            }
            if (posicion == indice)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                printf("Empleado dado de alta con exito!\n");;
            }
            else
            {
                ll_push(pArrayListEmployee, posicion, auxEmployee);
                printf("Empleado dado de alta con exito en la posicion %d\n", posicion);
            }

        }
        todoOk =1;

    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk= 0;
    int auxId;
    Employee* auxEmployee;
    int indice;
    int ultimoId;
    int opcion;
    char salir;
    char seguir = 's';
    char confirma;
    //////////////
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   *** MODIFICACION EMPLEADOS SISTEMA *** \n\n");

        controller_ListEmployee(pArrayListEmployee);

        ultimoId = buscarMayorId(pArrayListEmployee);

        validarEntero(&auxId, "Ingrese el id del empleado:\n", "Ingrese el id del empleado valida:\n", 0, ultimoId, 10);

        indice = buscarEmpleadosId(pArrayListEmployee, auxId);

        if ( indice != -1)
        {
            auxEmployee = ll_get(pArrayListEmployee, indice);

            do
            {
                system("cls");
                printf("\n");
                printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n");
                mostrarFullEmpleado(auxEmployee);

                opcion = menuModificar();

                switch (opcion)
                {
                case 1:
                    system("cls");
                    printf("  EDITAR NOMBRE EMPLEADO \n");
                    printf("INGRESE NUEVO NOMBRE:\n");
                    fflush(stdin);
                    scanf("%s", auxNombre);
                    setMayus(auxNombre, strlen(auxNombre));
                    while(!findError(auxNombre))
                    {
                        printf("ERROR...INGRESE NUEVO NOMBRE:\n");
                        fflush(stdin);
                        scanf("%s", auxNombre);
                        setMayus(auxNombre, strlen(auxNombre));

                    }

                    printf("Confirma cambio nombre? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setNombre(auxEmployee, auxNombre);
                        printf("Nombre cambiado con exito\n");
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }


                    break;
                case 2:
                    system("cls");
                    printf("  EDITAR HORAS TRABAJADAS\n");
                    validarEntero(&auxHorasTrabajadas,"INGRESE NUEVAS HORAS:\n", "ERROR, INGRESE HORAS VALIDAS", 2, 1000, 10 );
                    printf("CONFIRMA CAMBIO DE HORAS TRABAJADAS? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
                        printf("HORAS ACTUALIZADAS CORRECTAMENTE\n");
                    }
                    else
                    {
                        printf("EDICION CANCELADA POR EL USUARIO\n");
                    }

                    break;
                case 3:
                    system("cls");
                    printf("  EDITAR SUELDO\n");
                    validarEntero(&auxSueldo,"INGRESE NUEVO SUELDO: (10000-60000)\n", "ERROR, INGRESE NUEVO SUELDO VALIDO (10000-60000)", 10000, 60000, 10 );
                    printf("CONFIRMA CAMBIO DE SUELDO? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setSueldo(auxEmployee, auxSueldo);
                        printf("HORAS ACTUALIZADAS CORRECTAMENTE\n");
                    }
                    else
                    {
                        printf("EDICION CANCELADA POR EL USUARIO\n");
                    }


                    break;
                case 4:
                    printf("ESTA SEGURO QUE DESA SALIR? (S/N)\n");
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
                    break;
                }
                system("pause");
            }
            while(seguir == 's');
        }


    }
    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk= 0;
    int auxId;
    Employee* auxEmployee;
    int indice;
    int ultimoId;
    char confirmaBaja;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   *** BAJA EMPLEADOS DEL SISTEMA *** \n\n");
        if(controller_ListEmployee(pArrayListEmployee)==0)
        {
            printf(" NO HAY EMPLEADOS PARA MOSTRAR \n");
        }

        ultimoId = buscarMayorId(pArrayListEmployee);

        validarEntero(&auxId, "Ingrese el id del empleado:\n", "Ingrese el id del empleado valida:\n", 0, ultimoId, 10);

        indice = buscarEmpleadosId(pArrayListEmployee, auxId);
       // indice = ll_contains(pArrayListEmployee, &auxId);

        if ( indice != -1)
        {
            auxEmployee = ll_get(pArrayListEmployee, indice);
            system("cls");
            printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n\n");

            mostrarFullEmpleado(auxEmployee);
            if(ll_contains(pArrayListEmployee, auxEmployee))
            {
                printf("EL EMPLEADO SE ENCUNETRA EN LA LISTA\n");
            }

            printf("Confirma la baja del empleado? S o N?");
            fflush(stdin);
            scanf("%c", &confirmaBaja);
            confirmaBaja = toupper(confirmaBaja);
            while(confirmaBaja != 'S' && confirmaBaja !='N')
            {
                printf("Confirma la baja del empleado? S o N?");
                fflush(stdin);
                scanf("%c", &confirmaBaja);
                confirmaBaja = toupper(confirmaBaja);
            }
            if(confirmaBaja == 'S')
            {
                ll_pop(pArrayListEmployee, indice);
                printf("Baja realizada con exito\n");
                if(!ll_contains(pArrayListEmployee, auxEmployee))
                {
                    printf("El empleado no se encuentra mas en la lista\n");
                }
            }
            else
            {
                printf("Baja cancelada por el usuario \n");
            }

        }

        todoOk = 1;
    }
    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmp = NULL;
    if(ll_isEmpty(pArrayListEmployee)== 0)
    {
        printf("**************************************************************\n");
        printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n");
        printf("**************************************************************\n");
        for( int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
            mostrarFullEmpleado(auxEmp);
        }
        printf("\n\n");
        todoOk = 1;
    }
    else
    {
         printf("LA LISTA ESTA VACIA\n");
    }
    return todoOk;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;

    if (pArrayListEmployee != NULL)
    {
        if (elegirOrden(pArrayListEmployee))
        {
            printf("Empleados ordenados exitosamente\n");
        }
        else
        {
            printf("Error al tratar de organizar los empleados\n");
        }
        todoOk = 1;
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("GUARDADO EL ARCHIVO EN MODO CSV...\n");

        pFile = fopen(path, "w"); // abro el archivo
        if ( pFile == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        fprintf( pFile, "id,nombre,horasTrabajadas,sueldo\n" );

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if ( employee_getId( auxEmpleado, &id ) &&
                    employee_getNombre( auxEmpleado, nombre ) &&
                    employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
                    employee_getSueldo(auxEmpleado, &sueldo)
               )
            {
                fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    FILE* pFile;

    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        system("cls");
        printf("GUARDADO ARCHIVOS DESDE BINARIO...\n");

        pFile = fopen(path, "wb");
        if ( pFile == NULL )
        {
            printf("ERROR AL ABRIR EL ARCHIVO\n");

        }

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);

            if ( (auxEmpleado) != NULL )
            {
                fwrite( auxEmpleado, sizeof(Employee), 1, pFile );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}

// -------------------------FUNCIONES TP4------------------------------------
int controller_replaceEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmployee = NULL;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId;
    int index;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("Ingrese el indice donde quiere agregar un empleado:\n");
        scanf("%d", &auxId);
        index = buscarEmpleadosId(pArrayListEmployee, auxId);
        if (index == -1)
        {
            printf("No existe la posicion del empleado:\n");
        }
        else
        {
            controller_ListEmployee(pArrayListEmployee);
            printf("EL EMPLEADO EN ESTA POSICION ES: \n");
            auxEmployee = ll_get(pArrayListEmployee, index);
            printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n");
            mostrarFullEmpleado(auxEmployee);

            printf("Ingrese nombre del empleado:\n");
            fflush(stdin);
            scanf("%s", auxNombre);
            setMayus(auxNombre, 50);
            while(!findError(auxNombre))
            {
                printf("ERROR...Ingrese nombre del empleado:\n");
                fflush(stdin);
                scanf("%s", auxNombre);
            }
            validarEntero(&auxHorasTrabajadas, "Ingrese las horas trabajadas del empleado:\n", "ERROR... Ingrese las horas trabajadas del empleado:\n", 2, 2000, 10);
            validarEntero(&auxSueldo, "Ingrese el sueldo  del empleado:\n", "ERROR... Ingrese el sueldo  del empleado:\n", 10000, 60000, 10);

            if(!(employee_setId(auxEmployee, auxId) &&
                    employee_setNombre(auxEmployee, auxNombre) &&
                    employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas )&&
                    employee_setSueldo(auxEmployee, auxSueldo)))
            {
                free(auxEmployee);
                auxEmployee = NULL;
            }
            else
            {
                ll_set(pArrayListEmployee, index,auxEmployee);
                printf("Datos empleado reemplazado con exito!\n");;
            }

        }

        todoOk =1;

    }
    return todoOk;
}

int controller_clearList(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char confirma;
    if(pArrayListEmployee != NULL)
    {
        printf("DESEA ELIMINAR A TODOS LOS EMPLEADOS S o N?\n");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma = toupper(confirma);
        if(confirma == 'S')
        {
            ll_clear(pArrayListEmployee);
            printf("EMPLEADOS ELIMINADOS CON EXITO\n");
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
        todoOk = 1;
    }
    return todoOk;

}

int controller_deleteList(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char confirma;
    if(pArrayListEmployee != NULL)
    {
        printf("DESEA ELIMINAR LA LISTA S o N?\n");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma = toupper(confirma);
        if(confirma == 'S')
        {
            if(!ll_deleteLinkedList(pArrayListEmployee))
            {
                pArrayListEmployee = NULL;
                printf("LISTA ELIMINADOS CON EXITO\n");
            }
        }
        else
        {
            printf("Accion cancelada por el usuario\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
int controller_findEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int indice;
    int auxIndex;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("ingrese id\n");
        scanf("%d", &auxId);
        indice = buscarEmpleadosId(pArrayListEmployee, auxId);
        if ( indice != -1)
        {
            printf("\n");
            printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n");
            auxEmployee = ll_get(pArrayListEmployee, indice);
            mostrarFullEmpleado(auxEmployee);
            auxIndex = ll_indexOf(pArrayListEmployee, auxEmployee);
            printf("EL INDICE DEL EMPLEADO ES %d\n", auxIndex);
        }
    }

    return indice;
}

int controller_generateNewList(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int desde;
    int hasta;
    int limite = ll_len(pArrayListEmployee)-1;
    LinkedList* nuevaLista = NULL;

    if(pArrayListEmployee!= NULL)
    {
        system("cls");
        printf("        ***********NUEVA LISTA*******************\n");
        printf("Ingrese el inicio de la subLista: 0 -%d\n", limite);
        scanf("%d", &desde);
        printf("Ingrese el fin de la subLista:0 -%d\n", limite);
        scanf("%d", &hasta);

        nuevaLista = ll_subList(pArrayListEmployee, desde , hasta);
        if(ll_containsAll(pArrayListEmployee, nuevaLista))
        {
            printf("Lista creada correctamente\n");
            controller_ListEmployee(nuevaLista);
        }
        todoOk = 1;
    }
    return todoOk;
}

int controller_cloneLinkedList(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    LinkedList* cloneLinkedlist = NULL;
    if(pArrayListEmployee != NULL)
    {
        printf("*******LISTA CLOANDA************\n");

        cloneLinkedlist = ll_clone(pArrayListEmployee);
        if(ll_containsAll(pArrayListEmployee, cloneLinkedlist))
        {
            controller_ListEmployee(cloneLinkedlist);
            printf("LISTA CLONADA CORRECTAMENTE\n");
        }
        todoOk = 1;
    }
    return todoOk;
}
