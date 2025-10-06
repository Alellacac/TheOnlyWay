#include "Pantallas.hh"

void print_pantalla(vector<string>& pantalla, Player& pj, Mapa& map) {
    recalcular_pantalla_pos(pantalla, pj, map); 
    for (int i = 0; i < 20; i++) cout << pantalla[i];
    cout << endl;
}

void recalcular_pantalla_pos(vector<string>& pantalla, Player& pj, Mapa& map) {
    vector<string> cass_pan = map.obtener_casillas_chars(); 
    stringstream tmp;
    string aux; 

    //stats_pj[0] = PasosRes
    //stats_pj[1] = Atk
    //stats_pj[2] = HP
    //stats_pj[3] = Mana
    //stats_pj[4] = FlashRes
    vector<int> stats_pj = pj.get_stats(); 

    //Distancia de player a exit
    int dist_exit = map.get_dist_exit(); 

    //Poner pasosRes
    tmp << stats_pj[0];
    aux = (tmp.str());
    aux.resize(9,' ');
    swap_ranges(pantalla[3].begin() + 23, pantalla[3].begin() + 32, aux.begin());
    tmp.str("");

    //Poner la DistExit
    tmp << dist_exit;
    aux = (tmp.str());
    aux.resize(9,' ');
    swap_ranges(pantalla[3].begin() + 43, pantalla[3].begin() + 52, aux.begin());
    tmp.str("");

    //Poner los caracteres del mapeado actual                                                                               
    for (int i = 0; i < 11; i++) 
        swap_ranges(pantalla[5+i].begin() + 85, pantalla[5+i].begin() + 116, cass_pan[i].begin());

    //Poner AtkPlayer
    tmp << stats_pj[1];
    aux = tmp.str();
    aux.resize(14,' '); 
    swap_ranges(pantalla[5].begin() + 18, pantalla[5].begin() + 32, aux.begin()); 
    tmp.str("");

    //Poner HPPlayer
    tmp << stats_pj[2];
    aux = tmp.str();
    aux.resize(15,' '); 
    swap_ranges(pantalla[5].begin() + 37, pantalla[5].begin() + 52, aux.begin()); 
    tmp.str("");

    //Poner ManaPlayer
    tmp << stats_pj[3];
    aux = tmp.str();
    aux.resize(9,' '); 
    swap_ranges(pantalla[5].begin() + 59, pantalla[5].begin() + 68, aux.begin()); 
    tmp.str("");

    //Poner FlashRes
    tmp << stats_pj[4];
    aux = tmp.str();
    aux.resize(9,' '); 
    swap_ranges(pantalla[9].begin() + 23, pantalla[9].begin() + 32, aux.begin()); 
    tmp.str("");


    ///
    ///
    /// Falta imprimir la pasiva 
    ///
    ///
    // pantalla[11] = "l           Pasiva = %%                                                          =   _  _  _  _  _  _  _  _  _  _  _   =                ";
}


void escribir_titulo() {
    //136 * 20;
    string titulo[20]; 
     titulo[0] = "a======================================================================================================================================a";
     titulo[1] = "b======================================================================================================================================b";
     titulo[2] = "c======================================================================================================================================c";
     titulo[3] = "d======================================================================================================================================d";
     titulo[4] = "e======================================================================================================================================e";
     titulo[5] = "                     88                                                88                                                               ";
     titulo[6] = "               ,d    88                                                88                                                               ";
     titulo[7] = "               88    88                                                88                                                               ";
     titulo[8] = "             MM88MMM 88,dPPYba,   ,adPPYba,     ,adPPYba,  8b,dPPYba,  88 8b       d8    8b      db      d8 ,adPPYYba, 8b       d8      ";
     titulo[9] = "               88    88P´    `8a a8P_____88    a8´     `8a 88P´   ``8a 88 `8b     d8´    `8b    d88b    d8´ ``     `Y8 `8b     d8´      ";
    titulo[10] = "               88    88       88 8PP´´´´´´´    8b       d8 88       88 88  `8b   d8´      `8b  d8´`8b  d8´  ,adPPPPP88  `8b   d8´       ";
    titulo[11] = "               88,   88       88 `8b,   ,aa    `8a,   ,a8´ 88       88 88   `8b,d8´        `8bd8´  `8bd8´   88,    ,88   `8b,d8´        ";
    titulo[12] = "               `Y888 88       88  ``Ybbd8´´     ``YbbdP´´  88       88 88     Y88´           YP      YP     ``8bbdP´Y8     Y88´         ";
    titulo[13] = "                                                                              d8´                                          d8´          ";
    titulo[14] = "                                                                              d8´                                          d8´          ";
    titulo[15] = "p======================================================================================================================================p";
    titulo[16] = "q======================================================================================================================================q";
    titulo[17] = "r======================================================================================================================================r";
    titulo[18] = "s======================================================================================================================================s";
    titulo[19] = "t======================================================================================================================================t";                       
    for (int i = 0; i < 20; i++) cout << titulo[i]; 
}

void escribir_end_screen() {
    //136 * 20;
    string end[20]; 
     end[0] = "a======================================================================================================================================a";
     end[1] = "b======================================================================================================================================b";
     end[2] = "c======================================================================================================================================c";
     end[3] = "d======================================================================================================================================d";
     end[4] = "e======================================================================================================================================e";
     end[5] = "                                                                                                                     88                 ";
     end[6] = "                                                                                                                     `´                 ";
    end[14] = "                                                                                                                                        ";
     end[7] = "      ,adPPYba,  ,adPPYba,  ,adPPYba,       8b       d8  ,adPPYba,  88       88    ,adPPYYba,  ,adPPYb,d8 ,adPPYYba, 88 8b,dPPYba,      ";
     end[8] = "      I8[    `` a8P_____88 a8P_____88       `8b     d8´ a8´     `8a 88       88    ´´     `Y8 a8´    `Y88 ´´     `Y8 88 88P´   ``8a     ";
     end[9] = "       ``Y8ba,  8PP´´´´´´´ 8PP´´´´´´´        `8b   d8´  8b       d8 88       88    ,adPPPPP88 8b       88 ,adPPPPP88 88 88       88     ";
    end[10] = "      aa    ]8I `8b,   ,aa `8b,   ,aa         `8b,d8´   `8a,   ,a8´ `8a,   ,a88    88,    ,88 `8a,   ,d88 88,    ,88 88 88       88     ";
    end[11] = "      ``YbbdP´´  ``Ybbd8´´  ``Ybbd8´´           Y88´     ``YbbdP´´   ``YbbdP´Y8    ``8bbdP´Y8  ``YbbdP´Y8 ``8bbdP´Y8 88 88       88     "; 
    end[12] = "                                                d8´                                            aa,    ,88                               ";
    end[13] = "                                               d8´                                              `Y8bbdP´                                ";
    end[15] = "p======================================================================================================================================p";
    end[16] = "q======================================================================================================================================q";
    end[17] = "r======================================================================================================================================r";
    end[18] = "s======================================================================================================================================s";
    end[19] = "t======================================================================================================================================t";
    for (int i = 0; i < 20; i++) cout << end[i]; 
}

void reiniciar_pantalla() {
    for (int i = 0; i < 20; i++) cout << endl; 
}

void configurar_pantalla_ini() {
    string s = "Ajustar el tamaño de la pantalla hasta que solo veas los iguales, despues clica cualquier tecla: "; 
    cout << s << endl; 
    s = "========================================================================================================================================"; 
    cout << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl; 
    cout << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl << s << endl; 

    system("stty raw");
    char ch; 
    cin >> ch; 
    system("stty cooked"); 

    cout << "Pantalla escrita puesta perfectamente" << endl; 
    reiniciar_pantalla();
}
void combate(int seed) {
    //los enemigos tiene una estadistica de tipo(ataque, defensa)
    //los enemigos pueden moverse una cantidad de posiciones segun su tipo
    //los enemigos tienen un ataque y una cantidad de veces q lo pueden hacer por turno 
    
    vector<string> comb(20); 
    comb[0] = "a                                                                                                                                       ";
    comb[1] = "b                                                                                                                                       ";
    comb[2] = "c           Atk = %%            HP = %%         ======================================================================================= ";
    comb[3] = "d           Mana = %%           MRest = %%      =                                                                                     = ";
    comb[4] = "e                                               =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
    comb[5] = "f           Pasiva = %%                         =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
    comb[6] = "g           H1: %%                              =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
    comb[7] = "h           H2: %%                              =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
    comb[8] = "i           H3: %%                              =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
    comb[9] = "j                                               =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[10] = "k           E0: C(10,10)      E1: C(11,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[11] = "l           E2: P(10,20)      E3: P(10,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[12] = "m           E4: P(10,20)      E5: P(10,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[13] = "n           E6: P(10,20)      E7: P(10,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[14] = "o           E8: P(10,20)      E9: P(10,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[15] = "p           B$: P(10,20)      B&: P(10,20)      =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[16] = "q                                               =   _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _   = ";
   comb[17] = "r           Alter_vw => V                       =                                                                                     = ";
   comb[18] = "s           Pausa => P                          ======================================================================================= ";
   comb[19] = "t                                                                                                                                       ";
   for (int i = 0; i < 20; i++) cout << comb[i] << endl;
}