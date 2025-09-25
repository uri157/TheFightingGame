#include "Personaje_1_escena_fighting.h"
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Controles_Player_1.h"
#include "Controles_Player_2.h"
#include <iostream>
#include "Assets.h"
using namespace std;


Personaje_1_escena_fighting::Personaje_1_escena_fighting(int player_1_o_2,string nombre_luchador) {
	//Nota:Los personajes cargan un monton de sprites y texturas en distintos vectores y lo que se hace es que a travez de un puntero que se va modificando se va mostrando en cada momento el que corresponda
	//Inicializacion de sprites y texturas del luchador en posicion "de pie"
	for(int i=0;i<2;i++) { 
		Pj_standing_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_standing_"+to_string(i)+".png"));
		Pj_standing_sprite[i].setTexture(Pj_standing_texture[i]);
		Pj_standing_sprite[i].setPosition(480,700);
		Pj_standing_sprite[i].setScale(5,5);
	}
	
	//Se asigna al puntero que muestra el sprite en pantalla el sprite que corresponde de acuerdo a si es player 1 o player 2
	//Aclaracion:si es Player 1 arranca al lado izquierdo de la pantalla mirando hacia la derecha, y si es player 2 arranca del lado derecho mirando hacia la izquierda
	if(player_1_o_2==2){//Si es el player 2
		Sprite_Principal=&Pj_standing_sprite[1];
		Sprite_Principal->setPosition(1100,700);
		mirando_derecha=false;
		controles=new Controles_Player_2();//Se le asignan los controles correspondientes al player 2
	} else {//Si es el player 1
		Sprite_Principal=&Pj_standing_sprite[0];
		mirando_derecha=true;
		controles=new Controles_Player_1();//Se le asignan los controles correspondientes al player 1
	};
	
	
	//Inicializacion de sprites y texturas del luchador en accion "caminando"
	for(int i=0;i<4;i++) { 
		Pj_walking_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_walk_"+to_string(i)+".png"));
		Pj_walking_sprite[i].setTexture(Pj_walking_texture[i]);
		Pj_walking_sprite[i].setScale(5,5);
	}
	
	
	//Inicializacion de sprites y texturas del luchador en accion "atacando"
	for(int i=0;i<4;i++) { 
		Pj_attacking_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_attack_"+to_string(i)+".png"));
		Pj_attacking_sprite[i].setTexture(Pj_attacking_texture[i]);
		Pj_attacking_sprite[i].setScale(5,5);
	}
	
	
	//Inicializacion de sprites y texturas del luchador en accion "saltando"
	for(int i=0;i<2;i++) { 
		Pj_jumping_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_jump_"+to_string(i)+".png"));
		Pj_jumping_sprite[i].setTexture(Pj_jumping_texture[i]);
		Pj_jumping_sprite[i].setScale(5,5);
	}
	
	
	//Inicializacion de sprites y texturas del luchador en accion "final ganador"
	Pj_win_texture.loadFromFile(asset("sprites/"+nombre_luchador+"_wins.png"));
	Pj_win_sprite.setTexture(Pj_win_texture);
	Pj_win_sprite.setScale(5,5);
	
	
	//Inicializacion de sprites y texturas del luchador en accion "final perdedor"	
	for(int i=0;i<2;i++) { 
		Pj_losing_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_losing_"+to_string(i)+".png"));
		Pj_losing_sprite[i].setTexture(Pj_losing_texture[i]);
		Pj_losing_sprite[i].setScale(5,5);
		Pj_losing_sprite[i].setOrigin(0,-35);
	};
	
	
	//Inicializacion de sprites y texturas del luchador en accion "Recibir golpe"	
	for(int i=0;i<4;i++) { 
		Pj_get_hit_texture[i].loadFromFile(asset("sprites/"+nombre_luchador+"_get_hit_"+to_string(i)+".png"));
		Pj_get_hit_sprite[i].setTexture(Pj_get_hit_texture[i]);
		Pj_get_hit_sprite[i].setScale(5,5);
	}
	
	
	//Efectos de sonido correspondientes a los pasos
	footstep_effect_soundbuffer.loadFromFile(asset("audio/music/footstep_sound_effect.wav"));
	footstep_effect_sound.setBuffer(footstep_effect_soundbuffer);
	footstep_effect_sound.setVolume(35);
}

void Personaje_1_escena_fighting::Actualize() {
	if(fin==true and ataque==false){
		//Si termino el Round y no esta en posicion de ataque
		if(gano==true){
			//FINAL SI GANO EL ROUND
			m_Ejecutar_Fin_Ganador();
		} else {
			//FINAL SI PERDIO EL ROUND
			m_Ejecutar_Fin_Perdedor();
		};
	}else{
		//Si no termino el Round o se esta en posicion de ataque
		//En las clases que realizan el desplazamiento interfiere algo llamado coeficiente de salto, ya que cuando el personaje esta realizando un salto se mueve mas rapido que al caminar
		if(salto==true){
			coeficiente_salto=1.5;
		} else {
			coeficiente_salto=1;
		}
		m_Personaje_De_Pie();
		m_Determinar_Dentro_Limites();
		m_Desplazamiento_Hacia_La_Izquierda();
		m_Desplazamiento_Hacia_La_Derecha();
		m_Ataque();
		m_Salto();
		m_Get_Hit();
	}
}

void Personaje_1_escena_fighting::m_Ejecutar_Fin_Ganador(){
	Vector2f pos=Sprite_Principal->getPosition();
	Sprite_Principal=&Pj_win_sprite;	
	Sprite_Principal->setPosition(pos);
}


void Personaje_1_escena_fighting::m_Ejecutar_Fin_Perdedor(){
	posicion_original=Sprite_Principal->getPosition();
	//ASIGNACION DEL SPRITE CORRESPONDIENTE DE ACUERDO A LA ORIENTACION ACTUAL DEL LUCHADOR//
	if(atacado_desde_izquierda==false){//Si esta mirando hacia la derecha se asignan los sprites correspondientes orientados hacia la derecha
		Vector2f pos=Sprite_Principal->getPosition(); 
		Sprite_Principal=&Pj_get_hit_sprite[2];
		Sprite_Principal->setPosition(pos);
		//En la animacion del "final perdedor", si el luchador esta mirando hacia la derecha se desplaza hacia la izquierda, pero esto se debe limitar en caso de que este en el borde de la pantalla para que no escape del limite de la misma
		if(fuera_de_limites_izquierda==true){
			auxiliar_final_perdedor=0;
		}else{
			auxiliar_final_perdedor=-5;
		};
	} else {//Si esta mirando hacia la izquierda se asignan los sprites correspondientes orientados hacia la izquierda
		Vector2f pos=Sprite_Principal->getPosition();
		Sprite_Principal=&Pj_get_hit_sprite[3];
		Sprite_Principal->setPosition(pos);
		//En la animacion del "final perdedor", si el luchador esta mirando hacia la izquierda se desplaza hacia la derecha, pero esto se debe limitar en caso de que este en el borde de la pantalla para que no escape del limite de la misma
		if(fuera_de_limites_derecha==true){
			auxiliar_final_perdedor=-2;
		}else{
			auxiliar_final_perdedor=5;
		};
	};
	//FIN ASIGNACION DEL SPRITE CORRESPONDIENTE DE ACUERDO A LA ORIENTACION ACTUAL DEL LUCHADOR//
	
	//ANIMACION DEL FINAL PERDEDOR//
	if(m_clock.getElapsedTime().asMilliseconds()<100){//Los primeros 100ms se mueve de la siguiente manera
		Sprite_Principal->move(auxiliar_final_perdedor,-40);
	} else {
		if(m_clock.getElapsedTime().asMilliseconds()<200){//Los segundos 100ms se mueve de la siguiente manera
			Sprite_Principal->move(auxiliar_final_perdedor,-20);
		} else {
			if(m_clock.getElapsedTime().asMilliseconds()<300){//Los terceros 100ms se mueve de la siguiente manera
				Sprite_Principal->move(auxiliar_final_perdedor,-10);
			} else {
				if(m_clock.getElapsedTime().asMilliseconds()<400){//Los cuartos 100ms se mueve de la siguiente manera
					Sprite_Principal->move(auxiliar_final_perdedor,10);
				} else {
					if(m_clock.getElapsedTime().asMilliseconds()<500){//Los quintos 100ms se mueve de la siguiente manera
						Sprite_Principal->move(auxiliar_final_perdedor,20);
					} else {
						if(m_clock.getElapsedTime().asMilliseconds()<600){//Los sextos 100ms se mueve de la siguiente manera
							Sprite_Principal->move(auxiliar_final_perdedor,40);
						} else {//Una vez pasados 600ms la animacion termina
							if(mirando_derecha==true){//De acuerdo a su orientacion se le debe asignar el sprite correspondiente
								Sprite_Principal=&Pj_losing_sprite[0]; 
							} else {
								Sprite_Principal=&Pj_losing_sprite[1];
							};
							Sprite_Principal->setPosition(posicion_original);//Debe volver a posicionarse el sprite en el punto (x,y) original
						};
					};	
				};
			};
		};
	};	
}

void Personaje_1_escena_fighting::m_Determinar_Dentro_Limites(){
	if(Sprite_Principal->getPosition().x>1700){//Dentro de los limites del lado derecho?
		fuera_de_limites_derecha=true;
	} else {
		fuera_de_limites_derecha=false;
	}
	
	if(Sprite_Principal->getPosition().x<0){//Dentro de los limites del lado izquierdo?
		fuera_de_limites_izquierda=true;
	} else {
		fuera_de_limites_izquierda=false;
	}	
}

void Personaje_1_escena_fighting::m_Personaje_De_Pie(){
	if(caminar_izquierda==false and caminar_derecha==false and salto==false){
		if(mirando_derecha==true){
			Vector2f pos=Sprite_Principal->getPosition();
			Sprite_Principal=&Pj_standing_sprite[0];
			Sprite_Principal->setPosition(pos);
		} else {
			Vector2f pos=Sprite_Principal->getPosition();
			Sprite_Principal=&Pj_standing_sprite[1];
			Sprite_Principal->setPosition(pos);
		};
	};
}

void Personaje_1_escena_fighting::m_Desplazamiento_Hacia_La_Izquierda(){
	if(controles->Personaje_Caminando_Izquierda() and get_hit==false and fuera_de_limites_izquierda==false){//Si no se esta en los limites de la pantalla a la izquierda, no se esta siendo golpeado y el jugador pulso la tecla de moverse hacia la izquierda
		if(footstep_clock.getElapsedTime().asMilliseconds()>300){//Si hace mas de 300ms desde que se reprodujo por ultima vez el efecto de sonido de "pasos"
			footstep_clock.restart();
			footstep_effect_sound.play();
		};
		if(ataque==true){//Si se esta produciendo la animacion de ataque
			ataque_en_movimiento_izquierda=true;//Hay un ataque en movimiento
			if(ataque_en_movimiento_derecha){//Si existe un ataque en movimiento en sentido contrario se cancela
				ataque=false;
				ataque_en_movimiento_derecha=false;
				ataque_en_movimiento_izquierda=false;
			};
		};
		caminar_izquierda=true;
		mirando_derecha=false;
		//Nota:La animacion de caminar consta de 2 sprites, los cuales van alternando cada 150ms
		if(caminar_clock.getElapsedTime().asMilliseconds()<150){
			if(salto==false){//Si no se esta dando un salto, se inicializa el sprite 2 los primeros 150ms de desplazamiento. Si hay un salto en ejecucion el luchador se desplaza con el mismo sprite de salto
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_walking_sprite[2];
				Sprite_Principal->setPosition(pos);
			};
			Sprite_Principal->move(-7*coeficiente_salto,0);
			
		};
		if(caminar_clock.getElapsedTime().asMilliseconds()>150 and caminar_clock.getElapsedTime().asMilliseconds()<300){
			if(salto==false){//Si no se esta dando un salto, se inicializa el sprite 3 durante los segundos 150ms de desplazamiento. Si hay un salto en ejecucion el luchador se desplaza con el mismo sprite de salto
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_walking_sprite[3];
				Sprite_Principal->setPosition(pos);
			};
			Sprite_Principal->move(-7*coeficiente_salto,0);
		};
		if(caminar_clock.getElapsedTime().asMilliseconds()>300){//Una vez terminados los 300ms que dura la animacion se reinicia el ciclo
			caminar_clock.restart();
		};
	}else{
		caminar_izquierda=false;
	};
}


void Personaje_1_escena_fighting::m_Desplazamiento_Hacia_La_Derecha(){
	if(controles->Personaje_Caminando_Derecha() and get_hit==false and fuera_de_limites_derecha==false){//Si no se esta en los limites de la pantalla a la derecha, no se esta siendo golpeado y el jugador pulso la tecla de moverse hacia la derecha
		if(footstep_clock.getElapsedTime().asMilliseconds()>300){//Si hace mas de 300ms desde que se reprodujo por ultima vez el efecto de sonido de "pasos"
			footstep_clock.restart();
			footstep_effect_sound.play();
		};
		if(ataque==true){//Si se esta produciendo la animacion de ataque
			ataque_en_movimiento_derecha=true;//Hay un ataque en movimiento
			if(ataque_en_movimiento_izquierda){//Si existe un ataque en movimiento en sentido contrario se cancela
				ataque=false;
				ataque_en_movimiento_derecha=false;
				ataque_en_movimiento_izquierda=false;
			};
		};
		caminar_derecha=true;
		mirando_derecha=true;
		//Nota:La animacion de caminar consta de 2 sprites, los cuales van alternando cada 150ms
		if(caminar_clock.getElapsedTime().asMilliseconds()<150){
			if(salto==false){//Si no se esta dando un salto, se inicializa el sprite 0 los primeros 150ms de desplazamiento. Si hay un salto en ejecucion el luchador se desplaza con el mismo sprite de salto
				coeficiente_salto=1;
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_walking_sprite[0];
				Sprite_Principal->setPosition(pos);
			};
			Sprite_Principal->move(7*coeficiente_salto,0);
			
		};
		if(caminar_clock.getElapsedTime().asMilliseconds()>150 and caminar_clock.getElapsedTime().asMilliseconds()<300){
			if(salto==false){//Si no se esta dando un salto, se inicializa el sprite 1 durante los segundos 150ms de desplazamiento. Si hay un salto en ejecucion el luchador se desplaza con el mismo sprite de salto
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_walking_sprite[1];
				Sprite_Principal->setPosition(pos);
			};
			Sprite_Principal->move(7*coeficiente_salto,0);
		};
		if(caminar_clock.getElapsedTime().asMilliseconds()>300){//Una vez terminados los 300ms que dura la animacion se reinicia el ciclo
			caminar_clock.restart();
		};
	}else{
		caminar_derecha=false;
	}
}


void Personaje_1_escena_fighting::m_Salto(){
	if(salto==false and get_hit==false){//Si no esta saltando y no esta siendo golpeado en este momento
		if(controles->Personaje_Saltando()){//Si el jugador presiona la tecla de salto
			Jumping_Sound_Effect();
			ataque=false;//Se cancela el ataque en caso de estar en curso
			posicion_original=Sprite_Principal->getPosition();//Se toma la posicion de inicio
			salto=true;
			arriba=true;
			m_clock.restart();
		};
	};
	
	if(salto==true){//Si el luchador se encuentra saltando
		//SPRITES
		//Nota:el luchador al saltar cancela el ataque de estar realizandolo, pero mientras salta puede atacar si lo desea y de ser asi se muestran los sprites del ataque y no los de salto
		if(ataque==false){ //Siempre y cuando el luchador no realize un ataque en medio del salto en curso, se muestra el sprite en posicion de salto de acuerdo a la orientacion que corresponda
			if(mirando_derecha==true){
				Vector2f pos=Sprite_Principal->getPosition(); 
				Sprite_Principal=&Pj_jumping_sprite[0];
				Sprite_Principal->setPosition(pos);
			} else {
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_jumping_sprite[1];
				Sprite_Principal->setPosition(pos);
			};
		};
		
		//Animacion de salto
		if(m_clock.getElapsedTime().asMilliseconds()<100){//Los primeros 100ms se mueve de la siguiente manera
			Sprite_Principal->move(0,-40);
		} else {
			if(m_clock.getElapsedTime().asMilliseconds()<200){//Los segundos 100ms se mueve de la siguiente manera
				Sprite_Principal->move(0,-20);
			} else {
				if(m_clock.getElapsedTime().asMilliseconds()<300){//Los tercer 100ms se mueve de la siguiente manera
					Sprite_Principal->move(0,-10);
				} else {
					if(m_clock.getElapsedTime().asMilliseconds()<400){//Los cuartos 100ms se mueve de la siguiente manera
						Sprite_Principal->move(0,10);
					} else {
						if(m_clock.getElapsedTime().asMilliseconds()<500){//Los quintos 100ms se mueve de la siguiente manera
							Sprite_Principal->move(0,20);
						} else {
							if(m_clock.getElapsedTime().asMilliseconds()<600){//Los sextos 100ms se mueve de la siguiente manera
								Sprite_Principal->move(0,40);
							} else {//Luego de los 600ms la animacion de salto termina 
								footstep_effect_sound.play();
								salto=false;//termina el salto
								posicion_original.x=Sprite_Principal->getPosition().x;//se debe volver a la posicion original en y (aunque no en x)
								Sprite_Principal->setPosition(posicion_original);
								arriba=false;
								ataque_en_salto=false;
							};
						};
					};
				};
			};
		};
	};
}

void Personaje_1_escena_fighting::m_Get_Hit(){
	if(get_hit==true and get_hit_clock.getElapsedTime().asMilliseconds()<500){//Si el luchador ha sido golpeado y han pasado menos desde 500ms desde el echo
		int coeficiente=1;
		if(atacado_desde_izquierda==false){//Si el luchador esta orientado hacia la derecha
			if(salto==true){//Si esta en el aire se inicializan los sprites de caida orientado hacia la derecha
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_get_hit_sprite[2];
				Sprite_Principal->setPosition(pos);
			} else {//Si no esta en el aire se inicializan los sprites de "golpeado" orientado hacia la derecha
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_get_hit_sprite[0];
				Sprite_Principal->setPosition(pos);
			}; 
			if(fuera_de_limites_izquierda==true){
				coeficiente=0;
			}
		}else {//Si el luchador esta orientado hacia la izquierda
			if(fuera_de_limites_derecha==true){//Si esta fuera de los limites al ser golpeado no sera desplazado
				coeficiente=0;
			}else{//Si esta dentro de los limites sera desplazado
				coeficiente=-1;
			};
			if(salto==true){//Si esta en el aire se inicializan los sprites de caida orientado hacia la izquierda
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_get_hit_sprite[3];
				Sprite_Principal->setPosition(pos);
			} else {//Si no esta en el aire se inicializan los sprites de "golpeado" orientado hacia la izquierda
				Vector2f pos=Sprite_Principal->getPosition();
				Sprite_Principal=&Pj_get_hit_sprite[1];
				Sprite_Principal->setPosition(pos);
			};
		};
		if(get_hit_clock.getElapsedTime().asMilliseconds()<100){//Los primeros 100ms se desplazara de la siguiente manera
			Sprite_Principal->move(-20*coeficiente,0);
		} else {
			if(get_hit_clock.getElapsedTime().asMilliseconds()<200){//Los segundos 100ms se desplazara de la siguiente manera
				Sprite_Principal->move(-10*coeficiente,0);
			} else {
				if(get_hit_clock.getElapsedTime().asMilliseconds()<300){//Los tercer y cuartos 100ms se desplazara de la siguiente manera
					Sprite_Principal->move(-5*coeficiente,0);
				}
			}
		}
	} else { //Una vez pasados los 500ms que dura la animacion
		get_hit=false;
	}	
}

bool Personaje_1_escena_fighting::Atacando(){
	if(ataque==true){
		return true;
	};
	return false;
}

float Personaje_1_escena_fighting::Posicion_en_x(){
	return Sprite_Principal->getPosition().x;
}

void Personaje_1_escena_fighting::fin_ganador(){
	fin=true;
	gano=true;
}

void Personaje_1_escena_fighting::fin_perdedor(){
	if(fin==false){
		m_clock.restart();
	}
	fin=true;
	gano=false;
}

void Personaje_1_escena_fighting::Get_Hit(bool desde_izquierda){
	atacado_desde_izquierda=desde_izquierda;
	if(get_hit==false){
		get_hit=true;
		get_hit_clock.restart();
		Get_Hit_Sound_Effect();
	};
}


Personaje_1_escena_fighting::~Personaje_1_escena_fighting() {
        delete controles;
        // No delete: puntero no propietario (apunta a sprites miembro)
        Sprite_Principal = nullptr;
}

FloatRect Personaje_1_escena_fighting::Posicion_Defensa(){
	return Sprite_Principal->getGlobalBounds();
}
