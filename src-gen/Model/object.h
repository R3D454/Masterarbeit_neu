// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#ifndef MODEL_OBJECT_H
#define MODEL_OBJECT_H

/************************************************************
 object class header
 ************************************************************/

#include "Model/Pkg_Model.h"

#include "AnsiCLibrary/Pkg_AnsiCLibrary.h"
#include "EcorePrimitiveTypes/Pkg_EcorePrimitiveTypes.h"
#include "string"
#include <ostream>  // <<
#include <istream>  // >>



#include "Model/sensor.h"
#include "Model/weapon.h"
#include "Equipment.h"
/************************************************************
 functions
 ************************************************************/
 #include "externeFunktionen/pos_convert.h"
 #include "externeFunktionen/structs.h"
 #include "externeFunktionen/send_recv_data.h"


/************************************************************
 DIS class header
 ************************************************************/
 #include <DIS/EntityStatePdu.h>
 #include "DIS/Vector3Double.h"
 #include "DIS/Conversion.h"


 /************************************************************
  GeographicLib class header
  ************************************************************/
  #include <GeographicLib/Constants.hpp>
  #include <GeographicLib/Geocentric.hpp>
  #include <GeographicLib/Geodesic.hpp>

  #include "DIS_enum.h"
  using namespace GeographicLib;

// Geocentric earth(Constants::WGS84_a(), Constants::WGS84_f());
// Geodesic geod(Constants::WGS84_a(), Constants::WGS84_f());




namespace Model {
class Equipment;
}

namespace Model {

/************************************************************/
/**
 *
 */
class object {

protected:
  /**
   * creat DIS pdu
   *
   */
  void makeStdDISPDU(DIS::Vector3Float velo,DIS::Orientation orie);
  /**
  *
  *counter ++
  */
  void incrementCounter();
  /**
  *
  * counter --
  */
  void decrementCounter();
  /**
  *
  *counter ++
  */
  void incrementCounterFriendly();
  /**
  *
  * counter --
  */
  void decrementCounterFriendly();
  /**
  *
  *counter ++
  */
  void incrementCounterEnemy();
  /**
  *
  * counter --
  */
  void decrementCounterEnemy();
  /**
  *
  *counter ++
  */
  void incrementCounterNeutral();
  /**
  *
  * counter --
  */
  void decrementCounterNeutral();

public:


	/**
	 *
	 * @param name
	 */
	void setName(std::string /*in*/name);

	/**
	 *
	 * @return
	 */
	std::string getName();

	/**
	 *
	 * @return
	 */
	void generateEntityID();

	/**
	 *
	 * @param name
	 */
	void setCountry(std::string /*in*/name);

	/**
	 *
	 * @return
	 */
	 std::string getCountry();

	/**
	 *
	 * @param number
	 */
	void setProtocolVersion(int /*in*/number);

	/**
	 *
	 * @return
	 */
	int getProtocolVersion();

	/**
	 *
	 * @param name
	 */
	void SetDomain(std::string /*in*/name);

	/**
	 *
	 * @return
	 */
	 std::string getDomain();

	/**
	 *
	 * @param pos
	 */
	void setPosition(double/*in */lat,double/*in */lon,double/*in */ hight);

	/**
	 *
	 * @return position
	 */
	position_dec getPosition();

	/**
	 *
	 * @param value
	 */
	 void setKind(std::string /*in*/k);

	/**
	 *
	 * @return value
	 */
	  std::string getKind();
	/**
	 *
	 *
	 */

	 // virtual void  printInfo();
   // /**
   //  * creat DIS pdu
   //  *
   //  */
	 // void creatDIS_PDU();
   /**
    *
    * @ param struct DIS_EntityType_Variables
    */
   void setDIS_EntityType_Variables(DIS_EntityType_Variables /*in *//*in */entitytype);
   /**
    *
    *@return struct DIS_EntityType_Variables
    */
   DIS_EntityType_Variables getDIS_EntityType_Variables();
   /**
    *
    * @ param positionXYZ
    */
   void setPositionXYZ(Vector3D /*in */positionXYZ);
   /**
    *
    *@return positionXYZ
    */
   Vector3D getPositionXYZ();
   /**
    *
    *@
    */
    void sendToNetwork(char DST[15]);

    /**
     *
     *@param ArticulationParameter
     */
    void addArticulationParameter(std::vector<DIS::ArticulationParameter> /*in */ params);
    /**
     *
     *@return DIS EntityStatePdu
     */
    DIS::EntityStatePdu getDISPdu();
    /**
     *
     *@return Counter
     */
    int getCounter();
    /**
     *
     *@return Membership
     */
    std::string getMembership();
    /**
     *
     *@param membeship (enemy or friendly)
     */
     void setMembership(std::string membership);


    // int getIDNumber();

private:
	/**
	 *
	 */
	std::string Name;
	/**
	 *
	 */
	std::string Country;
	/**
	 *
	 */
	int ProtocolVersion;
	/**
	 *
	 */
	std::string Domain;
	/**
	 *
	 */
	position_dec Position;
	/**
	 *
	 */
  Vector3D PositionXYZ;
   /**
 	 *
 	 */
 	std::string Kind;
	/**
	 *
	 */
	DIS_EntityType_Variables DIS_EntityType;
	/**
	 *
	 */
	DIS::EntityStatePdu DISUnit;
  /**
  *
  */
  std::string Membership;
  /**
   *
   */
  static int Counter;
  /**
   *
   */
  static int CounterFriendly;
  /**
   *
   */
  static int CounterEnemy;
  /**
   *
   */
  static int CounterNeutral;

  bool EntityIDisSet = false;

};
/************************************************************/
/* External declarations (package visibility)               */
/************************************************************/

/* Inline functions                                         */

} // of namespace Model

/************************************************************
 End of object class header
 ************************************************************/

#endif
