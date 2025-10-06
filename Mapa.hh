#ifndef MAPA_HH
#define MAPA_HH
#include <iostream>
#include <unistd.h>
#include <vector>
#include "Player.hh"
using namespace std; 

struct casilla {
    int show = 0; 
    int id; 
    char ch; 

};

class Mapa {    
    private: 
        //Tabla del mapa
        vector<vector<casilla>> map; 
        
        //Posicion donde esta el jugador en el eje x
        int pos_pj_x; 

        //Posicion donde este el jugador en el eje y
        int pos_pj_y; 

        //Tamaño maximo de la x
        int tam_max_x;
        
        //Tamaño maximo del eje y
        int tam_max_y; 


    public: 
        ///////////////////        
        // Constructoras //
        ///////////////////

        //Genera un mapa vacio
        Mapa(); 

        //Genera un mapa con la semilla seed y los limites tam_max_x y tam_max_y y asigna al jugador pj su posicion inicial 
        Mapa(int seed, Player& pj, int tam_max_x, int tam_max_y);

        ///////////////////
        // Modificadoras //
        ///////////////////

        //Se mueve al jugador en funcion de la tecla enviada por ch, estas pueden ser 'w',     'a',     's',   'd'
        //moviendo respectivamente hacia                                            arriba, izquierda, abajo, derecha
        //y luego devuelve un entero en función de la casilla donde haya entrado el jugador 
        pair<int, char> act_player(char ch, Player& pj); 
        
        /////////////////
        // Consultoras //
        /////////////////

        //Devuelve la distancia que hay desde la posicion del jugador hasta el exit del nivel actual
        int get_dist_exit(); 

        //Devuelve un vector de strings que contiene la informacion necesaria para actualizar las filas de la pantalla que 
        //contienen la pantalla con valores
        vector<string> obtener_casillas_chars();

        //////////////////////
        // Entrada / Salida //
        //////////////////////

        //Imprime el mapa por pantalla
        void print_mapa(); 

    private: 
        ///////////////////        
        // Constructoras //
        ///////////////////

        ///////////////////
        // Modificadoras //
        ///////////////////

        //Genera los bordes del mapa y las zonas sin objetos
        void generar_bordes_y_espacios();
        
        //Genera los puntos de eventos
        void generar_eventos();

        //Genera las zonas donde estan los enemigos
        void generar_enemigos();

        //Genera las zonas donde estan los objetos
        void generar_objetos();

        //Assigna una posicion inicial al Player pj
        void inciar_player(Player& pj); 

        //Hace que las posiciones de alrededor del jugador queden marcadas con show = 1
        // (Hace que al "imprimirse"/obtenerse en obtener_casillas_chars estas se entreguen 
        //  con su char corresponiente)
        void revelar_alrededor();
        
        /////////////////
        // Consultoras //
        /////////////////

        //////////////////////
        // Entrada / Salida //
        //////////////////////
};
#endif
