
#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <string>

#include "Engimon.h"
#include "Skill.h"

namespace ns_Engimon {

    class Battle
    {
    private:
        /* data */
        Engimon player;
        Engimon musuh;

    public:
        Battle(Engimon,Engimon);
        ~Battle();
        float countPower(Engimon);
        float elemenAdv(std::string, std::string);
        int idElement(std::string);
    };

} /* Engimon::Battle */


#endif
