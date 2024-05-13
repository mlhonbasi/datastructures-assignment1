/*
* @file Konsol.cpp
* @description Kullanıcının girdiği tuşa göre istenilen işlevlerin gerçekleşmesi.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 16 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/
#include "Konsol.hpp"
#include "YoneticiListesi.hpp"
#include "SatirListesi.hpp"
#include "SatirDugum.hpp"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

//Menüyü yazdıran ve işlevlerini yerine getiren fonksiyon.
void Konsol::anaMenu(YoneticiListesi* yList, SatirListesi* satirList)
{
    int yoneticiDugumSayisi = YoneticiListesi::yoneticiListeSayisi(yList->ilkY);
    int ySira = 0;
    int sSira = 0;
    int silinecekSira;
    char tus;
    bool k = false;
    system("CLS");
    YoneticiListesi::yoneticiYazdir(yList->ilkY, ySira);
    YoneticiListesi::satirYazdir(yList->ilkY, sSira, (ySira*8),k);
    while(1)
    {
        if(YoneticiListesi::yoneticiListeSayisi(yList->ilkY)== 0)
            break;
        k=false;
        yoneticiDugumSayisi = YoneticiListesi::yoneticiListeSayisi(yList->ilkY);
        cin >>tus;
        system("CLS");
        switch (tus)
        {
        case 'a':
            if(ySira != 0)
                ySira--;
            sSira = ySira*8;
            break;
        case 'd':
            if(yoneticiDugumSayisi > 8 && (ySira+1)*8 < yoneticiDugumSayisi)
            {
                ySira++;
                sSira = ySira*8;
            }
            break;
        case 'z':
            if(sSira % 8 == 0 && ySira >0)
            {
                ySira--;
                sSira--;
            }
            else if(sSira > 0)
            {
                sSira--;
            }
            break;
        case 'c':
            if(sSira == 7 && sSira <yoneticiDugumSayisi-1)
            {
                ySira++;
                sSira = ySira*8;
            }   
            else if(sSira > 8 && sSira == ((ySira+1)*8)-1 && sSira < yoneticiDugumSayisi - 1)
            {
                ySira++;
                sSira = ySira*8;
            }     
            else
            {
                if(sSira < yoneticiDugumSayisi-1)
                    sSira++;
            }
            break;
        case 'p':
            yList->yoneticiSil(sSira);
            if(sSira % 8 == 0 && ySira >0)
            {
                ySira--;
                sSira--;
            }
            if(sSira == yoneticiDugumSayisi-1)
                sSira--;
            break;
        case 'k':
            k = true;
            silinecekSira = yList->rastgeleDugum(sSira);
            system("CLS");
            YoneticiListesi::yoneticiYazdir(yList->ilkY, ySira);
            YoneticiListesi::kLiSatirYazdir(yList->ilkY, sSira ,ySira, k,silinecekSira);
            char silme;
                cin>>silme;
                if(silme == 'k')
                yList->satirDugumSil(sSira, silinecekSira);
                yoneticiDugumSayisi = YoneticiListesi::yoneticiListeSayisi(yList->ilkY);
                while(sSira > yoneticiDugumSayisi - 1)
                    sSira--;
                    
                if(sSira % 8 == 7 && ySira > 0)
                    if(sSira != (ySira)*8 + 7)
                        ySira--;
                system("CLS");
            break;
        case 'q':
            exit(0);
            break;
        default:
            break;
        }
        yoneticiDugumSayisi =  YoneticiListesi::yoneticiListeSayisi(yList->ilkY);
        yList->yoneticiSirala(yList->ilkY);
        YoneticiListesi::yoneticiYazdir(yList->ilkY, ySira);
        YoneticiListesi::satirYazdir(yList->ilkY, sSira ,ySira, k);
    }
}