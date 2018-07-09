// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_SUBSURFACE_H
#define MODEL_SUBSURFACE_H

/************************************************************
 Subsurface class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "Model/driven.h"
#include "string"

namespace Model {

/************************************************************/
/**
 *
 */
class Subsurface: public driven {
public:

	// virtual void printInfo();
protected:

	/**
	 *
	 * @return isPositionValid
	 */
	std::string checkPosition();


};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of Subsurface class header
 ************************************************************/

#endif
