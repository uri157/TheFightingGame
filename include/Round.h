#ifndef ROUND_H
#define ROUND_H
#include "Healt_Bar.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Personaje_1_escena_fighting.h"
#include "Battleground.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Fighting_Escena.h"
#include "Presentacion_Round.h"
using namespace std;
using namespace sf;

class Fighting_Escena;

class Healt_Bar;

//Sostiene a los dos players, el cronometro, la vida de los luchadores, controla el hitbox, le pasa esa informacion procesada a HealtBar para que se ajuste y "administra" la clase que se encarga de las presentaciones

class Round {
	Battleground battleground;
	Healt_Bar *healt_bar;
	Personaje_1_escena_fighting *player_1, *player_2;
	bool menu_pause_abierto, presentacion=false;
	int vida_player_1=20, vida_player_2=20;//Dentro del juego no se ve de manera numerica pero cada jugador comienza con "20 de vida"
	Clock presentacion_clock, last_hit_player_1, last_hit_player_2;
	Clock final_clock, cronometro;;//Final clock representa el tiempo pasado a partir de que existe un ganador del round y comienzan las animaciones finales; cronometro es el cronometro de la pelea
	Presentacion_Round Presentacion;
public:
	Round(int round_num, int p1, int p2);//Round_num es el numero de round para realizar la presentacion, p1 y p2 son los codigos de luchadores seleccionados por los jugadores para poder inicializarlos
	void Actualize();
	int Ganador(Fighting_Escena &Fighting);//Le devuelve a la Escena el ganador (1=Player_1,2=Player_2) para que los pueda contabilizar
	int Obtener_Vida_Player_1();
	int Obtener_Vida_Player_2();
	int Obtener_Valor_En_Segundos_Cronometro();
	void Draw(RenderWindow &w);
	~Round();
};

#endif

