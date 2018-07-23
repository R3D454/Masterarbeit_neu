#include <iostream>

#include "warShip.h"
#include "cannon.h"
#include "rocket.h"
#include "vls.h"
#include "weapon.h"


// #include "externeFunktionen/pos_convert.h"


int main(int argc, char const *argv[]) {

Model::DIS_enum disa;

std::cout<<disa.getDISDomain("Land")<<std::endl;

Model::warShip ship1("Hamburg","F124");

Model::Equipment eq1("Alpha");

Model::cannon can1("Otto Melare","MK21",120);

ship1.addEquipment(&eq1);
//eq1.addWeapon(&can1);

ship1.printInfo();
ship1.getEquipment()->printInfo();

  return 0;
}
