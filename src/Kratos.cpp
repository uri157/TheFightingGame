#include "Kratos.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "Controles.h"
#include "Controles_Player_2.h"
#include "Controles_Player_1.h"
#include <SFML/System/Clock.hpp>
#include <iostream>
using namespace std;
using namespace sf;


Kratos::Kratos(int player_1_o_2):Personaje_1_escena_fighting(player_1_o_2,"Kratos") {//Recibe una variable que le indica si es Player 1 o Player 2

//Efectos de sonido correspondientes al luchador
	attacking_effect_soundbuffer.loadFromFile("Kratos_attack_sound_effect.wav");
	attacking_effect_sound.setBuffer(attacking_effect_soundbuffer);
	jumping_effect_soundbuffer.loadFromFile("Kratos_jumping_sound_effect.wav");
	jumping_effect_sound.setBuffer(jumping_effect_soundbuffer);
	get_hit_effect_soundbuffer.loadFromFile("Kratos_get_hit_sound_effect.wav");
	get_hit_effect_sound.setBuffer(get_hit_effect_soundbuffer);

	
//Correciones particulares que necesitan los sprites para funcionar correctamente
	Pj_attacking_sprite[3].setOrigin(84,0);
	Pj_win_sprite.setOrigin(0,15);

}


void Kratos::m_Ataque(){
	if(ataque==false){//Si no se esta realizando un ataque actualmente
		if(controles->Personaje_Atacando_Simple()){//Si el Jugador presiona la tecla de "atacar"
			attacking_effect_sound.play();
			atacar_clock.restart();//Se reinicia el cronometro de ataque
			ataque=true;
		};
	};
	if(ataque==true){//Si hay un ataque en curso
		if(atacar_clock.getElapsedTime().asMilliseconds()<100){//Si se esta en los primeros 100ms de la animacion de ataque
			Vector2f pos=Sprite_Principal->getPosition();
			//Se modifica el puntero principal para que muestre el sprite de ataque que corresponde de acuerdo al momento de la animacion y la orientacion del luchador
			if(mirando_derecha==true){
				Sprite_Principal=&Pj_attacking_sprite[0];
			}else{
				Sprite_Principal=&Pj_attacking_sprite[2];
			};
			Sprite_Principal->setPosition(pos);
		}else{
			if(atacar_clock.getElapsedTime().asMilliseconds()<300){//Si se esta entre los 100ms y los 300ms de la animacion de ataque
				Vector2f pos=Sprite_Principal->getPosition();
				//Se modifica el puntero principal para que muestre el sprite de ataque que corresponde de acuerdo al momento de la animacion y la orientacion del luchador
				if(mirando_derecha==true){
					Sprite_Principal=&Pj_attacking_sprite[1];
				}else{
					Sprite_Principal=&Pj_attacking_sprite[3];
				};
				Sprite_Principal->setPosition(pos);
			} else { 
				if(atacar_clock.getElapsedTime().asMilliseconds()>400){//Si se esta entre por encima de los 400ms que dura la animacion se termina el ataque
					if(ataque_en_salto==false){ //Si no se esta llevando adelante un salto simultaneamente al ataque se inicializa el sprite "de pie" que corresponda de acuerdo a la orientacion del luchador
						if(mirando_derecha==true){
							Vector2f pos=Sprite_Principal->getPosition();
							Sprite_Principal=&Pj_standing_sprite[0];
							Sprite_Principal->setPosition(pos);
						} else {
							Vector2f pos=Sprite_Principal->getPosition();
							Sprite_Principal=&Pj_standing_sprite[1];
							Sprite_Principal->setPosition(pos);
						};
						ataque=false;
						ataque_en_movimiento_derecha=false;
						ataque_en_movimiento_izquierda=false;
					};	
				};
			};
		};	
	};	
}


void Kratos::Jumping_Sound_Effect(){
	jumping_effect_sound.play();
}

void Kratos::Attack_Sound_Effect(){
	attacking_effect_sound.play();
}

void Kratos::Get_Hit_Sound_Effect(){
	get_hit_effect_sound.play();
}

void Kratos::Draw(RenderWindow &w){
	w.draw(*Sprite_Principal);
}

Kratos::~Kratos(){
}

FloatRect Kratos::Posicion_Ataque(){
	return Sprite_Principal->getGlobalBounds();
}

