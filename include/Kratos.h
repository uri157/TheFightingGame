#ifndef KRATOS_H
#define KRATOS_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include "Personaje_1_escena_fighting.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Controles.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
using namespace std;
using namespace sf;

class Kratos : public Personaje_1_escena_fighting{
	SoundBuffer attacking_effect_soundbuffer, jumping_effect_soundbuffer, get_hit_effect_soundbuffer;
	Sound attacking_effect_sound, jumping_effect_sound, get_hit_effect_sound;
public:
	Kratos(int player_1_o_2);
	void Draw(RenderWindow &w)override;//Se encarga del dibujado del sprite principal, el nombre en la barra de vida y el texto del final cuando gana
	void m_Ataque()override;//Se encarga de realizar la animacion de ataque del luchador
	void Jumping_Sound_Effect()override;
	void Attack_Sound_Effect()override;
	void Get_Hit_Sound_Effect()override;
	FloatRect Posicion_Ataque()override;//Retorna el "hitbox"
	~Kratos();
	
};

#endif

