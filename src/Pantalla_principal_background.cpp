#include "Pantalla_principal_background.h"
#include "InfoJugadores.h"
#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace std;
using namespace sf;

Pantalla_principal_background::Pantalla_principal_background():rectangulo(Vector2f(515, 300)) {
	//SE SETEAN TODOS LOS SPRITES, TEXTURES, ETC PARA LUEGO DIBUJARLOS EN LA CLASE DRAW//
	
	//FONDO DE PANTALLA
	Pantalla_principal_background_texture.loadFromFile("menu_background.jpg");
	Pantalla_principal_background_sprite.setTexture(Pantalla_principal_background_texture);
	Pantalla_principal_background_sprite.setPosition(0, 0);
	
	//HISTORIAL DE JUGADORES
	m_font.loadFromFile("MKtitle1.ttf");
	Nombre_Player_1_Text.setFont(m_font);
	Nombre_Player_1_Text.setPosition(70,10);
	Nombre_Player_1_Text.setCharacterSize(50);
	Nombre_Player_1_Text.setColor({255,20,50});
	Nombre_Player_1_Text.setString(Info_Jugadores.Ver_Nombre_Player_1());
	
	Ganadas_Player_1_Text.setFont(m_font);
	Ganadas_Player_1_Text.setPosition(70,70);
	Ganadas_Player_1_Text.setCharacterSize(20);
	Ganadas_Player_1_Text.setColor({255,20,50});
	Ganadas_Player_1_Text.setString("Ganadas: " + to_string(Info_Jugadores.Ver_Ganadas_Player_1()));
	
	Perdidas_Player_1_Text.setFont(m_font);
	Perdidas_Player_1_Text.setPosition(70,100);
	Perdidas_Player_1_Text.setCharacterSize(20);
	Perdidas_Player_1_Text.setColor({255,20,50});
	Perdidas_Player_1_Text.setString("Perdidas: " + to_string(Info_Jugadores.Ver_Perdidas_Player_1()));
	
	
	Nombre_Player_2_Text.setFont(m_font);
	Nombre_Player_2_Text.setPosition(70,130);
	Nombre_Player_2_Text.setCharacterSize(50);
	Nombre_Player_2_Text.setColor({255,20,50});
	Nombre_Player_2_Text.setString(Info_Jugadores.Ver_Nombre_Player_2());
	
	Ganadas_Player_2_Text.setFont(m_font);
	Ganadas_Player_2_Text.setPosition(70,190);
	Ganadas_Player_2_Text.setCharacterSize(20);
	Ganadas_Player_2_Text.setColor({255,20,50});
	Ganadas_Player_2_Text.setString("Ganadas: " + to_string(Info_Jugadores.Ver_Ganadas_Player_2()));
	
	Perdidas_Player_2_Text.setFont(m_font);
	Perdidas_Player_2_Text.setPosition(70,220);
	Perdidas_Player_2_Text.setCharacterSize(20);
	Perdidas_Player_2_Text.setColor({255,20,50});
	Perdidas_Player_2_Text.setString("Perdidas: " + to_string(Info_Jugadores.Ver_Perdidas_Player_2()));
	
	//Creditos
	Creditos_Linea_1_Text.setFont(m_font);
	Creditos_Linea_1_Text.setPosition(1400,posx_Linea_6-250);
	Creditos_Linea_1_Text.setCharacterSize(30);
	Creditos_Linea_1_Text.setColor({255, 160, 0});
	Creditos_Linea_1_Text.setString("Proyecto Final Programacion Orientada a Objetos");
	
	Creditos_Linea_2_Text.setFont(m_font);
	Creditos_Linea_2_Text.setPosition(1400, posx_Linea_6-200);
	Creditos_Linea_2_Text.setCharacterSize(35);
	Creditos_Linea_2_Text.setColor(sf::Color(255, 160, 0));
	Creditos_Linea_2_Text.setString("Profesor Teoria: Pablo Novara");
	
	Creditos_Linea_3_Text.setFont(m_font);
	Creditos_Linea_3_Text.setPosition(1400, posx_Linea_6-150);
	Creditos_Linea_3_Text.setCharacterSize(35);
	Creditos_Linea_3_Text.setColor(sf::Color(255, 160, 0));
	Creditos_Linea_3_Text.setString("Profesor Practica: Javier Godoy");
	
	Creditos_Linea_4_Text.setFont(m_font);
	Creditos_Linea_4_Text.setPosition(1400, posx_Linea_6-100);
	Creditos_Linea_4_Text.setCharacterSize(35);
	Creditos_Linea_4_Text.setColor(sf::Color(255, 160, 0));
	Creditos_Linea_4_Text.setString("Fecha de presentacion: 20/12/2023");
	
	Creditos_Linea_5_Text.setFont(m_font);
	Creditos_Linea_5_Text.setPosition(1400, posx_Linea_6-50);
	Creditos_Linea_5_Text.setCharacterSize(35);
	Creditos_Linea_5_Text.setColor(sf::Color(255, 160, 0));
	Creditos_Linea_5_Text.setString("UNL-FICH");
	
	Creditos_Linea_6_Text.setFont(m_font);
	Creditos_Linea_6_Text.setPosition(1400,posx_Linea_6);
	Creditos_Linea_6_Text.setCharacterSize(35);
	Creditos_Linea_6_Text.setColor({255, 160, 0});
	Creditos_Linea_6_Text.setString("Por: URIEL PAUL");
	cronometro_creditos.restart();
	

	cronometro_creditos.restart();
	
	
	//Rectangulo que recubre los Creditos
	rectangulo.setFillColor({0, 0, 0,150}); // Color del fondo
	rectangulo.setPosition(1400, posx_Linea_6-250);
}

void Pantalla_principal_background::Actualize(){
	if(cronometro_creditos.getElapsedTime().asSeconds()>1 and posx_Linea_6<1000){
		posx_Linea_6+=50;
		Creditos_Linea_1_Text.setPosition(1400,posx_Linea_6-250);
		Creditos_Linea_2_Text.setPosition(1400, posx_Linea_6-200);
		Creditos_Linea_3_Text.setPosition(1400, posx_Linea_6-150);
		Creditos_Linea_4_Text.setPosition(1400, posx_Linea_6-100);
		Creditos_Linea_5_Text.setPosition(1400, posx_Linea_6-50);
		Creditos_Linea_6_Text.setPosition(1400,posx_Linea_6);
		rectangulo.setPosition(1400, posx_Linea_6-250);
		cronometro_creditos.restart();
	}
}


void Pantalla_principal_background::Draw(RenderWindow &w){
	w.draw(Pantalla_principal_background_sprite);
	
	w.draw(Nombre_Player_1_Text);
	w.draw(Ganadas_Player_1_Text);
	w.draw(Perdidas_Player_1_Text);
	
	w.draw(Nombre_Player_2_Text);
	w.draw(Ganadas_Player_2_Text);
	w.draw(Perdidas_Player_2_Text);
	
	if(cronometro_creditos.getElapsedTime().asSeconds()<10){
	w.draw(rectangulo);
	w.draw(Creditos_Linea_1_Text);
	w.draw(Creditos_Linea_2_Text);
	w.draw(Creditos_Linea_3_Text);
	w.draw(Creditos_Linea_4_Text);
	w.draw(Creditos_Linea_5_Text);
	w.draw(Creditos_Linea_6_Text);
	};

}

Pantalla_principal_background::~Pantalla_principal_background(){
	
}
