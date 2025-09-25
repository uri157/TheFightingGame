#ifndef SUB_ZERO_H
#define SUB_ZERO_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include "Personaje_1_escena_fighting.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Controles.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
using namespace std;
using namespace sf;

class Sub_Zero: public Personaje_1_escena_fighting{
	Texture Sub_Zero_ice_ball_texture[2];
	Sprite Sub_Zero_ice_ball_sprite[2];
	Sprite *Sub_Zero_pointer_ice_ball_sprite;
	bool direccion_ataque_derecha;
	SoundBuffer attacking_effect_soundbuffer, jumping_effect_soundbuffer, get_hit_effect_soundbuffer;
	Sound attacking_effect_sound, jumping_effect_sound, get_hit_effect_sound;
public:
	Sub_Zero(int player_1_o_2);
	void Draw(RenderWindow &w)override;
	void m_Ataque()override;
	FloatRect Posicion_Ataque()override;
	void Jumping_Sound_Effect()override;
	void Attack_Sound_Effect()override;
	void Get_Hit_Sound_Effect()override;
	~Sub_Zero()override;
};

#endif

