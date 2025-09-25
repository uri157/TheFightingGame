#ifndef MENU_SELECCION_PERSONAJE_H
#define MENU_SELECCION_PERSONAJE_H
#include "Efectos_de_sonido_menus.h"
#include <SFML/System/Clock.hpp>
#include "Juego.h"

using namespace std;
using namespace sf;

class Menu_Seleccion_Personaje {
	bool seleccion_en_curso_p1=true,seleccion_en_curso_p2=true;
	Efectos_de_sonido_menus sonido;
	Clock seleccion_p1_clock, seleccion_p2_clock;
	int personaje_player_1=0,personaje_player_2=1;//Estas variables almacenan el codigo de luchador que seleccione cada jugador
public:
	Menu_Seleccion_Personaje();
	void Actualize (Juego & j);
	void m_Seleccion_De_Personaje_Player_1();//Se encarga de el proceso de seleccion del "Player 1"
	void m_Seleccion_De_Personaje_Player_2();//Se encarga de el proceso de seleccion del "Player 2"
	int Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_1();//Devuelve el codigo de luchador parcialmente seleccionado por el player 1
	int Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_2();//Devuelve el codigo de luchador parcialmente seleccionado por el player 2
	~Menu_Seleccion_Personaje();
};

#endif

