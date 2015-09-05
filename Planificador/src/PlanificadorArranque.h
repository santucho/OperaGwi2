/*
 * PlanificadorArranque.h
 *
 *  Created on: 2/9/2015
 *      Author: utnso
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sockets.h>
#include <commons/config.h>
#include <commons/log.h>


#ifndef PLANIFICADORARRANQUE_H_
#define PLANIFICADORARRANQUE_H_

int leerArchivoConfiguracion(char *ruta_archivo);

int crearArchivoLog();

//recursos
t_config* config;
t_log* logs;

//variables config
int PUERTO_ESCUCHA, QUANTUM;
char* ALGORITMO_PLANIF;

#endif /* PLANIFICADORARRANQUE_H_ */
