// main.cpp

// Program to simulate a particle detector made up of tracker, calorimeter,
// and muon chamber.

// Student ID: 10831050, last updated: 18/04/25

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdexcept>

#include "Particle.h"
#include "SubDetector.h"

int main()
{
  try
  {
    std::unique_ptr<FourMomentum> vector;
    vector = std::make_unique<FourMomentum>(20,3,4,5);

    std::cout<<*vector<<std::endl;
    std::cout<<*vector+*vector<<std::endl;
    std::cout<<*vector-*vector<<std::endl;
    std::cout<<2 * *vector<<std::endl;
    std::cout<<*vector * 2<<std::endl;
    std::cout<<*vector/2<<std::endl;
    std::cout<<*vector * *vector<<std::endl;


  }
  catch(const std::invalid_argument& error)
  {
    std::cerr<<"Error: "<<error.what()<<std::endl;
  }
  

  return 0;
}
