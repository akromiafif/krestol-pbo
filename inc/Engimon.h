
#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <string>
#include "skill/Skill.h"

using namespace std;
using namespace ns_Skill;

namespace ns_Engimon {
  /*
  Ada 5 spesies dari Engimon:
  1. Suhartomon -> Elements = water
  2. Jokowimon -> Elements = Fire
  3. Sukarnomon -> Elements = Electric
  4. Gusdurmon -> Elements = Ice
  5. Sbymon -> Elements = Ground
  */
  class Engimon {
    private:
      string name;
      string species;
      string parentName;
      Skill* listSkill;

      int countSkill;
      int maxCumulativeExp;
      int level;
      int experience;

    public:
      /* default ctor: name = Ratatamon, parentNames = JAVmon, species = Sangemon, level = 0, experience = 0, cumulativeExperience = 0*/
      Engimon();
      /* user defined ctor: */
      Engimon(string name, string species, int maxCumulativeExp, string parentName);
      /* cctor */
      Engimon(const Engimon&);
      /* operator assignment */
      Engimon& operator=(const Engimon&);
      /* dtor */
      ~Engimon();

      void levelUp();
      void addExp(int exp);
      bool isDead();
      void addSkill(Skill skill);
      void learnSkill();
      Skill checkSkill();

      // Getter
      string getName();
      string getSpecies();
      string getParentName();
      int getMaxCumulativeExp();
      int getLevel();
      int getExperience();
      int getCountSkill();
      Skill* getAllSkill();

      // Setter
      void setName(string name);
      void setSpecies(string species);
      void setParentName(string parentName);
      void setMaxCumulative(int maxCumulative);
      void setLevel(int level);
      void setExperience(int experience);
      void info();
  };
} /* Engimon::Engimon */

#endif
