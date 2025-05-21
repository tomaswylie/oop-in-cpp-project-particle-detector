// Electron.cpp

// Implementation of the Electron object

// Student ID: 10831050, last updated: 18/05/25

#include "Electron.h"

// Default constructor
Electron::Electron(int ID_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "positron":"electron",is_antiparticle ? 1:-1,0.511,std::vector<double>{0,0,0,0})
{};

// Paramterised constructor
Electron::Electron(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "positron":"electron",is_antiparticle ? 1:-1,0.511,momentum_in)
{};

// Destructor 
Electron::~Electron(){};

// Function to print the information of the electron
void Electron::print_particle() const
{
  std::cout<<((charge<0) ? "Electron: ":"Positron: ")<<"ID: "<<ID<<", Charge: "<<charge<<", Actual total energy: "
           <<(*momentum)[0] * 1e-3<<" GeV"<<std::endl;
}