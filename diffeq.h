//
// Created by Brian Dolle on 4/20/18.
//

#ifndef RUNGERLC_DIFFEQ_H
#define RUNGERLC_DIFFEQ_H

#include "coords.h"
class diffeq {

public:
    coords coords1_;   // Making an instance "coords1"

    // Member Variables
    double h_;
    double w=1.0;
    double L=25.0;
    double R=7.0;
    double C=5.0;
    double V0=2.0;
    int steps_;

    diffeq(double q, double i, double tinitial, double tfinal, int step); // Constructor
    ~diffeq(); // Destructor

    // Member functions
    void step();
    void runloop();
    double qdotfunc(coords);
    double idotfunc(coords);

}; // ends class

#endif //RUNGERLC_DIFFEQ_H
