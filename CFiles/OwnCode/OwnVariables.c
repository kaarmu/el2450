

// const float K_psi = 5.045;
// const float K_omega = 9.99;
float theta_R;
float theta_g;


// design parameter, virtual look-ahead dist.
const float p = 1; 
float dp, dg, v, omega;


const float K_omega = 1 / R_true;
const float K_psi = L_true / (R_true * p);

enum {
    ROTATION = 1,
    TRANSLATION = 2,
    SLEEP = 3
};
int state = ROTATION;

const float alpha = 2, beta = 0.5;