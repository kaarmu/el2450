
// theta_g = atan2((yg-y0),(xg-x0))*(180/PI);

// Serial.print("RenewControlState\n");

// switch (state)
// {
// case ROTATION:
    
//     // Guard
//     if (std::abs(theta - theta_g) <= alpha) {
//         state = TRANSLATION;
//     }

//     break;

// case TRANSLATION:

//     // Guard
//     if (sqrt(pow(xg - x, 2) + pow(yg - y, 2)) <= beta) {
//         state = ROTATION;
//     }

//     break;

// case SLEEP:
//     Serial.print("Stuck at SLEEP.");
//     break;

// default:
//     Serial.print("something has gone to shit.");
//     break;
// }



state = ROTATION;