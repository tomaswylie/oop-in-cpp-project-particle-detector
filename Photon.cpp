// Photon.cpp

// Implementation of the Photon object

// Student ID: 10831050, last updated: 21/05/25

#include "Photon.h"

// Default constructor
Photon::Photon(int ID_in) :
  Particle(ID_in,"photon",0,0,std::vector<double>{0,0,0,0})
{};

// Paramterised constructor
Photon::Photon(int ID_in, const std::vector<double> momentum_in) :
  Particle(ID_in,"photon",0,0,momentum_in)
{};

// Destructor 
Photon::~Photon(){};

// Function to print the information of the photon
void Photon::print_particle() const
{
  std::cout<<"Photon: "<<"ID: "<<ID<<", Charge: "<<charge<<", Actual total energy: "
           <<(*momentum)[0] * 1e-3<<" GeV"<<std::endl;
}