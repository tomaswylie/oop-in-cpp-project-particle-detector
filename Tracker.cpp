// Tracker.cpp

// Implementation of the Tracker object

// Student ID: 10831050, last updated: 30/04/25

#include "Tracker.h"

// Default constructor - initialises all member properties as their default values
Tracker::Tracker() :
  SubDetector("Tracker",""), number_of_layers{0}
{};

// Parameterised constructor - throws error if the input for number_of_layers is anything other than a positive integer
Tracker::Tracker(std::string material_in, int number_of_layers_in) :
  SubDetector("Tracker", material_in), number_of_layers{number_of_layers_in} 
{
  if(!(number_of_layers_in >= 0)) {throw std::invalid_argument("Number of layers must be a positive integer.");}
};

// Destructor
Tracker::~Tracker(){};

void Tracker::print_detector() const
{
  std::cout<<"\033[1;37mTracker:\033[0m "<<"Material: "<<material<<", Number of layers: "<<number_of_layers<<std::endl;
}