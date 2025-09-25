#ifndef EFECTOS_DE_SONIDO_MENUS_H
#define EFECTOS_DE_SONIDO_MENUS_H
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include "Assets.h"

using namespace std;
using namespace sf;

//Se encarga de la musica y los efectos de sonido de los menues
//Leyenda de la clase "play_music(int i)"
//0 Musica del Menu Principal
//1 Musica de seleccion de personaje	
class Efectos_de_sonido_menus {
	SoundBuffer moving_effect_soundbuffer, intro_effect_soundbuffer;
	Sound moving_effect_sound, intro_effect_sound;
	Music music;
public:
	Efectos_de_sonido_menus();
	void play_music(int i);
	void stop_music();
	void moving_sound_effect();
	void intro_sound_effect();
	~Efectos_de_sonido_menus();
};

#endif

