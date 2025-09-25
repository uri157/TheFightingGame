#ifndef MENU_PAUSE_H
#define MENU_PAUSE_H
#include "Efectos_de_sonido_menus.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Menu_General.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Fighting_Escena.h"

class Menu_Pause : public Menu_General{
	Efectos_de_sonido_menus sonido;
	Clock botones_menu_clock;
	int boton_seleccionado, cantidad_de_imagenes;
	Texture menu_textura[3];
	Sprite menu_sprite[3];
	Sprite *menu_sprite_principal;
	bool booleano_nulo, debe_cerrar_menu=false;

public:
	Menu_Pause();
	void Actualize(Juego &j)override;
	void Draw(RenderWindow &w)override;
	~Menu_Pause()override;
};

#endif

