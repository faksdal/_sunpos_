/*
 * SolarPhysics.h
 *
 *  Created on: 29 May 2020
 *      Author: jole
 */

#ifndef SOURCE_SOLARPHYSICS_H_
#define SOURCE_SOLARPHYSICS_H_

#include <math.h>

#include "julianDay.h"

class SolarPhysics{

	int			tz, dst;

	double		jc,
				jd,
				geomMeanLongSun,
				geomMeanAnomSun,
				eccentEarthOrbit,
				sunEqOfCtr,
				sunTrueLong,
				sunTrueAnom,
				sunRadVector,
				sunAppLong,
				meanObliqEcliptic,
				obliqCorr,
				sunRtAscen,
				sunDeclin,
				varY,
				eqOfTime,
				haSunrise,
				localSolarNoon,
				localSunRise,
				localSunSet,
				lat,
				lon;

	JulianDay	*Jd;

	double		RADIANS(double degrees) {return (degrees * M_PI / 180);}
	double		DEGREES(double radians) {return (radians * 180 / M_PI);}

public:
	SolarPhysics(int _year, int _month, int _day, int _hour, int _minutes, int _seconds, int _tz, double _lat, double _lon, int _dst);
	virtual ~SolarPhysics();

	int		gettz(void) { return tz;}

	char*	timeStringFromDecimal(double time);

	double	getJulianDay(void) {return jd;}
	double	getJulianCentury(void) {return jc;}

	double	getgeomMeanLongSun(void)	{ return geomMeanLongSun;}
	double	getgeomMeanAnomSun(void)	{ return geomMeanAnomSun;}
	double	geteccentEarthOrbit(void)	{ return eccentEarthOrbit;}
	double	getsunEqOfCtr(void)			{ return sunEqOfCtr;}
	double	getsunTrueLong(void)		{ return sunTrueLong;}
	double	getsunTrueAnom(void)		{ return sunTrueAnom;}
	double	getsunRadVector(void)		{ return sunRadVector;}
	double	getsunAppLong(void)			{ return sunAppLong;}
	double	getmeanObliqEcliptic(void)	{ return meanObliqEcliptic;}
	double	getobliqCorr(void)			{ return obliqCorr;}
	double	getsunRtAscen(void)			{ return sunRtAscen;}
	double	getsunDeclin(void)			{ return sunDeclin;}
	double	getvarY(void)				{ return varY;}
	double	geteqOfTime(void)			{ return eqOfTime;}
	double	gethaSunrise(void)			{ return haSunrise;}
	double	getlocalSolarNoon(void)		{ return localSolarNoon;}
	double	getlocalSunRise(void)		{ return localSunRise;}
	double	getlocalSunSet(void)		{ return localSunSet;}
	double	getlat(void)				{ return lat;}
	double	getlon(void)				{ return lon;}

};

#endif /* SOURCE_SOLARPHYSICS_H_ */
