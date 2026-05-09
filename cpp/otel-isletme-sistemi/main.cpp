#include <iostream>   // Klavyeden veri almak ve ekrana yazı yazmak için
#include <fstream>    // Dosya okuma ve yazma işlemleri için
#include <string>     // string veri tipini kullanabilmek için
#include <iomanip>    // setw ve left gibi biçimlendirme işlemleri için
#include <sstream>    // stringstream kullanarak string verileri parçalayıp okumak için

using namespace std;  // std:: yazmadan doğrudan cout, cin kullanabilmek için

// Oda bilgilerini tutan yapı (struct)
struct OdaBilgileri
{
	int OdaNo;
	int OdaUcreti;
};

// Müşteri bilgilerini tutan yapı (struct)
struct MusteriBilgileri
{
	int MusteriNo;
	string Ad;
	string Soyad;
	string TC;
};

// Fonksiyon prototipleri
void OdaEkle();
void MusteriEkle();
void OdaKayit();
void OdaListele();
void MusteriListele();

int main()
{
	int islemSecimi;

	do
	{
		cout << "..:: OTEL ISLEMLERI ::.." << endl;

		for (int i = 0; i < 30; i++) // Ayırıcı çizgi için döngü
		{
			cout << "-";             // Ekrana '-' karakteri yazdırılır
		}

		cout << endl;

		cout << "1- Oda Islemleri" << endl;        // Menü seçeneği
		cout << "2- Musteri Islemleri" << endl;    // Menü seçeneği
		cout << "3- Oda Kayit Islemleri" << endl;  // Menü seçeneği
		cout << "99- Cikis" << endl;               // Çıkış seçeneği

		cout << "Seciminiz: ";        // Kullanıcıdan seçim istenir
		cin >> islemSecimi;           // Kullanıcının girişi alınır

		switch (islemSecimi)          // Kullanıcının seçimine göre işlem yapılır
		{
		case 1:
		{
			int secim1;

			do
			{
				cout << "\n";
				cout << "1- Oda Ekle" << endl;  
				cout << "2- Odalari Listele" << endl;

				cout << "99- Ust Menu" << endl;
				cout << "Seciminiz: ";
				cin >> secim1;        // Alt menü seçimi alınır

				switch (secim1)      // Alt menü kontrolü
				{
				case 1: OdaEkle(); break;
				case 2: OdaListele(); break;
				case 99: break;
				default:
					cout << "Hatali Secim" << endl;
				}

			} while (secim1 != 99); // Üst menü seçilene kadar devam eder
			break;
		}

		case 2:
		{
			int secim2;

			do
			{
				cout << "\n";
				cout << "1- Musteri Ekle" << endl;
				cout << "2- Musterileri Listele" << endl;
				cout << "99- Ust Menu" << endl;
				cout << "Seciminiz: ";
				cin >> secim2;

				switch (secim2)
				{
				case 1: MusteriEkle(); break;
				case 2: MusteriListele(); break;
				case 99: break;
				default:
					cout << "Hatali Secim" << endl;
				}

			} while (secim2 != 99);
			break;
		}

		case 3:
			OdaKayit();
			break;

		case 99:
			cout << "Cikis yapildi." << endl;
			break;

		default:
			cout << "Hatali Secim" << endl;
			cout << " Devam Etmek Icin Tiklayiniz." << endl; break;


		}

	} while (islemSecimi != 99);

	return 0;
}

// Oda ekleme fonksiyonu
void OdaEkle()
{
	OdaBilgileri oda; // Oda yapısı tanımlanır
	ofstream odalar("odalar.txt", ios::app); // Dosya ekleme modunda açılır

	cout << "\nOda Numarasi: ";
	cin >> oda.OdaNo; // Oda numarası alınır

	cout << "Oda Ucreti: ";
	cin >> oda.OdaUcreti; // Oda ücreti alınır

	odalar << oda.OdaNo << setw(10) << oda.OdaUcreti << endl; // Oda bilgileri dosyaya yazılır.
	odalar.close();                              // Dosya kapatılır

	cout << "Oda Eklendi." << endl;
}

// Oda listeleme fonksiyonu
void OdaListele()
{
	ifstream odalar("odalar.txt"); // Dosya okuma modunda açılır
	cout << "\n";
	string satir; // satir satir okumak için
	if (odalar.is_open())  // odalar dosyasını açar
	{
		// Dosyayı satır satır oku
		cout << "OdaNo: " << "OdaUcreti: " << endl;
		while (getline(odalar, satir)) // satilari tek tek okrur ve yazdırır.
		{
			cout << satir << endl;
		}
		odalar.close();
	}
	else
	{
		cout << "Dosya acilamadi!" << endl; // Değilse açılmama durumu
	}

	odalar.close();
}

// Müşteri ekleme fonksiyonu
void MusteriEkle()
{
	MusteriBilgileri musteri; // Müşteri tanımlama yapısı
	ofstream musteriListele("musteriler.txt", ios::app); // musteriListele dosyasını açar.

	cout << "\nMusteri Numarasi: ";
	cin >> musteri.MusteriNo;

	cout << "Musteri Adi: ";
	cin >> musteri.Ad;

	cout << "Musteri Soyadi: ";
	cin >> musteri.Soyad;

	cout << "Musteri TC: ";
	cin >> musteri.TC;
	//musterileri listeler ve aralarında uygun boşluklar ekler.
	musteriListele << left << setw(10) << musteri.MusteriNo << setw(15) << musteri.Ad << setw(15) << musteri.Soyad << setw(15) << musteri.TC << endl; 

	musteriListele.close(); //  musteriListele adındaki dosyayi kapatılır
	cout << "Musteri Eklendi." << endl;
}

// Müşteri listeleme fonksiyonu
void MusteriListele()
{
	ifstream musteriListele("musteriler.txt");
	string satir;

	if (musteriListele.is_open())
	{
		// Dosyayı satır satır oku
		cout << left << setw(10) << "MusteriNo: " << "MusteriAd: " << "MusteriSoyad: " << "MusteriTC: " << endl;

		while (getline(musteriListele, satir))
		{
			stringstream ss(satir); // Satır parçalanmak üzere ss'e aktarılır

			int musterino;
			string musteriad, musterisoyad, musteritc;

			ss >> musterino >> musteriad >> musterisoyad >> musteritc; // ss deki satırlar alanlara ayrılır

			cout << left
				<< setw(12) << musterino //musterino listeler.
				<< setw(12) << musteriad //musteriad listeler.
				<< setw(12) << musterisoyad	//musterisoyad listeler.
				<< setw(12) << musteritc << endl; //musteritc listeler.
		}
		musteriListele.close();
	}
	else
	{
		cout << "Dosya acilamadi!" << endl;
	}
}

// Oda ve müşteri eşleştirme fonksiyonu
void OdaKayit()
{
	int odaNo, musteriNo; // Oda ve müşteri numaraları
	ofstream odakayitDosya("odakayit.txt", ios::app); // odakayitDosyasını açar.

	cout << "\nOda Numarasi: ";
	cin >> odaNo;

	cout << "Musteri Numarasi: ";
	cin >> musteriNo;

	odakayitDosya << odaNo << setw(10) << musteriNo << endl; // Kayıtlar dosyaya yazılır

	odakayitDosya.close(); // odakayitDosya kapatılır
	cout << "Oda Kaydi Basariyla Yapildi." << endl;
}
