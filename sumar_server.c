/* Este codigo es el mas corto y es el que especifica que es lo que hace el servicio/funcion
ofrecida por el servidor, en este caso solo es declarada una funcion que suma 2 parametros
que se encuentran en una estructura y las variables no despispistan al programador ya que se entiende
su funcion dentro del programa

*/

#include "sumar.h" //LLamada a la libreria con inf. del IDL y las interfaces

int *
suma_1_svc(dupla_int *argp, struct svc_req *rqstp)
{
	static int  result;//Declaracion de la variable que almecena el resultado de la funcion

	printf("Server is working\n");//Mensaje para comprobar que la funcion se llamo correctamente
	printf("parameters: %d, %d\n",argp->a,argp->b);//Impresion de los parametros introducidos por el Usuario
	result = argp->a + argp->b; //Operacion de suma entre los 2 numeros que introdujo el usuario
	printf("returning: %d\n", result); //Impresion del resultado del lado del servidor
	return &result;//Envio del resultado al cliente.
}
