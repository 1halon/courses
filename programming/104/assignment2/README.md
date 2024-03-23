# İçecek Otomatı

## Algoritma

### Makine
1. Makinenin değerlerini saklamak ve üzerinde işlem yapmak için bir Makine sınıfı oluştur.
2. Makinenin içindeki parayı temsil eden bir değer oluştur ve bu değerin ön atamasını 500 olarak ayarla.
3. Çağrıldığı esnada makinede olan paranın değerini döndürmek için getCash() metodunu oluştur.
4. Makineye para alımı yapılacağı zaman alınan parayı makinede olan paranın üstüne ekleyen intakeCash() metodunu oluştur.

### İçecek
1. İçecek değerlerini saklamak ve üzerinde işlem yapmak için bir İçecek sınıfı oluştur.
2. İçeceğin ismini, fiyatını ve stok sayısını temsil eden değerleri oluştur; bu değerlerin ön atamalarını sırasıyla "Su", 0.5 ve 100 olarak ayarla; bu değerleri döndüren getName(), getPrice() ve getStock() metodlarını oluştur.
3. İçecek satıldığı zaman içeceğin stoğunu bir azaltan sell() metodunu oluştur.

### Kayıt Tutucu
1. Kayıtları saklamak ve üzerinde işlem yapmak için bir Kayıt Tutucu sınıfı oluştur.
2. Yeni kayıt oluşturmak ya da kayıt zaten varsa kayıdın miktar sayısını artırmak için log() metodunu oluştur.
3. Çağırıldığı zaman makinede olan parayı giriş olarak alan ve makinenin para durumunu ve kayıtları report.txt dosyasına yazan report() metodunu oluştur.

### Program
1. İçecekleri listelemek için içecek sınıfı nesneleri dizisi alan bir list() fonsiyonu oluştur ve fonksiyon çağrıldığında içecek listesini, içeceklerin fiyatlarını ve seçim numaralarını göster.
2. İçecek satışı yapmak için makine, içecek ve kayıt tutucu sınıfı nesnesilerini alan bir sell() fonksiyonu oluştur ve bu fonksiyon çağırıldığında:
    1. İçeceğin stoğunu kontrol et.
    2. Ödeme iste.
        1. Eğer ödeme eksik ise iptal et ve para iadesi yap.
        2. Eğer ödeme fazla ise para üstünü ver.
    3. Parayı makineye ekle.
    4. İçeceğin stoğunu bir azaltmak için içecek nesnesinin sell() metodunu çağır.
    5. İçeceği ver.
    6. Kayıt tutucu nesnesinin log() metodunu içeceğin ismi ve fiyatı ile çağır.
3. Dili Türkçe'ye ayarla.
4. Bir tane makine sınıfı nesnesi oluştur.
5. 10 elemanlı bir içecekler sınıfı dizisi oluştur ve içecek sınıfı nesneleri ile doldur.
6. Bir tane kayıt tutucu sınıfı nesnesi oluştur.
7. Seçimi kaydetmek için bir değişken tanımla.
8. list() fonksiyonunu çağır.
9. Seçim yaptır.
10. Seçim 0 ise kayıt tutucu nesnesinin report() metodunu makinenin güncel parası ile çağır ve bitir.
11. Seçim geçersiz ise adım 8'ye dön.
12. Seçim geçerli ise sell() fonksiyonunu makine ve seçilen içecek ile çağır.
13. Adım 8'ye dön.

## Belgelendirme

### Makine

```cpp
class Machine
```

#### Genel

Makine sınıfını oluşturur ve olan para değerini 500 yapar.
```cpp
Machine(float available = 500);
```

Makinede o anda var olan para miktarını yani cash değerini verir.
```cpp
float getCash() const;
```

Makineye para alımını gerçekleştirir ve alınan para ile olan paranın toplamını cash değerine atar.
```cpp
void intakeCash(float intake);
```

#### Özel

Makinede olan para miktarını temsil eder.
```cpp
float cash;
```

### İçecek

```cpp
class Beverage
```

#### Genel

İçecek sınıfını oluşturur; isim, fiyat ve stok değerlerinin ön atamalarını ayarlar.
```cpp
Beverage(const char *alias = "Su", float price = .5, int stock = 100);
```

İçeceğin ismini verir.
```cpp
const char *getName() const;
```

İçeceğin fiyatını verir.
```cpp
float getPrice() const;
```

İçeceğin stok sayısını verir.
```cpp
int getStock() const;
```

İçecek stoğunu bir azaltır.
```cpp
void sell();
```

#### Özel

İçeceğin ismini temsil eder.
```cpp
const char *name;
```

İçeceğin stok sayısını temsil eder.
```cpp
int stock;
```

İçeceğin fiyatını temsil eder.
```cpp
float price;
```

### Kayıt Tutucu

```cpp
class Logger
```

#### Genel

Kayıt Tutucu sınıfını oluşturur.
```cpp
Logger();
```

Girilen ad ile bir kayıt yoksa kayıt oluşturur ve fiyatı ile beraber kaydeder, var ise kayıtın miktar sayısını bir artırır.
```cpp
void log(const char *name, float price);
```

Makinenin para değerini giriş olarak alır ve kayıtları, makinenin para durumu ile beraber report.txt dosyasına yazar.
```cpp
void report(float cash);
```

#### Özel

Kayıdı temsil eder.
```cpp
struct Log {
  // Kayıdı yapılan içeceğin ismini temsil eder.
  const char *name;
  // Kayıdı yapılan içeceğin fiyatını temsil eder.
  float price;
  // Kayıdı yapılan içeceğin kayıt sayısını temsil eder.
  int quantity;
};
```

Kayıtları temsil eder.
```cpp
vector<Log> logs;
```

### Program

Girilen length değeri kadar girilen yayına tire (-) yazar.
```cpp
void printhyphens(int length = 16, ostream &stream = cout);
```

Makinede bulunun içecekleri ve fiyatlarını yazar.
```cpp
void list(Beverage (&beverages)[10]);
```

İçecek satışını halleder.
```cpp
void sell(Machine &machine, Beverage &beverage);
```
