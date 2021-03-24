// Player.cpp

#include "../inc/Engimon.h"
#include "../src/Engimon.cpp"
// #include "tubes1-oop/inc/element.h"
// #include "tubes1-oop/src/element.cpp"
#include "../inc/skill/Skill.h"
#include "../src/skill/skill.cpp"
#include "Inventory.cpp"
#include "Player.h"

using namespace std;

// ctor
Player::Player(){
    //
}

// dtor
Player::~Player(){
    //
}

void Player::setActiveEngimon(Engimon* Engi){
    // gua blm kebayang jadinya kea gimana
}

void Player::MovePlayer(){
    // hanif isi
}

void Player::showEngimonList(){
    Inven.printEngimon();
}

void Player::showEngimonDetail(){
    // afif isi
}

void Player::showSkillList(){
    Inven.printSkill();
}

void Player::useSkilltoEngimon(){
    // gua blm kebayang gimana
}

void Player::interacttoEngimon(){
    // afif isi
}

void Player::beginBreeding(Engimon* Engi1, Engimon* Engi2){
    // kresna isi
}

void Player::beginBattle(){
    // ahan isi
}