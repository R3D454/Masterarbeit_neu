// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_SENSOR_H
#define MODEL_SENSOR_H

/************************************************************
 sensor class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "string"

namespace Model {

/************************************************************/
/**
 *
 */
class sensor {
public:

	/**
	 *
	 * @param n
	 */
	void setName(std::string /*in*/n);

	/**
	 *
	 * @return name
	 */
	std::string getName();

	/**
	 *
	 */
	virtual void printInfo();

	/**
	 *
	 * @param name
	 */
	void setCategory(std::string /*in*/c);

	/**
	 *
	 * @return
	 */
	std::string getCategory();

	/**
	 *
	 * @return type
	 */
	std::string getType();

	/**
	 *
	 * @param Name
	 */
	void setType(std::string /*in*/t);

private:
	/**
	 *
	 */
	std::string Name;
	/**
	 *
	 */
	std::string Category;
	/**
	 *
	 */
	std::string Type;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of sensor class header
 ************************************************************/

#endif
