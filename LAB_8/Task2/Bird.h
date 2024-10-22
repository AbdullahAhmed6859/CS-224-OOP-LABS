#include "Animal.h"

#ifndef BIRD_H
#define BIRD_H
class Bird:public Animal{
public:
   Bird();
   ~Bird();
   void fly();
};
#endif