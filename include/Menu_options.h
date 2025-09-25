#ifndef MENU_OPTIONS_H
#define MENU_OPTIONS_H
#include "Menu_General.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include "Efectos_de_sonido_menus.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <tuple>

using namespace std;
using namespace sf;

class Menu_options : public Menu_General{
	Efectos_de_sonido_menus sonido;
	Clock botones_menu_clock;
	int boton_seleccionado, cantidad_de_imagenes;
	Texture menu_textura[2],Menu_Background_textura;
	Sprite menu_sprite[2],Menu_Background_sprite;
	Sprite *menu_sprite_principal;
public:
	Menu_options();
	void Actualize(Juego &j)override;
	void Draw(RenderWindow &w)override;
	~Menu_options()override;
};

#endif

