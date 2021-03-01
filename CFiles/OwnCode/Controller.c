
switch(112) {
	case 15: // Task 5
	    theta_R = atan2(yg-y0, xg-x0) * 180/PI;

        v = 0;
        omega = K_Psi * (theta_R - theta);
	break;

	case 17: // Task 7
        d0 = (x0 - x) * cos(theta * PI/180)
           + (y0 - y) * sin(theta * PI/180);

        v = K_omega * d0;
        omega = 0;

		v = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)));
	break;

    case 18: // Task 8
	    theta_R = atan2(yg-y0, xg-x0) * 180/PI;

        d0 = (x0 - x) * cos(theta * PI/180)
           + (y0 - y) * sin(theta * PI/180);

        v = K_omega * d0;
        omega = K_Psi * (theta_R - theta);
	break;

	case 110: // Task 10
		theta_g = atan2(yg-y0, xg-x0); // in radians

		// Calculations from Task 10
		dg = cos(theta_g) * (xg - x)/100
           + sin(theta_g) * (yg - y)/100; // [dg] = cm/100 = m

		v = K_omega * dg; // [v] = 1/m * m = OK!
        omega = 0;
	break;

	case 112: // Task 12
		theta_g = atan2(yg-y0, xg-x0);

		// Calculations from Task 12
		dp = sin(theta_g) * (x/100 + p*cos(theta * PI/180) - x0/100)
		   - cos(theta_g) * (y/100 + p*sin(theta * PI/180) - y0/100); // [dp] = ( m + ([p]=m) + m )
		   													  		  //      = m
        v = 0;
		omega = K_Psi * dp; // [omega] = 1/m * m = OK!
	break;

	case 113:
		theta_g = atan2(yg-y0, xg-x0);

		// Calculations from Task 10
		dg = cos(theta_g) * (xg - x)
           + sin(theta_g) * (yg - y);

		// Calculations from Task 12
		dp = sin(theta_g) * (x + 100*p*cos(theta * PI/180) - x0)
		   - cos(theta_g) * (y + 100*p*sin(theta * PI/180) - y0);

		v = K_omega * dg;
		omega = K_Psi * dp;
	break;

	case ROTATION:

		// theta in deg
		// thetaR in deg

		theta_R = atan2((yg-y0),(xg-x0))*(180/PI); // deg

		Serial.print(std::abs(theta - theta_R), DEC);

		if (std::abs(theta - theta_R) <= alpha) {
			state = TRANSLATION;
			break;
		}

	    left = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))-(0.5)*K_Psi*(theta_R-theta);
	    right = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))+(0.5)*K_Psi*(theta_R-theta);
	break;
	case TRANSLATION:

		if (sqrt(pow(xg - x, 2) + pow(yg - y, 2)) <= beta) {
			state = ROTATION;
			break;
		}

		theta_g = atan2((yg-y0),(xg-x0))*(180/PI);

		// Calculations from Task 10
		dg = cos(theta_g*(PI/180)) * (xg - x) + sin(theta_g*(PI/180)) * (yg - y);
		v = K_omega * dg;

		// Calculations from Task 12
		dp = sin(theta_g*(PI/180)) * (x + p*cos(theta*(PI/180)) - x0)
		   - cos(theta_g*(PI/180)) * (y + p*sin(theta*(PI/180)) - y0);
		omega = K_Psi * dp;

		// Control inputs
		left = v - omega/2;
		right =  v + omega/2;
	break;

	default:
	break;
}
							// assumed dim
Serial.print("\n K_omega ");
Serial.print(K_omega, 10);
Serial.print("\n K_Psi   ");
Serial.print(K_Psi);

Serial.print("\n v     ");
Serial.print(v, 10);
Serial.print("\n omega ");
Serial.print(omega, 10);
Serial.print("\n x     ");	// cm
Serial.print(x, 10);
Serial.print("\n y     ");	// cm
Serial.print(y, 10);
Serial.print("\n theta "); 	// rad
Serial.print(theta, 10);

Serial.print("\n x0 ");		// cm
Serial.print(x0, 10);
Serial.print("\n y0 ");	 	// cm
Serial.print(y0, 10);

Serial.print("\n xg "); 	// cm
Serial.print(xg, 10);
Serial.print("\n yg "); 	// cm
Serial.print(yg, 10);

left  = v - omega/2;
right = v + omega/2;
