#ifndef PRESENTACION_ROUND_H
#define PRESENTACION_ROUND_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

using namespace std;
using namespace sf;

//Se encarga de mostrar el cartel de presentacion del round y reproducir la voz del anunciante y de realizar la presentacion del ganador mostrando un cartel y reproduciendo la voz del anunciante

class Presentacion_Round {
	Font m_font;
	Text m_text, luchador_p1,luchador_p2,ganador;
	SoundBuffer round_announcer_effect_soundbuffer,wins_effect_soundbuffer_p1,wins_effect_soundbuffer_p2;
	Sound round_announcer_effect_sound,wins_effect_sound_p1,wins_effect_sound_p2;
	Clock cronometro;//Este cronometro se utiliza para darle un margen al round desde que es creado, ya que sino es anunciado antes de ser mostrado en pantalla
	bool nunca_anunciado=true;//Se utiliza junto al cronometro para dar el margen anteriormente descrito
	bool hay_ganador=false;//Se utiliza para saber si se debe dibujar el nombre del ganador
	bool ganador_anunciado=false;//Se utiliza para saber si se debe anunciar el ganador
public:
	Presentacion_Round(int n_round, int p1, int p2);
	void Draw(RenderWindow &w);
	void Actualize();
	void Anunciar_Ganador(int i);
	~Presentacion_Round();
};

#endif

