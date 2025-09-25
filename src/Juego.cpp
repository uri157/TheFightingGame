#include "Juego.h"
#include "Escena.h"
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "Players_selected.h"
#include <fstream>
using namespace std;
using namespace sf;


	
//El constructor de la clase Juego recibe un puntero a la escena de la Pantalla_principal para iniciar el Juego
Juego::Juego(Escena *e) : m_win(VideoMode(1920,1080),"The Fighting Game",Style::Fullscreen) { 
	m_win.setFramerateLimit(60);
	m_escena = e;
	Players_selected Jugadores();
	View view;
	view.reset(sf::FloatRect(0, 0, 1920, 1080)); // Establece la vista a la resolución original
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f)); // Ajusta la vista al tamaño de la ventana
	m_win.setView(view);

}

void Juego::Jugar(){
	
	while(m_win.isOpen() and close==false) {
		while(m_win.pollEvent(e)) {
			if(e.type == Event::Closed)
				m_win.close();	
		}
		m_win.clear(Color(255,255,255,255));
		
		//Aqui se actualiza la escena actual pasandole un puntero a esta mismisima instancia de juego para que la escena cuando lo vea necesario
		//Pueda llamar a la funcion "Cambiar Escena" y esto permita el desplazamiento dinamico entre las escenas del juego
		m_escena->Actualize(*this);
		m_escena->Draw(m_win);
		m_win.display();
		
		
	
		if(m_prox){ //Si m_prox no es nullptr significa que la escena actual llamo a un cambio de escena, y la nueva escena esta dentro de m_prox
			delete m_escena;//se libera la memoria correspondiente a la escena actual
			m_escena=m_prox;//se sobreescribe el puntero m_escena con el puntero de la nueva escena en m_prox lo que significara el cambio de escena en el juego
			m_prox=nullptr;//se le da valor nulo a m_prox para reiniciar el ciclo
		}
		
	}
	
}

RenderWindow& Juego::ObtenerVentana(){
	return m_win;
}

void Juego::CambiarEscena(Escena *Nueva_Escena){//Cuando una escena llama al cambio pasa un puntero a una nueva escena
	m_prox=Nueva_Escena;
}


Juego::~Juego(){
	delete m_escena;//Se libera la ultima escena antes de cerrar el juego
}

	
void Juego::Modificar_players_selected(int player_1, int player_2){ //Recibe el codigo del luchador elegido por cada jugador en la seleccion de personajes
	Jugadores.Modificar_Player_1(player_1);
	Jugadores.Modificar_Player_2(player_2);
}
 
void Juego::CambiarMenu(Menu_General *nuevo_menu){//Recibe un puntero al nuevo menu
	m_escena->Cambiar_menu(nuevo_menu);//Aca el mismisimo menu ordena cambiar a otro menu a travez de *This
}

int Juego::Ver_Player_Selected_1(){
	return Jugadores.Ver_Player_1();
}

int Juego::Ver_Player_Selected_2(){
	return Jugadores.Ver_Player_2();
}
