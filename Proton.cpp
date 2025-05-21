// Proton.cpp

// Implementation of the Proton object

// Student ID: 10831050, last updated: 18/05/25

#include "Proton.h"

// Default constructor
Proton::Proton(int ID_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antiproton":"proton",is_antiparticle ? -1:1,938,std::vector<double>{0,0,0,0})
{};

// Paramterised constructor
Proton::Proton(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antiproton":"proton",is_antiparticle ? -1:1,938,momentum_in)
{};

// Destructor 
Proton::~Proton(){};

// Function to print the information of the electron
void Proton::print_particle() const
{
  std::cout<<((charge<0) ? "Anti-proton: ":"Proton: ")<<"ID: "<<ID<<", Charge: "<<charge<<", Actual total energy: "
           <<(*momentum)[0] * 1e-3<<" GeV"<<std::endl;
}