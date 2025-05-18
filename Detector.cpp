// Detector.cpp

// Implementation of the Detector object

// Student ID: 10831050, last updated: 18/05/25

#include "Detector.h"

// Constructor
Detector::Detector(std::string detector_name_in) :
  detector_name{detector_name_in}
{};

// Destructor
Detector::~Detector(){};

// Function to add a subdetector to the detector object and store in lists dependent on detector type
void Detector::add(std::unique_ptr<SubDetector> component)
{
  if(component->get_detector_type() == "Tracker")
  {
    trackers.push_back(std::move(component));
  }
  else if(component->get_detector_type() == "Calorimeter")
  {
    calorimeters.push_back(std::move(component));
  }
  else if(component->get_detector_type() == "MuonChamber")
  {
    muonchambers.push_back(std::move(component));
  }
}

void Detector::display() const
{
  std::cout<<"Detector name: "<<detector_name<<std::endl;

  if(!trackers.empty())
  {
    std::cout<<"\tTrackers:"<<std::endl;

    for(const std::unique_ptr<SubDetector>& i : trackers)
    {
      std::cout<<"\t\t";
      i->print_detector();
    }
  }

  if(!calorimeters.empty())
  {
    std::cout<<"\tCalorimeters:"<<std::endl;

    for(const std::unique_ptr<SubDetector>& i : calorimeters)
    {
      std::cout<<"\t\t";
      i->print_detector();
    }
  }

  if(!muonchambers.empty())
  {
    std::cout<<"\tMuon chambers:"<<std::endl;

    for(const std::unique_ptr<SubDetector>& i : muonchambers)
    {
      std::cout<<"\t\t";
      i->print_detector();
    }
  }
}

