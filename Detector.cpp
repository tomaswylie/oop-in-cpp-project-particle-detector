// Detector.cpp

// Implementation of the Detector object

// Student ID: 10831050, last updated: 28/04/25

#include "Detector.h"

Detector::Detector(std::string detector_name_in) :
  detector_name{detector_name_in}
{subdetectors = {};};

Detector::~Detector(){};

void Detector::add(SubDetector& component)
{
  subdetectors.push_back(std::make_unique<SubDetector>(component));
}

void Detector::display()
{
  std::vector<std::unique_ptr<SubDetector>> list{subdetectors};
  std::vector<std::unique_ptr<SubDetector>>::iterator it; // Iterator
  std::vector<std::unique_ptr<SubDetector>> ordered_list{{}}; // Might not need
  std::vector<std::unique_ptr<SubDetector>> tracker_list{{}};
  std::vector<std::unique_ptr<SubDetector>> calorimeter_list{{}};
  std::vector<std::unique_ptr<SubDetector>> muonchamber_list{{}};


  // Iterator to sort the list of detectors in order of type of detector
  for(it = (list).begin(); it != list.end(); ++it)
  {
    if((*it)->get_detector_type() == "Tracker")
    {
      tracker_list.push_back(*it);
      list.erase(it);
    }
    else if((*it)->get_detector_type() == "Calorimeter")
    {
      calorimeter_list.push_back(*it);
      list.erase(it);
    }
    else if((*it)->get_detector_type() == "MuonChamber")
    {
      muonchamber_list.push_back(*it);
      list.erase(it);
    }
  }

  if(tracker_list.size() != 0)
  {
    std::cout<<"Trackers:"<<std::endl;

    for(std::unique_ptr<SubDetector>& i : tracker_list)
    {
      std::cout<<"\t";
      i->print_detector();
    }
  }

  if(calorimeter_list.size() != 0)
  {
    std::cout<<"Calorimeters:"<<std::endl;

    for(std::unique_ptr<SubDetector>& i : calorimeter_list)
    {
      std::cout<<"\t";
      i->print_detector();
    }
  }

  if(muonchamber_list.size() != 0)
  {
    std::cout<<"Muon chambers:"<<std::endl;

    for(std::unique_ptr<SubDetector>& i : muonchamber_list)
    {
      std::cout<<"\t";
      i->print_detector();
    }
  }

  

}

