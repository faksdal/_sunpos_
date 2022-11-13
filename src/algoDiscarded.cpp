// Overview of different algorithms for calculating julian day

/*
	jdHour -= timeZone;

	jdJulianDay		= 0.;
	jdJulianCentury	= 0.;

	a	= floor(((14 - jdMonth) / 12));
	m	= jdMonth - 3 + (12 * a);
	y	= jdYear + 4800 - a;

	// if the date in question is 15th of October 1582 or newer, then assume Gregorian date and calculate with the proper algorithm
	if (jdYear > 1582 || (jdYear == 1582 && jdMonth > 10) || (jdYear == 1582 && jdMonth == 10 && jdDay >= 15)){
		jdJulianDay =	jdDay
						+ floor(((153 * m) + 2) / 5) 
						+ (365 * y) 
						+ floor(y / 4) 
						- floor(y / 100) 
						+ floor(y / 400) 
						- 32045;
		
		
		 * Algorithm from https://quasar.as.utexas.edu/BillInfo/JulianDatesG.html
		 * Valid for Gregorian dates
		
		int M, Y;
		
		if(jdMonth == 1 || jdMonth == 2){
			M = jdMonth + 12;
			Y = jdYear - 1;
		}
		else{
			M = jdMonth;
			Y = jdYear;
		}
		
		int		A			= floor(Y / 100);
		int		B			= floor(A / 4);
		int		C			= 2 - A + B;
		float	E			= floor(365.25 * (Y + 4716));
		float	F			= floor(30.6001 * (M + 1));
		float	uTexasJD	= C + jdDay + E + F - 1524.5;
		printf("\nWiki julian day from gregorian uTexas: %f\n\n", uTexasJD);
		
		
				
		 * 
		 * Wiki: https://en.wikipedia.org/wiki/Julian_day#Julian_day_number_calculation 
		/
		  float wikiJDGreg =	(1461 * (jdYear + 4800 + floor(floor((jdMonth - 14)/12)))/4)
				  
		 						+ floor(floor(367 * floor(jdMonth - 2 - 12 * floor(floor(jdMonth - 14)/12)))/12)
							
								- floor(floor(3 * ((jdYear + 4900 + floor(floor((jdMonth - 14)/12))/100)))/4)
							
								+ jdDay
							
								- 32075;
		  
		 
		
		//printf("Inside first if-loop\n");
		printf("\nWiki julian day from gregorian: %f\n\n", wikiJDGreg);
	}
	
	// otherwise, assume Julian date and calculate with another algorithm
	else{
		jdJulianDay = jdDay + floor((153 * m + 2) / 5) + floor(365 * y) + floor(y / 4) - 32083;
		//printf("Inside second if-loop\n");
		//printf("julian day from c++: %f\n", jdJulianDay);
		
		float wikiJDJul =	367 * jdYear 
							- floor((7 * (jdYear + 5001 + floor((jdMonth - 9)/7)))/4) 
							+ floor((275 * jdMonth)/9) 
							+ jdDay 
							+ 1729777;
		
		// 		JDN 	=	367 × Y 
		//					− (7 × (Y + 5001 + (M − 9)/7))/4 
		//					+ (275 × M)/9 
		//					+ D + 1729777
		printf("\nWiki julian day from julian: %f\n\n", wikiJDJul);
		
	}

	//jdJulianDay -= .5;
	//jdJulianDay -= jdTZ / 24.;

	//jdJulianDay += 1. - ((86400.0 - (jdSeconds + ((jdMinutes) * 60.0) + ( (jdHour) * 3600.0)) ) / 86400.0);

	jdJulianCentury = (jdJulianDay - 2451545.) / 36525.;

	jdTimePastLocalMidnightMinutes = jdHour * 60 + jdMinutes;
	printf("julian day from c++:	%f\n", jdJulianDay);
	
	
	
	if (jdMonth <= 2) {
			jdYear -= 1;
			jdMonth += 12;
	}
	float A = floor(jdYear/100);
	float B = 2 - A + floor(A/4);
	float JD = floor(365.25*(jdYear + 4716)) + floor(30.6001*(jdMonth+1)) + jdDay + B - 1524.5;
	printf("julian day from python:	%f\n", JD);
	
	
	
	float JDN	= (1461 * (jdYear + 4800 + (jdMonth - 14) / 12)) / 4
				+ (367 * (jdMonth - 2 - 12 * ((jdMonth - 14)/12)))/12 
				- (3 * ((jdYear + 4900 + (jdMonth - 14)/12)/100))/4
				+ jdDay 
				- 32075;
	printf("Julian day from Wiki:	%f\n", JDN);
	*/



