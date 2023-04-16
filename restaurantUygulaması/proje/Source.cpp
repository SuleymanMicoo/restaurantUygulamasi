#include <iostream>
#include <fstream>
using namespace std;
class masa
{
    int toplammasa;
public:
    string room_no[20];
    masa() {
        toplammasa = 20;
    }
    ~masa() {
        delete[] room_no;
    }
    void rezerveust(int masano, string name);
    void rezervealt(int masano, string name);
    void masalisteleust();
    void masalistelealt();


};
void masa::masalisteleust() {
    for (int i = 0; i < 12; i++)
        cout << i + 1 << ".masa=" << room_no[i] << "\n";
}
void masa::masalistelealt() {
    for (int i = 0; i < 18; i++)
        cout << i + 1 << ".masa=" << room_no[i] << "\n";
}
void masa::rezervealt(int masano, string name) {
    if (masano < 18) {
        if (room_no[masano - 1] == "") {
            room_no[masano - 1] = name;
            cout << "masa" << masano << " " << room_no[masano - 1] << " tarafýndan rezerve edildi." << endl;
        }
        else {
            cout << "bu masa " << room_no[masano - 1] << " tarfýndan rezeve" << endl;
        }
    }
    else {
        cout << "sadece 18 masa var" << endl;
    }
}
void masa::rezerveust(int masano, string name) {
    if (masano < 12) {
        if (room_no[masano - 1] == "") {
            room_no[masano - 1] = name;
            cout << "masa" << masano << " " << room_no[masano - 1] << " tarafýndan rezerve edildi." << endl;
        }
        else {
            cout << "bu masa " << room_no[masano - 1] << " tarfýndan rezeve" << endl;
        }
    }
    else {
        cout << "sadece 12 masa var" << endl;
    }
}
class node {
public:
    int data;
    node* next;
};
class masaekleme:public masa,node {
private:
    node* head, * tail;
public:
    masaekleme()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node* tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void printList()
    {
        node* temp = head;
        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
class Yiyecekler {
public:
    string name;
    int price;
    int Id;
    void Listele();
    int tutarGetir(int secim);

};
int Yiyecekler::tutarGetir(int secim)
{
    return 0;
}
void Yiyecekler::Listele() {
    cout << Id << ")" << name << endl;
    cout << "Ucreti: " << price << " TL" << endl;
}
class icecekler {
public:
    string name;
    int price;
    int Id;
    void Listele();
    int tutarGetir(int secim);
};
void icecekler::Listele() {
    cout << Id << ")" << name << endl;
    cout << "Ucreti: " << price << " TL" << endl;
}

int icecekler::tutarGetir(int secim)
{
    return 0;
}
class bahsis {
public:
    int bahsis;
    virtual void bahsisver() = 0;
};
class Fatura:public bahsis {
private:
    int privatePrice = 0;
public:
    int tutar = 0;
    void tutarEkle(int fatura);
    void faturaYazdir();
    void SETprivateprice(int privateprice);
    int GETprivateprice();
    void bahsisver() {
        cout << "Bahþiþ verilecek tutarý giriniz: " << endl;
        cin >> bahsis;
        cout << bahsis << " tutarýnda bahþiþ verildi." << endl;
    }

};
void Fatura::tutarEkle(int fatura) {
    tutar += fatura;
}
void Fatura::faturaYazdir() {
    cout << "Faturaniz: " << tutar << " Turk Lirasi" << endl;
}

void Fatura::SETprivateprice(int privateprice) {
    privatePrice = privateprice;
}
int Fatura::GETprivateprice() {
    return privatePrice;
}


int main() {
    setlocale(LC_ALL, "Turkish");
    bahsis* bh = new Fatura();
    masaekleme m12;
    string kupon, iSecim, secilenyemek1, secilenyemek2, secilenyemek3, secilenyemek4, secilenicecek1, secilenicecek2, secilenicecek3, isim;
    int siralama = 0, secim{}, adet = 0, tutar = 0, masano;
    masa m1;
    Fatura fatura;
    Yiyecekler yiyecek1;
    Yiyecekler yiyecek2;
    Yiyecekler yiyecek3;
    Yiyecekler yiyecek4;
    icecekler icecek1;
    icecekler icecek2;
    icecekler icecek3;
    yiyecek1.Id = 1;
    yiyecek1.name = "Adana Kebap";
    yiyecek1.price = 16;
    yiyecek2.Id = 2;
    yiyecek2.name = "Urfa Kebap";
    yiyecek2.price = 16;
    yiyecek3.Id = 3;
    yiyecek3.name = "Ciger Durum";
    yiyecek3.price = 13;
    yiyecek4.Id = 4;
    yiyecek4.name = "Yurek Durum";
    yiyecek4.price = 12;
    icecek1.Id = 1;
    icecek1.name = "Kola";
    icecek1.price = 7;
    icecek2.Id = 2;
    icecek2.name = "Ayran";
    icecek2.price = 5;
    icecek3.Id = 3;
    icecek3.name = "Soda";
    icecek3.price = 2;
    int secenek=0;
    cout << "HOÞ GELDÝNÝZ." << endl;
    cout << "0-ÇIKMAK ÝÇÝN" << endl;
    cout << "1-MENÜYE BAKMAK ÝÇÝN" << endl;

    cin >> secenek;
    while (secenek !=0)
    {

        cout << "1-Masa Rezerve et" << endl;
        cout << "2-Masa doluluk oranýna bak" << endl;
        cout << "3-Yemek Menüsünü gör" << endl;
        cout << "4-Ýçecek Menüsünü gör" << endl;
        cout << "5-Yemek sipariþi ver" << endl;
        cout << "6-Ýçecek sipariþi ver" << endl;
        cout << "7-Bahþiþ ver" << endl;
        cout << "çýkmak için 0'a basýnýz." << endl;
        cin >> secenek;
        switch (secenek)
        {
        case 1:
            int altust;
            cout << "Alt kat için 1'e basýnýz." << endl;
            cout << "Üst kat için 2'ye basýnýz." << endl;
            cin >> altust;
            if (altust == 1)
            {
                cout << "isim giriniz." << endl;
                cin >> isim;
                cout << "masano giriniz." << endl;
                cin >> masano;
                m12.add_node(masano);
                m1.rezervealt(masano, isim);
            }
            else {
                cout << "isim giriniz." << endl;
                cin >> isim;
                cout << "masano giriniz." << endl;
                cin >> masano;
                m12.add_node(masano);
                m1.rezerveust(masano, isim);
            }
            break;
        case 2:
            int altust2;
            cout << "Alt kat için 1'e basýnýz." << endl;
            cout << "Üst kat için 2'ye basýnýz." << endl;
            cin >> altust2;
            if (altust2 == 1)
            {
                m1.masalistelealt();
            }
            else {
                m1.masalisteleust();

            }
            break;
        case 3:
            yiyecek1.Listele();
            yiyecek2.Listele();
            yiyecek3.Listele();
            yiyecek4.Listele();
            break;
        case 4:
            icecek1.Listele();
            icecek2.Listele();
            icecek3.Listele();
            break;
        case 5:
            cout << "Secim Yapmayi Bitirmek Icin 0 Rakamini Giriniz" << endl;
            cout << "Secim Giriniz: ";
            cin >> secim;
            if (secim == 0)
                break;
            cout << "Adet Giriniz: ";
            cin >> adet;
            switch (secim) {
            case 1:
                tutar += yiyecek1.price * adet;
                secilenyemek1 = yiyecek1.name;
                break;
            case 2:
                tutar += yiyecek2.price * adet;
                secilenyemek2 = yiyecek2.name;
                break;
            case 3:
                tutar += yiyecek3.price * adet;
                secilenyemek3 = yiyecek3.name;
                break;
            case 4:
                tutar += yiyecek4.price * adet;
                secilenyemek4 = yiyecek4.name;
                break;
            default:
                cout << "Gecersiz Secim" << endl;
            }
        case 6:
            cout << "Secim Yapmayi Bitirmek Icin 0 Rakamini Giriniz" << endl;
            cout << "Secim Giriniz: ";
            cin >> secim;
            if (secim == 5)
                break;
            cout << "Adet Giriniz: ";
            cin >> adet;
            switch (secim) {
            case 1:
                tutar += icecek1.price * adet;
                secilenicecek1 = icecek1.name;
                break;
            case 2:
                tutar += icecek2.price * adet;
                secilenicecek2 = icecek2.name;
                break;
            case 3:
                tutar += icecek3.price * adet;
                secilenicecek3 = icecek3.name;
                break;
            default:
                cout << "Gecersiz Secim" << endl;
            }
            break;
        case 7:
            bh->bahsisver();
        }

    }
    fatura.tutarEkle(tutar);
    cout << "Indirim Kodunuz Varsa Giriniz: " << endl;
    cin >> kupon;
    if (kupon == "MASTER50") {
        fatura.SETprivateprice(tutar - (tutar / 2));
        cout << "Odemeniz Gereken Tutar: " << tutar << " Indirimli: " << fatura.GETprivateprice() << " TL" << endl;
    }
    else if (kupon == "MASTER25") {
        fatura.SETprivateprice(tutar - ((tutar / 2) / 2));
        cout << "Odemeniz Gereken Tutar: " << tutar << " Indirimli: " << fatura.GETprivateprice() << " TL" << endl;
    }
    else
        fatura.faturaYazdir();

    ofstream dosya;
    dosya.open("fatura.txt");
    if (dosya.is_open()) {
        if (kupon == "MASTER25") {
            dosya << "====== Fatura ======" << endl;
            dosya << "Masa Numarasý: " << masano << endl;
            dosya << " Alýnan yemekler = " << secilenyemek1 << " " << secilenyemek2 << " " << secilenyemek3 << " " << secilenyemek4 << endl;
            dosya << " Alýnan içecekler = " << secilenicecek1 << " " << secilenicecek2 << " " << secilenicecek3 << endl;
            dosya << " Tutar = " << tutar << endl;
            dosya << " Ýndirimli Tutar = " << fatura.GETprivateprice() << " TL" << endl;
            dosya << "--------------------------------" << endl;
            dosya.close();
        }
        else if (kupon == "MASTER50") {
            dosya << "====== Fatura ======" << endl;
            dosya << "Masa Numarasý: " << masano << endl;
            dosya << " Alýnan yemekler = " << secilenyemek1 << " " << secilenyemek2 << " " << secilenyemek3 << " " << secilenyemek4 << endl;
            dosya << " Alýnan içecekler = " << secilenicecek1 << " " << secilenicecek2 << " " << secilenicecek3 << endl;
            dosya << " Tutar = " << tutar << endl;
            dosya << " Ýndirimli Tutar = " << fatura.GETprivateprice() << " TL" << endl;
            dosya << "--------------------------------" << endl;
            dosya.close();
        }
        else {
            dosya << "====== Fatura ======" << endl;
            dosya << "Masa Numarasý: " << masano << endl;
            dosya << " Alýnan yemekler = " << secilenyemek1 << " " << secilenyemek2 << " " << secilenyemek3 << " " << secilenyemek4 << endl;
            dosya << " Alýnan içecekler = " << secilenicecek1 << " " << secilenicecek2 << " " << secilenicecek3 << endl;
            dosya << " Tutar = " << tutar << endl;
            dosya << "--------------------------------" << endl;
        }
    }
    else
        cout << "Dosya acilamadi" << endl;

}




