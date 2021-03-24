#include "Battle.h"
#include "Skill.h"
#include <iostream>

using namespace std;
using namespace ns_Engimon;

Battle::Battle(Engimon& player,Engimon& musuh)
{   
    this->player = player;
    this->musuh = musuh;
    // ini perhitungan elemen advantagenya gimana
    double eladvplayer = -999; 
    double eladvmusuh = -999;
    // for semua elemen player
        // for semua elemen musuh
            // double calcplayer = calculateElemenAdv(elemenplayer[i],elemenmusuh[j]);
            // double calcmusuh = calculateElemenAdv(elemenmusuh[j],elemenplayer[i]);

            // if (calcplayer > eladvplayer)
                // eladvplayer = calcplayer;
            // if (calcmusuh > eladvmusuh)
                // eladvmusuh = calcmusuh;

    double power_player = player.getLevel() * eladvplayer + sumSkill(player);
    double power_musuh = musuh.getLevel() * eladvmusuh + sumSkill(musuh);  
    cout << "Power Level Player : " << power_player << endl;
    cout << "Power Level Musuh : " << power_musuh << endl;

    // engimon yang kalah, mati
    // kalau power sama, yang menang player
    if (power_player >= power_musuh)
    {
        // player menang, musuh mati hapus dari map(?)
        // kalo inventory cukup, player mendapat engimon lawan, masukin ke inventory
        // active engimon dapet experience points, besaran bebas (50), mending statik
        player.addExp(50);
        // dapet random skill item yg kompatibel dengan engimon musuh
    
    }
    else
    {
        // player mati, hapus player dari inventory
    }
}

Battle::~Battle() 
{
}

double Battle::sumSkill(Engimon& E) 
{   
    double sum = 0;
    Skill* allSkill = E.getAllSkill();
    for (int i=0; i<E.getCountSkill(); i++) 
    {
        sum = sum + (allSkill[i].getBasePower() * allSkill[i].getMasteryLevel());
    }
    return sum;
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
double Battle::calculateElemenAdv(string elemenPlayer, string elemenMusuh) {
    // fire 0, water 1, electric 2,
    // ground 3, ice 4
    int el1 = idElement(elemenPlayer);
    int el2 = idElement(elemenMusuh);

    double chart[5][5] = {
        {1,0,1,0.5,2},
        {2,1,0,1,1},
        {1,2,1,0,1.5},
        {1.5,1,2,1,0},
        {0,1,0.5,2,1}
    };
    return chart[el1][el2];
}