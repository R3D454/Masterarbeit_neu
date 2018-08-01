// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_warPlane_BODY

/************************************************************
 warPlane class body
 ************************************************************/

// include associated header file
#include "Model/warPlane.h"

// Derived includes directives
#include "Model/Equipment.h"

namespace Model {

// static attributes (if any)

/**
 *
 * @param Name
 * @param Type
 */
warPlane::warPlane(std::string /*in*/Name, std::string /*in*/Type,std::string /*in*/country) {
object::setName(Name);
driven::setType(Type);
object::setCountry(country);
object::setKind("Platform");
object::SetDomain("Air");
object::setPosition(0,0,0);



object::incrementCounter();
equipment = NULL;
driven::setEquipment(NULL);
}

warPlane::~warPlane(){
  object::decrementCounter();
  if (object::getMembership() =="Friendly") {
    object::decrementCounterFriendly();
  } else if(object::getMembership() =="Enemy"){
    object::decrementCounterEnemy();
  }else if (object::getMembership() =="Neutral"){
    object::decrementCounterNeutral();
  }


}
/**
 *
 */
void warPlane::rmEquipment() {
  equipment = NULL;
}

/**
 *
 * @param Name
 */
void warPlane::addEquipment(Equipment /*in*/*eq) {
  equipment = eq;
  driven::setEquipment(eq);
}

/**
 *
 */
void warPlane::calcShoot() {
}

/**
 *
 * @return equipment
 */
Equipment* warPlane::getEquipment() {
  return equipment;
}

void warPlane::printInfo(){
  std::cout << "Name:" << object::getName() <<" "<< "Typ:" << driven::getType() << " "<< object::getMembership()<<'\n';

  equipment->printInfo();

}

} // of namespace Model

/************************************************************
 End of warPlane class body
 ************************************************************/
