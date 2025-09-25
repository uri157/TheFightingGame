#include "Sub_Zero.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>
#include "Controles.h"
#include "Controles_Player_2.h"
#include "Controles_Player_1.h"
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "Assets.h"
using namespace std;
using namespace sf;

Sub_Zero::Sub_Zero(int player_1_o_2):Personaje_1_escena_fighting(player_1_o_2,"Sub_Zero") { //Aqui recibe como informacion si sera Player_1 o Player_2 
	//Inicializa la bola de hielo del ataque de sub zero orientada hacia izquierda y derecha
        for(int i=0;i<2;i++) {
                Sub_Zero_ice_ball_texture[i].loadFromFile(asset("sprites/Sub_Zero_ice_ball_"+to_string(i)+".png"));
		Sub_Zero_ice_ball_sprite[i].setTexture(Sub_Zero_ice_ball_texture[i]);
		Sub_Zero_ice_ball_sprite[i].setScale(5,5);
	}
	
	Sub_Zero_pointer_ice_ball_sprite=&Sub_Zero_ice_ball_sprite[0];
	
	//Sonido
        attacking_effect_soundbuffer.loadFromFile(asset("audio/music/Sub_Zero_attack_sound_effect.wav"));
	attacking_effect_sound.setBuffer(attacking_effect_soundbuffer);
        jumping_effect_soundbuffer.loadFromFile(asset("audio/music/Sub_Zero_jumping_sound_effect.wav"));
	jumping_effect_sound.setBuffer(jumping_effect_soundbuffer);
        get_hit_effect_soundbuffer.loadFromFile(asset("audio/music/Sub_Zero_get_hit_sound_effect.wav"));
	get_hit_effect_sound.setBuffer(get_hit_effect_soundbuffer);

	
	//Correciones particulares que necesitan los sprites para funcionar correctamente
	Pj_attacking_sprite[3].setOrigin(25,15);
	Pj_attacking_sprite[1].setOrigin(0,15);
	
}

void Sub_Zero::m_Ataque(){
	if(ataque==false){
		if(controles->Personaje_Atacando_Simple()){
			attacking_effect_sound.play();
			atacar_clock.restart();
			ataque=true;
			
			if(mirando_derecha==true){
				direccion_ataque_derecha=true;
				Sub_Zero_pointer_ice_ball_sprite=&Sub_Zero_ice_ball_sprite[0];
				Sub_Zero_pointer_ice_ball_sprite->setPosition(Sprite_Principal->getPosition());
			} else {
				direccion_ataque_derecha=false;
				Sub_Zero_pointer_ice_ball_sprite=&Sub_Zero_ice_ball_sprite[1];
				Sub_Zero_pointer_ice_ball_sprite->setPosition(Sprite_Principal->getPosition());
			}
		};
	};
	if(ataque==true){
		if(direccion_ataque_derecha==true){
			Sub_Zero_pointer_ice_ball_sprite->move(20,0);
		}else{
			Sub_Zero_pointer_ice_ball_sprite->move(-20,0);
		};
		if(atacar_clock.getElapsedTime().asMilliseconds()<100){
			Vector2f pos=Sprite_Principal->getPosition();
			if(mirando_derecha==true){
				Sprite_Principal=&Pj_attacking_sprite[0];
			}else{
				Sprite_Principal=&Pj_attacking_sprite[2];
			};
			Sprite_Principal->setPosition(pos);
		}else{
			if(atacar_clock.getElapsedTime().asMilliseconds()<500){
				Vector2f pos=Sprite_Principal->getPosition();
				if(mirando_derecha==true){
					Sprite_Principal=&Pj_attacking_sprite[1];
				}else{
					Sprite_Principal=&Pj_attacking_sprite[3];
				};
				Sprite_Principal->setPosition(pos);
			} else { 
				if(atacar_clock.getElapsedTime().asMilliseconds()>699){
					if(ataque_en_salto==false){
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



void Sub_Zero::Draw(RenderWindow &w){
	w.draw(*Sprite_Principal);
	if(ataque==true){
		w.draw(*Sub_Zero_pointer_ice_ball_sprite);
	}
}


void Sub_Zero::Jumping_Sound_Effect(){
	jumping_effect_sound.play();
}

void Sub_Zero::Attack_Sound_Effect(){
	attacking_effect_sound.play();
}

void Sub_Zero::Get_Hit_Sound_Effect(){
	get_hit_effect_sound.play();
}

FloatRect Sub_Zero::Posicion_Ataque(){
	return Sub_Zero_pointer_ice_ball_sprite->getGlobalBounds();
}


Sub_Zero::~Sub_Zero(){
        // No delete: puntero no propietario (apunta a un elemento de Sub_Zero_ice_ball_sprite[])
        Sub_Zero_pointer_ice_ball_sprite = nullptr;

}
