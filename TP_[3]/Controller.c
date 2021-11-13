#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ctype.h"
#include "LinkedList.h"
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
    FILE* pFile = NULL;

    if (path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");
        if (pFile == NULL)
        {
            printf("Error al cargar el archivo\n");
        }
        else
        {
            if(parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                printf("Archivo Cargado Correctamente\n");
                todoOk = 1;
            }
        }
        todoOk = 1;
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
    FILE* pFile = NULL;

    if (path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if (pFile == NULL)
        {
            printf("Error al cargar el archivo\n");
        }
        else
        {
            if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                printf("Archivo Cargado Correctamente\n");
                todoOk = 1;
            }
        }
        todoOk = 1;
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
            ll_add(pArrayListEmployee, auxEmployee);
            printf("Empleado dado de alta con exito!\n");;
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
                        printf("SUELDO ACTUALIZADAS CORRECTAMENTE\n");
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

        todoOk=1;
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

        if ( indice != -1)
        {
            auxEmployee = ll_get(pArrayListEmployee, indice);
            system("cls");
            printf("LEGAJO      NOMBRE         HORAS TRABAJADAS        SUELDO\n");

            mostrarFullEmpleado(auxEmployee);

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
                ll_remove(pArrayListEmployee, indice);
                printf("Baja realizada con exito\n");
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
    if(pArrayListEmployee != NULL)
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
    FILE* pFile = NULL;
    Employee* auxEmployee;
    int auxId;
    char auxNombre[50];
    int auxHorasTrabajadas;
    int auxSueldo;

    if (path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");
        if (pFile == NULL)
        {
            printf("Error al cargar el archivo\n");
            exit(1);
        }
        else
        {
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i = 1; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = ll_get(pArrayListEmployee, i);

                if(!(employee_getId(auxEmployee, &auxId) &&
                        employee_getNombre(auxEmployee, auxNombre) &&
                        employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas )&&
                        employee_getSueldo(auxEmployee, &auxSueldo)))
                {
                    printf("Error al intentar guardar!\n");
                }
                else
                {
                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
                    todoOk = 1;
                }
            }
            fclose(pFile);

        }
    }

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
    FILE* pFile = NULL;
    Employee* auxEmployee;

    if (path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");
        if (pFile == NULL)
        {
            printf("Error al cargar el archivo\n");
        }
        else
        {
            for(int i = 1; i < ll_len(pArrayListEmployee); i++)
            {
                auxEmployee = ll_get(pArrayListEmployee, i);

                if( (auxEmployee +i) != NULL)
                {
                    fwrite(auxEmployee, sizeof(Employee), 1, pFile);
                    todoOk = 1;
                }
                else
                {
                    printf("Error al intentar guardar!\n");
                }
            }
            fclose(pFile);
        }

    }
    return todoOk;
}

