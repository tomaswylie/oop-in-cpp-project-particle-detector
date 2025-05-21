// Muon.h

// Interface of the Muon object

// Student ID: 10831050, last updated: 21/05/25

#ifndef MUON_H
#define MUON_H

#include "Particle.h"

class Muon: public Particle
{
protected:


public:

  // Default constuctor
  Muon(int ID_in, bool is_antiparticle = false);

  // Parameterised constructor
  Muon(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle = false);

  // Destructor
  ~Muon();

  // Overrided print_particle function
  void print_particle() const;

};

#endif