#include "Controles_Player_2.h"
#include <SFML/Window/Keyboard.hpp>

#include <fstream>
using namespace std;
using namespace sf;

Controles_Player_2::Controles_Player_2() {
	ifstream archi("Controles_p2.poo",ios::binary);
	archi.read(reinterpret_cast<char*>(&Caminar_Izquierda),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Caminar_Derecha),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Saltar),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Atacar),sizeof(Keyboard::Key));
	archi.close();
}


Controles_Player_2::~Controles_Player_2() {
	
}
