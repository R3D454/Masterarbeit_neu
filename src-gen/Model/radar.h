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
	radar( std::string /*in*/n, float /*in*/r);

	/**
	 *
	 */
	void printInfo();

	/**
	 *
	 * @param Name
	 */
	void setRange(float /*in*/f);

	/**
	 *
	 * @return type
	 */
	float getRange();

private:
	/**
	 *
	 */
	float Range;
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
