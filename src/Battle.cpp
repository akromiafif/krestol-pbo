#include "../inc/Battle.h"
#include "../inc/skill/Skill.h"
#include "../inc/Inventory.h"
// #include "../src/skill/skill.cpp" ini jangan sampe diinclude malah rusak
#include "Inventory.cpp"

#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace ns_Engimon;
using namespace ns_Skill;

Battle::Battle(Engimon* active, Engimon* musuh, Inventory<Engimon, Skill>* Inven)
{   
    this->active = *active;
    this->musuh = *musuh;
    
    // ini perhitungan elemen advantagenya gimana
    double eladvactive = -999; 
    double eladvmusuh = -999;
    // for semua elemen active
        // for semua elemen musuh
            // double calcactive = calculateElemenAdv(elemenactive[i],elemenmusuh[j]);
            // double calcmusuh = calculateElemenAdv(elemenmusuh[j],elemenactive[i]);

            // if (calcactive > eladvactive)
                // eladvactive = calcactive;
            // if (calcmusuh > eladvmusuh)
                // eladvmusuh = calcmusuh;

    // double power_active = (*active).getLevel() * eladvactive + sumSkill((*active));
    // double power_musuh = (*musuh).getLevel() * eladvmusuh + sumSkill((*musuh));  

    // ini contoh doang, nanti di hapus
    // Inventory<Engimon, Skill> Inven;

    double power_active = 1;
    double power_musuh = 0;
    cout << "Power Level Player : " << power_active << endl;
    cout << "Power Level Musuh : " << power_musuh << endl;

    Engimon* cmusuh = new Engimon(this->musuh);
    // engimon yang kalah, mati. kalau power sama, yang menang active
    if (power_active >= power_musuh)
    {
        cout << active->getName() << " menang!" << endl;
        // active menang, musuh mati hapus dari map(?)
        // kalo inventory cukup, active mendapat engimon lawan, masukin ke inventory
        if (!Inven->isInventoryFull())
            Inven->addEngimon(cmusuh);
        // active engimon dapet experience points 50, kalau isdead bunuh
        active->addExp(50);
        active->levelUp();
        if (active->isDead())
            // hapus dari inventory sama destruct
            cout << "Engimon " << active->getName() << " sudah mencapai batasnya! Katakan selamat tinggal..." << endl;
            Inven->removeEngimon(active);
        // dapet random skill item yg kompatibel dengan engimon musuh
        Skill* skillMusuh = cmusuh->getAllSkill();
        int random = rand() % cmusuh->getCountSkill();
        if (!Inven->isInventoryFull())
            Inven->addSkill(&skillMusuh[random]);
    }
    else
    {
        // active mati, hapus active dari inventory
        cout << active->getName() << " kalah!" << endl;
        Inven->removeEngimon(active);
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

int main() { // buat ngetes doang
    Inventory<Engimon, Skill> Inven;
    // bikin engimon
    Engimon e1("e1", "spes1", 320, "sukarno");
    Engimon e2("e2", "spes2", 50, "agayeff");
    Inven.addEngimon(&e1);
    Inven.addEngimon(&e2);

    // bikin skill
    Skill Glowup("Glowup", 100, 0);
    Inven.addSkill(&Glowup);

    // masukin skill ke engimon e1
    e1.addSkill(Glowup);
    
    
    // menang, nambah xp terus level up
    Engimon musuh1("musuh1", "spes1", 100, "sukarni");
    Skill duarapi("duarapi", 80, 0);
    musuh1.addSkill(duarapi);
    Inven.printInfo();
    Battle(&e1,&musuh1,&Inven);
    Inven.printInfo();
    // menang, nambah xp terus mati

    // kalah
    cout << "asu" << endl;
    return 0;
}