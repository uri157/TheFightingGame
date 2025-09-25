#include "InfoJugadores.h"

#include <string>
#include <fstream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <iostream>
#include <cstring>

#include "FileIO.h"

using namespace std;
using namespace sf;

struct Historial{//Este struct es el que se guarda en el binario que almacena los historicos
        char Nombre[20];//Se utiliza este tipo de dato debido al problema que suponen los strings en los binarios
        int ganadas, perdidas;
};




InfoJugadores::InfoJugadores() {
        Actualizar_Nombres();
}


void InfoJugadores::Actualizar_Nombres(){
        //Se abre el archivo de texto que contiene los nombres ingresados por los jugadores, se los lee y almacena
        constexpr const char* default_player_1 = "Player 1";
        constexpr const char* default_player_2 = "Player 2";

        auto persist_defaults = [&](const string& name1, const string& name2) {
                auto out = FileIO::open_ofstream_trunc("InfoPublicaJugadores.txt", std::ios::out | std::ios::trunc);
                if (!out) {
                        return;
                }
                out << "Nombre Player 1:" << '\n';
                out << name1 << '\n';
                out << "Nombre Player 2:" << '\n';
                out << name2 << '\n';
        };

        auto archi = FileIO::open_ifstream_or_create("InfoPublicaJugadores.txt", std::ios::in);
        if (!archi || archi.peek() == std::ifstream::traits_type::eof()) {
                Nombre_Player_1 = default_player_1;
                Nombre_Player_2 = default_player_2;
                persist_defaults(Nombre_Player_1, Nombre_Player_2);
                return;
        }

        string etiqueta;
        if (!getline(archi, etiqueta) || !getline(archi, Nombre_Player_1) || !getline(archi, etiqueta) || !getline(archi, Nombre_Player_2)) {
                Nombre_Player_1 = default_player_1;
                Nombre_Player_2 = default_player_2;
                persist_defaults(Nombre_Player_1, Nombre_Player_2);
        }
}

void InfoJugadores::Actualizar_Historial_Post_Fight(int Ganador){ //Si le llega 1 gano player 1 y si le llega 2 gano el player 2
        //Se abre el archivo binario que contiene los historicos
        fstream archi;
        FileIO::open_fstream_rw_or_create("Historial.poo", archi, ios::binary|ios::out|ios::in|ios::ate);
        if (!archi) {
                return;
        }
        streampos pos = archi.tellg();//Se calcula el tamao del historial/archivo
        if (pos < 0) {
                pos = 0;
        }
        int Tamanio_Historial=static_cast<int>(pos/sizeof(Historial));//Se calcula el tamao del historial/archivo
        archi.seekg(0);//Se coloca el "cursor" de lectura en el principio del archivo
        Historial m_Historial;//Se declara una variable auxiliar para oficiar la lectura del archivo

        for(int i=0;i<Tamanio_Historial;i++){
                archi.read(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                string aux(m_Historial.Nombre);
                if(Ganador==1){
                        if(aux==Nombre_Player_1){
                                m_Historial.ganadas=m_Historial.ganadas+1;
                                archi.seekp(i*sizeof(Historial));
                                archi.write(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                                archi.seekg((i+1)*sizeof(Historial));
                        } else {
                                if(aux==Nombre_Player_2){
                                        m_Historial.perdidas=m_Historial.perdidas+1;
                                        archi.seekp(i*sizeof(Historial));
                                        archi.write(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                                        archi.seekg((i+1)*sizeof(Historial));
                                }
                        }
                } else {
                        if(aux==Nombre_Player_2){
                                m_Historial.ganadas=m_Historial.ganadas+1;
                                archi.seekp(i*sizeof(Historial));
                                archi.write(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                                archi.seekg((i+1)*sizeof(Historial));
                        } else {
                                if(aux==Nombre_Player_1){
                                        m_Historial.perdidas=m_Historial.perdidas+1;
                                        archi.seekp(i*sizeof(Historial));
                                        archi.write(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                                        archi.seekg((i+1)*sizeof(Historial));
                                }
                        }
                }
        }
}

void InfoJugadores::Obtener_Historial_Jugadores() {
        //Se abre el archivo binario que contiene los historicos
        fstream archi;
        FileIO::open_fstream_rw_or_create("Historial.poo", archi, ios::binary|ios::in|ios::out|ios::ate);
        if (!archi) {
                return;
        }
        streampos pos = archi.tellg();//Se calcula el tamao del historial/archivo
        if (pos < 0) {
                pos = 0;
        }
        int Tamanio_Historial=static_cast<int>(pos/sizeof(Historial));//Se calcula el tamao del historial/archivo
        archi.seekg(0);//Se coloca el "cursor" de lectura en el principio del archivo
        Historial m_Historial;//Se declara una variable auxiliar para oficiar la lectura del archivo

        bool Player_1_Contabilizado=false, Player_2_Contabilizado=false;
        for(int i=0;i<Tamanio_Historial;i++){
                archi.read(reinterpret_cast<char*>(&m_Historial), sizeof(Historial));
                string aux(m_Historial.Nombre);
                if(aux==Nombre_Player_1){
                        Ganadas_Player_1=m_Historial.ganadas;
                        Perdidas_Player_1=m_Historial.perdidas;
                        Player_1_Contabilizado=true;
                }
                if(aux==Nombre_Player_2){
                        Ganadas_Player_2=m_Historial.ganadas;
                        Perdidas_Player_2=m_Historial.perdidas;
                        Player_2_Contabilizado=true;
                }
        };


        if(Player_1_Contabilizado==false){//Si el player_1 no fue contabilizado, es decir es su primera vez jugando, debera ser agregado al historico
                strcpy(m_Historial.Nombre,Nombre_Player_1.c_str());
                m_Historial.ganadas=0;
                m_Historial.perdidas=0;
                Ganadas_Player_1=0;
                Perdidas_Player_1=0;
                archi.seekp(Tamanio_Historial*sizeof(Historial));
                archi.write(reinterpret_cast<char*>(&m_Historial),sizeof(Historial));
        }
        if(Player_2_Contabilizado==false){//Si el player_1 no fue contabilizado, es decir es su primera vez jugando, debera ser agregado al historico
                strcpy(m_Historial.Nombre,Nombre_Player_2.c_str());
                m_Historial.ganadas=0;
                m_Historial.perdidas=0;
                Ganadas_Player_2=0;
                Perdidas_Player_2=0;
                cout << Perdidas_Player_2;
                archi.seekp(Tamanio_Historial*sizeof(Historial));
                archi.write(reinterpret_cast<char*>(&m_Historial),sizeof(Historial));
        }


}

string InfoJugadores::Ver_Nombre_Player_1(){
        Actualizar_Nombres();
        return Nombre_Player_1;
}

int InfoJugadores::Ver_Ganadas_Player_1(){
        Obtener_Historial_Jugadores();
        return Ganadas_Player_1;
}

int InfoJugadores::Ver_Perdidas_Player_1(){
        Obtener_Historial_Jugadores();
        return Perdidas_Player_1;
}

string InfoJugadores::Ver_Nombre_Player_2(){
        Actualizar_Nombres();
        return Nombre_Player_2;
}

int InfoJugadores::Ver_Ganadas_Player_2(){
        Obtener_Historial_Jugadores();
        return Ganadas_Player_2;
}

int InfoJugadores::Ver_Perdidas_Player_2(){
        Obtener_Historial_Jugadores();
        return Perdidas_Player_2;
}

InfoJugadores::~InfoJugadores() {


}
