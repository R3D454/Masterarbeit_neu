
#include "pos_convert.h"




// double convert_position (DIS::Vector3Double p){
//
//  double sec = 0;
//  double min = 0;
//
//  double dec_Pos = 0;
//
//   sec = p.getZ();
//   min = (p.getY() + sec) / 60;
//   dec_Pos= p.getX() + min;
//
//   return dec_Pos;
// }
//
//
// Position deconvert_position (double lat, double lon ) {
//   Position p ;
//
//   int degree_lat = lat;
//   p.lat.setX(degree_lat);
//   double x = (lat - degree_lat)*60;
//   p.lat.setY((int)x);
//   p.lat.setZ((short)(x-(int)x)*60);
//
//   int degree_lon = lon;
//   p.lon.setX(degree_lon);
//   double y = (lon - degree_lon)*60;
//   p.lon.setY((int)y);
//   p.lon.setZ((short)(y-(int)y)*60);
//
//   return p;
// }




XYZtriplet BLh2XYZ( position_dec blh)
{

   double a = a_wgs;
   double b = b_wgs;

	double fi = blh.lat * PI/180;
	double lambda = blh.lon* PI/180;
	double h = blh.height_above_geoid;

	double e_2 = 1.0 - b*b/a/a;
	double sn = sin(fi);
	double cs = cos(fi);
	double N = a/sqrt(1.0 - e_2*sn*sn);

	double X = (N + h)		* cs*cos(lambda);
	double Y = (N + h)		* cs*sin(lambda);
	double Z = (N*(1-e_2) + h)	* sn;

	XYZtriplet retval;
	retval.x = X;
	retval.y = Y;
	retval.z = Z;

	return retval;
}

position_dec XYZ2BLh( XYZtriplet p)
{
  const double a = a_wgs;
  const double b = b_wgs;
	double  f2, e22, X, Y, Z, R,
            aa, c, q1, q2, p1, p2,
            D, sqd, y, q, r, A, B,
            t, t2, tg, sn, xe, ye, tgphi, cosphi;

	f2  = a/b;
	e22 = a*f2 - b;
	X = p.x;
	Y = p.y;
	Z = p.z;
	R = sqrt(X*X + Y*Y);

	aa = 2*(f2*R + e22) / Z;
	c  = 2*(f2*R - e22) / Z;

    	q  = -(aa*c + 4.)/3.;
	r  =  (aa*aa - c*c)*0.5;
    	A  = -pow(fabs(r)+sqrt(r*r-q*q*q),1./3.);
    	//A = -exp(log(fabs(r)+sqrt(r*r-q*q*q)) * ONETHIRD);
    	if( r<0 ) A=-A;
    	B = (0==A ? 0 : q/A);
	y = A+B;

	D = y*y + 4.;
	sqd = sqrt(D);
    	q1 = (y + sqd) * 0.5;
    	q2 = (y - sqd) * 0.5;

    	p1 = (aa*q1-c)/(q1-q2);

	D = p1*p1 - 4*q1;
	if(D >= 0.0)
        	t = (-p1 + sqrt(D)) * 0.5;
	else
	{
        	p2 = (c-aa*q2)/(q1-q2);
        	t = (-p2 + sqrt(p2*p2 - 4*q2)) * 0.5; // D2 = p2*p2 - 4*q2;
    	}

    	position_dec blh;

	t2 = t*t;
	t *= 2;
	tg = t/(1-t2);
	sn = t/(1+t2);

	xe = a*sn/tg;
	ye = b*sn;

	tgphi = tg*f2;
	blh.lat = atan(tgphi)*180/PI;			//E = atan( (1-f_bessel)*tan(B) );
	blh.lon = atan(Y/X)*180/PI;
	cosphi = 1 / sqrt(1+tgphi*tgphi);
	blh.height_above_geoid = (R - xe)*cosphi + (Z-ye)*tgphi*cosphi;

	return blh;
}
