
#ifndef VALIDARCADENA_H_
#define VALIDARCADENA_H_

/** \brief function that find an incompatible data type in a string
 *
 * \param  char vec
 * \return int return 0 if error or 1 if ok
 *
 */

int findError(char vec[]);

/** \brief funciton that set mayus to the first letter of a name or lastName
 *
 * \param char vec
 * \param  large of vec
 * \return  int return 0 if errorr or 1 if ok
 *
 */

int setMayus(char vec[], int len);

#endif /* VALIDARCADENA_H_ */
