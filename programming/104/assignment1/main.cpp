#include <cstdio>
#include <iostream>
using namespace std;

class Machine {
public:
  Machine(float available = 500);
  float getCash() const;
  void intakeCash(float intake);

private:
  float cash;
};

Machine::Machine(float available) { cash = available; }
float Machine::getCash() const { return cash; }
void Machine::intakeCash(float intake) { cash += intake; }

class Beverage {
public:
  Beverage(const char *alias = "Su", float price = .5, int stock = 100);
  const char *getName() const;
  float getPrice() const;
  int getStock() const;
  void sell();

private:
  const char *name;
  int stock;
  float price;
};

Beverage::Beverage(const char *alias, float cost, int available) {
  name = alias;
  price = cost;
  stock = available;
}
const char *Beverage::getName() const { return name; }
float Beverage::getPrice() const { return price; }
int Beverage::getStock() const { return stock; }
void Beverage::sell() { stock -= 1; }

void printhyphens(int length) {
  for (int i = 0; i < length; i++) {
    cout << "-";
  }
}

void list(Beverage (&beverages)[10]) {
  printhyphens(16);
  cout << " Hoş geldiniz! ";
  printhyphens(16);
  cout << endl;
  for (int i = 0; i < sizeof(beverages) / sizeof(beverages[0]); i++) {
    Beverage beverage = beverages[i];
    printf("%s (%.2f TL) için %d giriniz.\n", beverage.getName(),
           beverage.getPrice(), i + 1);
  }
  cout << endl << "Çıkış yapmak için 0 giriniz." << endl;
  printhyphens(47);
  cout << endl;
}

void sell(Machine &machine, Beverage &beverage) {
  if (0 >= beverage.getStock()) {
    cout << "Seçilen ürünün stoğu tükenmiş bulunmaktadır." << endl;
    return;
  }

  float price = beverage.getPrice();
  printf("Borcunuz %.2f TL'dir, para girişi yapınız: ", price);

  float intake;
  cin >> intake;

  if (intake < price) {
    printf("Yetersiz para girişinde bulundunuz, %.2f TL değerindeki iadeniz "
           "yapılmıştır.",
           intake);
    cout << "" << endl;
    return;
  }

  if (intake >= price) {
    if (intake > price)
      printf("Fazladan %.2f TL para girişinde bulundunuz, para üstününüz "
             "verilmiştir.\n",
             intake - price);

    machine.intakeCash(price);
    beverage.sell();
    cout << "İçeceğinizi alabilirsiniz." << endl;
  }
}

int main(void) {
  setlocale(LC_ALL, "tr_TR-UTF-8");

  Machine machine;

  Beverage beverages[10] = {
      Beverage("Su"),
      Beverage("Şekersiz Çay", 1.25),
      Beverage("Şekerli Çay", 1.5),
      Beverage("Sade Kahve", 1.75),
      Beverage("Sütlü Sade Kahve", 2.25),
      Beverage("Şekerli Sade Kahve", 2.75),
      Beverage("Şekerli Sütlü Sade Kahve", 3.25),
      Beverage("Soğuk Kahve", 3.75),
      Beverage("Soda", 4.25),
      Beverage("Gazoz", 4.75),
  };

  int choice;

  do {
    list(beverages);
    cout << "Seçiminiz: ";
    cin >> choice;

    if (1 > choice || 10 < choice) {
      if (0 != choice)
        cout << "Geçersiz seçim!" << endl;
      continue;
    }

    sell(machine, beverages[choice - 1]);
  } while (0 != choice);

  printhyphens(16);
  cout << " Hoşça kalın! ";
  printhyphens(16);
  cout << endl;

  return 0;
}
