#include "swapArranque.h"



int leerArchivoConfiguracion(char *ruta_archivo) {
	int devolver = 0;

	config = config_create(ruta_archivo);
	printf("Leyendo archivo de configuraciones: %s\n", ruta_archivo);

	PUERTO_ESCUCHA = config_get_int_value(config, "PUERTO_ESCUCHA");
	NOMBRE_SWAP = config_get_string_value(config, "NOMBRE_SWAP");
	CANTIDAD_PAGINAS = config_get_int_value (config, "CANTIDAD_PAGINAS");
	TAMANIO_PAGINA = config_get_int_value(config, "TAMANIO_PAGINA");
	RETARDO_COMPACTACION = config_get_int_value(config, "RETARDO_COMPACTACION");

	printf("Puerto escucha: %d\n", PUERTO_ESCUCHA);
	printf("Nombre Swap: %s\n", NOMBRE_SWAP);
	printf("Cantidad de paginas: %d\n", CANTIDAD_PAGINAS);
	printf("Tamanio de paginas: %d\n", TAMANIO_PAGINA);
	printf("Retardo compactacion: %d\n", RETARDO_COMPACTACION);

	puts("Listo.\n");

	return devolver;
}

int crearArchivoLog() {
	int devolver = 0;

	remove("logsSwap");

	puts("Creando archivo de logueo...\n");

	logs = log_create("logsSwap", "SwapLog", 0, LOG_LEVEL_TRACE);

	if (logs == NULL) {
		puts("No se pudo generar el archivo de logueo\n");
		return -1;
	}

	log_info(logs, "INICIALIZACION DEL ARCHIVO DE LOGUEO");

	puts("Listo.\n");

	return devolver;
}
