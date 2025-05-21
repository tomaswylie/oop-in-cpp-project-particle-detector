// Photon.h

// Interface of the Photon object

// Student ID: 10831050, last updated: 21/05/25

#ifndef PHOTON_H
#define PHOTON_H

#include "Particle.h"

class Photon: public Particle
{
protected:


public:

  // Default constuctor
  Photon(int ID_in);

  // Parameterised constructor
  Photon(int ID_in, const std::vector<double> momentum_in);

  // Destructor
  ~Photon();

  // Overrided print_particle function
  void print_particle() const;

};

#endif