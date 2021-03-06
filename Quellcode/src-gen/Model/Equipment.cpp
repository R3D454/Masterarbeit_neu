// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_Equipment_BODY

/************************************************************
 Equipment class body
 ************************************************************/

// include associated header file
#include "Model/Equipment.h"

// Derived includes directives


namespace Model {

// static attributes (if any)

/**
 *
 * @param Name
 */
Equipment::Equipment(std::string /*in*/n) {
  Name=n;
}

/**
 *
 * @param name
 */
void Equipment::setName(std::string /*in*/n) {
  Name = n;
}

/**
 *
 * @return
 */
std::string Equipment::getName() {
return Name;
}

/**
 *
 * @return list of weapons
 */
 std::list<weapon*> Equipment::getWeapon() {
   return weaponList;
}
/**
 *
 * @return list of sensors
 */
std::list<sensor*> Equipment::getSensor() {
  return sensorList;
}
/**
 *
 * @param w
 */
void Equipment::addWeapon(weapon* /*in*/w) {
  weaponList.push_back(w);
}

/**
 *
 * @param s
 */
void Equipment::addSensor(sensor* /*in*/s) {
  sensorList.push_back(s);
}
/**
 *
 */
void Equipment::printInfo() {
  std::cout<< "Equipment name:" <<Name <<std::endl;
  std::cout << "Weapons are:" << '\n';
  if(!weaponList.empty()){
  	for(std::list<weapon*>::iterator it=weaponList.begin(); it != weaponList.end(); ++it)
  		{
  			(*it)->printInfo();
  			//std::cout<<" "<<std::endl;
  		}
  }
  else {
    std::cout << "Weapon list is empty" << '\n';
  }
  std::cout << "Sensors are:" << '\n';
  if(!sensorList.empty()){
  	for(std::list<sensor*>::iterator it=sensorList.begin(); it != sensorList.end(); ++it)
  		{
  			(*it)->printInfo();
  			//std::cout<<" "<<std::endl;
  		}
  }
  else {
    std::cout << "Sensor list  is empty" << '\n';
  }
}

} // of namespace Model

/************************************************************
 End of Equipment class body
 ************************************************************/
