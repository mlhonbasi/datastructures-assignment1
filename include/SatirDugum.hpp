//12.11.2022
#ifndef SatirDugum_hpp
#define SatirDugum_hpp
#include <iostream>
using namespace std;

class SatirDugum
{
    public:
        SatirDugum(int veri);
        ~SatirDugum();
        int veri;
        SatirDugum* sonraki;
        SatirDugum* onceki;
};

#endif
