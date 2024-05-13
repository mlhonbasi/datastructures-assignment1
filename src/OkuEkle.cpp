/*
* @file OkuEkle.cpp
* @description Dosya okuma ve okunan verilerin ilgili listeye eklenmesi.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 12 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/
#include "OkuEkle.hpp"
#include "SatirListesi.hpp"
#include "YoneticiDugum.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

//Dosyadan verilerin okunması ve okunan verilerin satır listesine eklenip satır listesini de yönetici düğüme ekleme.
void OkuEkle::okuEkle(YoneticiListesi* yliste)
{
    string satir;
    int sayi;
    ifstream dosya("veriler.txt");
    while(getline(dosya,satir))
    {
        SatirListesi* sliste = new SatirListesi();
        YoneticiDugum* yeniYliste = new YoneticiDugum();
        stringstream ss(satir);
        while(ss>>sayi)
        {
            sliste->dugumEkle(sayi); //Satırdaki sayıların satır listesine eklenmesi.
        }
        sliste->ortalama = SatirListesi::ortalamaHesapla(sliste); //Satır listesinin ortalamasını hesaplama.
        yliste->SatirEkle(sliste,yeniYliste);//Satır okuma bittikten sonra satır listesini yönetici düğüme ekleme.
    }
}