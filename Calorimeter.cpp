// Calorimeter.cpp

// Implementation file of the Calorimeter detector

// Student ID: 10831050, last updated: 30/04/25

#include "Calorimeter.h"

// Default constructor
Calorimeter::Calorimeter() :
  SubDetector("",""), number_of_crystals{0}
{};

// Parameterised constructor
Calorimeter::Calorimeter(std::string material_in, int number_of_crystals_in) :
  SubDetector("Calorimeter", material_in), number_of_crystals{number_of_crystals_in}
{
  if(!(number_of_crystals_in >= 0)) {throw std::invalid_argument("Number of crystals must be a positive integer.");}
};

// Destructor
Calorimeter::~Calorimeter(){};

// Overrides the print_detector function for calorimeter
void Calorimeter::print_detector() const
{
  std::cout<<"\033[1;37mCalorimeter:\033[0m "<<"Material: "<<material<<", Number of crystals: "<<number_of_crystals<<std::endl;
}

// Getter for detector type
std::string Calorimeter::get_detector_type() const {return detector_type;}

// Getter for material type
std::string Calorimeter::get_material() const {return material;}

// Overrided detected function for calorimeter
double Calorimeter::detected(Particle& p)
{
  if(p.get_particle_type() != "muon" && p.get_particle_type() != "antimuon")
  {
    return p.get_momentum()[0];
  }
  else
  {
    return 0;
  }
}