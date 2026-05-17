using System;
using System.Collections.Generic; // Dictionary yapisini kullanmak icin gerekli kutuphane

class Program
{
    static void Main()
    {
        // 1. Sözlük Tanımlama (Key: string, Value: int)
        Dictionary<string, int> urunler = new Dictionary<string, int>();

        // 2. Veri Ekleme Yontemleri
        urunler.Add("Laptop", 15);    // Add metodu ile ekleme
        urunler["Telefon"] = 25;      // Indeksleyici kullanarak ekleme
        urunler["Tablet"] = 10;

        // 3. Varlik Kontrolu
        if (urunler.ContainsKey("Laptop")) // Anahtar sozlukte var mi kontrolu
        {
            // 4. Veriye Erisim (Anahtar yardimiyla dogrudan erisim)
            int miktar = urunler["Laptop"];
            Console.WriteLine("Laptop Stok Adedi: " + miktar);
        }

        // 5. Veri Güncelleme
        urunler["Tablet"] = 12; // Mevcut anahtarin degerini degistirir.

        // 6. Veri Silme
        urunler.Remove("Telefon"); // Belirtilen anahtari ve degerini siler.

        // 7. Listeleme (Tüm listeyi ekrana yazdirma)
        Console.WriteLine("\n--- Güncel Stok Listesi ---");
        foreach (var urun in urunler)
        {
            // Her bir anahtari ve karsilik gelen degeri yazdirir.
            Console.WriteLine("Urun: " + urun.Key + " | Stok: " + urun.Value);
        }


    }
}
