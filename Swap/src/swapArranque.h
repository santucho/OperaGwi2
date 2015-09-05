/*
 * swapArranque.h
 *
 *  Created on: 3/9/2015
 *      Author: utnso
 */

#ifndef PROCESO_SWAP_SRC_SWAPARRANQUE_H_
#define PROCESO_SWAP_SRC_SWAPARRANQUE_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sockets.h>
#include <commons/config.h>
#include <commons/log.h>

//variables config

int PUERTO_ESCUCHA, TAMANIO_PAGINA, CANTIDAD_PAGINAS, RETARDO_COMPACTACION;
char* NOMBRE_SWAP;

//recursos
t_config* config;
t_log* logs;


int leerArchivoConfiguracion(char *ruta_archivo);

int crearArchivoLog();



#endif /* PROCESO_SWAP_SRC_SWAPARRANQUE_H_ */
