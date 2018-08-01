// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_MILITARY_H
#define MODEL_MILITARY_H

/************************************************************
 military class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/Land.h"
#include "string"

namespace Model {
class Equipment;
}

namespace Model {

/************************************************************/
/**
 *
 */
class military: public Land {
public:
	/**
	*
	* @param Name
	* @param Type
	*/
	military(std::string /*in*/Name, std::string /*in*/Type,std::string /*in*/country);

	~military();

	/**
	 *
	 */
	void calcShoot();

	/**
	 *
	 * @param Name
	 */
	void addEquipment(Equipment /*in*/*eq);

	/**
	 *
	 */
	void rmEquipment();


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
 End of military class header
 ************************************************************/

#endif
