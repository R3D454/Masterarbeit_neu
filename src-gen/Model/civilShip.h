// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_civilSHIP_H
#define MODEL_civilSHIP_H

/************************************************************
 civilShip class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/Surface.h"
#include "Model/Equipment.h"

#include "string"
#include <list>
namespace Model {
class sensor;
}

namespace Model {

/************************************************************/
/**
 *
 */
class civilShip: public Surface {
public:

	/**
	 *
	 * @param sensor
	 */
	void addSensor(sensor /*in*/*s);

	/**
	 *
	 */
	void rmSensor();

	/**
	 *
	 * @param Name
	 * @param Typ
	 */
	civilShip(std::string /*in*/n, std::string /*in*/t);

	/**
	 *
	 * @return sensors
	 */
	std::list<sensor*> getSensors();

	/*
	 *
	 *

	 */
	 void printInfo();
private:
	/**
	 *
	 */
	 std::list<sensor*> sensorList;

	 Equipment *equipment;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of civilShip class header
 ************************************************************/

#endif
