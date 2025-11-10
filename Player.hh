#ifndef PLAYER_HH
#define PLAYER_HH
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std; 
class Player {
    private: 
        //Posicion de columna en el mapa del jugador
        int pos_x; 

        //Posicion de fila en el mapa del jugador 
        int pos_y; 

        //Cantidad de ataque del jugador
        int atk; 

        //Cantidad de vida
        int hp;

        //Cantidad de mana
        int mana; 

        //Cantidad de mana restantes
        int mana_rest; 

        //Pasos restantes 
        int pasos; 

        //Flashes restantes
        int flash;  

        //Hechizos equipados
        //vector<int> eq_hechizos;

        //Objetos de buffeo
        //vector<int> eq_objetos; 
    public: 
        
        ///////////////////        
        // Constructoras //
        ///////////////////

        //Se crea a un Player iniciado todo a ceros
        Player(); 
        
        //Se crea al jugador en la posicion pos_x y pos_y
        Player(int pos_x, int pos_y); 


        ///////////////////
        // Modificadoras //
        ///////////////////

        //Se assigna al jugador la pos_x, pos_y
        void assignar_pos(int pos_x, int pos_y);

        //Se canvia la posicion del jugador sumandole el valor que tiene en inc_pos_x y inc_pos_y 
        //a la pos_x y pos_y del jugador en el caso de que el resultado este dentro del rango [1..max_x] y [1..max_y]
        void variar_pos_player(int inc_pos_x, int inc_pos_y); 

        //En el caso que (flash + cant) >= 0 hace que el jugador tenga una cantidad de flashes += cant y devuelve 1
        //En el caso contrario (flash + cant) < 0 devuelve 0 y no hace ninguna actualizacions
        int modificar_flash(int cant);

        //En el caso que (pasos + cant) >= 0 hace que el jugador tenga una cantidad de pasos += cant y devuelve 1
        //En el caso contrario (pasos + cant) < 0 devuelve 0 y no hace ninguna actualizacions 
        int modificar_pasos(int cant); 


        //Devuelve un vector V que contiene lo siguiente
        //V[0] = pasos
        //V[1] = atk
        //V[2] = hp
        //V[3] = mana
        //V[4] = flash
        vector<int> get_stats(); 
        

        /////////////////
        // Consultoras //
        /////////////////

        //Devuelve el valor pos_x de player
        int get_pos_x(); 

        //Devuelve el valor pos_y de player
        int get_pos_y(); 

        //////////////////////
        // Entrada / Salida //
        //////////////////////

        //Se muestra por pantalla pos_x y pos_y del Player
        void print_pos_player(); 


};

#endif
