
// u_l = left = v - omega/2
// u_r = right = v + omega/2

Serial.print("State\n");
Serial.print(state, DEC);

switch(state) {
	case 11:
	    theta_R=atan2((yg-y0),(xg-x0))*(180/PI);
	    left = -(0.5)*K_psi*(theta_R-theta);
	    right = (0.5)*K_psi*(theta_R-theta);
	break;
	case 12:
	    left = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)));
	    right = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)));
	break;
	case 13:
	    theta_R = atan2((yg-y0),(xg-x0))*(180/PI);
	    left = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))-(0.5)*K_psi*(theta_R-theta);
	    right = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))+(0.5)*K_psi*(theta_R-theta);
	break;

	case 14:
		theta_g = atan2((yg-y0),(xg-x0))*(180/PI);

		// Calculations from Task 10
		dg = cos(theta_g) * (xg - x) + sin(theta_g) * (yg - y);
		v = K_omega * dg;
		
		// Control inputs
		left = v;
		right = v;
	break;

	case 15:
		Serial.print("\n\n theta ");
		Serial.print(theta, DEC);

		theta_g = atan2((yg-y0),(xg-x0))*(180/PI);

		// Calculations from Task 12
		dp = sin(theta_g) * (x + p*cos(theta) - x0)
		   - cos(theta_g) * (y + p*sin(theta) - y0);
		omega = K_psi * dp;

		// dp = -(0.25 * theta)

		// Control inputs
		left = -omega/2;
		right = omega/2;

		Serial.print("\n theta_g");
		Serial.print(theta_g, DEC);
		Serial.print("\n omega ");
		Serial.print(omega, DEC);
		Serial.print("\n left ");
		Serial.print(left, DEC);
		Serial.print("\n right ");
		Serial.print(right, DEC);


	break;

	case 16:
		theta_g = atan2((yg-y0),(xg-x0))*(180/PI);

		// Calculations from Task 10
		dg = cos(theta_g) * (xg - x) + sin(theta_g) * (yg - y);
		v = K_omega * dg;

		// Calculations from Task 12
		dp = sin(theta_g) * (x + p*cos(theta) - x0)
		   - cos(theta_g) * (y + p*sin(theta) - y0);
		omega = K_psi * dp;

		// Control inputs
		left = v - omega/2;
		right =  v + omega/2;

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
		
	    left = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))-(0.5)*K_psi*(theta_R-theta);
	    right = K_omega*((x0-x)*cos(theta*(PI/180))+(y0-y)*sin(theta*(PI/180)))+(0.5)*K_psi*(theta_R-theta);

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
		omega = K_psi * dp;

		// Control inputs
		left = v - omega/2;
		right =  v + omega/2;
	break;
	default:
	break;
}

