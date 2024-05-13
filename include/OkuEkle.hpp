#ifndef OkuEkle_hpp
#define OkuEkle_hpp
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class OkuEkle
{
    public:
       static void okuEkle(YoneticiListesi* yListe);
};

#endif