// Inventory.h

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <unordered_map>

using namespace std;

template<class T1, class T2>
class Inventory{
    public:
        unordered_map<T1*, int> items1;
        unordered_map<T2*, int> items2;
        static int CurrentCapacity;
        static int MaximumCapacity;
    public:
        Inventory(); // ctor
        ~Inventory(); // dtor
        bool isInventoryFull(); // bool inventory full atau engga
        void addEngimon(T1* item);
        void addSkill(T2* item);
        void removeEngimon(T1* item);
        void removeSkill(T2* item);
        // getter
        void displayEngimonInfo();
        unordered_map<T1*, int> getItemEngimon();
        unordered_map<T2*, int> getItemSkill();
        int getCurrentCapacity();
        int getMaximumCapacity();
        void printInfo();
        void printEngimon();
        void printSkill();
};

#endif