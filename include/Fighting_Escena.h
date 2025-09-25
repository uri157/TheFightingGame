#ifndef FIGHTING_ESCENA_H
#define FIGHTING_ESCENA_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Kratos.h"
#include "Battleground.h"
#include "Menu_General.h"
#include "Healt_Bar.h"
#include "Round.h"
#include <vector>
#include "Escena.h"
#include "Juego.h"
#include <SFML/System/Clock.hpp>
#include "Personaje_1_escena_fighting.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "InfoJugadores.h"

using namespace std;
using namespace sf;
class Round;

//Se encarga de sostener la escena donde se realiza la "pelea", mas especificamente los "rounds", el "menu de pausa" y determinar el ganador de la misma

class Fighting_Escena: public Escena{
	int Player_1,Player_2;//Se recibe el codigo de luchador que eligio cada jugador, la leyenda de esto se puede encontrar en la clase "Players_selected" la cual es la responsable
	Clock cronometro_menu;
	Menu_General* menu;
	bool menu_abierto=false, primera_iteracion=true;
	int round_actual;
	vector<int> marcador;
	Round *round, *aux=nullptr;
	Font m_font;
	Text Escape_Text;
	InfoJugadores Info_J;
	int ganador;
public:
	Fighting_Escena();
	void Actualize(Juego &j)override;
	void Draw(RenderWindow &w)override;
	void CerrarMenuPause();
	void CambiarRound();
	void Cambiar_menu(Menu_General *Nuevo_menu)override;
	~Fighting_Escena();
};

#endif

