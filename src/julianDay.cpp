/*
 * julianDay.cpp
 *
 *  Created on: 15 Jul 2020
 *      Author: jole
 *      
 *	Class julianDay calculates the Julian Day Number for any given date and time.
 *	
 *	The work is based on the work of others, and includes resources I found here:
 *		- https://www.ladybug.tools/ladybug-web/solar-calculator-noaa/noaa-sandbox-r2.html
 *		- https://gml.noaa.gov/grad/solcalc/main.js
 *		- https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation
 *		  
 *	The class is provided 'as-is', feel free to modify to your own needs.		 
 */


#include <math.h>

#include "julianDay.h"



JulianDay::JulianDay(int year, int month, int day, int hour, int minutes, int seconds, int timeZone, int daylightSavings)
{
	float a, m, y;

	
	jdYear		= year;
	jdMonth		= month;
	jdDay		= day;

	jdHour		= hour;
	jdMinutes	= minutes;
	jdSeconds	= seconds;
	
	jdTZ		= timeZone;
	jdDST		= daylightSavings;
	
	// adjust for timezone
	//jdHour -= timeZone;

	// initialize to NIL
	jdJulianDay		= 0.;
	jdJulianCentury	= 0.;
	
	//printf("\nJulian day params: date: %d/%02d/%02d, local time: %02d:%02d:%02d timezone: %d DST: %d\n\n", jdYear, jdMonth, jdDay, jdHour, jdMinutes, jdSeconds, jdTZ, jdDST);

	// we assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statement
	validDate		= true;
	gregorianDate	= true;
	
	// if we're in 1582, check for valid date
	if(jdYear == 1582 && jdMonth == 10){
		switch(jdDay){
		case 1:
		case 2:
		case 3:
		case 4:		gregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	printf("\n No such date!\n Exiting...\n");
					validDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(jdYear == 1582 && jdMonth < 10){
		gregorianDate = false;
		//printf("\nYear == 1582 and month is less than 10.\n");
	}
	else if(jdYear < 1582){
		gregorianDate = false;
		//printf("\nYear is less than 1582.\n");
	}
		
	
	
	// pre-calculations used in both algorithms
	a	= floor(((14 - jdMonth) / 12));
	m	= jdMonth - 3 + floor(12 * a);
	y	= jdYear + 4800 - a;
	
	// different algorithms based on which calendar used, Gregorian or Julian
	if(!gregorianDate){
		printf("Perform calculations based on Julian date...\n");
		
		jdJulianDay = jdDay + floor((153 * m + 2) / 5) + floor(365 * y) + floor(y / 4) - 32083;
	}
	
	else if(gregorianDate){
			printf("Perform calculations based on gregorian date...\n");
			
			
			jdJulianDay =	jdDay
							+ floor(((153 * m) + 2) / 5) 
							+ (365 * y) 
							+ floor(y / 4) 
							- floor(y / 100) 
							+ floor(y / 400) 
							- 32045;
	}
	
	// calculate Julian Century
	jdJulianCentury = (jdJulianDay - 2451545.) / 36525.;
	
	// Up until here we've calculated the Julian day starting at noon the specific date.
	// Now we need to take into account the timezone, the location and local time.
	
	printf("JD at noon, before calculating time offset %f\n", jdJulianDay);
	
	// take off half-a-day so that we start at midnight
	jdJulianDay -= 0.5;
	printf("JD at noon, before calculating time offset %f\n", jdJulianDay);
	jdJulianDay += ((jdHour + (jdMinutes/60.) + (jdSeconds/3600.) )/24.);
	
	printf("JD at noon, after calculating time offset %f\n", jdJulianDay);
}



JulianDay::~JulianDay() {
	// TODO Auto-generated destructor stub
}



/*JulianDay::JulianDay(const JulianDay &other) {
	// TODO Auto-generated constructor stub

}
*/
