
#ifndef VALIDARENTERO_H_
#define VALIDARENTERO_H_

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int myGets(char* cadena, int longitud);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int esNumerica(char* cadena);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int getInt (int* pResultado);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int validarEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* VALIDARENTERO_H_ */
