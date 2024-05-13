#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp
#include "SatirListesi.hpp"
class YoneticiDugum
{
    public:
        YoneticiDugum();
        ~YoneticiDugum();
        YoneticiDugum* sonrakiYlist;
        YoneticiDugum* oncekiYlist;
        SatirListesi* satir;
};

#endif