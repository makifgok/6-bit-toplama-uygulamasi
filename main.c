/**
 * @file 6-Bit kodlama sistemi ile karakter Tabanli Toplama uygulamasi.c
 * @author [M.Akif Gök]
 * @brief 6-Bit kodlama sistemlerinin kýsýtlamalarýný simüle eden karakter tabanlý toplama uygulamasý.
 * @version 0.1
 * @date 2025-10-13 
 * * @copyright Copyright (c) 2025
 * * Bu program, Unix öncesi sistemlerin kýsýtlý Girdi/Çýktý (I/O) ortamýný simüle eder.
 * Kullanýcýdan standart giriþ (stdin) aracýlýðýyla iki adet tek haneli rakamý karakter
 * olarak okur. Bu karakterleri sayýsal deðerlere dönüþtürür, toplar ve sonucun
 * yine tek haneli olup olmadýðýný kontrol eder. Eðer sonuç 9'u aþarsa, bu durum
 * kýsýtlý sistemlerde bir 'taþma' (overflow) olarak kabul edilir ve bir hata mesajý verilir.
 */

#include <stdio.h> // Standart Girdi/Çýktý fonksiyonlarý (printf, getchar, putchar) için gerekli kütüphane.

/**
 * @brief Programýn ana giriþ noktasý.
 * * Deðiþkenleri tanýmlar, kullanýcýdan girdileri alýr, dönüþümleri ve kontrolleri
 * yapar, sonucu ekrana basar veya hata durumunda programý sonlandýrýr.
 * * @return int Programýn çýkýþ kodunu döndürür. 0 baþarý, 1 ise hata anlamýna gelir.
 */
int main() {
    // ch1 ve ch2: Kullanýcýnýn girdiði rakamlarý karakter olarak saklamak için.
    // char veri tipi, tek bir karakteri (örn: '5') veya küçük bir tam sayýyý tutabilir.
    char ch1, ch2; 

    // num1, num2: Karakterlerden dönüþtürülen sayýsal deðerleri tutmak için.
    // sum: Bu iki sayýnýn toplamýný tutmak için.
    // int veri tipi, tam sayýlarý saklamak için kullanýlýr.
    int num1, num2, sum;

    // --- BÝRÝNCÝ GÝRDÝ AÞAMASI ---
    printf("Lutfen toplamak istediginiz ilk rakami giriniz.\n");
    putchar('>'); // Kullanýcýya giriþ yapmasý için bir iþaretçi gösterir. Simülasyonun bir parçasý.
    ch1 = getchar(); // Klavyeden basýlan ÝLK karakteri okur ve ch1'e atar.
    
    // ARABELLEK TEMÝZLEME: Kullanýcý rakamý girdikten sonra Enter'a basar. Bu komut, arabellekte (buffer) kalan
    // Enter karakterini (newline - '\n') okuyup atar. Aksi halde bir sonraki getchar()
    // komutu bu Enter'ý okuyarak programýn hatalý çalýþmasýna neden olur.
    getchar(); 

    // --- ÝKÝNCÝ GÝRDÝ AÞAMASI ---
    printf("Lutfen toplamak istediginiz ikinci rakami giriniz.\n");
    putchar('>');
    ch2 = getchar(); // Ýkinci karakteri okur ve ch2'ye atar.
    getchar(); // Yine arabelleði temizlemek için Enter karakterini boþa okur.

    // --- KARAKTERDEN SAYIYA DÖNÜÞÜM ---
    // ASCII tablosunda rakamlar sýralý bir þekilde yer alýr ('0' = 48, '1' = 49, ... '9' = 57).
    // Örneðin kullanýcý '5' girdiyse, ch1'in sayýsal deðeri 53'tür.
    // 53'ten '0'ýn deðeri olan 48'i çýkarýrsak, matematiksel olarak 5 deðerini elde ederiz.
    num1 = ch1 - '0';
    num2 = ch2 - '0';

    // --- input kontrolu ---
    // Eðer yapýlan çýkarma iþlemi sonucu elde edilen sayý 0-9 aralýðýnýn dýþýndaysa,
    // bu kullanýcýnýn bir rakam girmediði (örn: 'a' veya '$') anlamýna gelir.
    if (num1 < 0 || num1 > 9 || num2 < 0 || num2 > 9) {
        putchar('\n');
        printf("HATA: Girilen karakterler rakam (0-9 arasi) olmalidir.\n");
        return 1; // Programý bir hata koduyla sonlandýr. '1' genellikle hata anlamýna gelir.
    }

    // --- TOPLAMA ÝÞLEMÝ ---
    sum = num1 + num2;

    // --- SONUÇ KONTROLÜ (6-Bit Simülasyon Kýsýtý) ---
    // Ödevin gerektirdiði gibi, sonucun tek haneli olup olmadýðýný kontrol ediyoruz.
    // Eðer toplam 9'dan büyükse, bu durum kýsýtlý sistemin kapasitesini aþtýðý için
    // bir hata olarak kabul edilir.
    if (sum > 9) {
        putchar('\n');
        printf("HATA: Toplam tek haneden buyuk (%d)! Kisitli sistem kapasitesi asildi.\n", sum);
        return 1; // Programý bir hata koduyla sonlandýr.
    }

    // --- SONUCUN YAZDIRILMASI ---
    // Tüm kontrollerden baþarýyla geçildiyse, sonuç ekrana yazdýrýlýr.
    printf("\nSonuc: %d\n", sum);
    
    return 0; // Program baþarýyla tamamlandý. '0' genellikle baþarý anlamýna gelir.
}
