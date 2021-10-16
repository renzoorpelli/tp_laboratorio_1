
#ifndef VALIDARENTERO_H_
#define VALIDARENTERO_H_

/** \brief lee el stdfin hasta encontrar un '\n' o hasta q se haya copiado en cadena un maximo de longityd - 1
 *
 * \param pResultado puntero al espacio en memoria donde se copia la cadena obtenida
 * \param longitud define el tamaño de la cadena
 * \return retorna 0 si esta ok y -1 si hay un error
 *
 */

int myGets(char* cadena, int longitud);
/** \brief verifica si la cadena ingresa es numerica
 *
 * \param cadena de caracteres
 * \return retorna 1 si es true o 0 si es falso
 *
 */

int esNumerica(char* cadena);
/** \brief
 *
 * \param pResultado punterro al espacio de memoria donde se dejara el resultado de la funcion
 * \return retorna 0 si esta todoOk o -1 si surgio un error
 *
 */

int getInt (int* pResultado);
/** \brief solicita un numero, despues de verificarlo devuelve el resultado
 *
 * \param pResultado puntero al espacio de momoria donde se dejar el resultado
 * \param mensaje es el mensaje que se mostrara
 * \param mensajeError es el mensaje que se mostrarar si el numero ingresado es incorrecto
 * \param minimo es el numero minimos a ser aceptado
 * \param maximo es el numero maximo a ser aceptado
 * \return retorna 0 si se obtuvo o -1 si hubo un error
 *
 */

int validarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* VALIDARENTERO_H_ */
