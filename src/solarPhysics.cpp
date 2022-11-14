/*
 * SolarPhysics.cpp
 *
 *  Created on: 29 May 2020
 *      Author: jole
 */

//#include "JulianDay.h"
#include "solarPhysics.h"

#include <iostream>

#include <math.h>
#include <stdio.h>

using namespace std;



SolarPhysics::SolarPhysics(int _year, int _month, int _day, int _hour, int _minutes, int _seconds, int _tz, double _lat, double _lon, int _dst) {

	Jd = new JulianDay(_year, _month, _day, _hour, _minutes, _seconds, _tz, _dst);

	this->tz	= Jd->getjdTz();
	this->dst	= Jd->getjdDST();

	this->jd	= Jd->getjdJulianDay();
	this->jc	= Jd->getjdJulianCentury();

	this->lat	= _lat;
	this->lon	= _lon;

	// Debug purpose
	//std::cout << "jc = " << this->jc << "\n";



	this->geomMeanLongSun	= fmod(280.46646 + this->jc * (36000.76983 + this->jc * 0.0003032), 360.);
	printf("jc: %f\n", this->jc*1000);
	this->geomMeanAnomSun	= 357.52911 + this->jc*(35999.05029 - 0.0001537 * this->jc);
	this->eccentEarthOrbit	= 0.016708634 - this->jc * (0.000042037 + 0.0000001267 * this->jc);
	this->sunEqOfCtr		= sin(RADIANS(this->geomMeanAnomSun)) *
							  (1.914602 - this->jc * (0.004817 + 0.000014 * this->jc)) +
							  sin(RADIANS(2. * this->geomMeanAnomSun)) *
							  (0.019993-0.000101 * this->jc) +
							  sin(RADIANS(3. * this->geomMeanAnomSun)) *
							  0.000289;

	this->sunTrueLong		= this->geomMeanLongSun + this->sunEqOfCtr;
	this->sunTrueAnom		= this->geomMeanAnomSun + this->sunEqOfCtr;
	this->sunRadVector		= (1.000001018*(1-this->eccentEarthOrbit*this->eccentEarthOrbit)) /
							  (1+this->eccentEarthOrbit*cos(RADIANS(this->sunTrueAnom)));
	this->sunAppLong		= this->sunTrueLong - 0.00569 -
	                          0.00478 *
	                          sin(RADIANS(125.04 - 1934.136 * this->jc));
	this->meanObliqEcliptic	= 23 +
	                          (26 +
	                          ((21.448 - this->jc * (46.815 + this->jc * (0.00059 - this->jc * 0.001813)))) / 60) / 60;
	this->obliqCorr			= this->meanObliqEcliptic +
	                          0.00256 * cos(RADIANS(125.04 - 1934.136 * this->jc));
	this->sunRtAscen		= DEGREES(atan2(cos(RADIANS(this->obliqCorr)) * sin(RADIANS(this->sunAppLong)),
			                                cos(RADIANS(this->sunAppLong))));
	this->sunDeclin			= DEGREES(asin(sin(RADIANS(this->obliqCorr)) *
	                                  sin(RADIANS(this->sunAppLong))));
	this->varY				= tan(RADIANS(this->obliqCorr/2.)) *
	                          tan(RADIANS(this->obliqCorr/2.));
	this->eqOfTime			= 4 * DEGREES(this->varY *
	                                      sin(2 * RADIANS(this->geomMeanLongSun)) -
	                                      2 * this->eccentEarthOrbit *
	                                      sin(RADIANS(this->geomMeanAnomSun)) +
	                                      4 * this->eccentEarthOrbit * this->varY *
	                                      sin(RADIANS(this->geomMeanAnomSun)) *
	                                      cos(2 * RADIANS(this->geomMeanLongSun)) -
	                                      0.5 * this->varY	 * this->varY *
	                                      sin(4 * RADIANS(this->geomMeanLongSun)) -
	                                      1.25 * this->eccentEarthOrbit * this->eccentEarthOrbit *
	                                      sin(2 * RADIANS(this->geomMeanAnomSun)));

	this->haSunrise			= DEGREES(acos(cos(RADIANS(90.833)) /
	                                      (cos(RADIANS(this->lat)) *
	                                       cos(RADIANS(this->sunDeclin))) -
	                                       tan(RADIANS(this->lat)) *
	                                       tan(RADIANS(this->sunDeclin))));
	if(isnan(this->haSunrise))
		this->haSunrise = -1.;

	this->localSolarNoon	= (720 -
	                           4 * this->lon -
							   this->eqOfTime + this->tz * 60) /
	                           1440;
	this->localSunRise		= this->localSolarNoon - this->haSunrise *4 / 1440;
	//printf("haSunrise from sp.cpp: %f\n", this->haSunrise);
	this->localSunSet		= this->localSolarNoon + this->haSunrise * 4 / 1440;

	//std::cout << "geomMeanLongSun (degrees): " << this->getgeomMeanLongSun() << "\n";
	//std::cout << "geomMeanAnomSun (degrees): " << this->getgeomMeanAnomSun() << "\n";

}

SolarPhysics::~SolarPhysics() {
	delete Jd;
}



char* SolarPhysics::timeStringFromDecimal(double time)
{
	char* retVal	= new char[16];
	
	if(!retVal)
		return NULL;

	time *= 24;

	int hour		= floor(time);
	int minutes		= floor((time - hour) * 60);
	int seconds		= floor((((time - hour) * 60) - minutes) * 60);

	sprintf(retVal, "%0d:%0d:%0d", hour, minutes, seconds);

	return retVal;
}
