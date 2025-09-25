#ifndef BATTLEGROUND_H
#define BATTLEGROUND_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio/Music.hpp>
using namespace std;
using namespace sf;



//Se encarga de la musica y el dibujado de el campo de batalla en la pelea
class Battleground {
	Texture battleground_textura;
	Sprite battleground_sprite;
	Music music;
public:
	Battleground(string battleground_name);
	void Draw(RenderWindow &w);
	void Actualize();
	void Play_music();
	void Stop_music();
	~Battleground();
};

#endif

