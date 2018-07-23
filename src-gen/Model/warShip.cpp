// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_warShip_BODY

/************************************************************
 warShip class body
 ************************************************************/

// include associated header file
#include "Model/warShip.h"

// Derived includes directives
#include "Model/Equipment.h"

namespace Model {

// static attributes (if any)

/**
 *
 * @param Name
 */
void warShip::addEquipment(Equipment /*in*/*eq)  {
  equipment = eq;

}

/**
 *
 * @param Name
 * @param Typ
 */
warShip::warShip(std::string /*in*/Name, std::string /*in*/Typ) {
object::setName(Name);
driven::setType(Typ);
object::setKind("Platform");
equipment = NULL;

}

/**
 *
 */
void warShip::rmEquipment() {
  equipment = NULL;
}

/**
 *
 */
void warShip::calcShoot() {
}

/**
 *
 * @return equipment
 */
Equipment* warShip::getEquipment() {
  
    return equipment;
}


void warShip::printInfo(){
  std::cout << "Name:" << object::getName() <<" "<< "Typ:" << driven::getType() <<'\n';

}

} // of namespace Model

/************************************************************
 End of warShip class body
 ************************************************************/
