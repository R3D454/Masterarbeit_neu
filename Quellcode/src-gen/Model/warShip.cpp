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
  driven::setEquipment(eq);

}

/**
 *
 * @param Name
 * @param Typ
 */
warShip::warShip(std::string /*in*/Name, std::string /*in*/Type, std::string/*in*/ country) {
object::setName(Name);
driven::setType(Type);
if (Type== "F124") {
  driven::setCategory("Guided Missile Frigate (FFG)");
  driven::setSubCategory("Sachsen Class (Type 124)");
} else if (Type == "F123") {
  driven::setSubCategory("Brandenburg class (Type 123)");
  driven::setCategory("Guided Missile Frigate (FFG)");

}else if (Type == "F122"){
  driven::setSubCategory("Bremen class (Type 122)");
  driven::setCategory("Guided Missile Frigate (FFG)");
} else{
    std::string SubCategory;
    std::string Category;
    std::cout <<"Category as written in DIS Enum:";
    getline(std::cin, Category);
    // std::cin >> Category;
    std::cout << std::endl <<"SubCategory as written in DIS Enum:";
      getline(std::cin, SubCategory);
    driven::setSubCategory(SubCategory);
    driven::setCategory(Category);
}
object::setCountry(country);
object::setKind("Platform");
object::SetDomain("Surface");
object::setPosition(0,0,0);
equipment = NULL;
object::incrementCounter();
}



warShip::~warShip(){
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
  std::cout << "Name:" << object::getName() <<" "<< "Typ:" << driven::getType() << " " << object::getMembership()<<'\n';

  equipment->printInfo();

}


} // of namespace Model

/************************************************************
 End of warShip class body
 ************************************************************/
