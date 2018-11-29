//
// Created by Brian Dolle on 4/20/18.
//

#include "diffeq.h"
#include<iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Defining constructor
diffeq::diffeq(double qinit, double iinit, double tinit, double tfinal, int stp){
    h_ = (tfinal - tinit)/stp;
    coords1_.t_ = tinit;
    coords1_.q_ = qinit;
    coords1_.i_ = iinit;
    steps_ = stp;
}

diffeq::~diffeq() = default; // Destructor

// This runs our step function a bunch of times and prints to a .csv file
void diffeq::runloop() {
    for(int i=0; i<steps_; i++){
        step();
        ofstream fout;
        fout.open("RLC.csv", ios::out | ios::app);
        fout<< coords1_.t_ << "," << coords1_.q_  <<","<<endl;
        // I chose not to print the current because the differential equation
        // called for charge as a function of time - q(t).
    } // closes i loop
} // closes runloop

// This function runs one step of our Runge Kutta code
void diffeq::step(){

    double k1q, k1i, k2q, k2i, k3q, k3i, k4q, k4i;
    coords intercoords;

    k1q = h_ * qdotfunc(coords1_);
    k1i = h_ * idotfunc(coords1_);
    intercoords.q_ = coords1_.q_ + k1q/2.0;
    intercoords.i_ = coords1_.i_ + k1i/2.0;
    intercoords.t_ = coords1_.t_ + h_/2.0;

    k2q = h_ * qdotfunc(intercoords);
    k2i = h_ * idotfunc(intercoords);
    intercoords.q_ = coords1_.q_ + k2q/2.0;
    intercoords.i_ = coords1_.i_ + k2i/2.0;
    intercoords.t_ = coords1_.t_ + h_/2.0;

    k3q = h_ * qdotfunc(intercoords);
    k3i = h_ * idotfunc(intercoords);
    intercoords.q_ = coords1_.q_ + k3q/2.0;
    intercoords.i_ = coords1_.i_ + k3i/2.0;
    intercoords.t_ = coords1_.t_ + h_;

    k4q = h_ * qdotfunc(intercoords);
    k4i = h_ * idotfunc(intercoords);

    coords1_.q_ = coords1_.q_ + k1q/6.0 + k2q/3.0 + k3q/3.0 + k4q/6.0;
    coords1_.i_ = coords1_.i_ + k1i/6.0 + k2i/3.0 + k3i/3.0 + k4i/6.0;
    coords1_.t_ = coords1_.t_ + h_;
}// Closes step function

// qdotfunc definition (qdot = i)
double diffeq::qdotfunc(coords localcoords) {
    return localcoords.i_;
}

// idotfunc definition (comes from our differential equation)
double diffeq::idotfunc(coords localcoords) {
    return ((V0 * sin(w * localcoords.t_) / L) - (R * localcoords.i_ / L) - (localcoords.q_ / L / C));
}