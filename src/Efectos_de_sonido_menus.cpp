#include "Efectos_de_sonido_menus.h"

using namespace std;
using namespace sf;

Efectos_de_sonido_menus::Efectos_de_sonido_menus() {
	moving_effect_soundbuffer.loadFromFile("audio/sfx/Menu_moving_effect.wav");
	moving_effect_sound.setBuffer(moving_effect_soundbuffer);
	intro_effect_soundbuffer.loadFromFile("audio/sfx/Menu_Intro_Effect.wav");
	intro_effect_sound.setBuffer(intro_effect_soundbuffer);
	
	
}

void Efectos_de_sonido_menus::play_music(int i){
	music.openFromFile("audio/music/Menu_music_"+to_string(i)+".wav");
	music.play();
}

void Efectos_de_sonido_menus::stop_music(){
	music.stop();
}

void Efectos_de_sonido_menus::moving_sound_effect(){
	moving_effect_sound.play();
}

void Efectos_de_sonido_menus::intro_sound_effect(){
	intro_effect_sound.play();
}


Efectos_de_sonido_menus::~Efectos_de_sonido_menus() {

	
}
