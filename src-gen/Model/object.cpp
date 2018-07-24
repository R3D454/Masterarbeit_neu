// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_object_BODY

/************************************************************
 object class body
 ************************************************************/

// include associated header file
#include "Model/object.h"

// Derived includes directives
#include "Model/Equipment.h"

namespace Model {

// static attributes (if any)

/**
 *
 * @param name
 */
void object::setName(std::string /*in*/name) {
	Name = name;
}

/**
 *
 * @return
 */
std::string object::getName() {
	return Name;
}

/**
 *
 * @return
 */
void object::generateEntityID() {
}

/**
 *
 * @param name
 */
void object::setCountry(std::string /*in*/name) {
	Country = name;
}

/**
 *
 * @return
 */
std::string object::getCountry() {
	return Country;
}

/**
 *
 * @param number
 */
void object::setProtocolVersion(int /*in*/number) {
	ProtocolVersion = number;
}

/**
 *
 * @return
 */
int object::getProtocolVersion() {
	return ProtocolVersion;
}

/**
 *
 * @param name
 */
void object::SetDomain(std::string /*in*/name) {
	Domain = name;
}

/**
 *
 * @return
 */
std::string object::getDomain() {
	return Domain;
}

/**
 *
 * @param pos
 */
void object::setPosition(double lat,double lon,double height) {
Position.lat = lat;
Position.lon = lon;
Position.height_above_geoid = height;

}

/**
 *
 * @return position
 */
position_dec object::getPosition() {
	return Position;
}

/**
 *
 * @param value
 */
void object::setKind(std::string /*in*/k) {
	Kind = k;
}

/**
 *
 * @return value
 */
std::string object::getKind() {
	return Kind;
}

void object::creatDIS_PDU(){
// DISUnit.setProtocolVersion(6);


}

/**
 *
 * @param location
 * @param orientation
 * @param equipment
 * @param category
 * @param subCategory
 */
// void object::convertToDIS(undefined /*in*/location, undefined /*in*/orientation,
// 		Equipment /*in*/equipment, int /*in*/category, int /*in*/subCategory) {
// }
	void object::setDIS_EntityType_Variables(DIS_EntityType_Variables entitytype){
	DIS_EntityType = entitytype;


	}

	DIS_EntityType_Variables object::getDIS_EntityType_Variables(){
			return DIS_EntityType;
	}

} // of namespace Model

/************************************************************
 End of object class body
 ************************************************************/
