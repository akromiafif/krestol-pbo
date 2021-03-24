#include <iostream>
#include <string>
#include "../inc/Engimon.h"
#include "skill/Skill.cpp"
using namespace std;
using namespace ns_Engimon;



Engimon::Engimon() {
  this->name = "Ratatamon";
  this->parentName = "JAVmon";
  this->species = "Tatangmon";
  this->maxCumulativeExp = 300;
  this->level = 0;
  this->experience = 0;

  this->countSkill = 1;
  this->listSkill = new Skill[4];
  this->listSkill[0] = Skill("SetrumSkill", 50, 1);
}

Engimon::Engimon(string name, string species, int maxCumulativeExp, string parentName) {
  this->name = name;
  this->species = species;
  this->maxCumulativeExp = maxCumulativeExp;
  this->parentName = parentName;
  this->level = 0;
  this->experience = 0;

  this->countSkill = 0;
  this->listSkill = new Skill[4];
}

Engimon::Engimon(const Engimon& engimon) {
  this->name = engimon.name;
  this->species = engimon.species;
  this->maxCumulativeExp = engimon.maxCumulativeExp;
  this->parentName = engimon.parentName;
  this->level = engimon.level;
  this->experience = engimon.experience;

  this->countSkill = engimon.countSkill;
  this->listSkill = new Skill[4];

  for (int i=0; i<countSkill; i++) {
    this->listSkill[i] = engimon.listSkill[i];
  }
  
}

Engimon::~Engimon() {
  delete[] listSkill;
  this->name = " ";
  this->species = " ";
  this->parentName = " ";
  this->maxCumulativeExp = 0;
  this->level = 0;
  this->experience = 0;
}

Engimon& Engimon::operator=(const Engimon& engimon) {
  delete[] this->listSkill;

  this->name = engimon.name;
  this->species = engimon.species;
  this->maxCumulativeExp = engimon.maxCumulativeExp;
  this->parentName = engimon.parentName;
  this->level = engimon.level;
  this->experience = engimon.experience;

  this->countSkill = engimon.countSkill;
  this->listSkill = new Skill[4];

  for (int i=0; i<countSkill; i++) {
    this->listSkill[i] = engimon.listSkill[i];
  }

  return *this;
}

void Engimon::levelUp() {
  if (experience % 100 == 0) {
    level++;
  }
}

void Engimon::addExp(int exp) {
  experience += exp;
}

bool Engimon::isDead() {
  return this->experience == this->maxCumulativeExp;
}

void Engimon::addSkill(Skill skill) {
  this->listSkill[this->countSkill] = skill;
  this->countSkill++;
}

void Engimon::learnSkill() {
  cout << "All Possible Skill" << endl;
  for (int i = 0;i<5;i++){
    cout << "Skill : "<< i+1 << endl;
    All_Skill[i].infoSkill();
  }
  cout << "\n\n Pilih Skill mu \n Pilihan mu :";
  int x;
  cin >> x;
  this->addSkill(All_Skill[x-1]);

}
/*  ===================== GETTERS ===================== */
string Engimon::getName() {
  return this->name;
}

string Engimon::getSpecies() {
  return this->species;
}

string Engimon::getParentName() {
  return this->parentName;
}

int Engimon::getMaxCumulativeExp() {
  return this->maxCumulativeExp;
}

int Engimon::getLevel() {
  return this->level;
}

int Engimon::getExperience() {
  return this->experience;
}

int Engimon::getCountSkill() {
  return this->countSkill;
}

Skill* Engimon::getAllSkill() {
  return this->listSkill;
}
/*  ===================== GETTERS ===================== */


/*  ===================== SETTERS ===================== */
void Engimon::setName(string name) {
  this->name = name;
}

void Engimon::setSpecies(string species) {
  this->species = species;
}

void Engimon::setParentName(string parentName) {
  this->parentName =  parentName; 
}

void Engimon::setMaxCumulative(int maxCumulative) {
  this->maxCumulativeExp = maxCumulative;
}

void Engimon::setLevel(int level) {
  this->level = level;
}

void Engimon::setExperience(int experience) {
  this->experience = experience;
}

void Engimon::info(){
  cout << "Name: " << this->getName() << endl;
  cout << "parentName: " << this->getParentName() << endl;
  cout << "species: " << this->getSpecies() << endl;
  cout << "maxCumulativeExp: " << this->getMaxCumulativeExp() << endl;
  cout << "level: " << this->getLevel() << endl;
  cout << "experience: " << this->getExperience() << endl;
  cout << "\n\n";
  cout << "Skill Engimon" <<endl;
  for (int i = 0;i<this->countSkill;i++){
    this->listSkill[i].infoSkill();
  }
  // for (int i=0; i<this->getCountSkill(); i++) {
  //   cout << "Skill 1:" << endl;
  //   this->listSkill->infoSkill();
  // }
}

/*  ===================== SETTERS ===================== */
