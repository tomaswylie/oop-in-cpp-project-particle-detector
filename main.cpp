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

int main()
{
  try
  {
    std::unique_ptr<Detector> detector{std::make_unique<Detector>("CMS")};
    detector->add(std::make_unique<Tracker>("silicon", 5));
    detector->add(std::make_unique<Calorimeter>("lead tungstate crystals", 75000));
    detector->add(std::make_unique<MuonChamber>("drift tubes", 250));

    detector->display();

    auto electron1 = std::make_unique<Electron>(1,std::vector<double>{0.511,0,0,0});

    std::cout<<"\033[1;37mParticle information and interaction with detectors:\033[0m"<<std::endl;
    detector->pass_through(*electron1);


  }
  catch(const std::invalid_argument& error)
  {
    std::cerr<<"Error: "<<error.what()<<std::endl;
  }
  

  return 0;
}
