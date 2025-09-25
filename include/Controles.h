#ifndef CONTROLES_H
#define CONTROLES_H
#include <SFML/Window/Keyboard.hpp>
using namespace sf;
using namespace std;

class Controles {
protected:
	Keyboard::Key Saltar;
	Keyboard::Key Caminar_Derecha;
	Keyboard::Key Caminar_Izquierda;
	Keyboard::Key Atacar;
public:
	Controles();
	bool Personaje_Caminando_Derecha();
	bool Personaje_Caminando_Izquierda();
	bool Personaje_Saltando();
	bool Personaje_Atacando_Simple();
	void Cambiar_Tecla_Saltar(Keyboard::Key k);
	void Cambiar_Tecla_Atacar(Keyboard::Key k);
	void Cambiar_Tecla_Caminar_Derecha(Keyboard::Key k);
	void Cambiar_Tecla_Caminar_Izquierda(Keyboard::Key k);
	~Controles();
};

#endif

