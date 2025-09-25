#include "Controles_Player_1.h"

#include <SFML/Window/Keyboard.hpp>
#include <fstream>

#include "FileIO.h"

using namespace std;
using namespace sf;

namespace {
void set_default_controls_player1(Keyboard::Key &left, Keyboard::Key &right, Keyboard::Key &jump, Keyboard::Key &attack) {
        left = Keyboard::Key::A;
        right = Keyboard::Key::D;
        jump = Keyboard::Key::Space;
        attack = Keyboard::Key::S;
}

void persist_player1_controls(const Keyboard::Key &left, const Keyboard::Key &right, const Keyboard::Key &jump, const Keyboard::Key &attack) {
        auto out = FileIO::open_ofstream_trunc("Controles_p1.poo", std::ios::binary | std::ios::trunc);
        if (!out) {
                return;
        }
        out.write(reinterpret_cast<const char*>(&left), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&right), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&jump), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&attack), sizeof(Keyboard::Key));
}
} // namespace

Controles_Player_1::Controles_Player_1(){
        auto archi = FileIO::open_ifstream_or_create("Controles_p1.poo", std::ios::binary);
        if (!archi || archi.peek() == std::ifstream::traits_type::eof()) {
                set_default_controls_player1(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                persist_player1_controls(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                return;
        }

        archi.read(reinterpret_cast<char*>(&Caminar_Izquierda),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Caminar_Derecha),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Saltar),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Atacar),sizeof(Keyboard::Key));

        if (!archi) {
                set_default_controls_player1(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                persist_player1_controls(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
        }
}




Controles_Player_1::~Controles_Player_1(){

}
