/*
* @file SatirListesi.cpp
* @description Satır listelerini oluşturan sınıf ve içerdiği fonksiyonlar.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 12 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include "Konsol.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//SatirListesi sınıfının kurucu fonksiyonu.
SatirListesi::SatirListesi()
{
    ilk = 0;
    ortalama = 0;
}

//SatirListesi sınıfının yok edici fonksiyonu. Satır listesi silinirken içerdeki düğümleri de siler.
SatirListesi::~SatirListesi()
{
    SatirDugum* temp = ilk;
    while(temp != 0)
    {
        SatirDugum* silinecek = temp;
        temp= temp->sonraki;
        delete silinecek;
    } 
}
void SatirListesi::dugumEkle(int veri) //Satır listesine düğümlerin eklenmesi(OkuEkle de çağırılıyor).
{
    SatirDugum* yeniDugum = new SatirDugum(veri);

    if(ilk==0)
    {
        ilk = yeniDugum;
    }
    else
    {
        SatirDugum* gec = ilk;
        while(gec->sonraki != 0)
        {
            gec = gec->sonraki;
        }
        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
        yeniDugum->sonraki = 0;
    }
}

float SatirListesi::ortalamaHesapla(SatirListesi* satirliste) //Satır listesinin ortalamasının hesaplanması.
{
    float toplam = 0;
    float ortalama;
    int adet = 0;
    if(satirliste->ilk == 0)
    {
        return 0;
    }
    if(satirliste->ilk->sonraki == 0)
    {
        return satirliste->ilk->veri;
    }
    else
    {
        SatirDugum* gec = satirliste->ilk;
        while(gec != 0)
        {
            toplam += gec->veri;
            gec = gec->sonraki;
            adet++;
        }
        ortalama = toplam/adet;

        return ortalama;
    }   
}
int SatirListesi::dugumSayisi(SatirListesi* strList) //İlgili satır listesinin düğüm sayısının hesaplanması.
{
    SatirDugum* temp = strList->ilk;
    int sayac = 0;
    if(strList->ilk == 0)
    {
        return 0;
    }
    else if (strList->ilk->sonraki == 0)
    {
        return 1;
    }
    else
    {
        while(temp != 0)
        {
            sayac++;
            temp=temp->sonraki;
        }
        return sayac;
    }
}

void SatirListesi::araCizgiYazdir(int s)
{
    cout <<setw(s*16)<<""<<"------------" <<setw(5)<<""<< endl; 
}



