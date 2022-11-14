/*
 * printUsage.cpp
 *
 *	Created on: 13th of November 2022
 *	Author: jole
 */

#include "printUsage.h"

using namespace std;

void printUsage(void)
{
	cout << "sunpos, a comamnd line utility to calculate the suns location on the sky, at the time and location given.\n";
	cout << "Copyright © 2022 Jon Leithe\n\n";
	cout << "Usage: sunpos --date yyyy-mm-dd --time hh:mm:ss --tz n --lat d.ddddd --lon d.ddddd --dst nn(minutes)\n";
	
	cout << "\n\n";
	cout << " --date		date given as yyyy/mm/dd or yyyy-mm-dd\n";
	cout << " --time		local time of day, given as hh:mm:ss\n";
	cout << " --tz		timezone, positive to the east\n";
	cout << " --lat		latitude, given as dd.ddddd°\n";
	cout << " --lon		longitude, given as dd.ddddd°\n";
	cout << " --dst		daylight savings time, given in minutes (usually 0 or 60)\n";
	
			/*
			{"date",	required_argument,	NULL,	1},
								{"time",	required_argument,	NULL,	2},
								{"tz",		required_argument,	NULL,	3},
								{"lat",		required_argument,	NULL,	4},
								{"lon",		required_argument,	NULL,	5},
								{"dst",
			*/	
}
