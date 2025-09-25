#ifndef MENU_GENERAL_H
#define MENU_GENERAL_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"


using namespace std;
using namespace sf;

class Juego;

class Menu_General{
public:
	Menu_General();
	virtual void Actualize(Juego &j)=0;
	virtual void Draw(RenderWindow &w)=0;
	virtual ~Menu_General()=0;
};

#endif

