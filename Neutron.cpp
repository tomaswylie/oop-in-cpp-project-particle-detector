// Neutron.cpp

// Implementation of the Neutron object

// Student ID: 10831050, last updated: 21/05/25

#include "Neutron.h"

// Default constructor
Neutron::Neutron(int ID_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antineutron":"neutron",0,940,std::vector<double>{0,0,0,0})
{};

// Paramterised constructor
Neutron::Neutron(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antineutron":"neutron",0,940,momentum_in)
{};

// Destructor 
Neutron::~Neutron(){};

// Function to print the information of the neutron
void Neutron::print_particle() const
{
  std::cout<<((particle_type=="antineutron") ? "Anti-neutron: ":"Neutron: ")<<"ID: "<<ID<<", Charge: "<<charge<<", Actual total energy: "
           <<(*momentum)[0] * 1e-3<<" GeV"<<std::endl;
}