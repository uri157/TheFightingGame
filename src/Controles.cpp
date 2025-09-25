#include "Controles.h"

Controles::Controles() {
	
}

bool Controles::Personaje_Caminando_Derecha ( ) {
	if(Keyboard::isKeyPressed(Caminar_Derecha)){
		return true;
	};
	return false;
}

bool Controles::Personaje_Caminando_Izquierda ( ) {
	if(Keyboard::isKeyPressed(Caminar_Izquierda)){
		return true;
	};
	return false;
}

bool Controles::Personaje_Saltando ( ) {
	if(Keyboard::isKeyPressed(Saltar)){
		return true;
	};
	return false;
}

bool Controles::Personaje_Atacando_Simple ( ) {
	if(Keyboard::isKeyPressed(Atacar)){
		return true;
	};
	return false;
}

void Controles::Cambiar_Tecla_Saltar(Keyboard::Key k){
	Saltar= k;
}

void Controles::Cambiar_Tecla_Atacar(Keyboard::Key k){
	Atacar= k;
}

void Controles::Cambiar_Tecla_Caminar_Derecha(Keyboard::Key k){
	Caminar_Derecha= k;
}

void Controles::Cambiar_Tecla_Caminar_Izquierda(Keyboard::Key k){
	Caminar_Izquierda= k;
}

Controles::~Controles() {
	
}
