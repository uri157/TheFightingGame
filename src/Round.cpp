#include "Round.h"
#include "Healt_Bar.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Personaje_1_escena_fighting.h"
#include "Kratos.h"
#include "Sub_Zero.h"
#include "Menu_Pause.h"
#include "Fighting_Escena.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
using namespace std;
using namespace sf;



Round::Round(int round_num, int p1, int p2):battleground("mkbattleground.png"),Presentacion(round_num,p1,p2) {
	//INICIALIZACION DE LOS LUCHADORES ELEGIDOS POR LOS JUGADORES// 
	switch(p1){//Recibe como dato el codigo de luchador elegido por el Player_1
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		player_1= new Kratos(1);
		break;
	case 2://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		player_1= new Sub_Zero(1);
		break;
	default:
		break;
	}
	
	switch(p2){//Recibe como dato el codigo de luchador elegido por el Player_2
	case 1://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Kratos"
		player_2= new Kratos(2);
		break;
	case 2://Para el codigo de luchador 1 se sabe por la leyenda expresada en la cabezera de la clase "Players_selected" se sabe es "Sub Zero"
		player_2= new Sub_Zero(2);
		break;
	default:
		break;
	}
	
	//Declaracion de la barra de vida de los luchadores
	healt_bar=new Healt_Bar(p1,p2);
	
	
	presentacion_clock.restart(); //Inicia la presentacion
}

void Round::Actualize() {
	if(presentacion==false){//Si no esta en curso la presentacion
		//Actualizaciones
		player_1->Actualize();
		player_2->Actualize();
		healt_bar->Actualize(*this);//Le pasa su mismisima instancia a Healt_Bar para que pueda pedir directamente la info que necesita de los luchadores
		battleground.Actualize();
		Presentacion.Actualize();
		//¿Players Atacando?
		if(player_1->Atacando() and last_hit_player_1.getElapsedTime().asMilliseconds()>700){//Si player_1 esta atacando y el ultimo hit fue hace mas de 700ms (discretisacion de ataques)
			//Se comprueba si el golpe fue efectivo (le dio el Hit al rival)
			FloatRect pos=player_1->Posicion_Ataque();
			if(pos.intersects(player_2->Posicion_Defensa())){//En caso de haber sido efectivo el golpe
				last_hit_player_1.restart();//Se reinicia el cronometro
				if(player_1->Posicion_en_x()<player_2->Posicion_en_x()){//Si la posicion en el eje x del player 1 es menor a la del player 2
					player_2->Get_Hit(true);//Fue atacado desde la izquierda
				} else {
					player_2->Get_Hit(false);//Fue atacado desde la derecha
				}
				vida_player_2=vida_player_2-5;
			};
		};
	
		if(player_2->Atacando() and last_hit_player_2.getElapsedTime().asMilliseconds()>700){//Si player_2 esta atacando y el ultimo hit fue hace mas de 700ms (discretisacion de ataques)
			//Se comprueba si el golpe fue efectivo (le dio el Hit al rival)
			FloatRect pos=player_2->Posicion_Ataque();
			if(pos.intersects(player_1->Posicion_Defensa())){//En caso de haber sido efectivo el golpe
				last_hit_player_2.restart();//Se reinicia el cronometro
				if(player_1->Posicion_en_x()<player_2->Posicion_en_x()){//Si la posicion en el eje x del player 1 es menor a la del player 2
					player_1->Get_Hit(false);//Fue atacado desde la derecha
				} else {
					player_1->Get_Hit(true);//Fue atacado desde la izquierda
				}
				vida_player_1=vida_player_1-5;
			};
		};
	};
	
	if(presentacion_clock.getElapsedTime().asMilliseconds()<3000){
		presentacion=true;
		cronometro.restart();
	}else{
		if(presentacion==true){
			battleground.Play_music();
		};
		presentacion=false;
	}

	//Fin del Round
	if(vida_player_1 <= 0 or vida_player_2 <= 0){//Si alguno de los players ya no tiene vida restante
		battleground.Stop_music();
		//Se le informa al ganador que debe hacer dicha animacion y al perdedor que debe realizar la animacion de perdedor
		if(vida_player_2 <= 0){
			Presentacion.Anunciar_Ganador(1);
			player_1->fin_ganador();
			player_2->fin_perdedor();
		} else {
			Presentacion.Anunciar_Ganador(2);
			player_2->fin_ganador();
			player_1->fin_perdedor();
		}
	} else {
		if(Obtener_Valor_En_Segundos_Cronometro()<=0){
			battleground.Stop_music();
			if(vida_player_1 >= vida_player_2){
				Presentacion.Anunciar_Ganador(1);
				player_1->fin_ganador();
				player_2->fin_perdedor();
			} else {
				Presentacion.Anunciar_Ganador(2);
				player_2->fin_ganador();
				player_1->fin_perdedor();
			}
		}else{
			final_clock.restart();
		}
	}
}



int Round::Ganador(Fighting_Escena &Fighting){
	if((final_clock.getElapsedTime().asMilliseconds())>3500 /*and sepasoalganador==false*/){
		if(vida_player_1>=vida_player_2){
			Fighting.CambiarRound();
			return 1;
		} else {
			Fighting.CambiarRound();
			return 2;
		}
	}
	return 0;
}


void Round::Draw(RenderWindow &w) {
	battleground.Draw(w);
	healt_bar->Draw(w);
	player_1->Draw(w);
	player_2->Draw(w);
	Presentacion.Draw(w);
}


int Round::Obtener_Vida_Player_1(){
	return vida_player_1;
}

int Round::Obtener_Vida_Player_2(){
	return vida_player_2;
}

int Round::Obtener_Valor_En_Segundos_Cronometro(){
	if((60-cronometro.getElapsedTime().asSeconds())>0){
	return 60-cronometro.getElapsedTime().asSeconds();
	} else {
		return 0;
	};
}

Round::~Round(){
	delete player_1;
	delete player_2;
	delete healt_bar;
}
