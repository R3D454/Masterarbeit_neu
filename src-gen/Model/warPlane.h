// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_WARPLANE_H
#define MODEL_WARPLANE_H

/************************************************************
 warPlane class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/Air.h"
#include "string"

namespace Model {
class Equipment;
}

namespace Model {

/************************************************************/
/**
 *
 */
class warPlane: public Air {
public:

	/**
	 *
	 * @param Name
	 * @param Type
	 */
	warPlane(std::string /*in*/Name, std::string /*in*/Type,std::string /*in*/country);


	~warPlane();
	/**
	 *
	 */
	void rmEquipment();

	/**
	 *
	 * @param Name
	 */
	void addEquipment(Equipment /*in*/*eq);

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
	Equipment* equipment;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of warPlane class header
 ************************************************************/

#endif
