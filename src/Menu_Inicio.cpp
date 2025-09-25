#include "Menu_Inicio.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu_General.h"
#include "Fighting_Escena.h"
#include "Seleccion_De_Personaje_Escena.h"
#include "Menu_options.h"
#include "Assets.h"


using namespace std;
using namespace sf;

Menu_Inicio::Menu_Inicio(){
	cantidad_de_imagenes=3;
        for(int i=0;i<cantidad_de_imagenes;i++)  {
                menu_textura[i].loadFromFile(asset("sprites/Menu_"+to_string(i)+".png"));
		menu_sprite[i].setTexture(menu_textura[i]);
		menu_sprite[i].setPosition(700,i+200);
	};
	menu_sprite_principal=&menu_sprite[0];
	boton_seleccionado=0;
}

void Menu_Inicio::Actualize(Juego &j){
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
			if(boton_seleccionado!=2){
				boton_seleccionado=boton_seleccionado+1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			botones_menu_clock.restart();
			sonido.intro_sound_effect();
			while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
				
			}
			if(boton_seleccionado==0){
			j.CambiarEscena(new Seleccion_De_Personaje_Escena);
			} else {
				if(boton_seleccionado==2){
				sonido.intro_sound_effect();
				m_win->close();
				} else { 
					if(boton_seleccionado==1){
						j.CambiarMenu(new Menu_options());
					}
				}
			};
			
		};
	};
	

}



void Menu_Inicio::Draw(RenderWindow &w){
	w.draw(*menu_sprite_principal);
	m_win=&w;
}

Menu_Inicio::~Menu_Inicio(){
	delete menu_sprite_principal;
}
