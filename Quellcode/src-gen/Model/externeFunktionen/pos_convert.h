
#ifndef POS_CONVERT_H
#define POS_CONVERT_H

// #include "DIS/Vector3Double.h"
#include <math.h>
#include <iostream>

#define  PI  3.141592653589793238463
#define DEG_TO_RAD  0.01745
const double  a_wgs	    = 6378137.0; //äquator radius
const double  b_wgs	    = 6356752.314245179; // Polradius

// struct Position {
//   DIS::Vector3Double lat;
//   DIS::Vector3Double lon;
//
// };

struct Vector3D { // for orientation x = psi, y = theta and z = phi
  double x;
  double y;
  double z;
};


struct position_dec {

double lat; // breite
double lon; // länge
double height_above_geoid;
long   height_above_ellipsoid;
};

struct XYZtriplet {
  double x;
  double y;
  double z;
};

// convert_position convert a position in degree° minutes' and seconds to a decimal position type if double
// deconvert_position convert a decimal position to the standard style of position degree° minutes' and seconds

// double convert_position (DIS::Vector3Double p);
// Position deconvert_position (double lat, double lon );
position_dec XYZ2BLh(XYZtriplet p);
XYZtriplet BLh2XYZ(position_dec blh);


#endif
