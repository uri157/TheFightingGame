#include "Players_selected.h"

Players_selected::Players_selected() {
	
}

void Players_selected::Modificar_Player_1(int a) {
	Player_1=a;
}

void Players_selected::Modificar_Player_2(int b) {
	Player_2=b;
}

int Players_selected::Ver_Player_1() {
	return Player_1;
}

int Players_selected::Ver_Player_2() {
	return Player_2;
}

Players_selected::~Players_selected() {
	
}
