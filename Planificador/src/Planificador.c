/*
 ============================================================================
 Name        : Planificador.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <commons/config.h>
#include <commons/log.h>
#include <commons/string.h>
#include "PlanificadorArranque.h"
#include "/home/utnso/workspace2/commonsPropias/src/sockets.h"

void consola();
int listenningSocket;
int socketCPU;

int main(void) {

	leerArchivoConfiguracion("configPlanificador");
	crearArchivoLog();

	listenningSocket = Escuchar(PUERTO_ESCUCHA);
	socketCPU = Aceptar(listenningSocket);
	Enviar(socketCPU, "BIENVENIDO A PLANIFICADOR");

	consola();

	Desconectar(listenningSocket);
	Desconectar(socketCPU);

	return EXIT_SUCCESS;
}

void consola() {

	//char eleccion[30];
	char* eleccion;
	char* comando;
	char* parametro;
	char c = 0;
	int longComando = 0;
	int posInicioParametro = 0;
	int consola = 1;

	while (consola) {
		posInicioParametro = 0;
		eleccion = string_new();
		comando = string_new();
		puts(
				"____________________________________________________________________\n\n"
						"Comandos disponibles: \n"
						"- 1) correr PATH \n"
						"- 2) finalizar PID \n"
						"- 3) ps \n"
						"- 4) cpu \n"
						"Ingrese un comando: ");
		scanf("%c", &c);
		//printf("Escanee %c\n",c);
		longComando++;
		eleccion = (char*) malloc( sizeof(char) * longComando );
		string_append(&eleccion, string_repeat(c,1));
		while(c != '\n'){
			scanf("%c", &c);
			//printf("Escanee %c\n",c);
			longComando++;
			eleccion = (char*) realloc(eleccion, sizeof(char) * longComando );
			string_append(&eleccion, string_repeat(c,1));
		}

		eleccion = (char*) realloc(eleccion, sizeof(char) * (longComando+1) );
		eleccion[longComando] = '\0';

		int i = 0;
		while(eleccion[i] != '\0'){
			if(eleccion[i] == ' ') posInicioParametro = i+1;
			i++;
		}
		//printf("El parametro empieza en la posicion %d\n", posInicioParametro);

		if(posInicioParametro != 0){
			parametro = string_new();
			comando = (char*) malloc( sizeof(char) * strlen(string_substring(eleccion, 0, posInicioParametro-1)));
			comando = string_substring(eleccion, 0, posInicioParametro-1);
			parametro = (char*) malloc( sizeof(char) * strlen(string_substring_from(eleccion, posInicioParametro)));
			parametro = string_substring_from(eleccion, posInicioParametro);
		}
		else{
			//printf("strlen %d \n", strlen(eleccion));
			eleccion[strlen(eleccion)-1] = '\0';
			//printf("strlen %d \n", strlen(eleccion));
			comando = (char*) malloc( sizeof(char) * strlen(eleccion) );
			comando = string_duplicate(eleccion);
		}

		if(posInicioParametro == 0){
			if(strcmp(eleccion, "ps") == 0){
				printf("3Comando a ejecutar: %s\n", comando);
			}
			else{
				if(strcmp(eleccion, "cpu") == 0){
					printf("4Comando a ejecutar: %s\n", comando);
				}
				else{
					printf("El comando (%s) ingresado no es valido \n", comando);
					eleccion[0] = '\0';
					comando[0] = '\0';
				}
			}
		}

		if(posInicioParametro != 0){
			if(strcmp(comando, "correr") == 0){
				printf("1Comando a ejecutar: %s %s\n", comando, parametro);
				Enviar(socketCPU, comando);
				Enviar(socketCPU, parametro);
			}
			else{
				if(strcmp(comando, "finalizar") == 0){
					printf("2Comando a ejecutar: %s %s\n", comando, parametro);
				}
				else{
					printf("El comando (%s %s) ingresado no es valido \n", comando, parametro);
					eleccion[0] = '\0';
					comando[0] = '\0';
					parametro[0] = '\0';
				}
			}
		}

		free(eleccion);
		free(comando);
		if(posInicioParametro != 0){
			free(parametro);
		}
	}
}
