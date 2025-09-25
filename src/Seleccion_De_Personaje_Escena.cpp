#include "Seleccion_De_Personaje_Escena.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Juego.h"
#include "Fighting_Escena.h"
#include "Pantalla_principal.h"
#include "Menu_Seleccion_Personaje.h"
#include "Assets.h"

#include <iostream>
using namespace std;
using namespace sf;

Seleccion_De_Personaje_Escena::Seleccion_De_Personaje_Escena():battleground("mkbattleground.png") {

	//fotos grandes
	Personajes_Texturas[0].loadFromFile(asset("sprites/Kratos_Seleccion_De_Personaje.png"));
	Personajes_Texturas[1].loadFromFile(asset("sprites/Sub_Zero_Seleccion_De_Personaje.png"));
	Personajes_Sprites[0].setTexture(Personajes_Texturas[0]);
	Personajes_Sprites[1].setTexture(Personajes_Texturas[1]);
	
	//iconos pequeos izquierda
	Personajes_Seleccion_Texturas_Izquierda[0].loadFromFile(asset("sprites/Kratos_Seleccion.png"));
	Personajes_Seleccion_Texturas_Izquierda[1].loadFromFile(asset("sprites/Sub_Zero_Seleccion.png"));
	Personajes_Seleccion_Sprites_Izquierda[0].setTexture(Personajes_Seleccion_Texturas_Izquierda[0]);
	Personajes_Seleccion_Sprites_Izquierda[1].setTexture(Personajes_Seleccion_Texturas_Izquierda[1]);
	
	//iconos pequeos derecha
	Personajes_Seleccion_Texturas_Derecha[0].loadFromFile(asset("sprites/Kratos_Seleccion.png"));
	Personajes_Seleccion_Texturas_Derecha[1].loadFromFile(asset("sprites/Sub_Zero_Seleccion.png"));
	Personajes_Seleccion_Sprites_Derecha[0].setTexture(Personajes_Seleccion_Texturas_Derecha[0]);
	Personajes_Seleccion_Sprites_Derecha[1].setTexture(Personajes_Seleccion_Texturas_Derecha[1]);
	
	//Recuadros de seleccion
	Recuadros_Seleccion_Texturas[0].loadFromFile(asset("sprites/Recuadro_Seleccion_p1.png"));
	Recuadros_Seleccion_Texturas[1].loadFromFile(asset("sprites/Recuadro_Seleccion_p2.png"));
	Recuadros_Seleccion_Sprites[0].setTexture(Recuadros_Seleccion_Texturas[0]);
	Recuadros_Seleccion_Sprites[1].setTexture(Recuadros_Seleccion_Texturas[1]);
	
	//Cartel
	m_font.loadFromFile(asset("fonts/MKtitle1.ttf"));
	Escape_Text.setFont(m_font);
	Escape_Text.setPosition(890,1000);
	Escape_Text.setCharacterSize(30);
	Escape_Text.setColor({255,20,50});
	Escape_Text.setString("Esc to Main Menu _");
	
	
	//Posicionamiento de iconos de seleccion
	for(int i=0;i<2;i++) { 
		Personajes_Seleccion_Sprites_Izquierda[i].setScale(0.5,0.5);
		Personajes_Seleccion_Sprites_Izquierda[i].setPosition(220+i*200,100);
		
		Personajes_Seleccion_Sprites_Derecha[i].setScale(0.5,0.5);
		Personajes_Seleccion_Sprites_Derecha[i].setPosition(1400+i*200,100);
	}
	battleground.Play_music(); //Musica de seleccion de personaje que es la misma que la musica de la pelea
}


void Seleccion_De_Personaje_Escena::Actualize (Juego & j) {
	menu.Actualize(j);
	personaje_player_1=menu.Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_1();
	personaje_player_2=menu.Ver_Codigo_Luchador_Seleccionado_Parcialmente_Player_2();
}

void Seleccion_De_Personaje_Escena::Draw (RenderWindow & w) {
	battleground.Draw(w);

	for(int i=0;i<2;i++) { 
		w.draw(Personajes_Seleccion_Sprites_Izquierda[i]);
		w.draw(Personajes_Seleccion_Sprites_Derecha[i]);
	}
	
	Recuadros_Seleccion_Sprites[0].setPosition(220+200*personaje_player_1,100);
	Recuadros_Seleccion_Sprites[1].setPosition(1400+200*personaje_player_2,100);
	
	Personajes_Sprites[personaje_player_1].setPosition(25,450);
	w.draw(Personajes_Sprites[personaje_player_1]);
	Personajes_Sprites[personaje_player_2].setPosition(1200,450);
	w.draw(Personajes_Sprites[personaje_player_2]);
	w.draw(Recuadros_Seleccion_Sprites[0]);
	w.draw(Recuadros_Seleccion_Sprites[1]);
	w.draw(Escape_Text);
}


void Seleccion_De_Personaje_Escena::Cambiar_menu(Menu_General *nuevo_menu){
	
}

Seleccion_De_Personaje_Escena::~Seleccion_De_Personaje_Escena(){
}
