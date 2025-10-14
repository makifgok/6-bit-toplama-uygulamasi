/**
 * @file 6-Bit kodlama sistemi ile karakter Tabanli Toplama uygulamasi.c
 * @author [M.Akif G�k]
 * @brief 6-Bit kodlama sistemlerinin k�s�tlamalar�n� sim�le eden karakter tabanl� toplama uygulamas�.
 * @version 0.1
 * @date 2025-10-13 
 * * @copyright Copyright (c) 2025
 * * Bu program, Unix �ncesi sistemlerin k�s�tl� Girdi/��kt� (I/O) ortam�n� sim�le eder.
 * Kullan�c�dan standart giri� (stdin) arac�l���yla iki adet tek haneli rakam� karakter
 * olarak okur. Bu karakterleri say�sal de�erlere d�n��t�r�r, toplar ve sonucun
 * yine tek haneli olup olmad���n� kontrol eder. E�er sonu� 9'u a�arsa, bu durum
 * k�s�tl� sistemlerde bir 'ta�ma' (overflow) olarak kabul edilir ve bir hata mesaj� verilir.
 */

#include <stdio.h> // Standart Girdi/��kt� fonksiyonlar� (printf, getchar, putchar) i�in gerekli k�t�phane.

/**
 * @brief Program�n ana giri� noktas�.
 * * De�i�kenleri tan�mlar, kullan�c�dan girdileri al�r, d�n���mleri ve kontrolleri
 * yapar, sonucu ekrana basar veya hata durumunda program� sonland�r�r.
 * * @return int Program�n ��k�� kodunu d�nd�r�r. 0 ba�ar�, 1 ise hata anlam�na gelir.
 */
int main() {
    // ch1 ve ch2: Kullan�c�n�n girdi�i rakamlar� karakter olarak saklamak i�in.
    // char veri tipi, tek bir karakteri (�rn: '5') veya k���k bir tam say�y� tutabilir.
    char ch1, ch2; 

    // num1, num2: Karakterlerden d�n��t�r�len say�sal de�erleri tutmak i�in.
    // sum: Bu iki say�n�n toplam�n� tutmak i�in.
    // int veri tipi, tam say�lar� saklamak i�in kullan�l�r.
    int num1, num2, sum;

    // --- B�R�NC� G�RD� A�AMASI ---
    printf("Lutfen toplamak istediginiz ilk rakami giriniz.\n");
    putchar('>'); // Kullan�c�ya giri� yapmas� i�in bir i�aret�i g�sterir. Sim�lasyonun bir par�as�.
    ch1 = getchar(); // Klavyeden bas�lan �LK karakteri okur ve ch1'e atar.
    
    // ARABELLEK TEM�ZLEME: Kullan�c� rakam� girdikten sonra Enter'a basar. Bu komut, arabellekte (buffer) kalan
    // Enter karakterini (newline - '\n') okuyup atar. Aksi halde bir sonraki getchar()
    // komutu bu Enter'� okuyarak program�n hatal� �al��mas�na neden olur.
    getchar(); 

    // --- �K�NC� G�RD� A�AMASI ---
    printf("Lutfen toplamak istediginiz ikinci rakami giriniz.\n");
    putchar('>');
    ch2 = getchar(); // �kinci karakteri okur ve ch2'ye atar.
    getchar(); // Yine arabelle�i temizlemek i�in Enter karakterini bo�a okur.

    // --- KARAKTERDEN SAYIYA D�N���M ---
    // ASCII tablosunda rakamlar s�ral� bir �ekilde yer al�r ('0' = 48, '1' = 49, ... '9' = 57).
    // �rne�in kullan�c� '5' girdiyse, ch1'in say�sal de�eri 53't�r.
    // 53'ten '0'�n de�eri olan 48'i ��kar�rsak, matematiksel olarak 5 de�erini elde ederiz.
    num1 = ch1 - '0';
    num2 = ch2 - '0';

    // --- input kontrolu ---
    // E�er yap�lan ��karma i�lemi sonucu elde edilen say� 0-9 aral���n�n d���ndaysa,
    // bu kullan�c�n�n bir rakam girmedi�i (�rn: 'a' veya '$') anlam�na gelir.
    if (num1 < 0 || num1 > 9 || num2 < 0 || num2 > 9) {
        putchar('\n');
        printf("HATA: Girilen karakterler rakam (0-9 arasi) olmalidir.\n");
        return 1; // Program� bir hata koduyla sonland�r. '1' genellikle hata anlam�na gelir.
    }

    // --- TOPLAMA ��LEM� ---
    sum = num1 + num2;

    // --- SONU� KONTROL� (6-Bit Sim�lasyon K�s�t�) ---
    // �devin gerektirdi�i gibi, sonucun tek haneli olup olmad���n� kontrol ediyoruz.
    // E�er toplam 9'dan b�y�kse, bu durum k�s�tl� sistemin kapasitesini a�t��� i�in
    // bir hata olarak kabul edilir.
    if (sum > 9) {
        putchar('\n');
        printf("HATA: Toplam tek haneden buyuk (%d)! Kisitli sistem kapasitesi asildi.\n", sum);
        return 1; // Program� bir hata koduyla sonland�r.
    }

    // --- SONUCUN YAZDIRILMASI ---
    // T�m kontrollerden ba�ar�yla ge�ildiyse, sonu� ekrana yazd�r�l�r.
    printf("\nSonuc: %d\n", sum);
    
    return 0; // Program ba�ar�yla tamamland�. '0' genellikle ba�ar� anlam�na gelir.
}
