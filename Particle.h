// Particle.h

// Interface of the abstract base class particle

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
  int ID;
  std::string particle_type;
  double charge; // Double as to support fractional charges for quarks
  double rest_mass; // In MeV
  std::unique_ptr<FourMomentum> momentum;

  // Protected parameterised constructor acessible only by derived classes
  Particle(int ID_in, std::string particle_type_in, double charge_in, double rest_mass_in, std::vector<double> mom_in);

public:

  // Virtual destructor
  virtual ~Particle() = default;

  // Pure virtual print particle function
  virtual void print_particle() const = 0;

  // Setter functions
  void set_particle_type(std::string particle_type_in);
  void set_charge(double charge_in);
  void set_rest_mass(double rest_mass_in);
  void set_momentum(std::unique_ptr<FourMomentum> momentum_in);

  // Getter functions
  std::string get_particle_type() const;
  double get_charge() const;
  double get_rest_mass() const;
  FourMomentum get_momentum() const;
};


#endif