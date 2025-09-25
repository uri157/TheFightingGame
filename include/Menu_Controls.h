#ifndef MENU_CONTROLS_H
#define MENU_CONTROLS_H
#include "Menu_General.h"
#include <SFML/System/Clock.hpp>
#include "Efectos_de_sonido_menus.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
using namespace std;
using namespace sf;
//Este menu "emula" esteticamente un menu de controles de un videojuego convencional pero en este caso es solamente un panel de informacion donde los jugadores pueden ver los controles pero no modificarlos

class Menu_Controls : public Menu_General {
	Keyboard::Key Saltar_p1,Caminar_Derecha_p1,Caminar_Izquierda_p1,Atacar_p1,Saltar_p2,Caminar_Derecha_p2,Caminar_Izquierda_p2,Atacar_p2;
	Clock botones_menu_clock;
	Efectos_de_sonido_menus sonido;
	int boton_seleccionado=0;
	Texture menu_textura[10],menu_background_textura;
	Sprite menu_sprite[10],menu_background_sprite;
	Font m_font;
	Text text_nombre_player_1,text_nombre_player_2, Text_Attack_Key_P1, Text_Jump_Key_P1, Text_Left_Key_P1, Text_Right_Key_P1, Text_Attack_Key_P2, Text_Jump_Key_P2, Text_Left_Key_P2, Text_Right_Key_P2;
	Sprite *menu_sprite_principal;
	Vector2f pos_attack_text_p1,pos_derecha_text_p1,pos_izquierda_text_p1,pos_jump_text_p1,pos_attack_text_p2,pos_derecha_text_p2,pos_izquierda_text_p2,pos_jump_text_p2;
public:
	Menu_Controls();
	void Actualize (Juego &j);
	void Draw (RenderWindow &w);
	void m_Cambiar_Tecla(Juego &j, Keyboard::Key &k);
	void m_Guardar_Cambios();//Guarda los controles tal cual se encuentran en las variables en dos binarios, uno que corresponde a player 1 y otro que corresponde a player 2
	void m_Leer_Controles();//Lee los controles desde los binarios que corresponden a player 1 y player 2
	void m_Setear_Nombre_Teclas_En_Pantalla(Vector2f posicion, Keyboard::Key k, Text &Key_text);//Setea el nombre de las teclas que representan un "control" en pantalla
	string m_Convertidor_Key_String(Keyboard::Key k);
	void m_Ajustar_Tamano_Texto(Text &texto);
	void m_CentrarTexto(Text &texto, Vector2f punto);
	~Menu_Controls();
};

#endif

