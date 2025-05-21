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

// Passes a particle through each detector component and determines what particle it is based on what each detector type detects
void Detector::pass_through(Particle& p) const
{
  double energy_detected;
  bool tracker_detected{false};
  bool calorimeter_detected{false};
  bool muonchamber_detected{false};
  int n{0};

  std::cout<<"\t";
  p.print_particle();
    
  for(const auto& i : trackers)
  {
    n+=1;
    energy_detected = i->detected(p);
    std::cout<<"\t\tDetected energy in Tracker "<<n<<": "<<std::setprecision(3)<<energy_detected * 1e-3<<" GeV"<<std::endl;
    if(energy_detected != 0) {tracker_detected = true;}
  }

  n, energy_detected = 0;

  for(const auto& i : calorimeters)
  {
    n+=1;
    energy_detected = i->detected(p);
    std::cout<<"\t\tDetected energy in Calorimeter "<<n<<": "<<std::setprecision(3)<<energy_detected * 1e-3<<" GeV"<<std::endl;
    if(energy_detected != 0) {calorimeter_detected = true;}
  }

  n, energy_detected = 0;

  for(const auto& i : muonchambers)
  {
    n+=1;
    energy_detected = i->detected(p);
    std::cout<<"\t\tDetected energy in Muon Chamber "<<n<<": "<<std::setprecision(3)<<energy_detected * 1e-3<<" GeV"<<std::endl;
    if(energy_detected != 0) {muonchamber_detected = true;}
  }

  if(tracker_detected == true && calorimeter_detected == true && muonchamber_detected == false)
  {
    if(p.get_rest_mass() == 0.511)
    {
      std::cout<<((p.get_charge() < 0) ? "\t\tParticle detected as an electron.":"\t\tParticle detected as a positron.")<<std::endl;
    }
    else
    {
      std::cout<<((p.get_charge()>0) ? "\t\tParticle detected as a proton.":"\t\tParticle detected as an anti-proton.")<<std::endl;
    }
  }
  else if(tracker_detected == true && calorimeter_detected == false && muonchamber_detected == true)
  {
    std::cout<<((p.get_charge() < 0) ? "\t\tParticle detected as a muon.":"\t\tParticle detected as an anti-muon.")<<std::endl;
  }
  else if(tracker_detected == false && calorimeter_detected == true && muonchamber_detected == false)
  {
    if(p.get_rest_mass() == 0)
    {
      std::cout<<"\t\tParticle detected as a photon."<<std::endl;
    }
    else
    {
      std::cout<<((p.get_particle_type()=="neutron") ? "\t\tParticle detected as a neutron.":
                  "\t\tParticle detected as an anti-neutron.")<<std::endl;
    }  
  }
  else
  {
    std::cout<<"\t\tNo particle detected."<<std::endl;
  }
}

