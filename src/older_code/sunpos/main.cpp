/*
 * main.cpp
 *
 *  Created on: 19 Jul 2020
 *      Author: jole
 */

using namespace std;

#include <iostream>
#include <getopt.h>

#include "src/JulianDay.h"


int main(int argc, char *argv[])
{
	int		c;

	string	argStr, outputStr = "";

	//JulianDay	jd(20, 6, 2020, 11, 54, 0, 1, 0);





	while (1) {
		int option_index = 0;
		static struct option long_options[] = {
				/*{"option",	required_argument or no_argument,	0,	0 or 'character'}*/
		        {"date",		required_argument,	0,	'd' },
		        {"time",		required_argument,	0,	't' },
		        {"timezone",		required_argument,	0,	'z' },
		        {"dst",			required_argument,	0,	's' },
		        //{"lat",			required_argument,	0,	0 },
		        //{"lon",			required_argument,	0,	0 },
				//{"output",		required_argument,	0,	0 },
				//{"help",		no_argument,		0,	0 },
		        {0, 0, 0, 0}
		};

		c = getopt_long(argc, argv, "d:t:z:s", long_options, &option_index);
		if (c == -1){
			printf("Learn how to use it! Call +47 466 96 784\n");
			break;
		}

		printf("Option %s", long_options[option_index].name);
		if (optarg){
			printf(" with arg %s\n", optarg);
		}

		switch (c){
			case 'd':	break;
			case 't':	break;

			default:	printf("?? getopt returned character code 0%c ??\n", c);
		}	// switch (c)
	}	// while()

	/*
	if (optind < argc) {
		printf("non-option ARGV-elements: ");
		while (optind < argc)
			printf("%s ", argv[optind++]);

		printf("\n");
	}
	*/


	//cout.precision(8);
	//cout.width(15);

	//cout << "Julianday day: " << fixed << jd.getjdJulianDay() << endl;

	return 0;
}
