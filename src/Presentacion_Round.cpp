#include "Presentacion_Round.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace std;
using namespace sf;

Presentacion_Round::Presentacion_Round(int n_round,int p1, int p2) {

	//Inicializacion del texto que indica el numero de round
	m_font.loadFromFile("MKtitle1.ttf");
	m_text.setFont(m_font);
	m_text.setPosition(700,200);
	m_text.setCharacterSize(200);
	m_text.setColor({255,20,50});
	m_text.setString("Round "+to_string(n_round));
	
	//Inicializacion del "sonido" correspondiente al anuncio del round por el presentador
	round_announcer_effect_soundbuffer.loadFromFile("Round_"+to_string(n_round)+"_sound_effect.wav");
	round_announcer_effect_sound.setBuffer(round_announcer_effect_soundbuffer);
	

	//Setear los nombres de los luchadores y las presentaciones del anunciante en caso de que ganen el round
	
	//En caso de ganar player_1
	switch(p1){//Recibe como dato el codigo de luchador ganador
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		luchador_p1.setFont(m_font);
		luchador_p1.setPosition(500,200);
		luchador_p1.setCharacterSize(200);
		luchador_p1.setColor({255,50,50});
		luchador_p1.setString("Kratos Wins");
		wins_effect_soundbuffer_p1.loadFromFile("Kratos_wins_sound_effect.wav");
		wins_effect_sound_p1.setBuffer(wins_effect_soundbuffer_p1);
		break;
	case 2://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		luchador_p1.setFont(m_font);
		luchador_p1.setPosition(450,200);
		luchador_p1.setCharacterSize(200);
		luchador_p1.setColor({255,50,50});
		luchador_p1.setString("Sub Zero Wins");
		wins_effect_soundbuffer_p1.loadFromFile("Sub_Zero_wins_sound_effect.wav");
		wins_effect_sound_p1.setBuffer(wins_effect_soundbuffer_p1);
		break;
	default:
		break;
	}
	
	//En caso de ganar player_2
	switch(p2){//Recibe como dato el codigo de luchador ganador
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		luchador_p2.setFont(m_font);
		luchador_p2.setPosition(500,200);
		luchador_p2.setCharacterSize(200);
		luchador_p2.setColor({255,50,50});
		luchador_p2.setString("Kratos Wins");
		wins_effect_soundbuffer_p2.loadFromFile("Kratos_wins_sound_effect.wav");
		wins_effect_sound_p2.setBuffer(wins_effect_soundbuffer_p2);
		break;
	case 2://Para el codigo de luchador 2 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		luchador_p2.setFont(m_font);
		luchador_p2.setPosition(450,200);
		luchador_p2.setCharacterSize(200);
		luchador_p2.setColor({255,50,50});
		luchador_p2.setString("Sub Zero Wins");
		wins_effect_soundbuffer_p2.loadFromFile("Sub_Zero_wins_sound_effect.wav");
		wins_effect_sound_p2.setBuffer(wins_effect_soundbuffer_p2);
		break;
	default:
		break;
	}

}

void Presentacion_Round::Actualize(){
	if(((cronometro.getElapsedTime().asSeconds())>1) and (nunca_anunciado==true)){//Si ya paso mas de un segundo desde la creacion del round y nunca fue anunciado
		round_announcer_effect_sound.play();	
		nunca_anunciado=false;
	}
}

void Presentacion_Round::Anunciar_Ganador(int i){
	if((i==1) and (ganador_anunciado==false)){
		ganador=luchador_p1;
		wins_effect_sound_p1.play();
		ganador_anunciado=true;
		hay_ganador=true;
	}
	if((i==2) and (ganador_anunciado==false)){
		ganador=luchador_p2;
		wins_effect_sound_p2.play();
		ganador_anunciado=true;
		hay_ganador=true;
	}
	
}

void Presentacion_Round::Draw(RenderWindow &w){
	if(cronometro.getElapsedTime().asMilliseconds()>700 and cronometro.getElapsedTime().asMilliseconds()<3500){
		w.draw(m_text);
	}
	if(hay_ganador==true){
		w.draw(ganador);
	}
}

Presentacion_Round::~Presentacion_Round(){
	
}
