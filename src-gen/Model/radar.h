// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_RADAR_H
#define MODEL_RADAR_H

/************************************************************
 radar class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "Model/sensor.h"
#include "string"

namespace Model {

/************************************************************/
/**
 * 
 */
class radar: public sensor {
public:

	/**
	 * 
	 * @param type 
	 * @param range 
	 * @param name 
	 */
	radar(std::string /*in*/type, float /*in*/range, std::string /*in*/name);

	/**
	 * 
	 */
	void printInfo();

	/**
	 * 
	 * @param Name 
	 */
	void setRange(std::string /*in*/Name);

	/**
	 * 
	 * @return type 
	 */
	std::string getRange();

private:
	/**
	 * 
	 */
	float range;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of radar class header
 ************************************************************/

#endif
