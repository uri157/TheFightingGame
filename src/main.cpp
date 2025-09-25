#include "Juego.h"
#include "Fighting_Escena.h"
#include "Pantalla_principal.h"
#include "Seleccion_De_Personaje_Escena.h"

using namespace std;

int main(int argc, char *argv[]){
	Juego j(new Pantalla_principal);
	j.Jugar();
	
	return 0;
}

