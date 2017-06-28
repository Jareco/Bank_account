#include"konto.h"
#include"person.h"
#include"bank.h"
#include<iostream>
using namespace std;
#include<vector>
#include<memory>

Bank::Bank(){
 this->bankname="Bank Austria";
}

Bank::Bank(string bankname){
 this->bankname=bankname;
}

vector<shared_ptr<Person>> Bank::getKunden() const{
return kunden;
}

void Bank::kuendigen(){
 for(auto& k: kunden)
	k=nullptr;

}

ostream& Bank::print(ostream& o) const{
 o<<"Kunden:" << endl;
 for(const auto& k: kunden){
  o<<*k;
 }
return o;
}

void Bank::neuerKunde(string name, char art){

  auto kunde=make_shared<Person>(name);
  kunden.push_back(kunde);
  kunde->neues_konto(art);
  

}
