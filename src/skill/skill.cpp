#include <iostream>
#include <string>
#include "../../inc/skill/Skill.h"
#include <array>
using namespace std;
using namespace ns_Skill;

static array<Skill,5> All_Skill = {
Skill("ApiSkill",100,0),
Skill("AirSkill",110,0),
Skill("BekuSkill",120,0),
Skill("BatuSkill",130,0),
Skill("PetirSkill",140,0)
};

Skill::Skill() {
  this->skillName = "RevolusiSkill";
  this->basePower = 130;
  this->masteryLevel = 1;
}

Skill::Skill(const Skill& skill) {
  this->skillName = skill.skillName;
  this->basePower = skill.basePower;
  this->masteryLevel = skill.masteryLevel;
}

Skill::Skill(string skillName, int basePower, int masteryLevel) {
  this->skillName = skillName;
  this->basePower = basePower;
  this->masteryLevel = masteryLevel;
}

Skill::~Skill() {
  this->skillName = " ";
  this->basePower = 0;
  this->masteryLevel = 0;
}

void Skill::infoSkill() {
  cout << "skillName: " << this->getSkillName() << endl;
  cout << "basePower: " << this->getBasePower() << endl;
  cout << "masteryLevel: " << this->getMasteryLevel() << endl;
  cout << endl;
}

/*  ===================== GETTERS ===================== */
string Skill::getSkillName() {
  return this->skillName;
}

int Skill::getBasePower() {
  return this->basePower;
}

int Skill::getMasteryLevel() {
  return this->masteryLevel;
}
/*  ===================== GETTERS ===================== */

/*  ===================== SETTERS ===================== */
void Skill::setSkillName(string skillName) {
  this->skillName = skillName;
}

void Skill::setBasePower(int basePower) {
  this->basePower = basePower;
}

void Skill::setMasteryLevel(int masteryLevel) {
  this->masteryLevel = masteryLevel;
}
/*  ===================== SETTERS ===================== */
