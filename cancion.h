#ifndef CANCION_H
#define CANCION_ H
#include <string>
using namespace std;


struct canciones {
	char nombreA[50];
	char cantanteA[30];
	float duracionA;
	char generoA[50];
	char albumA[50];
	int numero_cancionA;

	//LISTA ENLAZADA


};

struct lista {
	char * nombre;
	char * cantante;
	float duracion;
	char * genero;
	char * album;
	int numero;
	lista *sig;
	void setSig(lista * siguiente) {
		sig = siguiente;
	}
	lista  * getSig() {
		return sig;
	}
	lista(char * nom, char * cant, float dur, char * gen, char * alb, int num) {
		nombre = new char[strlen(nom)];
		strcpy_s(nombre, strlen(nom) + 1, nom);

		cantante = new char[strlen(cant)];
		strcpy_s(cantante, strlen(cant) + 1, cant);

		genero = new char[strlen(gen)];
		strcpy_s(genero, strlen(gen) + 1, gen);

		album = new char[strlen(alb)];
		strcpy_s(album, strlen(alb) + 1, alb);

		duracion = dur;
		numero = num;
		sig = 0;
		
	}
};

class cancion {
public:
	 lista * primero, *ultimo;
	 lista * actualA;
	 lista * actualT;

	 void setActualA(lista *actA) {
		 actualA = actA;
	 }
	 lista  * getActualA() {
		 return actualA;
	 }

	 void setActualT(lista *actT) {
		 actualT = actT;
	 }
	 lista  * getActualT() {
		 return actualT;
	 }
	 float duracionTotal;

     void ingresarCanciones();//ya 
     void totalCanciones();//ya
	 void leerArchivo();//ya
	 bool esVacia();//ya
	 void agregarNodo(char * nom, char * cant, float dur, char * gen, char * alb, int num);//ya

	 void totalTiempoCanciones();

	 void imprimirTodo();//ya

	 void imprimirGenero(char gen[] );//ya
	 void imprimirAlbum(char album[]);//ya
	 void ordenarCanciones();//ya
	 cancion();
};

#endif

