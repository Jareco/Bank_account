#include<iostream>
#include<memory>
#include "person.h"
#include "konto.h"
#include"bank.h"
using namespace std;
/**

 string name;
 vector<std::shared_ptr<Konto>> konten; 
**/

Person::Person(string name){
 this->name=name;
}

Person::Person(string name, vector<std::shared_ptr<Konto>>konten){
  this->name=name;
  this->konten=konten;
}

string Person::getName()const{
 return name;
}

bool Person::konto_teilen(Konto& k, Person& p){
 k.setZeich(p);
return true;
}

bool Person::neues_konto(char art){
 if(art=='g'){
  shared_ptr<Konto>k{new Girokonto};
  konten.push_back(k);
  k->setZeichback(*this);
 }else if(art=='b'){
  shared_ptr<Konto>k{new Businesskonto};
  konten.push_back(k);
  k->setZeichback(*this);
 }else throw runtime_error("False argument");
return true;
}

bool Person::addKonto(Konto& k){
 konten.push_back(k.getShared());
 k.setZeichback(*this);
return true;
}

bool Person::addKontoback(Konto& k){
 konten.push_back(k.getShared());
return true;
}

shared_ptr<Person> Person:: getShared(){
 return shared_from_this();
}

ostream& Person::print(ostream& o)const{
 o<<"Name: "<<name <<endl;
 o<<"Kontoanzahl: "<<konten.size()<<endl;
 for(const auto& k: konten){
   o<<k->getKontonr()<<endl;
 }
return o;
}

void Person::kuendigen(){
 for(auto& k: konten)
	k=nullptr;

}

vector<std::shared_ptr<Konto>> Person::getKonten(){
 return konten;
}
