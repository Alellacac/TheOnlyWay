#ifndef PANTALLAS_HH
#define PANTALLAS_HH
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <vector>
#include "Mapa.hh"

using namespace std; 

void print_pantalla(vector<string>& pantalla, Player& pj, Mapa& map); 

void recalcular_pantalla_pos(vector<string>& pantalla, Player& pj, Mapa& map); 

void escribir_titulo(); 

void escribir_end_screen();

void reiniciar_pantalla();

void configurar_pantalla_ini();

void combate(int seed);

#endif