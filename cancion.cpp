#include "cancion.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;




cancion::cancion() {
	this->primero = 0;
	this->ultimo = 0;
	this ->actualA = 0;
	this->actualA = 0;
	this->duracionTotal = 0;
}

bool cancion :: esVacia() {

	return primero == 0;
}
void cancion::agregarNodo(char * nom, char * cant, float dur, char * gen, char * alb, int num) {

	lista * nuevo2 = new lista(nom,cant,dur,gen,alb,num);

	if (esVacia()) {
		primero = nuevo2;
		ultimo = nuevo2;
	}
	else {
		ultimo->setSig(nuevo2);
		ultimo = nuevo2;
	}
	/*cout << "Agregado a la lista Correctamente";*/
}
void cancion::leerArchivo() {
	ifstream cancionesIn("album_reproduccion.dat", ios::in | ios::binary);

	if (!cancionesIn) {
		return;
	}

	canciones temporal;
	cancionesIn.seekg(0, ios::beg);//seek and get
	cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(canciones));

	while (!cancionesIn.eof()) {
			/*cout << "Cancion{ nombre: " << temporal.nombreA << ", Numero de Cancion: " << temporal.numero_cancionA << ", Cantante: " << temporal.cantanteA
					<< ", Duracion: " << temporal.duracionA << ", Genero: " << temporal.generoA << ", Album: " << temporal.albumA << "}" << endl;*/

			char * nom = temporal.nombreA;
			char * cant = temporal.cantanteA;
			char * gen = temporal.generoA;
			char * alb = temporal.albumA;

			agregarNodo(nom, cant, temporal.duracionA, gen, alb, temporal.numero_cancionA);

			cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(canciones));

	}

	cancionesIn.close();
}

void cancion::ingresarCanciones() {

	ofstream cancionesOut("album_reproduccion.dat", ios::out | ios::app | ios::binary);

	if (!cancionesOut) {

		cout << "Error al intetnar abrir el archivo album_reproduccion.dat";
		return;
	}

	canciones nuevo;

	cout << " ----------------------->INGRESO DE CANCIONES<-------------------------------" << endl;
	cout << "Ingrese el nombre de la cancion" << endl;
	cin >> nuevo.nombreA;
	cout << "Ingrese el  cantante" << endl;
	cin >> nuevo.cantanteA;
	cout << "Ingrese el duracion" << endl;
	cin >> nuevo.duracionA;
	cout << "Ingrese el genero" << endl;
	cin >> nuevo.generoA;
	cout << "Ingrese el album" << endl;
	cin >> nuevo.albumA;
	cout << "Ingrese el numero de cancion" << endl;
	cin >> nuevo.numero_cancionA;


	char * nom = nuevo.nombreA;
	char * cant = nuevo.cantanteA;
	char * gen = nuevo.generoA;
	char * alb = nuevo.albumA;

	agregarNodo(nom, cant, nuevo.duracionA, gen, alb, nuevo.numero_cancionA);

	cancionesOut.seekp(0, ios::end);//seek and put
	cancionesOut.write(reinterpret_cast<const char*>(&nuevo), sizeof(canciones));

	cancionesOut.close();

}

void cancion::totalCanciones() {

	ifstream cancionesIn("album_reproduccion.dat", ios::in | ios::binary);

	if (!cancionesIn) {

		cout << "Error al intetnar abrir el archivo empleados.dat";
		return;
	}
	cancionesIn.seekg(0, ios::end);
	int tamaño = cancionesIn.tellg();
	int cant_canciones = tamaño / sizeof(canciones);

	cout << "El numero de canciones en el archivo son: " << cant_canciones << endl;
}

void  cancion::imprimirGenero(char genero[]) {
	lista * temp = primero;
	cout << "SE IMPRIME CANCIONES POR GENERO" << endl;
	while (temp != 0) {
		if (strcmp(temp->genero , genero)==0) {
			cout << "Cancion{ nombre: " << temp->nombre << ", Numero de Cancion: " << temp->numero << ", Cantante: " << temp->cantante
				<< ", Duracion: " << temp->duracion << ", Genero: " << temp->genero << ", Album: " << temp->album << "}" << endl;
		}
		temp = temp->getSig();
	}

}
void  cancion::imprimirAlbum(char album[]) {
	lista * temp = primero;
	cout << "SE IMPRIME CANCIONES POR ALBUM" << endl;
	while (temp != 0) {
		if (strcmp(temp->album, album) == 0) {
			cout << "Cancion{ nombre: " << temp->nombre << ", Numero de Cancion: " << temp->numero << ", Cantante: " << temp->cantante
				<< ", Duracion: " << temp->duracion << ", Genero: " << temp->genero << ", Album: " << temp->album << "}" << endl;
		}
		temp = temp->getSig();
	}

}

void cancion::imprimirTodo() {
	lista * temp = primero;
	cout << "SE IMPRIME TODAS LAS CANCIONES DENTRO DEL ARCHIVO" << endl;
	while (temp != 0) {
			cout << "Cancion{ nombre: " << temp->nombre << ", Numero de Cancion: " << temp->numero << ", Cantante: " << temp->cantante
				<< ", Duracion: " << temp->duracion << ", Genero: " << temp->genero << ", Album: " << temp->album << "}" << endl;
		temp = temp->getSig();
	}

}

void cancion::totalTiempoCanciones() {
	lista * temp = primero;
	while (temp != 0) {
		duracionTotal = duracionTotal + temp->duracion;
		temp = temp->getSig();
	}

	cout << "La duracion total de todas las canciones almacenadas es: " << duracionTotal << endl;
}

void cancion::ordenarCanciones() {
	lista * actual = primero;

	while (actual != 0) {
		lista * despues = actual->getSig();

		while (despues != NULL) {
			if (actual->numero > despues->numero) {
				//numero
				int num = despues->numero;
				despues->numero = actual->numero;
				actual->numero = num;
				//album
				char album[50];
				char * alb = album;

				alb = despues->album;
				despues->album = actual->album;
				actual->album = alb;
				//genero
				char genero[50];
				char * gen = genero;

				gen = despues->genero;
				despues->genero = actual->genero;
				actual->genero = gen;
				//duracion
				float dur = despues->duracion;
				despues->duracion = actual->duracion;
				actual->duracion = dur;
				//cantante
				char cantante[50];
				char * cant = cantante;

				cant = despues->cantante;
				despues->cantante = actual->cantante;
				actual->cantante = cant;
				//nombre
				char nombre[50];
				char * nom = nombre;

				nom = despues->nombre;
				despues->nombre = actual->nombre;
				actual->nombre = nom;

			}
			despues = despues->getSig();
		}
		actual = actual->getSig();
	}
}


//void cancion::ordenarCanciones() {
//	lista * actual = primero;
//	lista * temp = actual->getSig();
//	
//	while (temp != 0) {
//		//cout << "entro while" << endl;
//		if (actual->numero > temp->numero) {
//			//cout << "entro if" << endl;
//			actual->setSig(temp->getSig());
//			temp->setSig(actual);
//
//			actual = temp->getSig();
//			temp = temp->getSig()->getSig();
//		}
//		else {
//			actual = actual->getSig();
//			temp = temp->getSig();
//		}
//
//	}
//	//cout << "aqui termina";
//}























//lista * temp = primero;
//lista * aux = NULL;
//lista * nodo;
//
//while (temp->getSig() != 0) {
//	cout << "entro al primer while" << endl;
//	aux = temp->getSig();
//	setActualA(aux);
//	setActualT(temp);
//
//	while (aux != NULL) {
//		cout << "entro al segundo while" << endl;
//		cout << "actualT->num" << getActualT()->numero << endl;
//		cout << "actualA->num" << getActualA()->numero << endl;
//		if (getActualT()->numero >= getActualA()->numero) {
//			nodo = getActualA();
//			setActualA(getActualT());
//			setActualT(nodo);
//			cout << "entro al if" << endl;
//
//		}
//		aux = aux->getSig();
//	}
//	temp = temp->getSig();
//}









































//void Canciones::imprimirGenero(char genero[]) {
//	ifstream cancionesIn("album_reproduccion.dat", ios::in | ios::binary);
//
//	if (!cancionesIn) {
//
//		cout << "Error al intetnar abrir el archivo album_reproduccion.dat";
//		return;
//	}
//
//	cancion temporal;
//	cout << "**----------------------------------IMPRIMIR CANCIONES POR GENERO**----------------------------" << endl;
//
//	cancionesIn.seekg(0, ios::beg);//seek and get
//	cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(cancion));
//
//	while (!cancionesIn.eof()) {
//
//		if (temporal.genero == genero) {
//		cout << "Cancion{ nombre: " << temporal.nombre << ", Numero de Cancion: " << temporal.numero_cancion << ", Cantante: " << temporal.cantante
//			<< ", Duracion: " << temporal.duracion << ", Genero: " << temporal.genero << ", Album: " << temporal.album << "}" << endl;
//		cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(cancion));
//	    }
//		cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(cancion));
//	}
//
//	cancionesIn.close();
//
//}
//void Canciones::imprimirCancionesdeAlbum(char * album) {
//	ifstream cancionesIn("album_reproduccion.dat", ios::in | ios::binary);
//
//	if (!cancionesIn) {
//
//		cout << "Error al intetnar abrir el archivo album_reproduccion.dat";
//		return;
//	}
//
//	cancion temporal;
//	cout << "**----------------------------------IMPRIMIR CANCIONES POR ALBUM**----------------------------" << endl;
//
//	cancionesIn.seekg(0, ios::beg);//seek and get
//	cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(cancion));
//
//	while (!cancionesIn.eof()) {
//
//		if (temporal.album == album){
//			cout << "Cancion{ nombre: " << temporal.nombre << ", Numero de Cancion: " << temporal.numero_cancion << ", Cantante: " << temporal.cantante
//			<< ", Duracion: " << temporal.duracion << ", Genero: " << temporal.genero << ", Album: " << temporal.album << "}" << endl;
//		}
//		cancionesIn.read(reinterpret_cast<char*>(&temporal), sizeof(cancion));
//	}
//
//	cancionesIn.close();
//
//}
