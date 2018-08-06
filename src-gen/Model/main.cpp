#include <iostream>

#include "warShip.h"
#include "cannon.h"
#include "rocket.h"
#include "vls.h"
#include "weapon.h"
#include "military.h"

#include "externeFunktionen/Timer.h"
// #include "object.h"


// Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
// Geodesic geod(Constants::WGS84_a(), Constants::WGS84_f());

// #include "externeFunktionen/pos_convert.h"



int main(int argc, char const *argv[]) {

Model::DIS_enum disa;

Model::warShip ship1("Hamburg","F124","Germany");
ship1.setMembership("Friendly");
//
Model::Equipment eq1("Alpha");
Model::cannon can1("Otto Melara MK21",120);
Model::vls vls1("VLS System",32 );
Model::rocket rocket("Tomahawk","Cruise missile",3000);
vls1.addRocket(&rocket);
ship1.addEquipment(&eq1);
eq1.addWeapon(&can1);
eq1.addWeapon(&vls1);
ship1.printInfo();

 // ship1.getEquipment()->printInfo();

// std::cout << disa.checkContentType(ship1.getSubCategory()) << '\n';

ship1.createDISPDU();
ship1.sendToNetwork();
// std::cout << ship1.getCounter() << '\n';

Model::military tank1("matilda","Leopard 2 A6","Germany");
Model::Equipment eq2("Bravo");
tank1.addEquipment(&eq2);
// std::cout << tank1.getCounter() << '\n';
tank1.setMembership("Enemy");
tank1.createDISPDU();
tank1.sendToNetwork();

Model::warShip ship2("Brandenburg","F124","Germany");
ship2.setMembership("Friendly");

ship2.createDISPDU();
ship2.sendToNetwork();

Model::military tank2("matilda","Leopard 2 A6","Germany");
tank2.setMembership("Enemy");
tank2.createDISPDU();
tank2.sendToNetwork();

tank2.setPosition(51,0,0);
tank2.setVelo(30,0,0);
tank2.setOrientation(90,0,0);   // x = 0 -> towards Northpole ; x = 90 towards east 




auto start = std::chrono::system_clock::now();
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
int i = 0 ;
while(i <20){

   end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
if (elapsed_seconds.count() < 0.50001 && elapsed_seconds.count() > 0.499999) {
  std::cout << elapsed_seconds.count() << '\n';
   start = std::chrono::system_clock::now();
   i++;
   tank2.updateObject(elapsed_seconds.count());
   std::cout<<" lat:" << tank2.getPosition().lat << " lon:"<< tank2.getPosition().lon<<'\n';
   tank2.createDISPDU();
   tank2.sendToNetwork();
}
// std::cout << elapsed_seconds.count() << '\n';
elapsed_seconds = end-start;

}



  return 0;
}
