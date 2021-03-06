// --------------------------------------------------------
// Code generated by Papyrus C++
// --------------------------------------------------------

#define Model_sensor_BODY

/************************************************************
 sensor class body
 ************************************************************/

// include associated header file
#include "Model/sensor.h"

// Derived includes directives

namespace Model {

// static attributes (if any)

/**
 *
 * @param n
 */
void sensor::setName(std::string /*in*/n) {
Name = n;
}

/**
 *
 * @return name
 */
std::string sensor::getName() {
  return Name;
}

/**
 *
 * @param name
 */
void sensor::setCategory(std::string /*in*/c) {
  Category = c;
}

/**
 *
 * @return
 */
std::string sensor::getCategory() {
  return Category;
}

/**
 *
 * @return type
 */
std::string sensor::getType() {
  return Type;
}

/**
 *
 * @param Name
 */
void sensor::setType(std::string /*in*/t) {
  Type = t;
}

void sensor::printInfo(){}
} // of namespace Model

/************************************************************
 End of sensor class body
 ************************************************************/
