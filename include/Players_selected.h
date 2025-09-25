#ifndef PLAYERS_SELECTED_H
#define PLAYERS_SELECTED_H



//Esta clase se encarga de guardar los "codigos de luchadores" elegidos por los jugadores 
//Leyenda
//1=Kratos
//2=Sub_Zero

class Players_selected {
	int Player_1=1;
	int Player_2=2;
public:
	Players_selected();
	void Modificar_Player_1(int a);//A travez de esta clase se ingresa el codigo del luchador que elige el Player_1
	void Modificar_Player_2(int b);//A travez de esta clase se ingresa el codigo del luchador que elige el Player_2
	int Ver_Player_1();//A travez de esta clase se consulta el codigo del luchador que elige el Player_1
	int Ver_Player_2();//A travez de esta clase se consulta el codigo del luchador que elige el Player_2
	~Players_selected();
};

#endif

