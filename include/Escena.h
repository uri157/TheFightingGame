#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu_General.h"

using namespace std;
using namespace sf;
class Menu_General;
class Juego;

class Escena {
	
public:
	Escena();
	virtual void Draw(RenderWindow &w)=0;
	virtual void Cambiar_menu(Menu_General *nuevo_menu)=0;
	virtual void Actualize(Juego &j)=0;
	virtual ~Escena()=0;
};

#endif

