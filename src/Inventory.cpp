using namespace std;
#include <iostream>
#include <string>
#include "../inc/Inventory.h"

// kapasitas awal, anggap 0 ?
template<class T1, class T2>
int Inventory<T1, T2>::CurrentCapacity = 0;

// kapasitas maksimum
template<class T1, class T2>
int Inventory<T1, T2>::MaximumCapacity = 100;

// ctor, masih gatau defaultnya mau ngapain
template<class T1, class T2>
Inventory<T1, T2>::Inventory(){
    // 
}

// dtor, masih gatau mau buang apaan
template<class T1, class T2>
Inventory<T1, T2>::~Inventory(){
    //
}

// bool inventory full
template<class T1, class T2>
bool Inventory<T1, T2>::isInventoryFull(){
    return (MaximumCapacity-CurrentCapacity == 0);
}

// add item
template<class T1, class T2>
void Inventory<T1, T2>::addEngimon(T1* item){
    typename std::unordered_map<T1*, int>::const_iterator found;
    if (isInventoryFull()){
        // inventory full
        cout << "Tidak bisa menambah Engimon, inventory penuh" << endl;
    } else{
        // inventory tidak full
        found = items1.find(item);
        if (found == items1.end()){
            // item belum ada di inventory
            items1[item] = 1;
            CurrentCapacity++;
        } else{
            // item sudah ada di inventory
            items1[item]++;
            CurrentCapacity++;
        }
        cout << "Berhasil menambahkan Engimon " << item->getName() << " ke Inventory!" << endl;
    }
}

// add item
template<class T1, class T2>
void Inventory<T1, T2>::addSkill(T2* item){
    typename std::unordered_map<T2*, int>::const_iterator found;
    if (isInventoryFull()){
        // inventory full
        cout << "Tidak bisa menambah Skill, inventory penuh" << endl;
    } else{
        // inventory tidak full
        found = items2.find(item);
        if (found == items2.end()){
            // item belum ada di inventory
            items2[item] = 1;
            CurrentCapacity++;
        } else{
            // item sudah ada di inventory
            items2[item]++;
            CurrentCapacity++;
        }
        cout << "Berhasil menambahkan Skill " << item->getSkillName() << " ke Inventory!" << endl;
    }
}

template<class T1, class T2>
void Inventory<T1, T2>::removeEngimon(T1* item){
    typename std::unordered_map<T1*, int>::const_iterator found;
    found = items1.find(item);
    if (found == items1.end()){
        // item belum ada di inventory
        cout << "Tidak ada Engimon tersebut di inventory!" << endl;
    } else{
        // item ada di inventory
        items1[item]--; // delete item 1
        CurrentCapacity--;
        cout << "Berhasil membuang Engimon " << item->getName() << " dari Inventory!" << endl;
        // kasus itemnya jadi 0
        if (found->second == 0){
            items1.erase(found);
        }
    }
}

template<class T1, class T2>
void Inventory<T1, T2>::removeSkill(T2* item){
    typename std::unordered_map<T2*, int>::const_iterator found;
    found = items2.find(item);
    if (found == items2.end()){
        // item belum ada di inventory
        cout << "Tidak ada Skill tersebut di inventory!" << endl;
    } else{
        // item ada di inventory
        items2[item]--; // delete item 1
        CurrentCapacity--;
        cout << "Berhasil membuang Skill " << item->getSkillName() << " sebanyak 1 dari Inventory!" << endl;
        // kasus itemnya jadi 0
        if (found->second == 0){
            items2.erase(found);
        }
    }
}

template<class T1, class T2>
void Inventory<T1, T2>::displayEngimonInfo(){
    string name;
    bool temp;
    cout << "Masukkan nama Engimon: ";
    cin >> name;

    temp = false;
    for(auto& x: items1){
        if (x.first->getName() == name){
            // gua butuh akses ke Engimon sesuatu(name, .., .., ..)
            x.first->info();
            temp = true;
        }
    }
    if (!temp){
        cout << "Tidak ada Engimon dengan nama " << name << " di inventory!" << endl;
    }
}

template<class T1, class T2>
unordered_map<T1*, int> Inventory<T1, T2>::getItemEngimon(){
    return items1;
}

template<class T1, class T2>
unordered_map<T2*, int> Inventory<T1, T2>::getItemSkill(){
    return items2;
}

template<class T1, class T2>
int Inventory<T1, T2>::getCurrentCapacity(){
    return CurrentCapacity;
}

template<class T1, class T2>
int Inventory<T1, T2>::getMaximumCapacity(){
    return MaximumCapacity;
}

template<class T1, class T2>
void Inventory<T1, T2>::printInfo(){
    cout << "Isi inventory:" << endl;
    cout << "  List Engimon :" << endl;
    for(auto& x: items1){
        cout << "    [" << x.first->getName() << "]" << endl;
    }
    cout << "  List Skill :" << endl;
    for(auto& x: items2){
        cout << "    [" << x.first->getSkillName() << "] : " << x.second << endl;
    }
}

template<class T1, class T2>
void Inventory<T1, T2>::printEngimon(){
    cout << "List Engimon :" << endl;
    for(auto& x: items1){
        cout << "  [" << x.first->getName() << "]" << endl;
    }
}

template<class T1, class T2>
void Inventory<T1, T2>::printSkill(){
    cout << "List Skill :" << endl;
    for(auto& x: items2){
        cout << "  [" << x.first->getSkillName() << "] : " << x.second << endl;
    }
}