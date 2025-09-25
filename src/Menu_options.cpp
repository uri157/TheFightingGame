#include "Menu_options.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Menu_General.h"

#include <tuple>
#include "Pantalla_principal.h"
#include "Menu_Inicio.h"
#include "Menu_Controls.h"

using namespace std;
using namespace sf;

Menu_options::Menu_options() {
	cantidad_de_imagenes=2;
	for(int i=0;i<cantidad_de_imagenes;i++)  { 
		menu_textura[i].loadFromFile("Menu_options_"+to_string(i)+".png");
		menu_sprite[i].setTexture(menu_textura[i]);
		menu_sprite[i].setPosition(700,i+200);
	};
	menu_sprite_principal=&menu_sprite[0];
	boton_seleccionado=0;
	Menu_Background_textura.loadFromFile("Menu_Options_Background.jpg");
	Menu_Background_sprite.setTexture(Menu_Background_textura);
}

void Menu_options::Actualize(Juego &j){
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
			if(boton_seleccionado!=cantidad_de_imagenes-1){
				boton_seleccionado=boton_seleccionado+1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			botones_menu_clock.restart();
			sonido.intro_sound_effect();
			while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
				
			}
			if(boton_seleccionado==1){
				j.CambiarMenu(new Menu_Inicio());
			} else {
				if(boton_seleccionado==0){
					j.CambiarMenu(new Menu_Controls());
				};
			}
		};
	};
	

}
	


	
	
void Menu_options::Draw(RenderWindow &w){
	w.draw(Menu_Background_sprite);
	w.draw(*menu_sprite_principal);
}

Menu_options::~Menu_options() {
	
}
