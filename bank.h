#include<iostream>
#include<vector> 
#include<memory>
using namespace std;
class Konto;
class Bank{
 vector<shared_ptr<Person>> kunden;
 string bankname;
public:
 Bank();
 Bank(string);	
 ostream& print(ostream&) const;
 void neuerKunde(string, char);
 vector<shared_ptr<Person>> getKunden() const;
 void kuendigen();
};

 inline ostream& operator <<(ostream& o, const Bank& b){
  return b.print(o);
 }

