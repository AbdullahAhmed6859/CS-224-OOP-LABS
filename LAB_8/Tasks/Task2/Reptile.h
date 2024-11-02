#include <iostream>
#include "Animal.h"

#ifndef REPTILE_H
#define REPTILE_H
class Reptile:public Animal{
public:
   Reptile();
   ~Reptile();
   void crawl();
};
#endif