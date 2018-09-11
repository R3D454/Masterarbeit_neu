// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_EQUIPMENT_H
#define MODEL_EQUIPMENT_H

/************************************************************
 Equipment class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "EcorePrimitiveTypes/Pkg_EcorePrimitiveTypes.h"
#include "list"
#include "string"
#include <list>

#include "Model/sensor.h"
#include "Model/weapon.h"

namespace Model {
class sensor;
}
namespace Model {
class weapon;
}

namespace Model {

/************************************************************/
/**
 *
 */
class Equipment {
public:

	/**
	 *
	 * @param Name
	 */
	Equipment(std::string /*in*/n);

	/**
	 *
	 * @param name
	 */
	void setName(std::string /*in*/n);

	/**
	 *
	 * @return
	 */
std::string getName();

	/**
	 *
	 * @return list of weapos
	 */
 std::list<weapon*> getWeapon();
 /**
  *
  * @return list of sensors
  */
 std::list<sensor*> getSensor();
	/**
	 *
	 * @param Name
	 */
	void addWeapon(weapon* /*in*/w);

	void addSensor(sensor* /*in*/s);


	/**
	 *
	 */



	void printInfo();

private:
	/**
	 *
	 */
	std::string Name;
	/**
	 *
	 */
	 std::list<weapon*> weaponList;
	/**
	 *
	 */
	 std::list<sensor*> sensorList;


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of Equipment class header
 ************************************************************/

#endif