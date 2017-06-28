#include"konto.h"
#include"person.h"
#include"bank.h"
#include<iostream>
using namespace std;
#include<vector>
#include<memory>
static int counter=0;

Konto::Konto(){
 kontostand=0;
 disporahmen=0;
 kontonummer=string("AT")+to_string(counter++);
}

Konto::Konto(string kontonummer, int kontostand, int disporahmen){
 this->kontonummer=kontonummer;
 this->kontostand=kontostand;
 this->disporahmen=disporahmen;
 this->zeichnungsberechtigt=zeichnungsberechtigt;
}


void Konto::einzahlen(unsigned einzahlen){
 kontostand=kontostand+einzahlen;
}

bool Konto::auszahlen(unsigned betrag){
 if(betrag<=disporahmen+kontostand){
   kontostand=kontostand-betrag;
   berechne_gebuehren(betrag);
   return true;
 }else{
   cout << "Guthaben ist nicht ausreichend" << endl;
   return false;
 }
}

bool Konto::ueberweisen(unsigned betrag, Konto& k2){
  if(betrag<=disporahmen+kontostand){
   auszahlen(betrag);
   k2.einzahlen(betrag);
   return true;
 }else{
   cout << "Guthaben ist nicht ausreichend" << endl;
   return false;
 }
}

string Konto::getKontonr()const{
 return kontonummer;
}

void Konto::setZeich(Person& p){
 if(zeichnungsberechtigt.size()>=10) throw runtime_error ("Man darf nicht mehr Personen hinzufuegen");
 shared_ptr<Person> ptr=p.getShared();
 weak_ptr<Person> gw=ptr;
 zeichnungsberechtigt.push_back(gw);
 p.addKontoback(*this);
}
void Konto::setZeichback(Person& p){
 if(zeichnungsberechtigt.size()>=10) throw runtime_error ("Man darf nicht mehr Personen hinzufuegen");
 shared_ptr<Person> ptr=p.getShared();
 weak_ptr<Person> gw=ptr;
 zeichnungsberechtigt.push_back(gw);

}

 std::ostream& Konto::print(std::ostream& o)const{
   o<<"Kontonummer: " << kontonummer << endl;
   o<<"Kontostand: " << kontostand << " Zeichungsberechtigte: " << zeichnungsberechtigt.size()<< endl;
      o<<"Name: "<<endl; 
  for(const auto& p: zeichnungsberechtigt){ 
	auto g=p.lock(); 		
	o<<g->getName();
  	o<<" "; 
  }
  o<<endl;
   
  return o;
 }

 int Konto:: getKontostand()const{
  return this->kontostand;
 }
 
 void Konto::setKontostand(int betrag){
  if(betrag<0) throw runtime_error("Betrag kann nicht negativ sein");
  kontostand =betrag;
 }

 shared_ptr<Konto> Konto:: getShared(){
 return shared_from_this();
}
 

//Girokonto_____________________________________
 Girokonto::Girokonto():Konto(){
  gebuehren=0;
  fixgebuehren=0;
 }


 Girokonto::Girokonto(int fixgebuehren):Konto(){
    this->fixgebuehren=fixgebuehren;
    gebuehren=0;
 }

  Girokonto::Girokonto(string kontonummer, int kontostand, int disporahmen, int geb):Konto(kontonummer,kontostand, disporahmen){
  fixgebuehren=geb;
  gebuehren=0;
 }


  ostream& Girokonto::print (std::ostream& o)const{
    o<<"Girokonto"<<endl;
    o<<"Gebuehren: "<<gebuehren<<endl;
    return Konto::print(o);
 }


void Girokonto::berechne_gebuehren(int buchung){
  gebuehren=gebuehren+fixgebuehren;
}
void Girokonto::setGebuehren(int betrag){
 if(betrag<0) throw runtime_error("Gebuehren können nicht negativ sein");
 fixgebuehren=betrag;
}



//Businesskonto__________________________

 Businesskonto::Businesskonto():Konto(){
  gebuehren=0;
  prozent=0;
 }


 Businesskonto::Businesskonto(int prozent):Konto(){
    prozent=prozent;
    gebuehren=0;
 }

  Businesskonto::Businesskonto(string kontonummer, int kontostand, int disporahmen, int geb):Konto(kontonummer,kontostand, disporahmen){
  prozent=geb;
  gebuehren=0;
 }


  ostream& Businesskonto::print (std::ostream& o)const{
    o<<"Businesskonto"<<endl;
    o<<"Gebuehren: "<<gebuehren<<endl;
    return Konto::print(o);
 }


void Businesskonto::berechne_gebuehren(int buchung){
  gebuehren=gebuehren+(buchung*prozent)/100;
}
void Businesskonto::setGebuehren(int betrag){
 if(betrag<0) throw runtime_error("Gebuehren können nicht negativ sein");
 gebuehren=betrag;
}

