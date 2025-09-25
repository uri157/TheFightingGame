#ifndef MENU_PRINCIPAL_BACKGROUND_H
#define MENU_PRINCIPAL_BACKGROUND_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "InfoJugadores.h"
#include <SFML/Graphics/RectangleShape.hpp>

using namespace std;
using namespace sf;


//Se encarga del dibujado de los elementos visuales de la pantalla principal excepto de los menues
class Pantalla_principal_background {
	Texture Pantalla_principal_background_texture;
	Sprite Pantalla_principal_background_sprite;
	InfoJugadores Info_Jugadores;
	Font m_font;
	Text Nombre_Player_1_Text;
	Text Ganadas_Player_1_Text;
	Text Perdidas_Player_1_Text;
	Text Nombre_Player_2_Text;
	Text Ganadas_Player_2_Text;
	Text Perdidas_Player_2_Text;
	Text Creditos_Linea_1_Text;
	Text Creditos_Linea_2_Text;
	Text Creditos_Linea_3_Text;
	Text Creditos_Linea_4_Text;
	Text Creditos_Linea_5_Text;
	Text Creditos_Linea_6_Text;
	Clock cronometro_creditos;//los creditos solo se mostraran por 10 segundos cada vez que sea creada la pantalla principal
	int posx_Linea_6=0;
	RectangleShape rectangulo;
public:
	Pantalla_principal_background();
	void Draw(RenderWindow &w);
	void Actualize();
	~Pantalla_principal_background();
};

#endif

