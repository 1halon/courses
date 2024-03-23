#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
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

class Logger {
public:
  void log(const char *name, float price);
  void report(float cash);

private:
  struct Log {
    const char *name;
    float cost;
    int quantity;
  };
  vector<Log> logs;
};

void Logger::log(const char *name, float price) {
  Log *log = NULL;
  for (vector<Log>::iterator i = logs.begin(); i < logs.end(); i++) {
    if (i->name == name) {
      log = i.base();
    }
  }

  if (log != NULL) {
    log->quantity += 1;
    return;
  }

  logs.push_back((Log){name, price, 1});
}

void printhyphens(int length = 16, ostream &stream = cout) {
  for (int i = 0; i < length; i++) {
    stream << '-';
  }
}

void Logger::report(float cash) {
  ofstream report_file;
  report_file.open("report.txt");
  printhyphens(32, report_file);
  report_file << endl;
  for (vector<Log>::iterator i = logs.begin(); i < logs.end(); i++) {
    report_file << i->quantity << " x " << i->name << " (₺" << i->cost << ")"
                << endl;
  }
  printhyphens(32, report_file);
  report_file << endl;
  report_file << "Gün Başı: ₺" << 500 << endl;
  report_file << "Gün Sonu: ₺" << cash << endl;
  report_file << "Kazanç: ₺" << cash - 500 << endl;
}

void list(Beverage (&beverages)[10]) {
  printhyphens();
  cout << " Hoş geldiniz! ";
  printhyphens();
  cout << endl;
  for (int i = 0; i < (int)(sizeof(beverages) / sizeof(beverages[0])); i++) {
    Beverage beverage = beverages[i];
    printf("%s (%.2f TL) için %d giriniz.\n", beverage.getName(),
           beverage.getPrice(), i + 1);
  }
  printhyphens(47);
  cout << endl;
}

void sell(Machine &machine, Beverage &beverage, Logger &logger) {
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
    logger.log(beverage.getName(), price);
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

  Logger logger;

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

    sell(machine, beverages[choice - 1], logger);
  } while (0 != choice);

  printhyphens();
  cout << " Hoşça kalın! ";
  printhyphens();
  cout << endl;

  logger.report(machine.getCash());

  return 0;
}
