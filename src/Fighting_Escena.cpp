#include "Fighting_Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu_Pause.h"
#include <SFML/Window/Keyboard.hpp>
#include "Sub_Zero.h"
#include "Juego.h"
#include "Pantalla_principal.h"
#include "Escena.h"
#include <iostream>
#include "Round.h"
using namespace std;

Fighting_Escena::Fighting_Escena(){
	marcador.push_back(0);
	marcador.push_back(0);
	round_actual=1;
	menu=new Menu_Pause();
	
	//Cartel "Esc to Pause"
	m_font.loadFromFile("MKtitle1.ttf");
	Escape_Text.setFont(m_font);
	Escape_Text.setPosition(30,1020);
	Escape_Text.setCharacterSize(30);
	Escape_Text.setColor({255,20,50});
	Escape_Text.setString("Esc to Pause _");
}

void Fighting_Escena::Actualize(Juego &j) {
	//Usualmente las inicializaciones se hacen en el constructor, pero en este caso se necesita de la mismisima instancia de la clase Juego, por eso se hace la excepcion
	if(primera_iteracion){
		Player_1=j.Ver_Player_Selected_1();
		Player_2=j.Ver_Player_Selected_2();
		round=new Round(round_actual,Player_1,Player_2);
		primera_iteracion=false;
	}
	
	//Controla si el menu de pausa esta abierto o no
	if(Keyboard::isKeyPressed(Keyboard::Key::Escape) and cronometro_menu.getElapsedTime().asMilliseconds()>200 and menu_abierto==false){
		cronometro_menu.restart();
		menu_abierto=true;
	} else {
		if(Keyboard::isKeyPressed(Keyboard::Key::Escape) and cronometro_menu.getElapsedTime().asMilliseconds()>200 and menu_abierto==true){
			cronometro_menu.restart();
			menu_abierto=false;
		};
	};
	
	//Si el menu esta abierto, el mismo se debe "actualizar"
	if(menu_abierto==true){
		menu->Actualize(j);
	}
	
	//Si el menu no esta abierto
	if(menu_abierto==false){
		round->Actualize();//Round debe actualizarse
		ganador=round->Ganador(*this);
		if(ganador!=0){//Si Round devuelve un valor distinto a 0 significa que hay ganador, y que el round termino
			if(ganador==1){
				marcador[0]=marcador[0]+1;//marcador[0] cuenta los rounds ganados por player_1
			} else {
				marcador[1]=marcador[1]+1;//marcador[0] cuenta los rounds ganados por player_1
			};
			//Si alguno de los dos llego a ganar dos rounds la pelea termino
			if(marcador[0]==2){
				Info_J.Actualizar_Historial_Post_Fight(1);//Se indica que player_1 gano para que se actualize el historico
				j.CambiarEscena(new Pantalla_principal);//Se vuelve a la pantalla principal
			} else {
				if(marcador[1]==2){
					Info_J.Actualizar_Historial_Post_Fight(2);//Se indica que player_2 gano para que se actualize el historico
					j.CambiarEscena(new Pantalla_principal);//Se vuelve a la pantalla principal
				};
			};
			
			//Si el programa llego a esta instancia significa que no hay ganador aun, y si aux es distinto a nullptr signica que se debe iniciar un nuevo round
			if(aux){
				delete round;
				round=aux;
				aux=nullptr;
			};
		};
	};
	

	
}

void Fighting_Escena::Cambiar_menu(Menu_General *nuevo_menu){
	
}

void Fighting_Escena::CambiarRound(){//Round llama esta funcion a travez del *This para indicar que el round termino y que debe comenzar otro 
	round_actual+=1;//El contador de Rounds se actualiza
	aux = new Round(round_actual,Player_1,Player_2);//Se inicializa aux con un nuevo round
}


void Fighting_Escena::Draw(RenderWindow &w) {
	/*if(round->Ganador()==0){*/
	if(ganador==0){
	round->Draw(w);
	};
	if(menu_abierto==true){
		menu->Draw(w);
	}
	w.draw(Escape_Text);
}


Fighting_Escena::~Fighting_Escena(){
	delete round;
	delete aux;
	delete menu;
	
}
