/* Este es el codigo principal desde la computadora que solicita algun servicio/funcion
Que ofrezca el servidor en cuestion. En este codigo hay que mencionar que es compresible
la mayor parte del codigo y sus variables


*/

#include "sumar.h" //LLamada a una libreria que contiene informacion del archivo IDL y las interfaces


void
suma_prog_1(char *host,int a,int b) //Funcion principal para llamar al servicio
{
	CLIENT *clnt; //cliente que se conceta al servidor
	int  *result_1; //Variable entera que almacena el resultado a la llamada del servicio
	dupla_int  suma_1_arg; //Estructura que almacena 2 variables enteras


#ifndef	DEBUG //Creacion del cliente
	clnt = clnt_create (host, SUMA_PROG, SUMA_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	suma_1_arg.a = a;//Variables del usuario almacenadas en los parametros de la estructura
	suma_1_arg.b = b;
	result_1 = suma_1(&suma_1_arg, clnt); //Llamada a la funcion del lado servidor
	if (result_1 == (int *) NULL) { //Comprobacion a que la llamada tuvo algun error
		clnt_perror (clnt, "call failed"); //error, y el cliente implementa un error
	}else{
		printf("result = %d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt); //Destruccion del cliente
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;//Declaracion de las 2 variables para la suma y el host
	int a, b;
	if (argc != 4) {//Comprobacion que se esten ingresando todos los parametros
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	if ((a = atoi(argv[2])) == 0 && *argv[2] != '0') {//El valor es valido
		fprintf(stderr, "invalid value: %s\n", argv[2]);
		exit(1); //Error, saliendo del codigo
	}
	if ((b = atoi(argv[3])) == 0 && *argv[3] != '0') {//El valor es valido
		fprintf(stderr, "invalid value: %s\n", argv[3]);
		exit(1);
	}
	suma_prog_1(host, a, b); //llamada ala funcion principañ
	exit(0);
	}
