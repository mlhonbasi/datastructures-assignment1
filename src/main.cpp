/*
* @file main.cpp
* @description Programın başlatılması.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 12 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/
#include "OkuEkle.hpp"
#include "SatirListesi.hpp"
#include "SatirDugum.hpp"
#include "Konsol.hpp"
#include "YoneticiListesi.hpp"
#include <iostream>
#include <iomanip>
#include <time.h>

int main()
{
  srand(time(NULL));
  YoneticiListesi* yoneticiListe = new YoneticiListesi();
  OkuEkle::okuEkle(yoneticiListe);
  Konsol::anaMenu(yoneticiListe, yoneticiListe->ilkY->satir);
  return 0;
}