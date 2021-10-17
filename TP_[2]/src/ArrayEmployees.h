
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} typedef Employee;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees (Employee *list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

int findPlace(Employee *list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary,int sector);

int newEmployee(Employee list[], int len, int* pId);
/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee* list, int length);
void printEmployee(Employee p);


/** \brief function that give to removeEmployee the id to search
 *
 * \param employee list
 * \param len
 * \return  int -1 if error int 0 if ok
 *
 */

int removeSearch(Employee list[], int len);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len, int id);

/** \brief function that helps to modify any data about the employees
 *
 * \param employee list
 * \param int len
 * \return int -1 if error 0 if ok
 *
 */

int modifyEmployee(Employee* list, int len);
/** \brief  funciton that show the menu of option
 *
 * \param  employee list
 * \param  int len
 * \param  int place of employee
 * \return int -1 if error or int 0 if ok
 *
 */

int modificationMenu(Employee list[], int len, int place);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len);

/** \brief show opcions to choose the typer of order
 *
 * \return  the opcion choosed
 *
 */

int sortOrderMenu();

/** \brief function that acumulate the salary of the employees
 *
 * \param Employe list
 * \param  len
 * \param  pointer of salary
 * \return -1 if errpr 0 if ok
 *
 */

int salaryEmployees(Employee* list, int len, float *pSalario, float *pTotalSalario);

/** \brief function that acumulate the salary and show how many employees have a good salary
 *
 * \param employee list
 * \param len
 * \param salary
 * \return -1 if error 0 if ok
 *
 */


int cobranBien (Employee* list, int len, float salario, float totalSalario);


#endif /* ARRAYEMPLOYEES_H_ */
