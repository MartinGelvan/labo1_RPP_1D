/*
 * estadiaDiaria.c
 *
 *  Created on: 7 oct. 2021
 *      Author: PCNEW
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nexo.h"
#include "Inputs.h"


void estadia_inicializarArray(eEstadiaDiaria estadias[], int tam)
{
	int i;
	for (i = 0; i < tam; i++) {
		estadias[i].estadoEstadia = VACIO;
	}
}

void estadia_hardCodearEstadia(eEstadiaDiaria estadias[], int tam)
{
	int i;
	int id[] = { 100000, 100001, 100002 };
	//char nombreDuenio[][21] = { "Juan", "Lucas", "Marta" };
	//int telefonoContacto[] = { 1565745216, 1587454125, 1584213768 };
	int idPerro[] = { 7000, 7001, 7002 };
	int idDuenio[] = {30000, 30001, 30002};
	int fechaDia[]= {1,13,4};
	int fechaMes[]= {4,11,2};
	int fechaAnio[]={2020,2030,2021};

	for (i = 0; i < 3; i++) {
		estadias[i].id = id[i];
		//strcpy(estadias[i].nombreDuenio, nombreDuenio[i]);
		//estadias[i].telefonoContacto = telefonoContacto[i];
		estadias[i].idPerro = idPerro[i];
		estadias[i].idDuenio = idDuenio[i];
		estadias[i].fecha.dia = fechaDia[i];
		estadias[i].fecha.mes = fechaMes[i];
		estadias[i].fecha.anio = fechaAnio[i];
		estadias[i].estadoEstadia = OCUPADO;
	}
}

int estadia_buscarEspacioLibre(eEstadiaDiaria estadias[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int estadia_buscarPorId(eEstadiaDiaria estadias[], int tam, int id)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO && estadias[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}



void estadia_mostrarUno(eEstadiaDiaria estadia)
{
	printf("%-15s %-15s %-5s %-5s %-10s %-15s\n","ID ESTADIA","ID DUE�O","DIA","MES","A�O","ID PERRO");
	printf("������������������������������������������������������������������������������������������\n");
	printf("%-15d %-15d %-5d %-5d %-10d %-15d\n",estadia.id, estadia.idDuenio, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio, estadia.idPerro);
}

void estadia_mostrarTodos(eEstadiaDiaria estadias[], int tam)
{
	int i;
	printf("\nMostrando lista de estadias...\n\n");
	printf("������������������������������������������������������������������������������������������\n");
	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO)
		{
			estadia_mostrarUno(estadias[i]);
		}
	}
	printf("\n");
}
/*
void estadia_mostrarUno(eEstadiaDiaria estadia)
{
	printf("%-15d %-20s %-20d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto);
}
*/
/*
void estadia_mostrarTodos(eEstadiaDiaria estadias[], int tam)
{
	int i;
	printf("\nMostrando lista de estadias...\n\n");
	for(i=0; i<tam; i++)
	{
		if(estadias[i].estadoEstadia == OCUPADO)
		{
			estadia_mostrarUno(estadias[i]);
		}
	}
	printf("\n");
}
*/
/*
int estadia_cancelarEstadia(eEstadiaDiaria estadias[], int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el ID de la estadia a cancelar (100000-170000): ",
				"Reingrese el ID de la estadia a cancelar (100000-170000): ", 100000, 170000);
	index = estadia_buscarPorId(estadias, tam, idIngresado);

	if(index != -1)
	{
		printf("\nEstadia a cancelar:\n\n%-5s %-20s %-20s\n", "ID", "NOMBRE DUENIO", "TELEFONO CONTACTO");
		printf("\n���������������������������������������������������������\n");
		estadia_mostrarUno(estadias[index]);
		printf("\n���������������������������������������������������������\n");

		if(pedirConfirmacion("\nIngrese 's' para confirmar la baja del producto: ")==0)
		{
			estadias[index].estadoEstadia = VACIO;
			printf("\nEstadia %d cancelada exitosamente\n\n", estadias[index].id);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la cancelacion de la estadia.\n\n");
		}
	}
	else
	{
		printf("\nError, estadia no encontrada...\n\n");
	}

	return retorno;
}

*/
