#ifndef Zmogus_H_INCLUDED
#define Zmogus_H_INCLUDED


#include <string>
using std::string;

class Zmogus{
  protected:
  string vardas_;
  string pavarde_;

  Zmogus(){};
  Zmogus(const string& vardas, const string& pavarde) 
    : vardas_(vardas), pavarde_(pavarde) {};

  public:
  virtual string getVardas() const = 0;
  virtual string getPavarde() const = 0;

  virtual ~Zmogus(){};

};

#endif