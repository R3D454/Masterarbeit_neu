// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_WEAPON_H
#define MODEL_WEAPON_H

/************************************************************
 weapon class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "string"
struct gunValues{
  double Orientation; // from -180.00 to 180.00 degree,  0 points to the front, 90 degree to the left side and -90(270) degree to the right side
  double OrientationRate;
  double Elevation; // from 0 to 90 degree
  double ElevationRate;
};
namespace Model {

/************************************************************/
/**
 *
 */
class weapon {
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
	 * @param t
	 */
	void setType(std::string t);
	/**
	 *
	 * @return type
	 */
	std::string getType();

	/**
	 *
	 */
	virtual void printInfo();
	/**
	 *
	 * @param t
	 */
	void setGunValues(double orientation, double elevation);

  void moveGuns(double orientationrate, double elevationrate, double dt);
	/**
	 *
	 * @return type
	 */
	gunValues getGunValues();

private:
	/**
	 *
	 */
	std::string Name;
	/**
	 *
	 */
	std::string Type;
	/**
	 *
	 */
	 gunValues GunValues;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of weapon class header
 ************************************************************/

#endif