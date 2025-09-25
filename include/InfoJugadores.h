#ifndef INFOJUGADORES_H
#define INFOJUGADORES_H
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

//Se encarga de obtener la informacion de los jugadores (nombres, historicos, etc), actualizar los historicos y brindarle esta info a las clases que lo requieran 

class InfoJugadores {
	string Nombre_Player_1;
	string Nombre_Player_2;
	int Ganadas_Player_1;
	int Perdidas_Player_1;
	int Ganadas_Player_2;
	int Perdidas_Player_2;
public:
	InfoJugadores();
	string Ver_Nombre_Player_1();
	string Ver_Nombre_Player_2();
	int Ver_Ganadas_Player_2();
	int Ver_Ganadas_Player_1();
	int Ver_Perdidas_Player_2();
	int Ver_Perdidas_Player_1();
	void Actualizar_Nombres();//Recibe los nombres desde un archivo de texto y los almacena en las variables de la clase, listas para ser consultadas por la clase que lo requiera
	void Actualizar_Historial_Post_Fight(int Ganador);//Luego de la batalla se llama a esta clase que actualiza el historico de los participantes
	void Obtener_Historial_Jugadores();//Obtiene los historicos de los jugadores desde un archivo binario y organiza la informacion en las variables de la clase, en caso de ser la primera participacion de uno o ambos jugadores los agrega al historico
	~InfoJugadores();
};

#endif

