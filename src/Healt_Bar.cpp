#include "Healt_Bar.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>


#include <iostream>
using namespace std;
using namespace sf;



Healt_Bar::Healt_Bar(int p1, int p2) {
	//Inicializacion de texturas y sprites correspondientes a las barras de vida
	for(int i=0;i<2;i++) {  
	Healt_Bar_Texture[i].loadFromFile("health_bar_"+to_string(i)+".png");
	Healt_Bar_Player_1_Sprite[i].setTexture(Healt_Bar_Texture[i]);
	Healt_Bar_Player_2_Sprite[i].setTexture(Healt_Bar_Texture[i]);
	};
	
	//Inicializacion de texturas, sprites y textos correspondientes al reloj
	clock_background_texture.loadFromFile("Life_bar_clock_background.png");
	clock_background_sprite.setTexture(clock_background_texture);
	clock_background_sprite.setOrigin(27,26);
	clock_background_sprite.setScale(2,2);
	clock_background_sprite.setPosition(950,110);
	text_font.loadFromFile("MKtitle1.ttf");
	clock_text.setFont(text_font);
	clock_text.setCharacterSize(40);
	clock_text.setPosition(925,80);

	
	//Posicionamiento de la barra de vida del Player_1
	Healt_Bar_Player_1_Sprite[0].setPosition(70,70);
	Healt_Bar_Player_1_Sprite[1].setPosition(84,84);
	
	//Posicionamiento de la barra de vida del Player_2
	Healt_Bar_Player_2_Sprite[0].setPosition(1050,70);
	Healt_Bar_Player_2_Sprite[1].setPosition(1064,986);
	
	//DETERMINACION DEL NOMBRE DEL LUCHADOR ELEGIDO POR EL PLAYER_1
	
	switch(p1){//Recibe como dato el codigo de luchador elegido por el Player_1
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		Nombre_en_barra_de_vida_Player_1.setString("Kratos");
		break;
	case 2://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		Nombre_en_barra_de_vida_Player_1.setString("Sub Zero");
		break;
	default:
		break;
	}
	
	//Posicionamiento del Nombre en la barra de vida del Player_1
	Nombre_en_barra_de_vida_Player_1.setFont(text_font);
	Nombre_en_barra_de_vida_Player_1.setCharacterSize(70);
	Nombre_en_barra_de_vida_Player_1.setColor({255,50,50});
	Nombre_en_barra_de_vida_Player_1.setPosition(95,67);
	
	
	//DETERMINACION DEL NOMBRE DEL LUCHADOR ELEGIDO POR EL PLAYER_2
	
	switch(p2){//Recibe como dato el codigo de luchador elegido por el Player_2
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		Nombre_en_barra_de_vida_Player_2.setString("Kratos");
		break;
	case 2://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		Nombre_en_barra_de_vida_Player_2.setString("Sub Zero");
		break;
	default:
		break;
	}
	
	//Posicionamiento del Nombre en la barra de vida del Player_2
	Nombre_en_barra_de_vida_Player_2.setFont(text_font);
	Nombre_en_barra_de_vida_Player_2.setCharacterSize(70);
	Nombre_en_barra_de_vida_Player_2.setColor({255,50,50});
	Nombre_en_barra_de_vida_Player_2.setPosition(1075,67);
}

void Healt_Bar::Draw(RenderWindow &w){
	//Barra de vida del Player_1
	w.draw(Healt_Bar_Player_1_Sprite[0]);
	for(int i=20;i>vida_player_1;i--) { 
		w.draw(Healt_Bar_Player_1_Sprite[1]);
		Healt_Bar_Player_1_Sprite[1].setPosition((46+(i*37.6)),84);
	}
	w.draw(Nombre_en_barra_de_vida_Player_1);
	//Barra de vida del Player_2
	w.draw(Healt_Bar_Player_2_Sprite[0]);
	for(int i=0;i<20-vida_player_2;i++) { 
		w.draw(Healt_Bar_Player_2_Sprite[1]);
		Healt_Bar_Player_2_Sprite[1].setPosition((1064+(i*37.6)),84);
	}
	w.draw(Nombre_en_barra_de_vida_Player_2);
	
	//Cronometro
	if(clock<10){
		clock_text.setPosition(940,80);
	}
	w.draw(clock_background_sprite);
	clock_text.setString(to_string(clock));
	clock_text.setScale(1.5,1.5);
	w.draw(clock_text);
}


void Healt_Bar::Actualize(Round &r){
	vida_player_1=r.Obtener_Vida_Player_1();
	vida_player_2=r.Obtener_Vida_Player_2();
	clock=r.Obtener_Valor_En_Segundos_Cronometro();
}

Healt_Bar::~Healt_Bar(){
}

