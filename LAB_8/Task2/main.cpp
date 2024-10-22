#include <iostream>
#include "Bird.h"
#include "Reptile.h"
using namespace std;



int main(){
   Bird bird;
   Reptile reptile;
   cout << "Bird:" << endl;
   bird.eat();
   bird.sleep();
   bird.fly();
   cout << endl;
   cout << "Reptile:" << endl;
   reptile.eat();
   reptile.sleep();
   reptile.crawl();
   cout << endl;
   return 0;
}