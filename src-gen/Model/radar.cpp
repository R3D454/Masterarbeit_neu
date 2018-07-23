// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_radar_BODY

/************************************************************
 radar class body
 ************************************************************/

// include associated header file
#include "Model/radar.h"

// Derived includes directives

namespace Model {

// static attributes (if any)

/**
 *
 * @param type
 * @param range
 * @param name
 */
radar::radar(std::string /*in*/n,std::string /*in*/t, float /*in*/r) : Range(r) {
	sensor::setName(n);
	sensor::setType(t);
}

/**
 *
 */
void radar::printInfo() {
}

/**
 *
 * @param Name
 */
void radar::setRange(float /*in*/r) {
}

/**
 *
 * @return type
 */
float radar::getRange() {
	return Range;
}

} // of namespace Model

/************************************************************
 End of radar class body
 ************************************************************/
