//12.11.2022

#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "SatirDugum.hpp"
#include "SatirListesi.hpp"
#include "YoneticiDugum.hpp"
#include <ostream>
#include <iomanip>
using namespace std;
class YoneticiListesi
{
    public:
        YoneticiListesi();
        ~YoneticiListesi();
        void SatirEkle(SatirListesi* sl, YoneticiDugum* ylist);
        static void araCizgiYonetici(int n);
        static void yoneticiYazdir(YoneticiDugum* yDugum, int sayac);
        static void satirYazdir(YoneticiDugum* yDugum, int sayac, int sayfa,bool k);
        static void kLiSatirYazdir(YoneticiDugum* yDugum, int sayac, int sayfa,bool k, int sira);
        static int yoneticiListeSayisi(YoneticiDugum* yDugum);
        void satirDugumSil(int sira, int sil);
        void yoneticiSil(int sira);
        void yoneticiSirala(YoneticiDugum* ilk);
        int rastgeleDugum(int sira);
        YoneticiDugum* yDugumGetir(int sira);
        YoneticiDugum* ilkY;
};

#endif