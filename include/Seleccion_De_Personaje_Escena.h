#ifndef SELECCION_DE_PERSONAJE_ESCENA_H
#define SELECCION_DE_PERSONAJE_ESCENA_H
#include "Escena.h"
#include "Battleground.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include "Efectos_de_sonido_menus.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Menu_Seleccion_Personaje.h"


using namespace std;
using namespace sf;

//Esta clase se encarga de sostener el Menu de seleccion de personaje, ademas de realizar el dibujado del mismo y de la escena

class Seleccion_De_Personaje_Escena : public Escena {
	Battleground battleground;
	Texture Personajes_Texturas[2];
	Texture Personajes_Seleccion_Texturas_Izquierda[2];
	Texture Personajes_Seleccion_Texturas_Derecha[2];
	Texture Recuadros_Seleccion_Texturas[2];
	Font m_font;
	Text Escape_Text;
	Sprite Recuadros_Seleccion_Sprites[2];
	Sprite Personajes_Seleccion_Sprites_Izquierda[2];
	Sprite Personajes_Seleccion_Sprites_Derecha[2];
	Sprite Personajes_Sprites[2];
	int personaje_player_1=0,personaje_player_2=1;//Estas variables almacenan el codigo de luchador que seleccione cada jugador
	Menu_Seleccion_Personaje menu;
public:
	Seleccion_De_Personaje_Escena();
	void Draw (RenderWindow & w);//Se encarga del dibujado de la escena
	void Cambiar_menu(Menu_General *nuevo_menu)override;
	void Actualize (Juego & j);
	~Seleccion_De_Personaje_Escena();
};

#endif

