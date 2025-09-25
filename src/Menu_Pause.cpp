#include "Menu_Pause.h"
#include <SFML/Window/Keyboard.hpp>
#include "Fighting_Escena.h"
#include "Pantalla_principal.h"
#include "Seleccion_De_Personaje_Escena.h"
#include "Assets.h"

Menu_Pause::Menu_Pause():booleano_nulo(nullptr){
	cantidad_de_imagenes=2;
        for(int i=0;i<cantidad_de_imagenes;i++)  {
                menu_textura[i].loadFromFile(asset("sprites/Menu_Pause_"+to_string(i)+".png"));
		menu_sprite[i].setTexture(menu_textura[i]);
		menu_sprite[i].setPosition(700,i+350);
	};
	menu_sprite_principal=&menu_sprite[0];
	boton_seleccionado=0;
	

	
}

void Menu_Pause::Actualize(Juego &j){
	if(botones_menu_clock.getElapsedTime().asMilliseconds()>200){
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado!=0){
				boton_seleccionado=boton_seleccionado-1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Down)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado!=1){
				boton_seleccionado=boton_seleccionado+1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			if(boton_seleccionado==0){
				sonido.intro_sound_effect();
				j.CambiarEscena(new Seleccion_De_Personaje_Escena);
			}else {
				if(boton_seleccionado==1){
					sonido.intro_sound_effect();
					j.CambiarEscena(new Pantalla_principal());
				} 
			};
			
		};
	};
	
}




void Menu_Pause::Draw(RenderWindow &w){
	w.draw(*menu_sprite_principal);
	
}

Menu_Pause::~Menu_Pause(){}
