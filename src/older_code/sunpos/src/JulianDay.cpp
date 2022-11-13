/*
 * JulianDay.cpp
 *
 *  Created on: 15 Jul 2020
 *      Author: jole
 */



#include "JulianDay.h"



JulianDay::JulianDay(int day, int month, int year, int hour, int minutes, int seconds, int timeZone, int daylightSavings)
{
	int a, m, y;


	jdDay		= day;
	jdMonth		= month;
	jdYear		= year;

	jdHour		= hour;
	jdMinutes	= minutes;
	jdSeconds	= seconds;

	jdTZ		= timeZone;
	jdDST		= daylightSavings;

	jdHour -= timeZone;

	jdJulianDay		= 0.;
	jdJulianCentury	= 0.;

	a	= ((14 - jdMonth) / 12);
	m	= jdMonth - 3 + 12 * a;
	y	= jdYear + 4800 - a;

	if (jdYear > 1582 || (jdYear == 1582 && jdMonth > 10) || (jdYear == 1582 && jdMonth == 10 && jdDay >= 15))
		jdJulianDay = jdDay + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	else
		jdJulianDay = jdDay + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;

	jdJulianDay -= .5;
	jdJulianDay -= jdTZ / 24.;

	jdJulianDay += 1. - ((86400.0 - (jdSeconds + ((jdMinutes) * 60.0) + ( (jdHour) * 3600.0)) ) / 86400.0);

	jdJulianCentury = (jdJulianDay - 2451545.) / 36525.;

	jdTimePastLocalMidnightMinutes = jdHour * 60 + jdMinutes;
}



JulianDay::~JulianDay() {
	// TODO Auto-generated destructor stub
}



/*JulianDay::JulianDay(const JulianDay &other) {
	// TODO Auto-generated constructor stub

}
*/
