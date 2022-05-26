/*
 * funcionesCensista.h
 *
 *  Created on: 25 May 2022
 *      Author: Santiago
 */

#ifndef FUNCIONESCENSISTA_H_
#define FUNCIONESCENSISTA_H_


struct
{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}typedef censista;

int buscarCensistaPorID(censista* lista, int len,int id);


void mostrarCensista(censista censistaIngresado, int showHeader);

int mostrarCensistas(censista* lista, int length);



#endif /* FUNCIONESCENSISTA_H_ */
