#include "../inc/Engimon.h"
#include "../src/Engimon.cpp"
// #include "tubes1-oop/inc/element.h"
// #include "tubes1-oop/src/element.cpp"
#include "../inc/skill/Skill.h"
#include "Inventory.cpp"

using namespace std;
using namespace ns_Engimon;

int main(){
    Inventory<Engimon, Skill> Inven;

    Engimon mamaMon("mamaMon", "Suhartomon", 200, "sukarno");
    Engimon tokeMon("tokeMon", "Suhartomon", 200, "denira");
    Engimon roy("roy", "Suhartomon", 200, "denira");
    Engimon koloMon("koloMon", "Suhartomon", 200, "denira");
    Engimon sugoMon("sugoMon", "Suhartomon", 200, "denira");
    Skill Glowup("Glowup", 100, 0);
    Skill duarapi("duarapi", 80, 0);
    Skill jasjus("jasjus", 230, 0);
    Skill Kohl("Kohl", 150, 0);
    Skill Starss("Starss", 50, 0);

    cout << "Kapasitas maksimum inventory adalah " << Inven.getMaximumCapacity() << endl;
    cout << "Kapasitas inventory sekarang adalah " << Inven.getCurrentCapacity() << endl;

    Inven.addEngimon(&mamaMon);
    Inven.addEngimon(&tokeMon);
    Inven.addEngimon(&roy);
    Inven.addEngimon(&koloMon);
    Inven.addEngimon(&sugoMon);
    Inven.addSkill(&Glowup);
    Inven.addSkill(&duarapi);
    Inven.addSkill(&jasjus);
    Inven.addSkill(&Kohl);
    Inven.addSkill(&Kohl);
    Inven.addSkill(&Kohl);

    Inven.printInfo();

    cout << "Kapasitas inventory sekarang adalah " << Inven.getCurrentCapacity() << endl;

    Inven.removeEngimon(&mamaMon);
    Inven.removeEngimon(&koloMon);
    Inven.removeSkill(&Kohl);
    Inven.addSkill(&Kohl);
    Inven.addSkill(&Kohl);

    Inven.printInfo();

    cout << "Kapasitas inventory sekarang adalah " << Inven.getCurrentCapacity() << endl;

    Engimon roy9("roy", "Karls", 200, "roxyy");

    roy9.addSkill(Kohl);
    roy9.addSkill(jasjus);
    roy9.addSkill(Glowup);
    roy.addSkill(duarapi);
    roy9.addSkill(jasjus); // ini masih masuk skillnya padahal udh ada
    // sama error pas skillnya udah 4 gua tambahin 1 skill lagi ni dibawah
    // roy9.addSkill(Starss);

    Inven.addEngimon(&roy9);

    Inven.displayEngimonInfo();
    
    return 0;
}