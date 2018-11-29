#include <iostream>
#include "diffeq.h"

using namespace std;

int main() {

    double t0 = 0.0;          // Initial time
    double tf = 200.0;       // Final time
    double q0 = 0.0;          // Initial charge
    double i0 = 0.0;          // Initial current
    int steps = 10000;      // Number of steps

    // Instantiating an object "loop1"
    diffeq loop1(q0, i0, t0, tf, steps);
    // Running the runloop function on "loop1"
    loop1.runloop();
    return 0;
}