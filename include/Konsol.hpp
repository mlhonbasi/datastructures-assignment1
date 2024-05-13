#ifndef Konsol_hpp
#define Konsol_hpp
#include <iostream>
#include <iomanip>
#include <ostream>
#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"
using namespace std;

class Konsol
{
    public:
        static void anaMenu(YoneticiListesi* yList, SatirListesi* satirList);
};

#endif