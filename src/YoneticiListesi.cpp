/*
* @file YoneticiListesi.cpp
* @description Yönetici listesini oluşturan sınıf ve içerdiği fonksiyonlar.
* @course 1.Öğretim 1-C
* @assignment 1.Ödev
* @date 12 Kasım 2022
* @author Melih Onbaşı - melih.onbasi@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"
#include "SatirDugum.hpp"
#include "OkuEkle.hpp"
#include "Konsol.hpp"
#include <iostream>
using namespace std;

YoneticiListesi::YoneticiListesi() //YoneticiListesi sınıfının kurucu fonksiyonu.
{
    ilkY = 0;
}
YoneticiListesi::~YoneticiListesi() //YoneticiListesi sınıfının yok edici fonksiyonu.
{

}

void YoneticiListesi::SatirEkle(SatirListesi* ySatir,YoneticiDugum* yeniListe ) // Yonetici listesine veri olarak SatırListesi ekleme.
{
    yeniListe->satir = ySatir;
    if(ilkY == 0) //İlk düğümün kontrol edilmesi ve düğüm yoksa yeni geleni ilk düğüme atama.
    {
        ilkY = yeniListe;
        ilkY->satir = ySatir;
    }
    else //İlk düğüm varsa başa, araya ve sona ekleme yapar, eklerken sıralı biçimde eklenir.
    {
        YoneticiDugum* ylgec = ilkY;
        if(yeniListe->satir->ortalama <= ylgec->satir->ortalama)
        {
            ylgec->oncekiYlist = yeniListe;
            yeniListe->sonrakiYlist = ylgec;
            yeniListe->oncekiYlist = 0;
            ilkY = yeniListe;
        }
        else
        {
            bool sonaEklendiMi = false;
            while(yeniListe->satir->ortalama > ylgec->satir->ortalama)
            {

                if(ylgec->sonrakiYlist == 0 && ylgec->satir->ortalama < yeniListe->satir->ortalama)
                {
                    ylgec->sonrakiYlist = yeniListe;
                    yeniListe->oncekiYlist = ylgec;
                    yeniListe->sonrakiYlist = 0;
                    sonaEklendiMi = true;
                }
                ylgec = ylgec->sonrakiYlist;
            }
            if(ylgec->sonrakiYlist == 0 && YoneticiListesi::yoneticiListeSayisi(ilkY)==2 && !sonaEklendiMi)
            {
                    ylgec->oncekiYlist->sonrakiYlist = yeniListe;
                    yeniListe->sonrakiYlist = ylgec;
                    yeniListe->oncekiYlist = ylgec->oncekiYlist;
                    ylgec->oncekiYlist = yeniListe;
            }
            else if(ylgec->sonrakiYlist != 0)
            {
                ylgec->oncekiYlist->sonrakiYlist = yeniListe;
                yeniListe->sonrakiYlist = ylgec;
                yeniListe->oncekiYlist = ylgec->oncekiYlist;
                ylgec->oncekiYlist = yeniListe;
            }
        }
    }
}

void YoneticiListesi::yoneticiYazdir(YoneticiDugum* yDugum, int sayac) //Yonetici düğümlerini ekranda yazdıran fonksiyon.
{   

    cout<<endl<<endl;
    YoneticiDugum* temp = yDugum;
    int yoneticiAdet = YoneticiListesi::yoneticiListeSayisi(yDugum);
    bool azSayidaYonetici = false;
    bool tamSekizxOlmayanYonetici = false;
    int n = 8;
    int azSayi = 0;
    int cokSayi = 0;

    if(temp == 0)
    {
        cout<<"Butun dugumler silindi"<<endl;
        return;
    }
    if(sayac == 0 && yoneticiAdet < 8)
    {
        azSayidaYonetici = true;
        azSayi = yoneticiAdet;
    }
    else if(sayac == 1 && (sayac+1)*8 > yoneticiAdet)
    {
        for(int i = 0; i < (sayac*8); i++)
        {
            temp = temp->sonrakiYlist;
        }
        tamSekizxOlmayanYonetici = true;
        cokSayi = (yoneticiAdet - ((sayac)*8));
    }
    else if((sayac+1)*8 > yoneticiAdet)
    {
        for(int i = 0; i < sayac*8; i++)
        {
            temp = temp->sonrakiYlist;
        }
        tamSekizxOlmayanYonetici = true;
        cokSayi = (yoneticiAdet - ((sayac)*8));
    }
    else
    {
        for(int i = 0; i < sayac*8 ; i++)
        {
            temp = temp->sonrakiYlist;
        }
    }
    YoneticiDugum* tempTutucu = temp;
    if(azSayidaYonetici)
    {
        n = azSayi;
    }
    if(tamSekizxOlmayanYonetici)
    {
        n = cokSayi;
    }
    
    if(azSayidaYonetici)
    {
        cout<<"Ilk"<<setw(116)<<""<<"Son"<<endl<<endl;
    }
    else if(sayac == 0)
    {
        cout<<"Ilk"<<setw(116)<<""<<"--->"<<endl<<endl;
    }
    else if(tamSekizxOlmayanYonetici)
    {
         cout<<"<---"<<setw(116)<<""<<"Son"<<endl<<endl;
    }
    else
    {
         cout<<"<---"<<setw(116)<<""<<"--->"<<endl<<endl;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<setw(12)<< temp << setw(4) << "";
        temp = temp->sonrakiYlist;
    }
    cout<<endl;

    YoneticiListesi::araCizgiYonetici(n);

    temp = tempTutucu;

    for(int i = 0 ; i < n; i++)
    {
        if(temp->oncekiYlist == 0)
        {
            cout<<"|"<<setw(10)<<"000000000"<<"|"<<setw(4)<<"";
        }
        else
        cout<<"|"<<setw(10)<< temp->oncekiYlist <<"|"<< setw(4) <<"";
        temp = temp->sonrakiYlist;
    }
    cout<< endl;

    YoneticiListesi::araCizgiYonetici(n);

    temp = tempTutucu;

    for(int i = 0; i < n; i++)
    {
        cout << fixed;
        cout.precision(1);
        cout<<"|"<<setw(10)<<temp->satir->ortalama<<"|"<<setw(4)<<"";
        temp = temp->sonrakiYlist;
    }
    cout<<endl;

    YoneticiListesi::araCizgiYonetici(n);

    temp = tempTutucu;

    for(int i = 0 ; i < n; i++)
    {
        if(temp->sonrakiYlist == 0)
        {
            cout<<"|"<<setw(10)<<"000000000"<<"|"<<setw(4)<<"";
        }
        else
        cout<<"|"<<setw(10)<<temp->sonrakiYlist <<"|"<< setw(4) <<"";
        temp = temp->sonrakiYlist;
    }
    cout << endl;

    YoneticiListesi::araCizgiYonetici(n);
}

void YoneticiListesi::araCizgiYonetici(int n)
{
    for(int i = 0; i < n; i++)
        cout << "------------" << setw(4) << "";
    cout << endl;
}

//Satır listesinin düğümlerini ekrana yazdıran fonksiyon.
void YoneticiListesi::satirYazdir(YoneticiDugum* yDugum, int sayac, int sayfa, bool k) 
{
    YoneticiDugum* yTemp = yDugum;
    int yListAdet = YoneticiListesi::yoneticiListeSayisi(yDugum);
    

    if(yTemp->sonrakiYlist != 0)
    {
        for(int i = 0; i < sayac; i++)
        {
            yTemp = yTemp->sonrakiYlist;
        }
    }

    int silmesirasi = 0;
    SatirDugum* dTemp = yTemp->satir->ilk;
    if(yTemp != 0)
    {
        cout<<endl<<endl<<setw(((sayac%8)*16))<<""<<"^^^^^^^^^^^^" << endl;
        for(int i = 0; i < SatirListesi::dugumSayisi(yTemp->satir) ; i++)
        {
            SatirListesi::araCizgiYazdir(sayac%8);
            cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp<<"|"<<setw(3)<<""<< endl;
            SatirListesi::araCizgiYazdir(sayac%8);
            cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp->veri<<"|"<<setw(3)<<""<<endl;
            SatirListesi::araCizgiYazdir(sayac%8);
            if(dTemp->sonraki == 0)
                cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<"000000000"<<"|"<<setw(3)<<""<<endl;
            else
                cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp->sonraki<<"|"<<setw(3)<<""<<endl;
            SatirListesi::araCizgiYazdir(sayac%8);
            dTemp = dTemp->sonraki;
            silmesirasi++;
        }
    }
}
//Tek düğüm silmesi için seçilen düğümü ve aynı zamanda listesini ekrana yazdıran fonksiyon.
void YoneticiListesi::kLiSatirYazdir(YoneticiDugum* yDugum, int sayac, int sayfa, bool k, int sira) 
{
    YoneticiDugum* yTemp = yDugum;
    if(yTemp == 0)
    {
        return;
    }
    int yListAdet = YoneticiListesi::yoneticiListeSayisi(yDugum);

    if(yTemp->sonrakiYlist != 0)
    {
        for(int i = 0; i < sayac; i++)
        {
            yTemp = yTemp->sonrakiYlist;
        }
    }

    int silmesirasi = 0;
    SatirDugum* dTemp = yTemp->satir->ilk;
    if(yTemp != 0)
    {
        cout<<endl<<endl<<setw(((sayac%8)*16))<<""<<"^^^^^^^^^^^^" << endl;
        for(int i = 0; i < SatirListesi::dugumSayisi(yTemp->satir) ; i++)
        {
            SatirListesi::araCizgiYazdir(sayac%8);
            cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp<<"|"<<setw(3)<<""<< endl;
            SatirListesi::araCizgiYazdir(sayac%8);
            cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp->veri<<"|";
            if(k && sira == silmesirasi)
            {
                cout<<" <--- Silinecek"<<endl;
            }
            else
            {
                cout<<endl;
            }
            SatirListesi::araCizgiYazdir(sayac%8);
            if(dTemp->sonraki == 0)
                cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<"000000000"<<"|"<<setw(3)<<""<<endl;
            else
                cout<<setw((sayac%8)*16)<<""<<"|"<<setw(10)<<dTemp->sonraki<<"|"<<setw(3)<<""<<endl;
            SatirListesi::araCizgiYazdir(sayac%8);
            dTemp = dTemp->sonraki;
            silmesirasi++;
        }
    }
}
int YoneticiListesi::yoneticiListeSayisi(YoneticiDugum* yDugum) //Yonetici Listesinde kaç düğüm olduğunu döndüren fonksiyon.
{
    YoneticiDugum* temp = yDugum;
    int yoneticiSayi = 0;

    while(temp != 0)
    {
        yoneticiSayi++;
        temp = temp->sonrakiYlist;
    }
    return yoneticiSayi;
}
void YoneticiListesi::yoneticiSil(int sira) //Seçilen yönetici listesi düğümünü silme işlemini yapan fonksiyon.
{
    YoneticiDugum* silinecek = yDugumGetir(sira);
    if(silinecek->oncekiYlist == NULL && silinecek->sonrakiYlist == NULL)
    {
        delete silinecek;
        ilkY = 0;
        cout<<"Silinecek yonetici dugumu kalmadi!"<<endl;
        return;
    }
    if(silinecek)
    {
        YoneticiDugum* silinecekOnceki = silinecek->oncekiYlist;
        YoneticiDugum* silinecekSonraki = silinecek->sonrakiYlist;
        if(silinecekSonraki)
            silinecekSonraki->oncekiYlist = silinecekOnceki;

        if(silinecekOnceki)
            silinecekOnceki->sonrakiYlist = silinecekSonraki;
        else
            ilkY = silinecekSonraki;
        delete silinecek;
    }
}

//K tuşuna basıldığında rastgele düğüm seçme işlemi için rastgele düğüm için indeks döndüren fonksiyon.
int YoneticiListesi::rastgeleDugum(int sira) 
{
    YoneticiDugum* yTemp = yDugumGetir(sira);
    int indeks = rand() % SatirListesi::dugumSayisi(yTemp->satir);
    return indeks;
}

YoneticiDugum* YoneticiListesi::yDugumGetir(int sira) //İstenilen yönetici listesi düğümünü döndüren fonksiyon.
{
    int istenen = 0;
    YoneticiDugum* dgm = ilkY;
    while(dgm != 0)
    {
        if(istenen == sira)
            return dgm;
        dgm = dgm->sonrakiYlist;
        istenen++;
    }
}

//Satır listesinin düğümlerinin teker teker silinmesi.(K tuşuna basıldığında)
void YoneticiListesi::satirDugumSil(int sira, int silinecekSira) 
{
    YoneticiDugum* ytmp = yDugumGetir(sira);
    int sayac = 0;
    int dgmSayisi = ytmp->satir->dugumSayisi(ytmp->satir);
    int indeks = silinecekSira;
    SatirDugum* gec = ytmp->satir->ilk;
    SatirDugum* temp = gec;
    if(silinecekSira== 0)
    {
        ytmp->satir->ilk = gec->sonraki;
        delete gec;
    }
    else
    {
        while(sayac < indeks)
        {
            temp = gec;
            gec = gec->sonraki;
            sayac++;
        }
        if(indeks == dgmSayisi)
        {
            temp->sonraki = 0;
            delete gec;
        }
        else
        {
            temp->sonraki = gec->sonraki;
            delete gec;
        }
    }
    //Düğümü silindikten sonra ilgili satır listesinin ortalamasının güncellenmesi.
    ytmp->satir->ortalama = SatirListesi::ortalamaHesapla(ytmp->satir); 
    dgmSayisi = ytmp->satir->dugumSayisi(ytmp->satir);

    if(dgmSayisi == 0) //Hiç düğüm kalmamışsa yönetici düğümünün silinmesi.
    {
        yoneticiSil(sira);
        delete ytmp;
    }
}

void YoneticiListesi::yoneticiSirala(YoneticiDugum* ilk) //Yönetici düğümlerinin sıralanması.
{
    
    YoneticiDugum* yoneticiDugum1;
    YoneticiDugum* yoneticiDugum2 = 0;
    bool degistiMi;

    if(ilk == 0)
        return;
    
    do
    {
        degistiMi = false;
        yoneticiDugum1 = ilk;

        while(yoneticiDugum1->sonrakiYlist != yoneticiDugum2)
        {
            if(yoneticiDugum1->satir->ortalama > yoneticiDugum1->sonrakiYlist->satir->ortalama)
            {
                SatirListesi* yoneticiDugum1Satir = yoneticiDugum1->satir;
                SatirListesi* yDugum1SonrakiSatir = yoneticiDugum1->sonrakiYlist->satir;
                yoneticiDugum1->satir = yDugum1SonrakiSatir;
                yoneticiDugum1->sonrakiYlist->satir = yoneticiDugum1Satir;
                degistiMi = true;
            }
            yoneticiDugum1 = yoneticiDugum1->sonrakiYlist;
        }
        yoneticiDugum2 = yoneticiDugum1;  
    } while (degistiMi); 
}
