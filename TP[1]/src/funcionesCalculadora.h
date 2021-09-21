/*
 * funcionesCalculadora.h
 *
 *  Created on: 21 sep. 2021
 *      Author: renzo
 */

#ifndef FUNCIONESCALCULADORA_H_
#define FUNCIONESCALCULADORA_H_


/** \brief recibe el valor de cada variable y los suma
 * \param valida la operacion
 * \param cacula el resultado
 * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float sumarNumeros(float x, float y, float* pSumarNumeros);
/** \brief recibe el valor de las dos variables y los resta
 *
 * \param valida la operacion
 * \param calcula el resultado
 * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float restarNumeros(float x, float y, float* pRestarNumeros);
/** \brief recibe el valor de las dos variables y los multiplica
 *
 * \param valida la operacion
 * \param calcula el resultado
 * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float multiplicarNumeros(float x, float y, float* pMultiplicacionNumeros);
/** \brief recibe el valor de las dos variable y hace la division
 *
 * \param valida que no divida por cero
 * \param calcula el resultado
  * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float dividirNumeros(float x, float y, float* pResDiv);
/** \brief recibe el valor de la variable X y calcula el factorial
 *
 * \param valida que el numero sea negativo o mayor a doce porque despues del 12 se desborda por el tipo de variable utilizada
 * \param calcula el resultado del factorial
 * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float factorialOperandoX(float x, float *pResFactorialX);
/** \brief recibe el valor de la variable Y y calcula el factorial
 *
 * \param valida que el numero sea negativo o mayor a doce porque despues del 12 se desborda por el tipo de variable utilizada
 * \param calcula el resultado del factorial
 * \param pasa el valor de la operacion por un puntero
 * \return retorna 1 si la operacion pudo ser calculada
 *
 */

float factorialOperandoY(float y, float *pResFactorialY);

#endif /* FUNCIONESCALCULADORA_H_ */
