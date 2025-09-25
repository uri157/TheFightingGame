#ifndef CONTROLES_PLAYER_1_H
#define CONTROLES_PLAYER_1_H
#include "Controles.h"
#include <fstream>
#include <SFML/Window/Keyboard.hpp>
using namespace std;
using namespace sf;

//Se encarga de almacenar la informacion de los controles del Player 1 y brindarla a quien se lo solicite en caso de ser necesario

class Controles_Player_1 : public Controles {
public:
	Controles_Player_1();
	~Controles_Player_1();
};

#endif

