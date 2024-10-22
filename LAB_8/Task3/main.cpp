#include <iostream>
#include "Bird.h"
#include "Reptile.h"
#include "Fish.h"
using namespace std;



int main(){
   Bird bird;
   Reptile reptile;
   Fish fish;
   cout << "Bird:" << endl;
   bird.eat();
   bird.sleep();
   bird.fly();
   cout << endl;
   cout << "Reptile:" << endl;
   reptile.eat();
   reptile.sleep();
   reptile.crawl();
   fish.eat();
   fish.sleep();
   fish.swim();
   cout << endl;
   return 0;
}