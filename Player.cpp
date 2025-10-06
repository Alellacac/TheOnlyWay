#include "Player.hh"

Player::Player() {
    this->atk = 10;
    this->hp = 20; 
    this->mana = 10;
    this->mana_rest = this->mana; 
    this->pasos = 200; 
    this->flash = 5; 
}

Player::Player(int pos_x, int pos_y) {
    this->pos_x = pos_x; 
    this->pos_y = pos_y; 
    this->atk = 10;
    this->hp = 20; 
    this->mana = 20;
    this->mana_rest = this->mana; 
    this->pasos = 200; 
    this->flash = 5; 
}   

void Player::print_pos_player() {
    cout << this->pos_x << " " << this->pos_y << endl; 
}

void Player::assignar_pos(int pos_x, int pos_y) {
    this->pos_x = pos_x; 
    this->pos_y = pos_y; 
}
void Player::variar_pos_player(int inc_pos_x, int inc_pos_y) {
    this->pos_x += inc_pos_x;
    this->pos_y += inc_pos_y; 
} 

int Player::get_pos_x() {
    return pos_x;
}

int Player::get_pos_y() {
    return pos_y; 
}
int Player::modificar_flash(int cant) {
    if (this->flash + cant < 0) return 0;
    this->flash += cant; 
    return 1; 
}
int Player::modificar_pasos(int cant) {
    if (this->pasos + cant < 0) return 0;
    this->pasos += cant; 
    return 1; 
}
vector<int> Player::get_stats() {
    vector<int> tmp(5); 
    tmp[0] = pasos; 
    tmp[1] = atk;
    tmp[2] = hp;
    tmp[3] = mana; 
    tmp[4] = flash;
    return tmp; 
}
