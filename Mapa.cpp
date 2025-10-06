#include "Mapa.hh"

Mapa::Mapa() {}

Mapa::Mapa(int seed, Player& pj, int tam_max_x, int tam_max_y) {
    this->map = vector<vector<casilla>> (tam_max_y, vector<casilla> (tam_max_x)); 
    this->tam_max_x = tam_max_x; 
    this->tam_max_y = tam_max_y; 
    srandom(seed); 
    generar_bordes_y_espacios();
    generar_eventos();
    generar_enemigos(); 
    generar_objetos(); 
    inciar_player(pj);
}

void Mapa::print_mapa() {
    //Tamaño del mapa es 200 x 200
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            cout << this->map[i][j].ch;  
        }
        cout << endl; 
    }
}
int Mapa::get_dist_exit() {
    return random()%39204; 
}
void Mapa::generar_bordes_y_espacios() {
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 200; j++) {
            if (i == 0 || i == 199 || j == 0 || j == 199) this->map[i][j].ch = '#'; 
            else this->map[i][j].ch = ' '; 
        }
    }
}
void Mapa::generar_eventos() {
    int i = 0;
    while (i < 100) {
        int pos = random()%39204;
        int x = 1 + pos%198;
        int y = 1 + (pos/198);
        if (this->map[y][x].ch == ' ') {
            this->map[y][x].ch = 'E'; 
            this->map[y][x].id = i; 
            i++;
        }
    }
}
void Mapa::generar_enemigos() {
    int i = 0;
    while (i < 100) {
        int pos = random()%39204;
        int x = 1 + pos%198;
        int y = 1 + (pos/198);
        if (this->map[y][x].ch == ' ') {
            this->map[y][x].ch = 'X'; 
            this->map[y][x].id = i;            
            i++;
        }
    }
}
void Mapa::generar_objetos() {
    int i = 0;
    while (i < 100) {
        int pos = random()%39204;
        int x = 1 + pos%198;
        int y = 1 + (pos/198);
        if (this->map[y][x].ch == ' ') {
            this->map[y][x].ch = 'O'; 
            this->map[y][x].id = i; 
            i++;
        }
    }
}
void Mapa::inciar_player(Player& pj) {
    int i = 0; 
    while (i == 0) {
        int pos = random()%39204;
        int x = 1 + pos%198;
        int y = 1 + (pos/198);   
        if (this->map[y][x].ch == ' ') {
            pj.assignar_pos(x, y);
            this->pos_pj_x = x;
            this->pos_pj_y = y; 
            this->map[y][x].ch = '@';
            i++; 
        }
    }

}
void Mapa::revelar_alrededor() {
    for (int y = 0; y < 11; y++) 
        for (int x = 0; x < 11; x++) 
            if (((pos_pj_y - 5 + y) < (tam_max_y - 1)) && ((pos_pj_y - 5 + y) > 0) &&
                ((pos_pj_x - 5 + x) < (tam_max_x - 1)) && ((pos_pj_x - 5 + x) > 0)) this->map[pos_pj_y - 5 + y][pos_pj_x - 5 + x].show = 1;   
}

vector<string> Mapa::obtener_casillas_chars() {
    vector<string> tmp(11); 
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 11; x++) {
            if (((pos_pj_y - 5 + y) >= (tam_max_y - 1)) || ((pos_pj_y - 5 + y) <= 0) ||
                ((pos_pj_x - 5 + x) >= (tam_max_x - 1)) || ((pos_pj_x - 5 + x) <= 0)) tmp[y].push_back('#');
            else if ((this->map[pos_pj_y - 5 + y][pos_pj_x - 5 + x].ch == ' ') || 
                     (this->map[pos_pj_y - 5 + y][pos_pj_x - 5 + x].show == 1) || 
                     (this->map[pos_pj_y - 5 + y][pos_pj_x - 5 + x].ch == '@')) tmp[y].push_back(this->map[pos_pj_y - 5 + y][pos_pj_x - 5 + x].ch); 
            else tmp[y].push_back('?'); 
            tmp[y].push_back(' ');
            tmp[y].push_back(' ');     
        }
    }
    return tmp;
}

pair<int, char> Mapa::act_player(char ch ,Player& pj) {
    pair<int, char> tmp (-1, ' '); 
    switch (ch) {

        //imprime el mapa
        case 'm': {
            cout << endl; 
            print_mapa();
            return tmp; 
            //break
        }

        //muevete para arriba (y--)
        case 'w': {
            if (1 < pos_pj_y) {
                //mirar la posicion en la que queremos ir contenido 
                tmp.first = this->map[pos_pj_y - 1][pos_pj_x].id; 
                tmp.second = this->map[pos_pj_y - 1][pos_pj_x].ch; 
                this->map[pos_pj_y - 1][pos_pj_x].ch = '@'; 
                this->map[pos_pj_y][pos_pj_x].ch = ' ';
                pj.variar_pos_player(0,-1);
                pj.modificar_pasos(-1);
                this->pos_pj_y--; 
            }
            return tmp; 
            //break; 
        }

        //muevete para izquierda (x--)
        case 'a': {
            if (1 < pos_pj_x) {
                //mirar la posicion en la que queremos ir contenido 
                tmp.first = this->map[pos_pj_y][pos_pj_x - 1].id; 
                tmp.second = this->map[pos_pj_y][pos_pj_x - 1].ch; 
                this->map[pos_pj_y][pos_pj_x - 1].ch = '@'; 
                this->map[pos_pj_y][pos_pj_x].ch = ' ';
                pj.variar_pos_player(-1,0);
                pj.modificar_pasos(-1);
                this->pos_pj_x--; 
            }
            return tmp; 
            //break;
        }

        //muevete para abajo (y++)
        case 's': {
            if (pos_pj_y < 198) {
                //mirar la posicion en la que queremos ir contenido 
                tmp.first = this->map[pos_pj_y + 1][pos_pj_x].id; 
                tmp.second = this->map[pos_pj_y + 1][pos_pj_x].ch; 
                this->map[pos_pj_y + 1][pos_pj_x].ch = '@'; 
                this->map[pos_pj_y][pos_pj_x].ch = ' ';
                pj.variar_pos_player(0,1);
                pj.modificar_pasos(-1);
                this->pos_pj_y++; 
            }
            return tmp; 
            //break;
        }
       
        //muevete para derecha (x++)
        case 'd': {
            if (pos_pj_x < 198) {
                //mirar la posicion en la que queremos ir contenido 
                tmp.first = this->map[pos_pj_y][pos_pj_x + 1].id; 
                tmp.second = this->map[pos_pj_y][pos_pj_x + 1].ch; 
                this->map[pos_pj_y][pos_pj_x + 1].ch = '@'; 
                this->map[pos_pj_y][pos_pj_x].ch = ' ';
                pj.variar_pos_player(1,0);
                pj.modificar_pasos(-1);
                this->pos_pj_x++;
            }
            return tmp; 
            //break; 
        }

        //Usa un flash
        case 'f': {
            int comp = pj.modificar_flash(-1); 
            if (comp) revelar_alrededor(); 
            return tmp;
            break; 
        }

        //exit del juego
        case 'z': {
            tmp.second = 'z'; 
            return tmp;  
            //break
        }
        //comportamiento por defectos
        default: {
            return tmp; 
            //break; 
        }
    }
}
