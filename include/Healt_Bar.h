#ifndef HEALT_BAR_H
#define HEALT_BAR_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Clock.hpp>
#include "Round.h"
using namespace std;
using namespace sf;


class Round;
//Se encarga de dibujar las barras de vida de los luchadores y el cronometro
class Healt_Bar {
	Texture Healt_Bar_Texture[2];
	Texture clock_background_texture;
	Sprite Healt_Bar_Player_1_Sprite[2];
	Sprite Healt_Bar_Player_2_Sprite[2];
	Sprite clock_background_sprite;
	Text clock_text,Nombre_en_barra_de_vida_Player_1,Nombre_en_barra_de_vida_Player_2;
	Font text_font;
	int clock,vida_player_1,vida_player_2;
public:
	Healt_Bar(int p1, int p2);
	void Draw(RenderWindow &w);
	void Actualize(Round &r);
	~Healt_Bar();
};

#endif

