# 6-bit_kodlama_sistemi_ile_karakter_tabanli_toplama_uygulamasi
Bu program, Unix öncesi sistemlerin kısıtlı Girdi/Çıktı (I/O) ortamını simüle eder.
# 6-Bit Kodlama Simülasyonu: Karakter Tabanlı Toplama Uygulaması

**Yazar:** M.Akif Gök
**Tarih:** 15.10.2025
**Ders:** [Buraya Dersin Adını Yazın]

Bu proje, belirtilen ders kapsamında geliştirilmiş olup, Unix öncesi 6-bit kodlama sistemlerinin kısıtlı Girdi/Çıktı (G/Ç) ortamını simüle eden bir C uygulamasıdır.

## Projenin Amacı

Program, kullanıcıdan standart giriş aracılığıyla iki adet tek haneli rakamı, sayısal değerler olarak değil, ASCII karakterleri olarak okur. Bu girdiler üzerinde matematiksel bir toplama işlemi gerçekleştirir ve sonucu yine tek haneli bir sayı ise ekrana basar. Eğer toplama sonucu 9'u aşarsa (çift haneli olursa), bu durumu eski sistemlerdeki bir "taşma" (overflow) hatası olarak kabul eder ve kullanıcıya bir hata mesajı göstererek sonlanır.

## Teorik Arka Plan: 6-Bit ve 8-Bit Sistemler

Bu projenin temel aldığı konsept, eski bilgisayar sistemlerindeki donanım kısıtlamalarıdır.

* **6-Bit Kodlama**: Erken dönem bilgisayarlarda bellek maliyetlerinden dolayı kullanılan bu sistem, toplamda $2^6 = 64$ farklı karakteri temsil edebilirdi. Bu set genellikle sadece büyük harfleri, rakamları ve birkaç temel sembolü içerirdi, bu da işlem kapasitesini oldukça sınırlardı.
* **8-Bit Kodlama (ASCII)**: Günümüz bilgisayarlarının temelini oluşturan bu sistem ise $2^8 = 256$ farklı karakteri temsil edebilir. Bu geniş aralık, küçük/büyük harfleri, tüm sembolleri ve kontrol karakterlerini içererek çok daha esnek bir yapı sunar.

Projemiz, modern 8-bitlik bir ortamda (ASCII) çalışmasına rağmen, bilinçli olarak 6-bitlik sistemlerin kısıtlamalarını (sınırlı sayı aralığı ve işlem kapasitesi) simüle etmektedir.

## Kullanılan Teknolojiler

* **Programlama Dili:** C
* **Kütüphane:** `stdio.h` (Standart Girdi/Çıktı Kütüphanesi)
* **Derleyici:** GCC (veya herhangi bir standart C derleyicisi)

## Nasıl Derlenir ve Çalıştırılır?

1.  Bu repoyu klonlayın veya `.c` uzantılı kaynak dosyasını indirin.
2.  Bir terminal veya komut istemcisi açarak dosyanın bulunduğu dizine gidin.
3.  Aşağıdaki komutu kullanarak kodu derleyin:
    ```bash
    gcc "6-Bit kodlama sistemi ile karakter Tabanli Toplama uygulamasi.c" -o toplama_uygulamasi
    ```
4.  Derlenen programı çalıştırın:
    ```bash
    ./toplama_uygulamasi
    ```

## Dil Modeli Kullanımı

Bu projenin geliştirilmesi sırasında **Google Gemini** dil modelinden aşağıdaki konularda destek alınmıştır:
* C dilindeki `getchar()` fonksiyonunun arabellek (buffer) yönetimi ve `Enter` tuşundan kaynaklanan `\n` karakterinin nasıl temizleneceği konusunda teknik bilgi edinme.
* Endüstri standartlarına uygun, Doxygen formatında profesyonel ve teknik yorum satırları oluşturma.
* 6-bit ve 8-bit kodlama sistemleri arasındaki farkları açıklayan teorik metinlerin ve karşılaştırma mantığının hazırlanması.
* Profesyonel bir `README.md` dosyası için bu şablonun ve içeriğinin oluşturulması.
