#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	    Employee* auxEmployee = NULL;
	    char id[50];
	    char nombre[50];
	    char horasTrabajadas[20];
	    char sueldo[20];
	    int cant;

	    if ( pFile != NULL && pArrayListEmployee != NULL)
	    {
	        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas, sueldo);

	        do
	        {
	            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id,nombre,horasTrabajadas, sueldo);
	            if ( cant < 4)
	            {
	                break;
	            }
	            auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
	            if (auxEmployee != NULL)
	            {
	                ll_add(pArrayListEmployee, auxEmployee);
	                todoOk = 1;
	            }

	        }while(!feof(pFile));

	    }

	   return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	    Employee* auxEmpleado = NULL;
	    int cant;

	    if ( pFile != NULL && pArrayListEmployee != NULL)
	    {
	        while (!feof(pFile))
	        {
	            auxEmpleado = employee_new();
	            if (auxEmpleado !=NULL)
	            {
	                cant = fread(auxEmpleado,sizeof(Employee),1,pFile);
	                if(cant ==1)
	                {
	                    ll_add(pArrayListEmployee, auxEmpleado);
	                    todoOk = 1;
	                }
	            }
	        }
	    }
	    return todoOk;

}
