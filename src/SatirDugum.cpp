/*
* @file SatirDugum.cpp
* @description SatirListesi için düğüm oluşturulması.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 12 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/

#include "SatirDugum.hpp"
#include <iostream>

//SatirDugum sınıfının kurucu fonksiyonu.
SatirDugum::SatirDugum(int veri)
{
    this->veri = veri;
    onceki = 0;
    sonraki = 0;
}

//SatirDugum sınıfının yok edici fonksiyonu.
SatirDugum::~SatirDugum()
{

}