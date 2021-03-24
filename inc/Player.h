// Player.h

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "../inc/Engimon.h"
#include "../src/Engimon.cpp"
#include "../inc/skill/Skill.h"
#include "Inventory.h"
using namespace std;

class Player{
    private:
        void MoveActiveEngimon(); // engimon active
        int inputCommand(); // command input player
    protected:
        // inventory
        Inventory<ns_Engimon::Engimon, Skill> Inven;
    public:
        Player();
        ~Player();
        void setActiveEngimon(ns_Engimon::Engimon*); // set engimon active
        void MovePlayer(); // bergerak di map ?
        void showEngimonList(); // menampilkan list engimon
        void showEngimonDetail(); // menampilkan data lengkap engimon
        void showSkillList(); // menampilkan list skill item
        void useSkilltoEngimon(); // menggunakan skill item ke Engimon
        void interacttoEngimon(); // interaksi dengan engimon active
        void beginBreeding(ns_Engimon::Engimon*, ns_Engimon::Engimon*); // melaksanakan breeding
        void beginBattle(ns_Engimon::Engimon*, ns_Engimon::Engimon*); // melakukan battle
};

#endif