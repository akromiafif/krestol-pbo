
#include <string>

#include "Battle.h"

using namespace std;
using namespace ns_Engimon;

Battle::Battle(Engimon player,Engimon musuh)
    : player(player), musuh(musuh)
{
}

Battle::~Battle() {
}

float Battle::countPower(Engimon e1) {
    float elAdvantage;
    float power = e1.getLevel() * elAdvantage;
    // skill masih banyak kurang jd ini belom bisa
}

int Battle::idElement(string namaElemen) {
    int id;
    // Urutan Fire, Water, Electric, Ground, Ice
    if (namaElemen == "Fire")
        id = 0;
    else if (namaElemen == "Water")
        id = 1;
    else if (namaElemen == "Electric")
        id = 2;
    else if (namaElemen == "Ground")
        id = 3;
    else if (namaElemen == "Ice")
        id = 4;
    else
        id = -1;
    return id;
}
float Battle::elemenAdv(string elemen1, string elemen2) {
    // fire 0, water 1, electric 2,
    // ground 3, ice 4
    int el1 = idElement(elemen1);
    int el2 = idElement(elemen2);

    float chart[5][5] = {
        {1,0,1,0.5,2},
        {2,1,0,1,1},
        {1,2,1,0,1.5},
        {1.5,1,2,1,0},
        {0,1,0.5,2,1}
    };
    return chart[el1][el2];
}
