#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "validarCadena.h"
#include "Controller.h"
Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id= 0;
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo=0;
    }


    return newEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)// duda
{
    Employee* newEmployee = employee_new();

    if (newEmployee !=  NULL)
    {
        if(!(employee_setId(newEmployee, atoi(idStr)) &&
                employee_setNombre(newEmployee, nombreStr) &&
                employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))&&
                employee_setSueldo(newEmployee, atoi(sueldoStr))))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }

    return newEmployee;
}



void employee_delete(Employee* this)
{
    free(this);
}

/////////////////////////////////////////////////////////

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if ( this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}


int employee_getId(Employee* this,int* id)
{
    int todOk= 0;
    if ( this != NULL && id != NULL)
    {
        (*id) = this->id;
        todOk = 1;
    }
    return todOk;
}

///////////////////////////////////////////////////////////////

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    char auxCadena[50];

    if ( this != NULL && nombre != NULL && strlen(nombre)>0 && strlen(nombre)< 20)
    {
        strcpy(auxCadena, nombre);
        findError(auxCadena);
        setMayus(auxCadena, strlen(auxCadena));
        strcpy(this->nombre, auxCadena);
        todoOk = 1;
    }

    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todOk= 0;
    if ( this != NULL && nombre != NULL)
    {
        strcpy( nombre,this->nombre);
        todOk = 1;
    }
    return todOk;
}

////////////////////////////////////////////////////////////////

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todOk= 0;
    if ( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todOk = 1;
    }
    return todOk;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todOk= 0;
    if ( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas =  this->horasTrabajadas;
        todOk = 1;
    }
    return todOk;
}

//////////////////////////////////////////////////////

int employee_setSueldo(Employee* this,int sueldo)
{
    int todOk= 0;
    if ( this != NULL && (sueldo > 0 || sueldo < 100000))
    {
        this->sueldo = sueldo;
        todOk = 1;
    }
    return todOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todOk= 0;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo =  this->sueldo;
        todOk = 1;
    }
    return todOk;
}

//////////////////////////////////////////////////////


int mostrarFullEmpleado(Employee* empleado)
{
    int todoOk = 0;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    if(empleado != NULL)
    {
        if(
            employee_getId(empleado, &id) &&
            employee_getNombre(empleado, nombre) &&
            employee_getHorasTrabajadas(empleado, &horasTrabajadas) &&
            employee_getSueldo(empleado, &sueldo))
        {
            printf(" %2d    %11s                %2d               $%2d\n", id,
                   nombre,
                   horasTrabajadas,
                   sueldo);
            todoOk =1;
        }
    }
    return todoOk;
}

//////////////////////////////////////////////////////


int buscarMayorId(LinkedList* lista)
{
    Employee* auxEmp = NULL;
    int mayor= 0;
    int id;
    if(lista != NULL)
    {

        for( int i = 0; i < ll_len(lista); i++)
        {
            auxEmp = (Employee*) ll_get(lista, i);
            employee_getId(auxEmp, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }

    }
    return mayor;
}


/////////////////////////////////////////////////////

int buscarEmpleadosId(LinkedList* lista, int id)
{
    int indice = -1;
    int idAux;
    Employee* auxEmployee;

    for (int i = 0; i < ll_len(lista); i++)
    {
        auxEmployee = ll_get(lista, i);
        if(employee_getId(auxEmployee, &idAux) && idAux == id)
        {
            indice = i;
        }
    }

    return indice;
}

//////////////////////////////////////////////////////

//ORDENAMIENTO SEGUN CRITERIO

int menuOrdenamiento()
{
    int opcion = 0;
    system("cls");
    printf("    ***ABM Personas***\n");
    printf("1- ORDENAR EMPLEADOS POR HORAS TRABAJADAS ASCENDENTE \n");
    printf("2- ORDENAR EMPLEADOS POR HORAS TRABAJADAS DESCENDENTE\n");
    printf("3- ORDENAR EMPLEADOS POR SALARIO ASCENDENTE\n");
    printf("4- ORDENAR EMPLEADOS POR SALARIO DESCENDENTE \n");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


int compararEmpleadosHorasTrabajadas(void* pPersonA,void* pPersonB)
{
    int todoOk= 0;

    if(((Employee*)pPersonA)->horasTrabajadas > ((Employee*)pPersonB)->horasTrabajadas)
    {
        todoOk= 1;
    }
    if(((Employee*)pPersonA)->horasTrabajadas <
            ((Employee*)pPersonB)->horasTrabajadas)
    {
        todoOk = -1;
    }
    return todoOk;
}


int compararEmpleadosSueldo(void* pPersonA,void* pPersonB)
{
    int todoOk= 0;

    if(((Employee*)pPersonA)->sueldo > ((Employee*)pPersonB)->sueldo)
    {
        todoOk= 1;
    }
    if(((Employee*)pPersonA)->sueldo <
            ((Employee*)pPersonB)->sueldo)
    {
        todoOk = -1;
    }
    return todoOk;

}


int elegirOrden(LinkedList* listaEmpleados)
{
    int todoOk = 0;
    if(listaEmpleados != NULL)
    {

        switch(menuOrdenamiento())
                {
                case 1:
                    system("cls");
                    printf("Ordenando...\n");
                    ll_sort(listaEmpleados, compararEmpleadosHorasTrabajadas, 1);
                    controller_ListEmployee(listaEmpleados);
                    break;
                case 2:
                    system("cls");
                    printf("Ordenando...\n");
                    ll_sort(listaEmpleados, compararEmpleadosHorasTrabajadas, 0);
                    controller_ListEmployee(listaEmpleados);
                    break;
                case 3:
                    system("cls");
                    printf("Ordenando...\n");
                    ll_sort(listaEmpleados, compararEmpleadosSueldo, 1);
                    controller_ListEmployee(listaEmpleados);
                    break;
                case 4:
                    system("cls");
                    printf("Ordenando...\n");
                    ll_sort(listaEmpleados, compararEmpleadosSueldo, 0);
                    controller_ListEmployee(listaEmpleados);
                break;
                default:
                    printf("OPCION INVALIDA!\n");
                    break;
                }
                todoOk = 1;
    }
    return todoOk;
}

int menuModificar()
{
    int opcion = 0;
    printf("    ***ABM Personas***\n");
    printf("1- MODIFICAR NOMBRE EMPLEADO \n");
    printf("2- MODIFICAR HORAS TRABAJADAS EMPLEADO\n");
    printf("3- MODIFICAR SUELDO EMPLEADO\n");
    printf("4- SALIR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
