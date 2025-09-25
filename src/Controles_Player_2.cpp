#include "Controles_Player_2.h"

#include <SFML/Window/Keyboard.hpp>
#include <fstream>

#include "FileIO.h"

using namespace std;
using namespace sf;

namespace {
void set_default_controls_player2(Keyboard::Key &left, Keyboard::Key &right, Keyboard::Key &jump, Keyboard::Key &attack) {
        left = Keyboard::Key::Left;
        right = Keyboard::Key::Right;
        jump = Keyboard::Key::Numpad4;
        attack = Keyboard::Key::Numpad8;
}

void persist_player2_controls(const Keyboard::Key &left, const Keyboard::Key &right, const Keyboard::Key &jump, const Keyboard::Key &attack) {
        auto out = FileIO::open_ofstream_trunc("Controles_p2.poo", std::ios::binary | std::ios::trunc);
        if (!out) {
                return;
        }
        out.write(reinterpret_cast<const char*>(&left), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&right), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&jump), sizeof(Keyboard::Key));
        out.write(reinterpret_cast<const char*>(&attack), sizeof(Keyboard::Key));
}
} // namespace

Controles_Player_2::Controles_Player_2() {
        auto archi = FileIO::open_ifstream_or_create("Controles_p2.poo", std::ios::binary);
        if (!archi || archi.peek() == std::ifstream::traits_type::eof()) {
                set_default_controls_player2(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                persist_player2_controls(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                return;
        }

        archi.read(reinterpret_cast<char*>(&Caminar_Izquierda),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Caminar_Derecha),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Saltar),sizeof(Keyboard::Key));
        archi.read(reinterpret_cast<char*>(&Atacar),sizeof(Keyboard::Key));

        if (!archi) {
                set_default_controls_player2(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
                persist_player2_controls(Caminar_Izquierda, Caminar_Derecha, Saltar, Atacar);
        }
}


Controles_Player_2::~Controles_Player_2() {

}
