#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "validarEntero.h"
#include "validarCadena.h"



int initEmployees (Employee list[], int len)
{
    int checkStatus = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;// agregar define 1 VACIO
        }
        checkStatus = 0;
    }

    return checkStatus;
}


int findPlace(Employee list[], int len)
{
    int checkStatus = -1;
    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty)
        {
            checkStatus = i;
            break;
        }
    }

    return checkStatus;
}

int newEmployee(Employee list[], int len, int* pId)
{
    Employee auxEmployee;
    char auxLongName[100];
    char auxLongLastName[100];
    int checkStatus = -1;
    int auxSalario;
    int auxSector;
    int r;//variable que guarda el retorno de name
    int x;// variable q guarda el retorno de lastname
    int place;


    if (list!= NULL && len > 0 && pId != NULL)
    {
        system("cls");
        printf("            ***ALTA PERSONAS***     \n");
        place = findPlace(list, len);
        if (place == -1)
        {
            printf("Errorr, no hay mas lugar\n");
        }
        else
        {
            auxEmployee.id = *pId;
            (*pId)++;

            printf("Ingrese nombre: \n");
            scanf("%s", auxLongName);
            fflush(stdin);
            setMayus(auxLongName, 100);
            r = findError(auxLongName);
            while(r==0)
            {
                printf("Error... Ingrese nombre valido: \n");
                scanf("%s", auxLongName);
                fflush(stdin);
                r = findError(auxLongName);
            }

            strncpy(auxEmployee.name, auxLongName, sizeof(auxEmployee.name));

            printf("Ingrese apellido: \n");
            scanf("%s", auxLongLastName);
            fflush(stdin);
            setMayus(auxLongLastName, 100);
            x = findError(auxLongLastName);
            while (x == 0)
            {
                printf("Error... Ingrese un apellido valido: \n");
                scanf("%s", auxLongLastName);
                fflush(stdin);
                x = findError(auxLongLastName);
            }

            strncpy(auxEmployee.lastName, auxLongLastName, sizeof(auxEmployee.lastName));

            validarEntero(&auxSalario, "Ingrese un salario: \n", "Eror, ingrese un salario valido:\n", 2000, 10000, 10);
            auxEmployee.salary = auxSalario;

            validarEntero(&auxSector, "Ingrese el sector: \n", "Error, ingrese un sector valido:\n", 1, 10, 10);
            auxEmployee.sector = auxSector;


            addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);

            checkStatus = 0;
        }
    }


    return checkStatus;
}


int addEmployee(Employee list[], int len, int id, char name[], char lastName[], int salary, int sector)
{
    int checkStatus = -1;
    int place;

    if (list != NULL && name != NULL && lastName != NULL && salary > 0 && sector > 0 && len > 0)
    {
        place = findPlace(list, len);

        list[place].id = id;
        strcpy(list[place].name, name);
        strcpy(list[place].lastName, lastName);
        list[place].salary = salary;
        list[place].sector = sector;
        list[place].isEmpty = 0;
        checkStatus = 0;

    }

    return checkStatus;
}

int printEmployees(Employee* list, int length)
{
    int checkStatus = -1;
    int flag = 1;
    if (list != NULL && length > 0)
    {
        system("cls");
        printf("                            **** LISTA DE  PERSONAS****     \n");
        printf("-----------------------------------------------------------------------\n");
        printf("    ID          NOMBRE          APELLIDO        SALARIO         SECTOR \n");
        printf("-----------------------------------------------------------------------\n");

        for (int i = 0; i < length ; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
                flag=0;
            }

        }
        if(flag)
        {
            printf("No hay personas para mostrar\n");
        }
        checkStatus = 0;
    }
    return checkStatus;

}
void printEmployee(Employee p)
{
    printf("   %d    %10s        %10s        %5.2f          %2d\n",
           p.id,
           p.name,
           p.lastName,
           p.salary,
           p.sector
          );
}

int findEmployeeById(Employee* list, int len, int id)
{
    int checkStatus = -1;
    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 0 && list[i].id == id)
        {
            checkStatus = i;
            break;
        }
    }
    return checkStatus;
}
int removeEmployee(Employee* list, int len, int id)
{
    int checkStatus = -1;
    int location;//ubicacion del empleado a remover por id
    char confirmRemove;
    if (list != NULL && len > 0 && id > 0)
    {
        system("cls");
        printf("                            **** BAJA DE  PERSONAS****     \n\n");
        location = findEmployeeById(list, len, id);

        if (location == -1)
        {
            printf("El ID %d no esta registrado en el sistema\n", id);
        }
        else
        {
            printEmployee(list[location]);
            printf("Confirma la baja del sistema?: S o N ");
            fflush(stdin);
            scanf("%c", &confirmRemove);
            if (confirmRemove == 's')
            {
                list[location].isEmpty = 1;
                checkStatus = 0;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return checkStatus;
}

int removeSearch(Employee list[], int len)
{
    int checkStatus = -1;
    int idPerson;
    int saveReturn;//guarda retorno de remove
    if (list != NULL && len > 0)
    {
        system("cls");
        printf("                            **** BAJA DE  PERSONAS****     \n\n");
        printf("Ingrese le id: \n");
        scanf("%d", &idPerson);
        saveReturn = removeEmployee(list, len, idPerson);
        if (saveReturn == -1)
        {
            checkStatus = -1;
            printf("Hubo un error al realizar la baja");
        }

        checkStatus = 0;
    }

    return checkStatus;

}

int modifyEmployee(Employee* list, int len)
{
    int checkStatus = 0;
    int location;//ubicacion del empleado a remover por id
    int id;
    char confirmRemove = 's';
    char seguir = 's';
    char auxName[51];
    char auxLastName[51];
    int auxSalary;
    int auxSector;
    int fixName; // guarda el retorno de name en la funcion findError
    int fixLastName; // guarda el retorno de lastname en ela funcion find error


    if (list != NULL && len > 0)
    {
        system("cls");
        printf("                            **** MODIFICAR  PERSONAS****     \n\n");
        printf("Ingrese le id: \n");
        scanf("%d", &id);

        location = findEmployeeById(list, len, id);

        if (location == -1)
        {
            printf("El ID %d no esta registrado en el sistema\n", id);
        }
        else
        {
            printEmployee(list[location]);
            printf("Confirma la modificacion de datos?: S o N ");
            fflush(stdin);
            scanf("%c", &confirmRemove);
            if (confirmRemove == 's')
            {
                do
                {
                    switch(modificationMenu(list, len, location))
                    {
                    case 1:
                        printf("Ingrese nuevo Nombre: ");
                        scanf("%s",auxName);
                        fflush(stdin);
                        setMayus(auxName, 51);
                        fixName =  findError(auxName);
                        while ( fixName == 0)
                        {
                            printf("Error...Ingrese un nuevo Nombre valido: ");
                            scanf("%s",auxName);
                            fflush(stdin);
                            fixName =  findError(auxName);
                        }
                        strcpy(list[location].name, auxName);
                        break;

                    case 2:
                        printf("Ingrese nuevo Apellido: ");
                        scanf("%s",auxLastName);
                        fflush(stdin);
                        setMayus(auxLastName, 51);
                        fixLastName = findError(auxLastName);
                        while (fixLastName == 0)
                        {
                            printf("Error...Ingrese un nuevo Apellido valido: ");
                            scanf("%s",auxLastName);
                            fflush(stdin);
                            fixLastName = findError(auxLastName);
                        }
                        strcpy(list[location].lastName, auxLastName);
                        break;
                    case 3:
                        validarEntero(&auxSalary, "Ingrese un nuevo salario:\n", "Error, ingrese un nuevo salario valido:\n", 2000, 10000, 10);
                        list[location].salary = auxSalary;
                        break;
                    case 4:
                        validarEntero(&auxSector, "Ingrese un nuevo sector:\n", "Error, ingrese un nuevo sector valido:\n", 1, 10, 10);
                        list[location].sector = auxSector;
                        break;
                    case 5:
                        printf("Usted eligion Salir\n");
                        seguir = 'x';
                        break;
                    default:
                        printf("Opcion invalida, reingrese\n");
                    }
                }
                while(seguir == 's');

            }
            else
            {
                printf("Modificacion cancelada por el usuario\n");
            }

            checkStatus = 1;
        }

    }
    return checkStatus;
}

int modificationMenu(Employee list[], int len, int place)
{
    int opcion;
    system("cls");
    printf("                            **** MODIFICAR  PERSONAS****     \n\n");
    printf("------------------------------------------------------------\n");
    printf("\n Nombre: %s\n Apellido: %s\n Salario: %.2f\n Sector: %d\n", list[place].name, list[place].lastName, list[place].salary, list[place].sector);
    printf("------------------------------------------------------------\n\n");
    printf("1- Modificar Nombre\n");
    printf("2- Modificar Apellido\n");
    printf("3- Modificar Salario\n");
    printf("4- Modificar Sector\n");
    printf("5-Salir\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int sortEmployees(Employee* list, int len)
{
    int checkStatus = -1;
    Employee auxPersona;

    if (list != NULL && len > 0 )
    {
        switch(sortOrderMenu())
        {
        case 1:
            for (int i = 0; i < len -1; i++)
            {
                for (int j = i+1; j < len; j++)
                {
                    if( list[i].sector > list[j].sector ||
                            (list[i].sector == list[j].sector &&
                             strcmp(list[i].lastName, list[j].lastName)>0))
                    {
                        auxPersona = list[i];
                        list[i] = list[j];
                        list[j] = auxPersona;
                    }
                }
            }
            break;
        case 2 :
            for (int i = 0; i < len -1; i++)
            {
                for (int j = i+1; j < len; j++)
                {
                    if( list[i].sector < list[j].sector ||
                            (list[i].sector == list[j].sector &&
                             strcmp(list[i].lastName, list[j].lastName)>0))
                    {
                        auxPersona = list[i];
                        list[i] = list[j];
                        list[j] = auxPersona;
                    }
                }
            }
            break;
        default:
            printf("Opcion Invalida\n");
        }


        checkStatus = 0;
    }

    return checkStatus;
}

int sortOrderMenu()
{
    int opcion;
    printf("1- Ordenar de manera Ascendente\n");
    printf("2- Ordenar de manera Descendente\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int salaryEmployees(Employee* list, int len, float *pSalario)
{
    int checkStatus = -1;
    float auxSalary = 0;
    int contSalary = 0;

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                auxSalary += list[i].salary;
                contSalary++;
            }
        }
        checkStatus = 0;

        *pSalario = (float)auxSalary /contSalary;

    }

    return checkStatus;
}


int cobranBien(Employee* list, int len, float salario)
{
    int checkStatus = -1;
    int cont = 0;

    salaryEmployees(list,len, &salario);

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                if(list[i].salary > salario)
                {
                    cont++;
                }
            }
        }
        checkStatus = 0;
    }

    printf("La cantidad de %d personas cobran mas del promedio de salarios en total\n", cont);

    return checkStatus;
}

