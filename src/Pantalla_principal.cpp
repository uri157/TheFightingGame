#include "Pantalla_principal.h"
#include <SFML/Window/Keyboard.hpp>
#include "Menu_Inicio.h"
#include "Juego.h"
#include "Fighting_Escena.h"
#include <iostream>
using namespace std;
using namespace sf;


Pantalla_principal::Pantalla_principal():menu(new Menu_Inicio()){
		sonido.play_music(0);
	}	
	
	
	
void Pantalla_principal::Draw(RenderWindow &w){
	background.Draw(w);
	menu->Draw(w);
}
	
	
	

void Pantalla_principal::Actualize(Juego &j){//Recibe la instancia de la mismisima instancia de la clase juego
	background.Actualize();
	menu->Actualize(j);//Le pasa dicha instancia de la clase Juego al menu para que realice el cambio de menu o escena de ser necesario
	if(menu_aux){//si menu_aux es distinto a nullptr se debe realizar el cambio
		delete menu;
		menu=menu_aux;
		menu_aux=nullptr;
	}
}
	
void Pantalla_principal::Cambiar_menu(Menu_General *nuevo_menu){//Recibe el nuevo Menu
	menu_aux=nuevo_menu;
}

	
Pantalla_principal::~Pantalla_principal(){
	delete menu;//Libera la memoria de menu 
}

