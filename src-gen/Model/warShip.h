// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_WARSHIP_H
#define MODEL_WARSHIP_H

/************************************************************
 warShip class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/Surface.h"
#include "string"
#include "Model/Equipment.h"

namespace Model {
class Equipment;
}

namespace Model {

/************************************************************/
/**
 *
 */
class warShip: public Surface {
public:

	/**
	 *
	 * @param Name
	 */
	void addEquipment(Equipment /*in*/*eq);

	/**
	 *
	 * @param Name
	 * @param Typ
	 */
	warShip(std::string /*in*/Name, std::string /*in*/Typ, std::string country);

	/**
	 *
	 */
	void rmEquipment();

	/**
	 *
	 */
	void calcShoot();

	/**
	 *
	 * @return equipment
	 */
	Equipment* getEquipment();
	/**
	 *
	 */
	 void printInfo();
private:
	/**
	 *
	 */
	Equipment *equipment;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of warShip class header
 ************************************************************/

#endif
