
#include <iostream>
#include "cancion.h"
using namespace std;


int main() {

	char album[50];
	char genero[50];
	int cont=0;

	cancion can;
	can.leerArchivo();

	cout << "--------------------------->BIENVENIDO<----------------------------------" << endl;

	do {
		can.ingresarCanciones();
		cont++;
	} while (cont <= 5);

	can.totalCanciones();
	can.ordenarCanciones();
	cout << "----------------------------------------------------------------" << endl;
	cout << "Ingrese el Album :" << endl;
	cin >> album;
	can.imprimirAlbum(album);
	cout << "----------------------------------------------------------------" << endl;
	cout << "Ingrese el genero :" << endl;
	cin >> genero;
	can.imprimirGenero(genero);

	cout << "----------------------------------------------------------------" << endl;
	can.imprimirTodo();
	cout << "----------------------------------------------------------------" << endl;
	can.totalTiempoCanciones();

	system("pause");
}