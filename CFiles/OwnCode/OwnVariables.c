
// controller.c variables
double theta_R, theta_g, d0, dp, dg, omega, v;

// design parameter. Make sure you update K_Psi accordingly
// I think higher p -> faster movement.
// if p > 1: K_Psi < L/(Rp)
// else: K_Psi < L/R
const double p = 1;

// Controller variables, see report
// OBS! Error using R_true, L_true.
const double K_omega = 1/R_true, K_Psi = L_true/(R_true * p);
// const double K_Psi = 1.5 * 5.045, K_omega = 9.99;

// States, see report
enum {
    ROTATION = 1,
    TRANSLATION = 2,
    SLEEP = 3
};
int state = ROTATION; // initial state

// Guard tolerances, see report
const double alpha = 2, beta = 0.5;