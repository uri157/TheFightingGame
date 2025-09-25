#ifndef PERSONAJE_1_ESCENA_FIGHTING_H
#define PERSONAJE_1_ESCENA_FIGHTING_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Controles.h"
using namespace std;
using namespace sf;

class Personaje_1_escena_fighting{
protected:
	Texture Pj_standing_texture[2];
	Texture Pj_get_hit_texture[4];
	Texture Pj_walking_texture[4];
	Texture Pj_attacking_texture[4];
	Texture Pj_jumping_texture[2];
	Texture Pj_win_texture;
	Texture Pj_losing_texture[2];
	Sprite Pj_standing_sprite[2];
	Sprite Pj_walking_sprite[4];
	Sprite Pj_attacking_sprite[4];
	Sprite Pj_jumping_sprite[2];
	Sprite Pj_get_hit_sprite[4];
	Sprite Pj_win_sprite;
	Sprite Pj_losing_sprite[2];
	Sprite *Sprite_Principal;
	bool salto=false,atacado_desde_izquierda,mirando_derecha,caminar_derecha=false,caminar_izquierda=false,ataque=false,ataque_en_movimiento_derecha=false,ataque_en_movimiento_izquierda=false,ataque_en_salto=false,arriba,get_hit=false,gano,fin=false,fuera_de_limites_derecha,fuera_de_limites_izquierda;
	Clock caminar_clock, atacar_clock,m_clock,get_hit_clock,footstep_clock;
	Vector2f posicion_original;
	SoundBuffer footstep_effect_soundbuffer;
	Sound footstep_effect_sound;
	float coeficiente_salto,m_vida, auxiliar_final_perdedor;
	Controles *controles;
public:
	Personaje_1_escena_fighting(int player_1_o_2,string nombre_luchador);
	void Actualize();
	virtual void Draw(RenderWindow &w)=0;
	bool Atacando();//devuelve un booleano a la clase que lo solicite indicando si el luchador esta atacando o no
	void fin_ganador();//Informa de que el luchador gano (por lo que se debe realizar la animacion correspondiente)
	void fin_perdedor();//Informa de que el luchador perdio (por lo que se debe realizar la animacion correspondiente)
	void Get_Hit(bool desde_izquierda);//Informa de que el luchador fue golpeado
	float Posicion_en_x();//Devuelve la posicion en el eje x del luchador
	void m_Get_Hit();//Ejecuta la animacion "ser golpeado" del luchador
	void m_Salto();//Se encarga de realizar la animacion de salto del luchador
	virtual void m_Ataque()=0;//Se encarga de realizar la animacion de ataque del luchador
	void m_Desplazamiento_Hacia_La_Derecha();//Se encarga de realizar el desplazamiento hacia la derecha del luchador
	void m_Desplazamiento_Hacia_La_Izquierda();//Se encarga de realizar el desplazamiento hacia la izquierda del luchador
	void m_Ejecutar_Fin_Ganador();//Se encarga de realizar la animacion "fin ganador" cuando el luchador gana el round
	void m_Ejecutar_Fin_Perdedor();//Se encarga de realizar la animacion "fin Perdedor" cuando el luchador pierde el round
	void m_Determinar_Dentro_Limites();//Se encarga de determinar si el luchador esta dentro de los limites de la pantalla
	void m_Personaje_De_Pie();//Se encarga de inicializar al personaje en posicion de pie cuando no esta realizando otra accion
	virtual FloatRect Posicion_Ataque()=0;//Retorna el "hitbox" de ataque
	FloatRect Posicion_Defensa();//Retorna el "hitbox" de defensa
	virtual void Jumping_Sound_Effect()=0;
	virtual void Attack_Sound_Effect()=0;
	virtual void Get_Hit_Sound_Effect()=0;
	virtual ~Personaje_1_escena_fighting();
};

#endif

