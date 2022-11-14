//#include <iostream>
//#include <iomanip>

#include <getopt.h>

#include "julianDay.h"
#include "printUsage.h"
#include "parseOptarg.h"
#include "solarPhysics.h"



using namespace std;



int main(int argc, char *argv[])
{
	SolarPhysics *sp;
	
	int		year, month, day, hour, minute, second, timezone, dst;
	double		lat, lon;
	
	/*getopt variables*/
	int		c, optionIndex;
	//float	input = 0L, output;
	char	*shortOptions = (char*)"";
		
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	1},
					{"time",	required_argument,	NULL,	2},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{0, 0, 0, 0}
	};
	/*end og getopt variables*/
	
	// print a message telling how to use the software if the user don't supply arguments
	if(argc == 1){
		printUsage();
		exit(1);
	}
	
	// initialize command line variables to some default values, should the user fail to provide...
	year		= 2000;
	month		= 1;
	day			= 1;
	hour		= 13;
	minute		= 0;
	second		= 0;
	timezone	= 1;
	dst			= 0;
	lat			= 64.466;
	lon			= 11.495;
	
	/*getopt switch statement*/
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 1:		{
								year = atoi(optarg);
								parseOptarg(&optarg);
								month = atoi(optarg);
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg
																								
								// print for debug purposes
								//printf("year: %d, month: %d, day %d\n", year, month, day);
								break;
							}
				case 2:		{
								hour = atoi(optarg);
								parseOptarg(&optarg);
								minute = atoi(optarg);
								parseOptarg(&optarg);
								second = atoi(optarg);
								// end of parsing optarg
																															
								// print for debug purposes
								//printf("hour: %d, minute: %d, second %d\n", hour, minute, second);
								break;
							}
				case 3:		{	
								timezone = atoi(optarg);
								
								// print for debug purposes
								//printf("timezone: %d\n", timezone);
								break;
							}
				case 4:		{
								lat = atof(optarg);
								
								// print for debug purposes
								//printf("latitude: %f\n", lat);
								break;
				}
				case 5:		{	
								lon = atof(optarg);
								
								// print for debug purposes
								//printf("longitude: %f\n", lon);
								break;
							}
				case 6:		{
								dst = atoi(optarg);
								//printf("dst(min): %d\n", dst);
								break;
							}
				default:	{
								printf("switch default\n");
								break;
							}
			}
		}
	/*end of getopt switch statement*/

	
	
	sp = new SolarPhysics(year, month, day, hour, minute, second, timezone, lat, lon, dst);

	//cout.setf(ios::showpos); 
	//cout.setf(ios::scientific); 
	//cout.fill('0');
	cout.precision(8);
	cout.width(20);
	cout << "               Julian Day: " << std::fixed << sp->getJulianDay() << "\n";
	//cout.precision(8);
	cout << "           Julian Century: " << std::fixed <<  sp->getJulianCentury() << "\n";
	
	cout << "\n            lat (degrees): " << sp->getlat() << "\n";
	cout << "            lon (degrees): " << sp->getlon() << "\n";

	cout << "                 Timezone: " << sp->gettz() << "\n";

	
	cout << "geomMeanLongSun (degrees): " << sp->getgeomMeanLongSun() << "\n";
	cout << "geomMeanAnomSun (degrees): " << sp->getgeomMeanAnomSun() << "\n";
	cout << "         eccentEarthOrbit: " << sp->geteccentEarthOrbit() <<"\n";
	cout << "               sunEqOfCtr: " << sp->getsunEqOfCtr() <<"\n";
	cout << "              sunTrueLong: " << sp->getsunTrueLong() <<"\n";
	cout << "              sunTrueAnom: " << sp->getsunTrueAnom() <<"\n";
	cout << "             sunRadVector: " << sp->getsunRadVector() <<"\n";
	cout << "               sunAppLong: " << sp->getsunAppLong() <<"\n";
	cout << "        meanObliqEcliptic: " << sp->getmeanObliqEcliptic() <<"\n";
	cout << "                obliqCorr: " << sp->getobliqCorr() <<"\n";
	cout << "               sunRtAscen: " << sp->getsunRtAscen() <<"\n";
	cout << "                sunDeclin: " << sp->getsunDeclin() <<"\n";
	cout << "                     varY: " << sp->getvarY() <<"\n";
	/*
	cout << "                 eqOfTime: " << sp->geteqOfTime() <<"\n";
	cout << "                haSunrise: " << sp->gethaSunrise() <<"\n";
	cout << " localSolarNoon (decimal): " << sp->getlocalSolarNoon() <<"\n";
	cout << "   localSolarNoon (h:m:s): " << sp->timeStringFromDecimal(sp->getlocalSolarNoon()) <<"\n";
	
	if(sp->gethaSunrise() != -1){
		cout << "             localSunRise: " << sp->getlocalSunRise() <<"\n";
		cout << "     localSunRise (h:m:s): " << sp->timeStringFromDecimal(sp->getlocalSunRise()) <<"\n";
		cout << "              localSunSet: " << sp->getlocalSunSet() <<"\n";
		cout << "     localSunSet (h:m:s): " << sp->timeStringFromDecimal(sp->getlocalSunSet()) <<"\n";
	}
	else{
		cout << "     Sun below horizon\n";
	}
	*/

	return 1;
}

