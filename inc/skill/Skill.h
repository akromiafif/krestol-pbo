#include <string>

#ifndef SKILL_HPP
#define SKILL_HPP

using namespace std;

/*
  Skill mempunyai 9 subskill, bisa dilihat dibawah ini

  parameter 1 = Nama skill, parameter 2 = basePower, parameter 3 = masteryLevel
  Skill SetrumSkill("SetrumSkill", 50, 1); --> Skill bawaan element Electric
  Skill BasahSkill("BasahSkill", 70, 2); --> Skill bawaan element Water
  Skill BakarSkill("BakarSkill", 90, 1); --> Skill bawaan element Fire
  Skill BekuSkill("BakarSkill", 100, 1); --> Skill bawaan element Ice
  Skill KerasSkill("KerasSkill", 150, 2); --> Skill bawaan element Ground
  Skill MalingSkill("MalingSkill", 120, 1); --> Skill custom
  Skill KorupsiSkill("KorupsiSkill", 110, 3); --> Skill custom
  Skill RevolusiSkill("RevolusiSkill", 130, 1); --> Skill custom
  Skill ReformasiSkill("ReformasiSkill", 80, 2); --> Skill custom
*/

namespace ns_Skill {
  class Skill {
    private:
      string skillName;
      int basePower;
      int masteryLevel;
    
    public:
      Skill();
      Skill(const Skill&);
      Skill(string skillName, int basePower, int masteryLevel);
      ~Skill();

      // GETTERS //
      string getSkillName();
      int getBasePower();
      int getMasteryLevel();

      //SETTERS//
      void setSkillName(string skillName);
      void setBasePower(int basePower);
      void setMasteryLevel(int masteryLevel);

      void infoSkill();
  };
} 

#endif
