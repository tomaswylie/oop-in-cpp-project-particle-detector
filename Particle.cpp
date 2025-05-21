// Particle.cpp

// Implementation of the Particle abstract base class

// Student ID: 10831050, last updated: 21/05/25

#include "Particle.h"

Particle::Particle(int ID_in, std::string particle_type_in, double charge_in, double rest_mass_in, std::vector<double> mom_in) :
  ID{ID_in}, particle_type{particle_type_in}, charge{charge_in}, rest_mass{rest_mass_in},
  momentum{std::make_unique<FourMomentum>(mom_in[0],mom_in[1],mom_in[2],mom_in[3])}
{
  if(mom_in.size() != 4) {throw std::invalid_argument("Inputted particle momentum is not a 4-vector.");}
};

void Particle::set_particle_type(std::string particle_type_in) {particle_type=particle_type_in;}
void Particle::set_charge(double charge_in) {charge=charge_in;}
void Particle::set_rest_mass(double rest_mass_in) {rest_mass=rest_mass_in;}
void Particle::set_momentum(std::unique_ptr<FourMomentum> momentum_in) {*momentum=*momentum_in;}

// Getter functions
std::string Particle::get_particle_type() const {return particle_type;}
double Particle::get_charge() const {return charge;}
double Particle::get_rest_mass() const {return rest_mass;}
FourMomentum Particle::get_momentum() const {return *momentum;}