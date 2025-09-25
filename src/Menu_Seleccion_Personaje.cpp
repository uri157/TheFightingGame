#include "Menu_Seleccion_Personaje.h"
#include <SFML/Window/Keyboard.hpp>
#include "Pantalla_principal.h"
#include "Fighting_Escena.h"

using namespace std;
using namespace sf;

Menu_Seleccion_Personaje::Menu_Seleccion_Personaje() {
	
}

void Menu_Seleccion_Personaje::Actualize (Juego & j) {
	m_Seleccion_De_Personaje_Player_1();
	m_Seleccion_De_Personaje_Player_2();
	
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape)){//Si el usuario presiona la tecla "Escape"
		sonido.intro_sound_effect();
		seleccion_p2_clock.restart();
		while(seleccion_p2_clock.getElapsedTime().asMilliseconds()<380){//Se da ese margen antes de cambiar la escena para que pueda sonar el efecto de sonido correspondiente
			
		}
		j.CambiarEscena(new Pantalla_principal);//Se cambia de escena a la pantalla principal
	};
	
	if(seleccion_en_curso_p1==false and seleccion_en_curso_p2==false){
		j.Modificar_players_selected(personaje_player_1+1,personaje_player_2+1);//Se le informa a la clase juego los luchadores seleccionados por los jugadores para que pueda inicializar la escena de la pelea
		j.CambiarEscena(new Fighting_Escena);//Una vez finalizada la seleccion se le solicita a la clase juego que cambie la escena para dar comienzo a la pelea
	}
}


int Menu_Seleccion_Personaje::Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_1(){
	return personaje_player_1; 
}


int Menu_Seleccion_Personaje::Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_2(){
	return personaje_player_2; 
}




void Menu_Seleccion_Personaje::m_Seleccion_De_Personaje_Player_1(){
	if(seleccion_p1_clock.getElapsedTime().asMilliseconds()>200 and seleccion_en_curso_p1==true){
		if(Keyboard::isKeyPressed(Keyboard::Key::D)){
			sonido.moving_sound_effect();
			seleccion_p1_clock.restart();
			if(personaje_player_1<1){
				personaje_player_1+=1;
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::A)){
			sonido.moving_sound_effect();
			seleccion_p1_clock.restart();
			if(personaje_player_1>0){
				personaje_player_1-=1;
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::S)){
			sonido.intro_sound_effect();
			seleccion_en_curso_p1=false;
		};
	};	
}


void Menu_Seleccion_Personaje::m_Seleccion_De_Personaje_Player_2(){
	if(seleccion_p2_clock.getElapsedTime().asMilliseconds()>200 and seleccion_en_curso_p2==true){//Se utiliza el cronometro para discretizar los inputs, ya que sino al querer realizar un input realizabas infinitos
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){//Si el usuario presiona la tecla "Flecha Derecha"
			sonido.moving_sound_effect();
			seleccion_p2_clock.restart();
			if(personaje_player_2<1){
				personaje_player_2+=1;
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)){//Si el usuario presiona la tecla "Flecha Izquierda"
			sonido.moving_sound_effect();
			seleccion_p2_clock.restart();
			if(personaje_player_2>0){
				personaje_player_2-=1;
			};
		};
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){//Si el usuario presiona la tecla "Enter"
			sonido.intro_sound_effect();
			seleccion_en_curso_p2=false;//La seleccion de este jugador termina
		};
	};
}

Menu_Seleccion_Personaje::~Menu_Seleccion_Personaje() {
	
}
