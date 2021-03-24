#include <iostream>
#include <string>
#include "../inc/Engimon.h"
#include "Engimon.cpp"
#include "../inc/skill/Skill.h"

using namespace std;
using namespace ns_Engimon;
using namespace ns_Skill;


int main(int argc, char const *argv[]) {

  // Contoh default objek Engimon beserta attribut2nya
  Engimon ratataMon;

  cout << "Name: " << ratataMon.getName() << endl;
  cout << "parentName: " << ratataMon.getParentName() << endl;
  cout << "species: " << ratataMon.getSpecies() << endl;
  cout << "maxCumulativeExp: " << ratataMon.getMaxCumulativeExp() << endl;
  cout << "level: " << ratataMon.getLevel() << endl;
  cout << "experience: " << ratataMon.getExperience() << endl;

  cout << endl;
  cout << endl;
  Skill* ratataMonSkill = ratataMon.getAllSkill();
  for (int i=0; i<ratataMon.getCountSkill(); i++) {
    cout << "Skill 1:" << endl;
    ratataMonSkill[i].infoSkill();
  }

  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  // Contoh user defined objek Engimon beserta attribut2nya
  Engimon pokeMon("mamaMon", "Suhartomon", 200, "sukarno");

  Skill BasahSkill("BasahSkill", 70, 2);
  pokeMon.addSkill(BasahSkill);

  Skill BakarSkill("BakarSkill", 90, 1);
  pokeMon.addSkill(BakarSkill); 

  cout << "Name: " << pokeMon.getName() << endl;
  cout << "parentName: " << pokeMon.getParentName() << endl;
  cout << "species: " << pokeMon.getSpecies() << endl;
  cout << "maxCumulativeExp: " << pokeMon.getMaxCumulativeExp() << endl;
  cout << "level: " << pokeMon.getLevel() << endl;
  cout << "experience: " << pokeMon.getExperience() << endl;
  cout << "counSkill: " << pokeMon.getCountSkill() << endl;

  cout << endl;
  cout << endl;
  Skill* pokeMonAllSkill = pokeMon.getAllSkill();
  for (int i=0; i<pokeMon.getCountSkill(); i++) {
    cout << "Skill " << i+1 << ": " << endl;
    pokeMonAllSkill[i].getBasePower() *pokeMonAllSkill[i].getMasteryLevel();
  }


  return 0;
}