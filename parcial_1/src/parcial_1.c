/*
 ============================================================================
 Name        : parcial_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesCensista.h"
#include "funcionesVivienda.h"
#include "utn_get.h"

#define CANT 3

int main(void) {

	setbuf(stdout,NULL);

	int opcion=0;
	int flag=0;
	int idIngresado;
	int indiceMayorCensista=2;
	vivienda listaViviendas[CANT];
	censista listaCensistas[] = {{100, "Ana", 34, 12032345},{101, "Juan", 24, 430154678}, {102, "Sol", 47, 590237487}};

	if(iniVivienda(listaViviendas, CANT)==-1){

		printf("ERROR");
		return -1;
	}

	while(opcion!=6)
	{
		printf("\n1-Altas\n"
				"2-Modificar\n"
				"3-Baja\n"
				"4-Informar Viviendas\n"
				"5-Informar Censistas\n"
				"6-Finalizar\n");

		printf("Ingrese el numero de opcion");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:

				if(buscarIndiceVacioV(listaViviendas, CANT)!=-1)
				{

					if(cargarVivienda(listaViviendas, CANT, listaCensistas, 3)!=-1)
					{
						flag=1;
					}else{
						printf("Error en la carga de datos");
					}
				}else{
					printf("Error, es posible que la base de datos este llena");
				}

				break;
			case 2:




				if(flag!=0){
					if(mostrarViviendas(listaViviendas, CANT)!=-1 &&
					utn_getInt(&idIngresado, "Ingrese el ID de la vivienda que desea modificar", "Por favor ingrese un ID valido", 9999, 2000, 100)!=-1 &&
					buscarViviendaPorID(listaViviendas,CANT,idIngresado)!=-1)
					{
						modificarVivienda((*(listaViviendas+buscarViviendaPorID(listaViviendas,CANT,idIngresado))), &listaViviendas[buscarViviendaPorID(listaViviendas,CANT,idIngresado)],listaCensistas,3);
					}else{
						printf("Error en la modificacion, puede que no se haya encontrado el ID ingresado");
						break;
					}
				}else{

					printf("\n Primero ingrese una vivienda, por favor");
				}


				break;
			case 3:

				if(flag!=0){

					if(mostrarViviendas(listaViviendas, CANT)!=-1 &&
					   utn_getInt(&idIngresado, "Ingrese el ID de la vivienda que desea modificar", "Por favor ingrese un ID valido", 9999, 2000, 100)!=-1 &&
					   buscarViviendaPorID(listaViviendas,CANT,idIngresado)!=-1)
					{
						bajarVivienda(listaViviendas,CANT,idIngresado);
					}

					if(estaCargado(listaViviendas, CANT) == 0){
						flag=0;
					}
				}else{

					printf("\n Primero ingrese una vivienda, por favor");

				}

				break;
			case 4: //Opcion 4 Informa los pasajeros

				if(flag!=0){

					ordenarVivienda(listaViviendas, CANT);
					mostrarViviendas(listaViviendas, CANT);


				}else{

					printf("\n Primero ingrese una vivienda, por favor");

				}



				break;
			case 5:
				mostrarViviendasPorCensistas(listaCensistas, 3,listaViviendas, CANT, &indiceMayorCensista);
				printf("El censista con mas viviendas censadas es: %s", ((*(listaCensistas+indiceMayorCensista)).nombre));

				break;

			case 6:

				printf("Programa Finalizado");
				break;

			default:
				printf("Por favor ingrese una opcion valida");
				break;

		}
	}

	return 0;

}


