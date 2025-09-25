#include "Battleground.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
using namespace std;
using namespace sf;

Battleground::Battleground(string battleground_name) {//recibe un string con el nombre del mapa requerido
	battleground_textura.loadFromFile(battleground_name);
	battleground_sprite.setTexture(battleground_textura);
	battleground_sprite.setPosition(0, 0);
	music.openFromFile("Battleground_music_0.wav");
	music.setVolume(25);
}

void Battleground::Draw(RenderWindow &w){
	w.draw(battleground_sprite);
}

void Battleground::Actualize(){
	
}

void Battleground::Play_music(){
	music.play();
}

void Battleground::Stop_music(){
	music.stop();
}

Battleground::~Battleground(){}
