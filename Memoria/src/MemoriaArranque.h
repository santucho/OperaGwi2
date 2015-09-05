/*
 * MemoriaArranque.h
 *
 *  Created on: 3/9/2015
 *      Author: utnso
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sockets.h>
#include <commons/config.h>
#include <commons/log.h>

#ifndef MEMORIAARRANQUE_H_
#define MEMORIAARRANQUE_H_


int leerArchivoConfiguracion(char *ruta_archivo);

int crearArchivoLog();

//recursos
t_config* config;
t_log* logs;

//variables config
int PUERTO_ESCUCHA, PUERTO_SWAP, MAXIMO_MARCOS_POR_PROCESO, CANTIDAD_MARCOS, TAMANIO_MARCO, ENTRADAS_TLB, RETARDO;
char* IP_SWAP;
char* TLB_HABILITADA;

#endif /* MEMORIAARRANQUE_H_ */
