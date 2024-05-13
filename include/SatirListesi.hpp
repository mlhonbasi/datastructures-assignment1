// 12.11.2022

#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "SatirDugum.hpp"


class SatirListesi
{
    public:
        SatirListesi();
        ~SatirListesi();
        void dugumEkle(int veri);
        static float ortalamaHesapla(SatirListesi* satirliste);
        static void araCizgiYazdir(int s);
        static int dugumSayisi(SatirListesi* sListe);
        float ortalama;
        SatirDugum* ilk;    
};

#endif