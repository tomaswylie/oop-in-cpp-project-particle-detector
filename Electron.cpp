// Electron.cpp

// Implementation of the Electron object

// Student ID: 10831050, last updated: 18/05/25

#include "Electron.h"

// Default constructor
Electron::Electron(bool is_antiparticle = false) :
  Particle(is_antiparticle ? "positron":"electron",is_antiparticle ? 1:-1,0.511,{0,0,0,0})
{};

// Paramterised constructor
Electron::Electron(std::vector<double> momentum_in, bool is_antiparticle = false) :
  Particle(is_antiparticle ? "positron":"electron",is_antiparticle ? 1:-1,0.511,momentum_in)
{};

// Destructor 
Electron::~Electron(){};