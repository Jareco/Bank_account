#include<iostream>
#include<memory>
#include<vector>
using namespace std;
class Konto;
class Person: public std::enable_shared_from_this<Person>{
 string name;
 vector<std::shared_ptr<Konto>> konten; 
public:
 Person(string);
 Person(string, vector<std::shared_ptr<Konto>>);
  bool konto_teilen(Konto& k, Person& p);
  bool neues_konto(char);
  void kuendigen();
  string getName()const;
  bool addKonto(Konto&);
  ostream& print(ostream&)const;
  shared_ptr<Person> getShared();
  bool addKontoback(Konto&);
  vector<std::shared_ptr<Konto>> getKonten();
};

inline ostream& operator<<(ostream& o, const Person& p){
 return p.print(o);
}
