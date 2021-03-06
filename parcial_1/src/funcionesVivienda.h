/*
 * funcionesVivienda.h
 *
 *  Created on: 25 May 2022
 *      Author: Santiago
 */

#ifndef FUNCIONESVIVIENDA_H_
#define FUNCIONESVIVIENDA_H_

#include "funcionesCensista.h"

struct
{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
}typedef vivienda;

int iniVivienda(vivienda* lista, int len);



int cargarVivienda(vivienda* listaV, int lenV, censista* listaC, int lenC);


int buscarViviendaPorID(vivienda* lista, int len,int id);


int bajarVivienda(vivienda* lista, int len, int id);



int buscarIndiceVacioV (vivienda* lista, int len);



int ordenarVivienda(vivienda* lista, int len);


void mostrarVivienda(vivienda viviendaIngresada, int showHeader);


int mostrarViviendas(vivienda* lista, int length);



int modificarVivienda(vivienda viviendaIngresada, vivienda *viviendaModificada, censista* listaC, int lenC);


int estaCargado(vivienda* lista, int len);

int mostrarViviendasPorCensista(censista censistaIngresado,vivienda* listaV, int lenV, int* contadorCargado);

int mostrarViviendasPorCensistas(censista* listaC, int lenC,vivienda* listaV, int lenV, int* indiceMayorVporC);

#endif /* FUNCIONESVIVIENDA_H_ */
