// Player.h

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "../inc/Engimon.h"
#include "../inc/skill/Skill.h"
#include "Inventory.h"

class Player{
    private:
        void MoveActiveEngimon(); // engimon active
        int inputCommand(); // command input player
    protected:
        // inventory
        Inventory<Engimon, Skill> Inven;
    public:
        Player();
        ~Player();
        void setActiveEngimon(Engimon* Engi); // set engimon active
        void MovePlayer(); // bergerak di map ?
        void showEngimonList(); // menampilkan list engimon
        void showEngimonDetail(); // menampilkan data lengkap engimon
        void showSkillList(); // menampilkan list skill item
        void useSkilltoEngimon(); // menggunakan skill item ke Engimon
        void interacttoEngimon(); // interaksi dengan engimon active
        void beginBreeding(Engimon* Engi1, Engimon* Engi2); // melaksanakan breeding
        void beginBattle(); // melakukan battle
};

#endif