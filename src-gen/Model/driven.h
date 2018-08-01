// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_DRIVEN_H
#define MODEL_DRIVEN_H

/************************************************************
 driven class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "Model/object.h"
#include "string"


namespace Model {

/************************************************************/
/**
 *
 */
class driven: public object {
public:

	/**
	 *
	 * @return
	 */
	std::string getCategory();

	/**
	 *
	 * @param name
	 */
	void setCategory(std::string /*in*/cat);

	/**
	 *
	 * @return
	 */
	std::string getSubCategory();

	/**
	 *
	 * @param name
	 */
	void setSubCategory(std::string /*in*/sub);
	/**
	 *
	 */
	void rmAllEquipment();

	/**
	 *
	 * @param velocity
	 */
	void setVelo(Vector3D /*in*/v);

	/**
	 *
	 * @return velocity
	 */
	Vector3D getVelo();

	/**
	 *
	 * @param orientation
	 */
	void setOrientation(Vector3D /*in*/o);

	/**
	 *
	 * @return orientation
	 */
	Vector3D getOrientation();


	/**
	 *
	 * @param type
	 */
	void setType(std::string /*in*/type);

	/**
	 *
	 * @return type
	 */
	std::string getType();

	/**
	 *
	 *
	 */
	 virtual void printInfo();
	 /**
 	 *
 	 *
 	 */
	 void getDIS_PDUType(std::string kind, std::string domain , std::string country , std::string category,  std::string subcategory);
	 /**
 	 *
 	 *
	 */
	 void createDISPDU();
	 /**
 	 *
 	 *
	 */
	 void makeDISArticulationsParameter();




protected:
	/**
	*
	*
	*/
	void setEquipment(Equipment *eq);
	/**
	*
	*
	*/
	Equipment* getEquipment();

	/**
	 *
	 * @return isPositionValid
	 */
	// virtual std::string checkPosition();

	void updateObject(double dt);
private:
	/**
	 *
	 */
	std::string Type;
	/**
	 *
	 */
	std::string Category;
	/**
	 *
	 */
	Vector3D Velocity;
	/**
	 *
	 */
	Vector3D Orientation;
	/**
	 *
	 */
	std::string SubCategory;

	Equipment *equipment = NULL;
};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of driven class header
 ************************************************************/

#endif
