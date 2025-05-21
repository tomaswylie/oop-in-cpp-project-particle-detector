// main.cpp

// Program to simulate a particle detector made up of tracker, calorimeter,
// and muon chamber.

// Student ID: 10831050, last updated: 20/05/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdexcept>

#include "Particle.h"
#include "SubDetector.h"
#include "Tracker.h"
#include "Calorimeter.h"
#include "MuonChamber.h"
#include "Detector.h"
#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Proton.h"
#include "Neutron.h"

int main()
{
  try
  {
    std::vector<std::unique_ptr<Particle>> particle_list;

    std::unique_ptr<Detector> detector{std::make_unique<Detector>("CMS")};
    detector->add(std::make_unique<Tracker>("silicon", 5));
    detector->add(std::make_unique<Calorimeter>("lead tungstate crystals", 75000));
    detector->add(std::make_unique<MuonChamber>("drift tubes", 250));

    detector->display();

    particle_list.push_back(std::make_unique<Electron>(1,std::vector<double>{0.8,0,0,0.2})); // Initialisation of electron
    particle_list.push_back(std::make_unique<Electron>(2,std::vector<double>{50,5,3,2},true)); // Initialisation of positron

    particle_list.push_back(std::make_unique<Muon>(3,std::vector<double>{200,8,3,7})); // Initialisation of muon
    particle_list.push_back(std::make_unique<Muon>(4,std::vector<double>{250,90,3,21},true)); // Initialisation of anti-muon
    
    particle_list.push_back(std::make_unique<Photon>(5,std::vector<double>{30,4,15,2})); // Initialisation of photon

    particle_list.push_back(std::make_unique<Proton>(6,std::vector<double>{1345,300,40,210})); // Initialisation of proton
    particle_list.push_back(std::make_unique<Proton>(7,std::vector<double>{1460,480,20,15},true)); // Initialisation of anti-proton

    particle_list.push_back(std::make_unique<Neutron>(8,std::vector<double>{1260,200,170,25})); // Initialisation of neutron
    particle_list.push_back(std::make_unique<Neutron>(9,std::vector<double>{1700,70,580,170},true)); // Initialisation of anti-neutron

    std::cout<<"\033[1;37mParticle information and interaction with detectors:\033[0m"<<std::endl;

    for(const auto& i : particle_list)
    {
      detector->pass_through(*i);
    }




  }
  catch(const std::invalid_argument& error)
  {
    std::cerr<<"Error: "<<error.what()<<std::endl;
  }
  

  return 0;
}
