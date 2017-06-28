#include<iostream>
#include<memory>
#include<vector>
#include "konto.h"
#include "person.h"
#include "bank.h"
using namespace std;

int main(){

auto konto=make_shared<Girokonto>();
auto person1=make_shared<Person>("Gregor");
auto person2=make_shared<Person>("Melanie");
person2->addKonto(*konto);
person2->konto_teilen(*konto,*person1);
cout << *konto;
	



/**
Bank b("erst");
b.neuerKunde("Mascha",'g');
b.neuerKunde("Oleg",'b');

b.getKunden().front()->konto_teilen(*b.getKunden().front()->getKonten().front(), *b.getKunden().back());
b.getKunden().front()->getKonten().front()->print(cout);
**/
/**
Konto k;

Person p("Vitalii");
auto sp=make_shared<Person>(p);

k.setZeich(*sp);

cout <<k;

cout <<*sp;
cout <<"____________"<< endl;
**/

/**
auto gg=make_shared<Konto>();
auto cc=make_shared<Person>("Lena");
cc->addKonto(*gg);
cout << *cc;
cout << endl;
cout << endl;
cout << *gg;
cout << endl;
gg->auszahlen(19);
**/

/**
Bank b;
b.neuerKunde("Anton");
b.neuerKunde("ANatolii");
cout << b;
**/

//auto person1=make_shared<Person>("Natasha");
//auto person2=make_shared<Person>("Vitalii");
//auto konto1=make_shared<Konto>("AT123123", 560, 30);
//person1->addKonto(*konto1);
//person1->konto_teilen(*konto1, *person2);

//cout << *konto1<<endl;

/**
Bank b;
b.neuerKunde("Olga",'g');
cout << b;
vector<shared_ptr<Person>>kunden=b.getKunden();
cout << *kunden[0]<< endl;
vector<shared_ptr<Konto>> konten=kunden[0]->getKonten();
konten[0]->einzahlen(50);
cout << *konten[0];
**/


/**
Bank b("erste");
b.neuerKunde("p1", 'g');
    b.neuerKunde("p2", 'b');
   // cout<< *b.getKunden()[0];
    b.getKunden().front()->getKonten().front()->einzahlen(200);
    b.getKunden().front()->getKonten().front()->ueberweisen(50, *b.getKunden().back()->getKonten().front());
    
    b.getKunden().back()->getKonten().front()->print(cout);
    auto p3 = make_shared<Person>("Aigerim");
    b.getKunden().front()->konto_teilen(*b.getKunden().front()->getKonten().front(), *p3);
    b.getKunden().front()->konto_teilen(*b.getKunden().front()->getKonten().front(), *b.getKunden().back());
    b.getKunden().back()->getKonten().back()->print(cout);

**/



/**
Bank b("erste");
  b.neuerKunde("Daniil", 'g');
    
b.neuerKunde("Alisa", 'b');

b.getKunden().front()->print(cout);
b.getKunden().front()->getKonten().front()->einzahlen(100);
b.getKunden().front()->getKonten().front()->setGebuehren(2);
b.getKunden().front()->getKonten().front()->print(cout);

b.getKunden().front()->getKonten().front()->ueberweisen(10, *(b.getKunden().back()->getKonten().front()));

b.getKunden().back()->getKonten().front()->print(cout);
b.getKunden().front()->getKonten().front()->print(cout);
**/






/**
Bank b("erste");
    b.neuerKunde("Daniil", 'g');
    
    
    
    
   // b.getkunden().at(0)->print(cout);
    
   // b.getkunden().front()->getkonten().front()->print(cout);
    
   // b.neuerKunde("asfas",'b');
     b.getKunden().front()->getKonten().front()->print(cout);
    b.getKunden().front()->getKonten().front()->setGebuehren(2);
    cout << "**** Uberweisen test::: "<<endl;
    b.getKunden().front()->getKonten().front()->einzahlen(1000);
    cout << "Nach der 1000 einzahlung( 1 ): "<<endl;
   
    b.getKunden().front()->getKonten().front()->ueberweisen(10, *b.getKunden().back()->getKonten().front());
    cout << "( 2 ) "<<endl;
    b.getKunden().back()->getKonten().front()->print(cout);
     cout << "Nach der 1000 ueberweisung ( 1 ): "<<endl;
    b.getKunden().front()->getKonten().front()->print(cout);
	
    
   // cout <<"OK"<<endl;

**/
/**
auto person= make_shared<Person>("Alla");
person->neues_konto('g');
cout << *person;

person->getKonten().front()->print(cout);
**/









/**
cout <<endl;
Businesskonto b("AT2313",1000,100,10);
cout <<b;
b.auszahlen(200);
cout << b;
**/

return 0;
}
