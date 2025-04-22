// Particle.h

//

// Student ID: 10831050, last updated: 21/04/25

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<stdexcept>
#include<cmath>

#include "FourMomentum.h"

class Particle
{
protected:
std::string particle_type;
double charge; // Double as to support fractional charges for quarks
double rest_mass; // In MeV
std::unique_ptr<FourMomentum> momentum;

public:

};


#endif