#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include "../include/Zmogus.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;

using std::string;
using std::vector;

class Studentas : public Zmogus{
  private:
  vector <double> nd_;
  double egz_;
  double galutinis_;

  public:
  // Konstruktoriai
  Studentas(){};
  Studentas(const string& vardas, const string& pavarde, const vector <double>& nd, double egz);
  Studentas(const string& vardas, const string& pavarde, int kiekis);

  // Kopijavimo Konstruktoius
  Studentas(const Studentas& saltinis);
  
  // Destruktorius
  ~Studentas();

  // Overloaded Assignment Operator - Kopijavimo priskirymo operatorius
  Studentas& operator=(const Studentas& saltinis);

  friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
  friend std::istream& operator>>(std::istream& is, Studentas& s);

  // set'eriai
  void setVardas(const string& vardas) {vardas_ = vardas; }
  void setPavarde(const string& pavarde) {pavarde_ = pavarde; }
  void setNd(const vector<double>& nd) {nd_ = nd; }
  void setEgz(const double& egz) {egz_ = egz; }
  void setGalutinis(const double& ivertinimas){galutinis_ = ivertinimas; }

  // get'eriai
  string getVardas() const override { return vardas_; }
  string getPavarde() const override { return pavarde_; }

  inline double getEgz() const {return egz_; }
  inline vector<double> getNd() const { return nd_; }
  inline double getGalutinis() const { return galutinis_; }

  void Ivertinimas_vid();
  void Ivertinimas_med();

  

};

#endif