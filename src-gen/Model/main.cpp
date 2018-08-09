#include <iostream>

#include "warShip.h"
#include "cannon.h"
#include "rocket.h"
#include "vls.h"
#include "weapon.h"
#include "military.h"
#include <time.h>
// #include "externeFunktionen/Timer.h"
// #include "object.h"

#include <inttypes.h>
// Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
// Geodesic geod(Constants::WGS84_a(), Constants::WGS84_f());

// #include "externeFunktionen/pos_convert.h"


double getDiffTime(struct timespec end, struct timespec start){
double diff;

diff = ((double)end.tv_sec+1.0e-9*end.tv_nsec)-((double)start.tv_sec+1.0e-9*start.tv_nsec);


return round(diff*100)/100;


// #define DST "127.0.0.255"
// #define DST "192.168.4.255"
#define DST "192.168.4.7"

}

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
ship1.sendToNetwork(DST);
//
//
Model::military tank1("matilda","Leopard 2 A6","Germany");
Model::Equipment eq2("Bravo");
tank1.addEquipment(&eq2);
tank1.setMembership("Enemy");
tank1.createDISPDU();

tank1.sendToNetwork(DST);

Model::warShip ship2("Brandenburg","F123","Germany");
ship2.setMembership("Friendly");

ship2.createDISPDU();
ship2.sendToNetwork(DST);

Model::military tank2("matilda","Leopard 2 A6","Germany");
tank2.setPosition(51,0,0);
tank2.setMembership("Enemy");
tank2.createDISPDU();
tank2.sendToNetwork(DST);

ship1.setVelo(300,0,0);
ship1.setOrientation(90,0,0);   // x = 0 -> towards Northpole ; x = 90 towards east


struct timespec start,end;
double diff;
clock_gettime(CLOCK_REALTIME, &start);

// usleep(300000);
clock_gettime(CLOCK_REALTIME, &end);

std::cout << getDiffTime(end,start) << '\n';
int i = 0 ;
while(i <20){

  clock_gettime(CLOCK_REALTIME, &end);
  diff = getDiffTime(end,start);
if (diff == 0.5) {
  std::cout << diff << '\n';
  clock_gettime(CLOCK_REALTIME, &start);
   i++;
   ship1.updateObject(diff);
   std::cout<<" lat:" << ship1.getPosition().lat << " lon:"<< ship1.getPosition().lon<<'\n';
   ship1.createDISPDU();
   ship1.sendToNetwork(DST);
}
diff = getDiffTime(end,start);

}


// std::cout << i << '\n';
  return 0;
}
