/*
 * julianDay.h
 *
 *	Created on: 15 Jul 2020
 *	Author: jole
 *	
 *	JulianDay calculates JD for the given time at Greenwich meridian
 */

#ifndef SRC_JULIANDAY_H_
#define SRC_JULIANDAY_H_

using namespace std;

#include <ctime>
#include <iostream>
#include <string.h>
#include <stdio.h>



class JulianDay {

	bool	gregorianDate, validDate;
	
	int		jdYear, jdMonth, jdDay, jdHour, jdMinutes, jdSeconds, jdTZ, jdDST, jdTimePastLocalMidnightMinutes;

	double	jdJulianDay, jdJulianCentury;

public:
	JulianDay(int year, int month, int day, int hour, int minutes, int seconds, int timeZone, int daylightSavings);

	virtual ~JulianDay();


	int		getjdYear(void)							{ return jdYear; }
	int		getjdMonth(void)						{ return jdMonth; }
	int		getjdDay(void)							{ return jdDay; }
	int		getjdHour(void)							{ return jdHour; }
	int		getjdMinutes(void)						{ return jdMinutes; }
	int		getjdSeconds(void)						{ return jdSeconds; }
	int		getjdTz(void)							{ return jdTZ; }
	int		getjdDST(void)							{ return jdDST; }
	int 	getjdTimePastLocalMidnightMinutes(void)	{ return jdTimePastLocalMidnightMinutes; }

	double 	getjdJulianDay(void)					{ return jdJulianDay; }
	double 	getjdJulianCentury(void)				{ return jdJulianCentury; }
};

#endif /* SRC_JULIANDAY_H_ */
