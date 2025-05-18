// MuonChamber.cpp

// Implementation file of the MuonChamber detector

// Student ID: 10831050, last updated: 30/04/25

#include "MuonChamber.h"

// Default constructor
MuonChamber::MuonChamber() :
  SubDetector("MuonChamber",""), number_of_drift_tubes{0}
{};

// Parameterised constructor
MuonChamber::MuonChamber(std::string material_in, int number_of_drift_tubes_in) :
  SubDetector("MuonChamber", material_in), number_of_drift_tubes{number_of_drift_tubes_in} 
{
  if(!(number_of_drift_tubes_in >= 0)) {throw std::invalid_argument("Number of layers must be a positive integer.");}
};

// Destructor
MuonChamber::~MuonChamber(){};

// Overrided print_detector function to print MuonChamber data
void MuonChamber::print_detector() const
{
  std::cout<<"\033[1;37mMuon chamber:\033[0m "<<"Material: "<<material<<", Number of layers: "<<number_of_drift_tubes<<std::endl;
}

// Getter for detector type
std::string MuonChamber::get_detector_type() const {return detector_type;}

// Getter for material type
std::string MuonChamber::get_material() const {return material;}

// Overrided detected function for muon chamber
double MuonChamber::detected(Particle& p)
{
  if(p.get_particle_type() == "muon" || p.get_particle_type() == "antimuon")
  {
    return p.get_momentum()[0];
  }
  else
  {
    return 0;
  }
}