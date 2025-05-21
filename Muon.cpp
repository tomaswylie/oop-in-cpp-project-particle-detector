// Muon.cpp

// Implementation of the Muon object

// Student ID: 10831050, last updated: 21/05/25

#include "Muon.h"

// Default constructor
Muon::Muon(int ID_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antimuon":"muon",is_antiparticle ? 1:-1,106,std::vector<double>{0,0,0,0})
{};

// Paramterised constructor
Muon::Muon(int ID_in, const std::vector<double> momentum_in, bool is_antiparticle) :
  Particle(ID_in,is_antiparticle ? "antimuon":"muon",is_antiparticle ? 1:-1,106,momentum_in)
{};

// Destructor 
Muon::~Muon(){};

// Function to print the information of the electron
void Muon::print_particle() const
{
  std::cout<<((charge<0) ? "Muon: ":"Anti-muon: ")<<"ID: "<<ID<<", Charge: "<<charge<<", Actual total energy: "
           <<(*momentum)[0] * 1e-3<<" GeV"<<std::endl;
}