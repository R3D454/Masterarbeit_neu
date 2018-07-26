#include <iostream>

#include "warShip.h"
#include "cannon.h"
#include "rocket.h"
#include "vls.h"
#include "weapon.h"
// #include "object.h"


// Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
Geodesic geod(Constants::WGS84_a(), Constants::WGS84_f());

// #include "externeFunktionen/pos_convert.h"

namespace Articulation
   {
      enum Motion
      {
         AZIMUTH = 11,
         AZIMUTH_RATE = 12,
         ELEVATION
      };

      enum Part
      {
         PRIMARY_TURRET = 4096,
         PRIMARY_GUN = 4416,
         SECONDARY_GUN = 6016
      };

      enum Designator
      {
         ARTICULATED = 0,
         ATTACHED = 1
      };
   }

int main(int argc, char const *argv[]) {

Model::DIS_enum disa;

Model::warShip ship1("Hamburg","F124","Germany");
Model::Equipment eq1("Alpha");
Model::cannon can1("Otto Melara MK21",120);
ship1.addEquipment(&eq1);
std::cout << ship1.getKind() << '\n';
eq1.addWeapon(&can1);

ship1.printInfo();
// ship1.getEquipment()->printInfo();

// std::cout << disa.checkContentType(ship1.getSubCategory()) << '\n';

ship1.createDISPDU();
ship1.sendToNetwork();

DIS::ArticulationParameter equipment[5];
equipment[1].setPartAttachedTo(0);

std::cout << DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET,Articulation::AZIMUTH)<< '\n';
std::cout << DIS::Convert::GetArticulationTypeMetric(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET,Articulation::AZIMUTH)) << '\n';
std::cout << DIS::Convert::GetArticulationTypeClass(DIS::Convert::MakeArticulationParameterType(Articulation::PRIMARY_TURRET,Articulation::AZIMUTH)) << '\n';

// ship1.makeDISArticulationsParameter(&eq1);
  return 0;
}
