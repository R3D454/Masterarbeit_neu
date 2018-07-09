// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_CIVALSHIP_H
#define MODEL_CIVALSHIP_H

/************************************************************
 civalShip class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/Surface.h"
#include "string"

namespace Model {
class sensor;
}

namespace Model {

/************************************************************/
/**
 *
 */
class civalShip: public Surface {
public:

	/**
	 *
	 * @param sensor
	 */
	void addSensor(sensor /*in*/sensor);

	/**
	 *
	 */
	void rmSensor();

	/**
	 *
	 * @param Name
	 * @param Typ
	 */
	civilShip(std::string /*in*/Name, std::string /*in*/Typ);

	/**
	 *
	 * @return sensors
	 */
	sensor getSensors();

	/*
	 *
	 *

	 */
	 void printInfo();
private:
	/**
	 *
	 */
	sensor* sensors;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of civalShip class header
 ************************************************************/

#endif
