/*
 * funcionesCensista.c
 *
 *  Created on: 25 May 2022
 *      Author: Santiago
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn_get.h"
#include "funcionesVivienda.h"
#include "funcionesCensista.h"

int buscarCensistaPorID(censista* lista, int len,int id)
{
	int retorno = -1;
	if (lista != NULL && len > 0 && id > 0) {
		for (int i = 0; i < len; i++) {
			if ((lista+i)->legajoCensista == id) {
				retorno = i;
				break;//esta funcion busca todos los espacios del array hasta encontrar un id igual al que le dimos, cuando lo encuentra lo guarda como retorno y usamos break para parar de iterar
			}
		}
	}
	return retorno;
}

void mostrarCensista(censista censistaIngresado, int showHeader)
{

	if (censistaIngresado.legajoCensista != 0){

		  // usamos showHeader para saber si debemos mostrar un encabezado, o si este se mostrara a traves de la funcion printPassenger
		  if(showHeader==1){
				printf("\n+-----+--------------------+----+---------+\n");
				printf("|%-5s|%-20s|%-4s|%-9s|\n","ID", "Nombre", "Edad", "Telefono");
				printf("+-----+--------------------+----+---------+\n");

		  }
		  //hacemos un printf de una sola linea
		  printf("|%-5d|%-20s|%-4d|%-9d|\n", censistaIngresado.legajoCensista, censistaIngresado.nombre,censistaIngresado.edad ,censistaIngresado.telefono);
		  printf("+-----+--------------------+----+---------+\n");
	}
}

int mostrarCensistas(censista* lista, int length)
{
	int retorno = -1;
	if (lista != NULL && length > 0) {

		//La funcion muestra un encabezado por lo cual a show passenger le vamos a pasar un 0 para que no lo muestre en todas las iteraciones
		printf("\n+-----+--------------------+----+---------+\n");
		printf("|%-5s|%-20s|%-4s|%-9s|\n","ID", "Nombre", "Edad", "Telefono");
		printf("+-----+--------------------+----+---------+\n");

		for (int i = 0; i < length; i++) {

			if((*(lista+i)).legajoCensista!=0){

				mostrarCensista((*(lista+i)),0); //utilizamos un for para buscar todos los espacion del array en donde isEmpty sea 0, y por cada uno que encuentra le pasamos los datos a showPassenger para que lo muestre
			}
		}

		retorno = 0;
	}
	return retorno;
}

