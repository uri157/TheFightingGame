#ifndef PANTALLA_PRINCIPAL_H
#define PANTALLA_PRINCIPAL_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu_General.h"
#include "Efectos_de_sonido_menus.h"
#include "Pantalla_principal_background.h"
#include "Escena.h"
#include "Juego.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>



using namespace std;
using namespace sf;

//Escena encargada de sostener el menu principal, es la primera escena que se muestra al iniciar el juego
class Pantalla_principal : public Escena{
	Efectos_de_sonido_menus sonido;
	Pantalla_principal_background background;
	Menu_General *menu, *menu_aux=nullptr;

public:
	Pantalla_principal();
	void Draw(RenderWindow &w)override;//Se encarga del "dibujo" de los elementos de la escena
	void Actualize(Juego &j)override;//Se encarga de actualizar los elementos de la escena
	void Cambiar_menu(Menu_General *nuevo_menu)override;//Se encarga realizar el cambio de menues, ordenado por la clase Juego, la cual fue llamada desde el mismo menu a travez del *This
	~Pantalla_principal()override;
	
	
};

#endif

