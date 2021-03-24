
#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>
#include "Player.h"
#include "Engimon.h"
using namespace std;
using namespace ns_Engimon;

class Battle
{
private:
    /* data */
    Engimon active;
    Engimon musuh;

public:
    Battle(Engimon*,Engimon*,Inventory<Engimon, Skill>*);
    ~Battle();
    double sumSkill(Engimon&);
    double calculateElemenAdv(std::string, std::string);
    int idElement(std::string);
};

#endif
