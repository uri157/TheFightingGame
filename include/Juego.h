#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Players_selected.h"
#include "Menu_General.h"
#include <SFML/Window/Event.hpp>

class Menu_General;
class Escena;
using namespace std;
using namespace sf;

//Esta clase se encarga de la administracion de las escenas (cambiarlas, actualizarlas, etc), de la creacion y actualizacion de la ventana 
//y almacena algo de informacion necesaria entre escenas


class Juego {
	RenderWindow m_win;
	Event e;
	Escena *m_escena, *m_prox=nullptr;
	bool close =false;
	Players_selected Jugadores; //La escena de seleccion de personajes brinda los personajes seleccionados para que se le puedan indicar a la clase que se encarga de la batalla 
public:
	Juego(Escena *e);
	void Jugar(); //Actualiza, dibuja y realiza el cambio de escena
	void CambiarEscena(Escena *Nueva_Escena);//Permite realizar el cambio entre escenas, el cual es guiado por las mismas escenas a travez de un *This
	void Modificar_players_selected(int player_1, int player_2);//Permite a la escena de seleccion de personajes brindar la info necesaria para la clase que se encargara de la batalla
	void CambiarMenu(Menu_General *nuevo_menu);//Los distintos menues se encargan de cambiar entre ellos a travez de esta funcion mediante un *This
	int Ver_Player_Selected_1();//Permite consultar el luchador que eligio el Player_1 en la seleccion de personaje
	int Ver_Player_Selected_2();//Permite consultar el luchador que eligio el Player_2 en la seleccion de personaje
	RenderWindow& ObtenerVentana();//Permite consultar el evento actual si existe
	~Juego();
};

#endif

