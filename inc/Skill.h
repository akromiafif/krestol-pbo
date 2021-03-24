#ifndef SKILL_HPP
#define SKILL_HPP

#include <string>
#include "element.h"

namespace ns_Skill {

    class Skill {
      private:
        int basePower;
        int mastery;

      public:
        void learn();
    };

} /* Engimon */

#endif
