#include<iostream>
#include<vector> 
#include<memory>
using namespace std;
class Person;
class Konto: public std::enable_shared_from_this<Konto>{
 string kontonummer;
 int kontostand;
 int disporahmen; //wie viel man abgheben kann
 vector<std::weak_ptr<Person>> zeichnungsberechtigt; //max 10 mind 1

public:
 Konto();
 Konto(string, int, int);
 void einzahlen(unsigned);
 bool auszahlen(unsigned betrag);
 bool ueberweisen(unsigned, Konto&);
 string getKontonr()const;
 void setZeich(Person&);
 void setZeichback(Person&);
 int getKontostand() const;
 void setKontostand(int);
 shared_ptr<Konto> getShared();
virtual void berechne_gebuehren(int){}
virtual ostream& print (std::ostream&)const;
virtual void setGebuehren(int){}
};


class Girokonto: public Konto{
 double gebuehren;
 double fixgebuehren;
 
public:
 Girokonto();
 Girokonto(int);
 Girokonto(string,int,int,int);
 void setGebuehren(int);
 void berechne_gebuehren(int);
 ostream& print (std::ostream&)const override;
};

class Businesskonto: public Konto{
 double gebuehren;
 double prozent;
 
public:
 Businesskonto();
 Businesskonto(int);
 Businesskonto(string,int,int,int);
 void setGebuehren(int);
 void berechne_gebuehren(int);
 ostream& print (std::ostream&)const override;
};



inline ostream& operator <<(ostream& o, const Konto& k){
  return k.print(o);
 }



