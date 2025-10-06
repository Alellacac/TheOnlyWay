#include <iostream>
#include <sstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>

#include "Pantallas.hh"
#include "Mapa.hh"
#include "Player.hh"

using namespace std; 


// Primer intento de juego  => Este es en la consola de linux asi que bueno, ns si windows ira tambien //
// Aqui viene estructuras de datos utiles //


/*
    /////////////////////////
        DEFINIR SIGNALS
    /////////////////////////
    sigset_t mask; 
    sigfillset(&mask); 
    sigdelset(&mask); 
    sigaddset(&mask, SIG_BLOCK); 
    ...
    sigprocmask(SIG_BLOCK, &mask, NULL); 
    
    
    
    
    
    struct sigaction sa;
    signsq(&sa.sa_mask);      
    sa.sa_flags = 0; 
    sa.sa_handler(&funcion); 
    sigaction(Signal, &sa, NULL);

    
    /////////////////////////
        LECTURA DE 
        CARACTERES
        SIN ENTER
    /////////////////////////

    system("stty raw");
    system("stty cooked"); 

*/
// DEFINIDO EN EL MAPA // 
/*
struct casilla {
    int id; 
    char ch; 
};


*/
    
int select_seed() {
    int n; 
    cout << "Introduce el número de seed que quieres para tu mundo: "; 
    cin >> n; 
    reiniciar_pantalla(); 
    return n; 
}

void iniciar_partida_nueva() {
    escribir_titulo(); 
    int seed = select_seed();
    Player pj;
    Mapa map(seed, pj, 200, 200); 

    // Pantalla del jugador // HUD
    vector<string> pantalla(20); 
     pantalla[0] = "a                                                                                                                                       ";
     pantalla[1] = "b                                                                                                                                       ";
     pantalla[2] = "c                                                                                                                                       ";
     pantalla[3] = "d           PasosRes = %%       DistExit = %%                                    =======================================                ";
     pantalla[4] = "e                                                                                =                                     =                ";
     pantalla[5] = "f           Atk = %%            HP = %%             Mana = %%                    =   _  _  _  _  _  _  _  _  _  _  _   =                ";
     pantalla[6] = "g                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
     pantalla[7] = "h                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
     pantalla[8] = "i                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
     pantalla[9] = "j           FlashRes = %%                                                        =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[10] = "k                                                                                =   _  _  _  _  _  @  _  _  _  _  _   =                ";
    pantalla[11] = "l           Pasiva = %%                                                          =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[12] = "m                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[13] = "n                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[14] = "o           Habilidades => H                                                     =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[15] = "p                                                                                =   _  _  _  _  _  _  _  _  _  _  _   =                ";
    pantalla[16] = "q           Pausa => P         Exit => Z                                         =                                     =                ";
    pantalla[17] = "r                                                                                =======================================                ";
    pantalla[18] = "s                                                                                                                                       ";
    pantalla[19] = "t                                                                                                                                       ";

    char ch; 
    pair<int, char> act_done;
    //act_done == 0 -> No move
    //act_done == 1 -> Move to blank space
    //act_done == 2 -> Move to other kind of space

    //sirve para contabilizar la cantidad de veces que se ha impreso en la terminal para que no se vuelva loca la terminal y hacer un clear
    print_pantalla(pantalla, pj, map); 

    while (1) {
        system("stty raw");
        cin >> ch;
        system("stty cooked");   
        act_done = map.act_player(ch, pj); 
        cout << endl << "act_done = " << act_done.first << " " << act_done.second << endl;
        print_pantalla(pantalla, pj, map); 
        if (act_done.second == 'z') {
            escribir_end_screen();
            exit(0);  
        }
        else if (act_done.second == 'X') {
            combate(10);
        };      
    }
}
int main (int argc, char* argv[]) {
    configurar_pantalla_ini();
    iniciar_partida_nueva(); 
}