#include "../include/Studentas.h"
#include "../include/Mylib.h"

Studentas :: Studentas(const string& vardas, const string& pavarde, const vector <double>& nd, double egz){
    vardas_ = vardas;
    pavarde_ = pavarde;
    nd_ = nd;
    egz_ = egz;
    galutinis_ = 0;
}

Studentas :: Studentas(const string& vardas, const string& pavarde, int nd_kiekis){
    const int min_rezult = 1;
    const int max_result = 10;
    //Atsitiktiniu skaičiu generatorius
    random_device rd_genrator;  
    // Intervalas atsitiktinei reikšmei
    uniform_int_distribution<int> Ivertinimas(min_rezult, max_result);
    vardas_ = vardas;
    pavarde_ = pavarde;

    for(int i = 0; i < nd_kiekis; i++){
        int nd_ivertinimas = Ivertinimas(rd_genrator);
        cout << setw(5) << left << nd_ivertinimas;
        nd_.push_back(nd_ivertinimas);
    }

    double egzoIvertinimas = Ivertinimas(rd_genrator);
    egz_ = egzoIvertinimas;
    cout << egzoIvertinimas << endl;
}

// Kopijavimo Konstruktoius
Studentas :: Studentas(const Studentas& saltinis){
    vardas_ = saltinis.vardas_;
    pavarde_ = saltinis.pavarde_;
    nd_ = saltinis.nd_;
    egz_ = saltinis.egz_;
    galutinis_ = saltinis.galutinis_;

}

// Overloaded Assignment Operator - Kopijavimo priskirymo operatorius
Studentas& Studentas :: operator = (const Studentas& saltinis){
    if(this == &saltinis){
        return *this;
    }

    vardas_ = saltinis.vardas_;
    pavarde_ = saltinis.pavarde_;
    nd_ = saltinis.nd_;
    egz_ = saltinis.egz_;
    galutinis_ = saltinis.galutinis_;

    return *this;
};

// Destruktorius
Studentas :: ~Studentas(){
    nd_.clear();
};

ostream& operator<<(ostream& os, const Studentas& s){
    os << setw(15) << left << s.vardas_ << setw(16) << left << s.pavarde_ << setw(19) << left << fixed << setprecision(2) << s.galutinis_;
    return os;
};

istream& operator>>(std::istream& is, Studentas& s){
    if (&is == &std::cin){
        cout << "Įveskite vardą, pavardę: " ;
    }
    is >> s.vardas_ >> s.pavarde_;

    string pasirinkimas;
    if(&is == &cin){
        cout << "Ar norite, kad mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai?(Taip/Ne) ";
        while(true){

            is >> pasirinkimas;
            std::transform(pasirinkimas.begin(), pasirinkimas.end(), pasirinkimas.begin(), ::toupper);
            if(pasirinkimas.substr(0, 4) == "TAIP"){
                int nd_kiekis;
                cout << "Įveskite namų darbų kiekį: ";
                is >> nd_kiekis;
                s = Studentas(s.vardas_, s.pavarde_, nd_kiekis);
            }
            else{
                cout << "Įveskite visus namų darbų įvertinimus. Norėdami baigti įvedimą spauskite dukart 'Enter' klavišą" << endl;
                cin.ignore();
                string eil;            
                int ivertinimas;

                while(true){
                    getline(is, eil);   
                    if(eil.empty()){
                        break;
                    }

                    try{
                        stringstream ss(eil);
                        if(!(ss >> ivertinimas)){
                            throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
                        }

                        if(ivertinimas < 1 || ivertinimas > 10){
                            throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
                        }
                        s.nd_.push_back(ivertinimas);

                    } catch (const invalid_argument &e){
                        cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
                    } catch (const out_of_range &e){
                        cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
                    }
                }

                cout << "Įveskite studento egzamino įvertinimą: ";
                while(true){
                    getline(cin, eil);
                    try{
                        stringstream ss(eil);
                        if(!(ss >> ivertinimas)){
                            throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
                        }

                        if(ivertinimas < 1 || ivertinimas > 10){
                            throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
                        }

                        s.egz_ = ivertinimas;
                        break;

                    } catch (const invalid_argument &e){
                        cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
                    } catch (const out_of_range &e){
                        cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
                    }
                }
            }
            break;  
        }

    } else{
        vector<double> namuDarbai;
        int ivertinimas;
        while(is >> ivertinimas){
            namuDarbai.push_back(ivertinimas);
        }
        s.egz_ = namuDarbai.back();
        namuDarbai.pop_back();
        s.nd_ = namuDarbai;

        namuDarbai.clear();
    }

    return is;
};


// Funkcija skirta galutiniam įvertinimui pagal vidurkį apskaičiuoti.
void Studentas :: Ivertinimas_vid(){
    double suma = 0;
    int nd_kiekis = nd_.size();

    // Pridedame kiekievieną namų darbų įvertinimą prie bendros sumos.
    for (int j = 0; j < nd_kiekis; j++){
         suma += nd_[j];
    }

    double ivertinimas;
    if (nd_kiekis > 0 ){
        galutinis_ = 0.4 * suma/nd_kiekis + 0.6 * egz_;
    } else {
        galutinis_ =  0.6 * egz_;

    }
}

// Funkcija skirta galutiniam įvertinimui pagal medianą apskaičiuoti.
void Studentas :: Ivertinimas_med(){
    int nd_kiekis = nd_.size();

    // Jei namų darbų nėra, tai galutinį įvertinimą nustatome pagal egzaminą.
    if (nd_kiekis == 0){
        galutinis_ = 0.6 * egz_;   
        return;
    }
    
    sort(begin(nd_), end(nd_));


// Medianos ieškojimas
    double mediana = 0;
    int nr = nd_kiekis / 2;
    if (nd_kiekis % 2 == 0){
        mediana = (nd_[nr - 1] + nd_[nr]) / 2.0;
    } else {
        mediana = nd_[nr];
    }

// Ivertinimo apskaičiavimas naudojant medianą.
    galutinis_ = 0.4 * mediana + 0.6 * egz_;
    
}


