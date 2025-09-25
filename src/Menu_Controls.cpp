#include "Menu_Controls.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu_options.h"
#include "InfoJugadores.h"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <fstream>
#include <SFML/System/Vector2.hpp>
#include <string>
using namespace std;



Menu_Controls::Menu_Controls():pos_attack_text_p1(612,274),pos_jump_text_p1(614,438),pos_derecha_text_p1(613,607),pos_izquierda_text_p1(611,776),pos_attack_text_p2(1316,290),pos_jump_text_p2(1316,455),pos_derecha_text_p2(1315,623),pos_izquierda_text_p2(1313,793){
//	//Teclas Default
//	Saltar_p1=Keyboard::Key::Space;
//	Caminar_Derecha_p1=Keyboard::Key::D;
//	Caminar_Izquierda_p1=Keyboard::Key::A;
//	Atacar_p1=Keyboard::Key::S;
//	
//	Saltar_p2=Keyboard::Key::Numpad4;
//	Caminar_Derecha_p2=Keyboard::Key::Right;
//	Caminar_Izquierda_p2=Keyboard::Key::Left;
//	Atacar_p2=Keyboard::Key::Numpad8;
	
	m_Leer_Controles();
	
	
	for(int i=0;i<10;i++) { 
		menu_textura[i].loadFromFile("Menu_Controls_Sprite_"+to_string(i)+".png");
		menu_sprite[i].setTexture(menu_textura[i]);
	}
	InfoJugadores Info_J;
	
	
	menu_background_textura.loadFromFile("Menu_Controls_Background.jpg");
	menu_background_sprite.setTexture(menu_background_textura);
	
	
	m_font.loadFromFile("MKtitle1.ttf");
	text_nombre_player_1.setFont(m_font);
	text_nombre_player_1.setPosition(37,72);
	text_nombre_player_1.setCharacterSize(100);
	text_nombre_player_1.setColor({180,40,50});
	text_nombre_player_1.setString(Info_J.Ver_Nombre_Player_1());
	
	

	Text_Attack_Key_P1.setFont(m_font);
	Text_Attack_Key_P1.setCharacterSize(80);
	Text_Attack_Key_P1.setColor({180,40,50});

	m_Setear_Nombre_Teclas_En_Pantalla(pos_attack_text_p1,Atacar_p1, Text_Attack_Key_P1);
	
	Text_Jump_Key_P1.setFont(m_font);
	Text_Jump_Key_P1.setCharacterSize(80);
	Text_Jump_Key_P1.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_jump_text_p1,Saltar_p1, Text_Jump_Key_P1);
	
	
	Text_Right_Key_P1.setFont(m_font);
	Text_Right_Key_P1.setCharacterSize(80);
	Text_Right_Key_P1.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_derecha_text_p1,Caminar_Derecha_p1, Text_Right_Key_P1);
	
	Text_Left_Key_P1.setFont(m_font);
	Text_Left_Key_P1.setCharacterSize(80);
	Text_Left_Key_P1.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_izquierda_text_p1,Caminar_Izquierda_p1, Text_Left_Key_P1);
	
	
	text_nombre_player_2.setFont(m_font);
	text_nombre_player_2.setPosition(1538,91);
	text_nombre_player_2.setCharacterSize(100);
	text_nombre_player_2.setColor({180,40,50});
	text_nombre_player_2.setString(Info_J.Ver_Nombre_Player_2());
	
	
	Text_Attack_Key_P2.setFont(m_font);
	Text_Attack_Key_P2.setCharacterSize(80);
	Text_Attack_Key_P2.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_attack_text_p2,Atacar_p2, Text_Attack_Key_P2);
	
	Text_Jump_Key_P2.setFont(m_font);
	Text_Jump_Key_P2.setCharacterSize(80);
	Text_Jump_Key_P2.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_jump_text_p2,Saltar_p2, Text_Jump_Key_P2);
	
	Text_Right_Key_P2.setFont(m_font);
	Text_Right_Key_P2.setCharacterSize(80);
	Text_Right_Key_P2.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_derecha_text_p2,Caminar_Derecha_p2, Text_Right_Key_P2);
	
	Text_Left_Key_P2.setFont(m_font);
	Text_Left_Key_P2.setCharacterSize(80);
	Text_Left_Key_P2.setColor({180,40,50});
	m_Setear_Nombre_Teclas_En_Pantalla(pos_izquierda_text_p2,Caminar_Izquierda_p2, Text_Left_Key_P2);
	
	menu_sprite_principal=&menu_sprite[boton_seleccionado];
	
}

void Menu_Controls::Actualize (Juego &j) {
	//FUNCIONAMIENTO GENERAL DEL MENU//
	if(botones_menu_clock.getElapsedTime().asMilliseconds()>200){
		if(Keyboard::isKeyPressed(Keyboard::Key::Down)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado!=0){
				boton_seleccionado=boton_seleccionado-1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado<5){
				boton_seleccionado=boton_seleccionado+5;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Left)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado>4){
				boton_seleccionado=boton_seleccionado-5;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		
		if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
			sonido.moving_sound_effect();
			botones_menu_clock.restart();
			if(boton_seleccionado!=9){
				boton_seleccionado=boton_seleccionado+1;
				menu_sprite_principal=&menu_sprite[boton_seleccionado];
			};
		};
		if(Keyboard::isKeyPressed(Keyboard::Key::Return)){
			sonido.intro_sound_effect();
			switch(boton_seleccionado){
			case 0:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				j.CambiarMenu(new Menu_options());
				break;
			case 1:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Caminar_Izquierda_p1);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_izquierda_text_p1,Caminar_Izquierda_p1, Text_Left_Key_P1);
				break;
			case 2:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Caminar_Derecha_p1);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_derecha_text_p1,Caminar_Derecha_p1, Text_Right_Key_P1);
				break;
			case 3:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Saltar_p1);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_jump_text_p1,Saltar_p1, Text_Jump_Key_P1);
				break;
			case 4:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Atacar_p1);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_attack_text_p1,Atacar_p1, Text_Attack_Key_P1);
				break;
			case 5:
				m_Guardar_Cambios();
				break;
			case 6:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Caminar_Izquierda_p2);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_izquierda_text_p2,Caminar_Izquierda_p2, Text_Left_Key_P2);
				break;
			case 7:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Caminar_Derecha_p2);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_derecha_text_p2,Caminar_Derecha_p2, Text_Right_Key_P2);
				break;
			case 8:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Saltar_p2);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_jump_text_p2,Saltar_p2, Text_Jump_Key_P2);
				break;
			case 9:
				botones_menu_clock.restart();
				while(botones_menu_clock.getElapsedTime().asMilliseconds()<380){
					
				}
				m_Cambiar_Tecla(j,Atacar_p2);
				m_Setear_Nombre_Teclas_En_Pantalla(pos_attack_text_p2,Atacar_p2, Text_Attack_Key_P2);
				break;
			default:
				
				break;
			}
		};
	};
}

void Menu_Controls::Draw (RenderWindow & w) {
	
	w.draw(menu_background_sprite);
	w.draw(*menu_sprite_principal);
	w.draw(text_nombre_player_1);
	w.draw(text_nombre_player_2);
	w.draw(Text_Attack_Key_P1);
	w.draw(Text_Jump_Key_P1);
	w.draw(Text_Right_Key_P1);
	w.draw(Text_Left_Key_P1);
	w.draw(Text_Attack_Key_P2);
	w.draw(Text_Jump_Key_P2);
	w.draw(Text_Right_Key_P2);
	w.draw(Text_Left_Key_P2);
}

void Menu_Controls::m_Cambiar_Tecla(Juego &j, Keyboard::Key &k){
	Event e;
	RenderWindow *w=&j.ObtenerVentana();
	while(Keyboard::isKeyPressed(Keyboard::Key::Escape)==false) {
		w->pollEvent(e);
		if (e.type== Event::KeyPressed and e.key.code!= Keyboard::Key::Return and e.key.code!= Saltar_p1 and e.key.code!= Caminar_Derecha_p1 and e.key.code!= Caminar_Izquierda_p1 and e.key.code!= Atacar_p1 and e.key.code!= Saltar_p2 and e.key.code!= Caminar_Derecha_p2 and e.key.code!= Caminar_Izquierda_p2 and e.key.code!= Atacar_p2) {
			k=e.key.code;
			break;
		}
	}
}

void Menu_Controls::m_Guardar_Cambios(){
	ofstream archi("Controles_p1.poo",ios::binary);
	archi.write(reinterpret_cast<char*>(&Caminar_Izquierda_p1),sizeof(Keyboard::Key));
	archi.write(reinterpret_cast<char*>(&Caminar_Derecha_p1),sizeof(Keyboard::Key));
	archi.write(reinterpret_cast<char*>(&Saltar_p1),sizeof(Keyboard::Key));
	archi.write(reinterpret_cast<char*>(&Atacar_p1),sizeof(Keyboard::Key));
	archi.close();
	
	ofstream archiv("Controles_p2.poo",ios::binary);
	archiv.write(reinterpret_cast<char*>(&Caminar_Izquierda_p2),sizeof(Keyboard::Key));
	archiv.write(reinterpret_cast<char*>(&Caminar_Derecha_p2),sizeof(Keyboard::Key));
	archiv.write(reinterpret_cast<char*>(&Saltar_p2),sizeof(Keyboard::Key));
	archiv.write(reinterpret_cast<char*>(&Atacar_p2),sizeof(Keyboard::Key));
	archiv.close();
}

void Menu_Controls::m_Leer_Controles(){
	ifstream archi("Controles_p1.poo",ios::binary);
	archi.read(reinterpret_cast<char*>(&Caminar_Izquierda_p1),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Caminar_Derecha_p1),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Saltar_p1),sizeof(Keyboard::Key));
	archi.read(reinterpret_cast<char*>(&Atacar_p1),sizeof(Keyboard::Key));
	archi.close();
	
	ifstream archiv("Controles_p2.poo",ios::binary);
	archiv.read(reinterpret_cast<char*>(&Caminar_Izquierda_p2),sizeof(Keyboard::Key));
	archiv.read(reinterpret_cast<char*>(&Caminar_Derecha_p2),sizeof(Keyboard::Key));
	archiv.read(reinterpret_cast<char*>(&Saltar_p2),sizeof(Keyboard::Key));
	archiv.read(reinterpret_cast<char*>(&Atacar_p2),sizeof(Keyboard::Key));
	archiv.close();
}


void Menu_Controls::m_Setear_Nombre_Teclas_En_Pantalla(Vector2f posicion, Keyboard::Key k, Text &Key_text){
	
	Key_text.setString(m_Convertidor_Key_String(k));
	m_Ajustar_Tamano_Texto(Key_text);
	m_CentrarTexto(Key_text,posicion);
	
	
}

void Menu_Controls::m_CentrarTexto(Text &texto, Vector2f punto) {


	// Obtiene el tamaño del texto
	FloatRect bounds = texto.getLocalBounds();
	
	
	//Calcular el centro vertical y horizontalmente
	float centerX = bounds.left + (bounds.width/2);
	float centerY = bounds.top + (bounds.height/2);
	
	// Establecer el origen en el centro
	texto.setOrigin(centerX, centerY);
	texto.setPosition(punto.x, punto.y);
}

void Menu_Controls::m_Ajustar_Tamano_Texto(Text &texto) {
	// Define el tamaño máximo y mínimo del texto
	int tamanoMaximo = 80;
	int tamanoMinimo = 35;
	
	// Obtiene la longitud del texto actual
	int longitud = texto.getString().getSize();
	
	// Calcula el nuevo tamaño del texto basado en la longitud
	int nuevoTamano = tamanoMaximo - longitud*7;
	
	// Limita el tamaño del texto entre el máximo y el mínimo
	nuevoTamano = max(tamanoMinimo, min(tamanoMaximo, nuevoTamano));
	
	// Establece el nuevo tamaño del texto
	texto.setCharacterSize(nuevoTamano);
}


string Menu_Controls:: m_Convertidor_Key_String(Keyboard::Key k) {
	string s;

	switch (k) {
	case Keyboard::Key::A: s = "A"; break;
	case Keyboard::Key::B: s = "B"; break;
	case Keyboard::Key::C: s = "C"; break;
	case Keyboard::Key::D: s = "D"; break;
	case Keyboard::Key::E: s = "E"; break;
	case Keyboard::Key::F: s = "F"; break;
	case Keyboard::Key::G: s = "G"; break;
	case Keyboard::Key::H: s = "H"; break;
	case Keyboard::Key::I: s = "I"; break;
	case Keyboard::Key::J: s = "J"; break;
	case Keyboard::Key::K: s = "K"; break;
	case Keyboard::Key::L: s = "L"; break;
	case Keyboard::Key::M: s = "M"; break;
	case Keyboard::Key::N: s = "N"; break;
	case Keyboard::Key::O: s = "O"; break;
	case Keyboard::Key::P: s = "P"; break;
	case Keyboard::Key::Q: s = "Q"; break;
	case Keyboard::Key::R: s = "R"; break;
	case Keyboard::Key::S: s = "S"; break;
	case Keyboard::Key::T: s = "T"; break;
	case Keyboard::Key::U: s = "U"; break;
	case Keyboard::Key::V: s = "V"; break;
	case Keyboard::Key::W: s = "W"; break;
	case Keyboard::Key::X: s = "X"; break;
	case Keyboard::Key::Y: s = "Y"; break;
	case Keyboard::Key::Z: s = "Z"; break;
	case Keyboard::Key::Num0: s = "0"; break;
	case Keyboard::Key::Num1: s = "1"; break;
	case Keyboard::Key::Num2: s = "2"; break;
	case Keyboard::Key::Num3: s = "3"; break;
	case Keyboard::Key::Num4: s = "4"; break;
	case Keyboard::Key::Num5: s = "5"; break;
	case Keyboard::Key::Num6: s = "6"; break;
	case Keyboard::Key::Num7: s = "7"; break;
	case Keyboard::Key::Num8: s = "8"; break;
	case Keyboard::Key::Num9: s = "9"; break;
	case Keyboard::Key::Escape: s = "Escape"; break;
	case Keyboard::Key::LControl: s = "Ctrl iz"; break;
	case Keyboard::Key::LShift: s = "Shift izq"; break;
	case Keyboard::Key::LAlt: s = "Alt izq"; break;
	case Keyboard::Key::LSystem: s = "Sist izq"; break;
	case Keyboard::Key::RControl: s = "Ctrl der"; break;
	case Keyboard::Key::RShift: s = "Shift der"; break;
	case Keyboard::Key::RAlt: s = "Alt der"; break;
	case Keyboard::Key::RSystem: s = "Sist der"; break;
	case Keyboard::Key::Menu: s = "Menú"; break;
	case Keyboard::Key::LBracket: s = "["; break;
	case Keyboard::Key::RBracket: s = "]"; break;
	case Keyboard::Key::SemiColon: s = ";"; break;
	case Keyboard::Key::Comma: s = ","; break;
	case Keyboard::Key::Period: s = "."; break;
	case Keyboard::Key::Quote: s = "'"; break;
	case Keyboard::Key::Slash: s = "/"; break;
	case Keyboard::Key::BackSlash: s = "\\"; break;
	case Keyboard::Key::Tilde: s = "~"; break;
	case Keyboard::Key::Equal: s = "="; break;
	case Keyboard::Key::Dash: s = "-"; break;
	case Keyboard::Key::Space: s = "Espacio"; break;
	case Keyboard::Key::Return: s = "Enter"; break;
	case Keyboard::Key::BackSpace: s = "Retroceso"; break;
	case Keyboard::Key::Tab: s = "Tab"; break;
	case Keyboard::Key::PageUp: s = "Pág ar"; break;
	case Keyboard::Key::PageDown: s = "Pág ab"; break;
	case Keyboard::Key::End: s = "Fin"; break;
	case Keyboard::Key::Home: s = "Inicio"; break;
	case Keyboard::Key::Insert: s = "Insert"; break;
	case Keyboard::Key::Delete: s = "Borrar"; break;
	case Keyboard::Key::Add: s = "+"; break;
	case Keyboard::Key::Subtract: s = "-"; break;
	case Keyboard::Key::Multiply: s = "*"; break;
	case Keyboard::Key::Divide: s = "/"; break;
	case Keyboard::Key::Left: s = "Flecha izq"; break;
	case Keyboard::Key::Right: s = "Flecha der"; break;
	case Keyboard::Key::Up: s = "Flecha ar"; break;
	case Keyboard::Key::Down: s = "Flecha ab"; break;
	case Keyboard::Key::Numpad0: s = "Num0"; break;
	case Keyboard::Key::Numpad1: s = "Num1"; break;
	case Keyboard::Key::Numpad2: s = "Num2"; break;
	case Keyboard::Key::Numpad3: s = "Num3"; break;
	case Keyboard::Key::Numpad4: s = "Num4"; break;
	case Keyboard::Key::Numpad5: s = "Num5"; break;
	case Keyboard::Key::Numpad6: s = "Num6"; break;
	case Keyboard::Key::Numpad7: s = "Num7"; break;
	case Keyboard::Key::Numpad8: s = "Num8"; break;
	case Keyboard::Key::Numpad9: s = "Num9"; break;
	case Keyboard::Key::F1: s = "F1"; break;
	case Keyboard::Key::F2: s = "F2"; break;
	case Keyboard::Key::F3: s = "F3"; break;
	case Keyboard::Key::F4: s = "F4"; break;
	case Keyboard::Key::F5: s = "F5"; break;
	case Keyboard::Key::F6: s = "F6"; break;
	case Keyboard::Key::F7: s = "F7"; break;
	case Keyboard::Key::F8: s = "F8"; break;
	case Keyboard::Key::F9: s = "F9"; break;
	case Keyboard::Key::F10: s = "F10"; break;
	case Keyboard::Key::F11: s = "F11"; break;
	case Keyboard::Key::F12: s = "F12"; break;
	case Keyboard::Key::F13: s = "F13"; break;
	case Keyboard::Key::F14: s = "F14"; break;
	case Keyboard::Key::F15: s = "F15"; break;
	case Keyboard::Key::Pause: s = "Pausa"; break;
	default: s = "Tecla no contemplada"; break;
	}
	return s;
}

Menu_Controls::~Menu_Controls(){

}
