#include <iostream>

#include "warShip.h"
#include "cannon.h"
#include "rocket.h"
#include "vls.h"
#include "weapon.h"
#include "object.h"



// #include "externeFunktionen/pos_convert.h"


int main(int argc, char const *argv[]) {

Model::DIS_enum disa;

std::cout<<disa.getDISDomain("Land")<<std::endl;
DIS_EntityType_Variables dis, disb;
dis = disa.getDISEntityType("Platform", "Surface",
                              "Germany", "Guided Missile Frigate (FFG)",
                              "Bremen class (Type 122)",  "",
                              "");

std::cout << dis.Kind<<" " << dis.Domain<<" " << dis.Country<<" " <<dis.Category<<" " <<dis.SubCategory <<'\n';

Model::warShip ship1("Hamburg","F124","Germany");

Model::Equipment eq1("Alpha");

Model::cannon can1("Otto Melare","MK21",120);

ship1.addEquipment(&eq1);
std::cout << ship1.getKind() << '\n';
eq1.addWeapon(&can1);

ship1.printInfo();
ship1.getEquipment()->printInfo();
std::cout << ship1.getSubCategory() << '\n';

ship1.creatDIS_PDU(ship1.getKind(),ship1.getDomain(),ship1.getCountry(),ship1.getCategory(), ship1.getSubCategory());

disb = ship1.getDIS_EntityType_Variables();
std::cout << disb.Kind<<" " << disb.Domain<<" " << disb.Country<<" " <<disb.Category<<" " <<disb.SubCategory <<'\n';

// std::cout << disa.checkContentType(ship1.getSubCategory()) << '\n';


 DIS::DataStream buffer( DIS::BIG );
 DIS::EntityStatePdu n1;


  return 0;
}
