#ifndef MENU_INICIO_H
#define MENU_INICIO_H
#include "Menu_General.h"
#include "Efectos_de_sonido_menus.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"


using namespace std;
using namespace sf;

class Menu_Inicio : public Menu_General{
	Efectos_de_sonido_menus sonido;
	Clock botones_menu_clock;
	int boton_seleccionado, cantidad_de_imagenes;
	Texture menu_textura[3];
	Sprite menu_sprite[3];
	Sprite *menu_sprite_principal;
	RenderWindow *m_win;
	
public:
	Menu_Inicio();
	void Actualize(Juego &j)override;
	/*int Exit()override;*/
	void Draw(RenderWindow &w)override;
	~Menu_Inicio()override;
};

#endif

