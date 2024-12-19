
#include "../include/Studentas.h"
#include "../include/Stud.h"
#include "../include/timer.h"

// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
template <typename Container>
void Duom_ivedimas(Container &stud, string vardas, string pavarde){

    cout << "Įveskite visus namų darbų įvertinimus. Norėdami baigti įvedimą spauskite dukart 'Enter' klavišą" << endl;
    string eil;             // Kintamasis įvesties eilutei saugoti
    int ivertinimas;
    vector<double> namuDarbai;

    // While ciklas, skirtas įrašyti studento namų darbų įvertinimus. Vyksta tol kol vartotojas nuspaudžia du kart "Enter".
    while(true){
        getline(cin, eil);   // Įvedama visą eilutė
        if(eil.empty()){     // Jei įvestis tuščia (buvo nuspaustas 'Enter'), nutraukiamas ciklas.  
            break;
        }

        // Išimčių tvarkymas skirtas namų darbų įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> ivertinimas)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }

            if(ivertinimas < 1 || ivertinimas > 10){
                throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
            }
            namuDarbai.push_back(ivertinimas);

        } catch (const invalid_argument &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą." << endl;
        }
    }

    // Egzamino įvertinimo įvedimas.
    cout << "Įveskite studento egzamino įvertinimą: ";
    while(true){
        getline(cin, eil);   // Įvedama visą eilutė

        // Išimčių tvarkymas skirtas egzamino įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> ivertinimas)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
            }

            if(ivertinimas < 1 || ivertinimas > 10){
                throw out_of_range("Netinkama įvestis, įvertinimas turi būti nuo 1 iki 10. ");
            }

            stud.push_back(Studentas(vardas, pavarde, namuDarbai, ivertinimas));
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const invalid_argument &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

}
template void Duom_ivedimas<vector<Studentas>>(vector<Studentas>&, string, string);
template void Duom_ivedimas<list<Studentas>>(list<Studentas>&, string, string);


// Funkcija, kurioje klausiama kiek studentų vartotojas norėtų įtraukti, klausiama studentų vardų bei pavardžių, 
// klausiama koks įvertinimų įvedimas(rankinis ar generavimas) ir pagal tai įvykdoma. 
template <typename Container>
void Info_ivedimas_ranka(Container &stud, int n){
    string eil;
    string random_pasirinkimas;

    cout << "Kiek studentų norite įtraukti į sistemą: ";
    cin.ignore();
    while(true){
        
        getline(cin, eil);   // Įvedama visą eilutė.
        // Išimčių tvarkymas skirtas studentų skaičiaus įvedimui.
        try{
            stringstream ss(eil);
            if(!(ss >> n)){
                throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
        }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const invalid_argument &e){
        cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        } 
    }

    for(int i = 0; i < n; i++){
        string vardas, pavarde;

        cout << "Įveskite studento vardą: ";
        cin >> vardas;

        cout << "Įveskite studento pavarde: ";
        cin >> pavarde;

        cout << "Ar norite, kad mokinio gautieji balai už namų darbus bei egzaminą būtų generuojami atsitiktinai?(Taip/Ne) ";
        while(true){

            cin >> random_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas tikrai įvedė 'taip' arba 'ne'.
            try{

                if(random_pasirinkimas != "Taip" && random_pasirinkimas != "taip" && random_pasirinkimas != "TAIP" && random_pasirinkimas != "Ne" && random_pasirinkimas != "ne"&& random_pasirinkimas != "Ne"){
                    throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'Taip' arba 'Ne'. ");
                }
                break;   // Išeiname iš while ciklo, jei įvestis teisinga.

            } catch (const out_of_range &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            }
        }

        if(random_pasirinkimas == "Taip" || random_pasirinkimas == "taip" || random_pasirinkimas == "TAIP"){
            int nd_kiekis;
            cout << "Kiek namų darbų norėtumėt, kad būtų sugeneruota? ";
            cin.ignore();
            while(true){
            
                getline(cin, eil);   // Įvedama visą eilutė

                // Išimčių tvarkymas skirtas studentų skaičiaus įvedimui.
                try{
                    stringstream ss(eil);
                    if(!(ss >> nd_kiekis)){
                        throw invalid_argument("Netinkama įvestis, įvestis nėra skaičius. ");
                    }
                    break;   // Išeiname iš while ciklo, jei įvestis teisinga.

                } catch (const invalid_argument &e){
                    cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
                } 
            }
            
            stud.push_back(Studentas(vardas, pavarde, nd_kiekis));
            
        }
        else if(random_pasirinkimas == "Ne" || random_pasirinkimas == "ne" || random_pasirinkimas == "NE"){

            // cin.ignore() pašalina visus likusius simbolius iš įvesties srauto iki pirmo naujos eilutės simbolio.
            cin.ignore(); 
            Duom_ivedimas(stud, vardas, pavarde);

        }

    } 
}

template void Info_ivedimas_ranka<vector<Studentas>>(vector<Studentas>&, int);
template void Info_ivedimas_ranka<list<Studentas>>(list<Studentas>&, int);



template <typename Container>
void Duom_is_failo(Container &stud){
    ifstream failasIn;   //Skirtas failo nuskaitymui
    string f_pav;        //Failo pavadinimas
    string eil;

    cout << "Įveskite failo pavadinimą: ";
    while(true){
        try{
            cin >> f_pav;

            Timer t;

            failasIn.open(f_pav);

            if (!failasIn.is_open()) {
                throw runtime_error("Klaida, failas nerastas! Bandykite dar kartą! ");
            }  

            getline(failasIn, eil);

            while(getline(failasIn, eil)){
                stringstream ss(eil);
                string vardas, pavarde;
                ss >> vardas >> pavarde;

                vector<double> namuDarbai;
                int ivertinimas;
                string netinkantis_ivertinimas;

                while(true){
                    try{
                        if(!(ss >> ivertinimas)){
                            if(ss.eof()) break;   // eof - end of file
                            ss.clear();
                            ss >> netinkantis_ivertinimas;
                            throw invalid_argument("Netinkamas įvertinimas, įvertinimas nėra skaičius: '" + netinkantis_ivertinimas + "'");
                        }
                        if (ivertinimas < 1 || ivertinimas > 10){
                            throw out_of_range("Netinkamas įvertinimas: " + std::to_string(ivertinimas));
                        }
                        namuDarbai.push_back(ivertinimas);

                    } catch(const invalid_argument &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    } catch(const out_of_range &e){
                        cout << "Klaida: " << e.what() << ". Šis įvertinimas bus praleistas." << endl;
                        continue;   //einame prie kito elemento
                    }               
                }

                double egzaminas;

                if(!namuDarbai.empty()){
                    egzaminas = namuDarbai.back();
                    namuDarbai.pop_back();

                }
                
                stud.emplace_back(Studentas(vardas, pavarde, namuDarbai, egzaminas));

            }
            failasIn.close();
            cout << endl;
            cout << "Failas sėkmingai perskaitytas. Studentų kiekis: " << stud.size() << endl; 
            cout << "Duomenų skaitymas užtruko: " << t.elapsed() << " s\n";
            
            break;   //Išeiname is while ciklo, jei failas atsidarė
        }catch (const runtime_error &e) {
            cout << e.what();
        }
    }


}

template void Duom_is_failo<vector<Studentas>>(vector<Studentas>&);
template void Duom_is_failo<list<Studentas>>(list<Studentas>&);


// Funkcija skirta failo generavimui pagal įrašų kiekį.
void Stud_failu_generavimas(int kiekis){
const int min_rezult = 1;
const int max_result = 10;

//Atsitiktiniu skaičiu generatorius
random_device rd_genrator;   
// Intervalas atsitiktinei reikšmei
uniform_int_distribution<int> Ivertinimas(min_rezult, max_result);

    string pav = "Studentai_" + to_string(kiekis) + ".txt";

    ofstream failas;
    failas.open(pav);

    if(failas.is_open()){

        // Antraštė
        failas << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde";
        for(int i = 0; i < 15; i++){
            failas << setw(5) << left << "ND" + to_string(i + 1);
        }
        failas << setw(5) << left << "EGZ" << endl;

        // Sukuriami studentų duomenys
        for(int i = 0; i < kiekis; i++){
            string vardas = "Vardas" + to_string(i + 1);
            string pavarde = "Pavarde" + to_string(i + 1);

            failas << setw(15) << left << vardas << setw(15) << left << pavarde  << " ";
            for(int i = 0; i < 15; i++){
                int nd_ivertinimas = Ivertinimas(rd_genrator);
                failas << setw(5) << left << nd_ivertinimas;
            }
            int egz = Ivertinimas(rd_genrator);
            failas << setw(5) << left << egz << "\n";
        }
        

        failas.close();
        cout << "Failas "<< pav << " sugeneruotas sėkmingai! Sugeneruota: " << kiekis << " įrašai(-ų)" << endl;
        
    }
    else{
        cout << "ERROR! Nepavyko atidaryti " << pav << " failo" << endl;
    }

}

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas){
    
    if (isvedimo_pasirinkimas == "T"){
        if(pasirinkimas == "V"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Adresas atmintyje" << endl;
            out << "-------------------------------------------------------------------------" << endl;
        }
        else if(pasirinkimas == "M"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(20) << left << "Galutinis (Med.)" << setw(20) << left << "Adresas atmintyje" << endl;
            out << "-------------------------------------------------------------------------" << endl;
        }
    } else {
        if(pasirinkimas == "V"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
            out << "------------------------------------------------" << endl;
        }
        else if(pasirinkimas == "M"){
            out  << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
            out << "------------------------------------------------" << endl;
        }
    }
}

// Funkcija skirta studentų rūšiavimui.
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas){
    if constexpr (is_same_v<Container, vector<Studentas>>){
        if(pasirinkimas == "VP"){
        // Rūšiavimas pagal vardą ir pavardę
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
            if(s1.getVardas() != s2.getVardas()){
                return s1.getVardas() < s2.getVardas();
            }
            return s1.getPavarde() < s2.getPavarde();
            });
        } else if(pasirinkimas == "PV"){
            // Rūšiavimas pagal pavardę ir vardą
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2) {
            if(s1.getPavarde() != s2.getPavarde()){
                return s1.getPavarde() < s2.getPavarde();
            }
            return s1.getVardas() < s2.getVardas();
            });
        }
        else if(pasirinkimas == "GM"){
            // Rušiavimas pagal galutinį įvertinimą mažėjančiai
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis() > s2.getGalutinis();
            });
        }
        else if(pasirinkimas == "GD"){
            // Rušiavimas pagal galutinį įvertinimą didėjančiai
            sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
                return s1.getGalutinis() < s2.getGalutinis();
            });
        }
    } else {
        if(pasirinkimas == "VP"){
            // Rūšiavimas pagal vardą ir pavardę
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                if (s1.getVardas() != s2.getVardas()) {
                    return s1.getVardas() < s2.getVardas();
                }
                return s1.getPavarde() < s2.getPavarde();
            });
        } else if(pasirinkimas == "PV"){
            // Rūšiavimas pagal pavardę ir vardą
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                if (s1.getPavarde() != s2.getPavarde()) {
                    return s1.getPavarde() < s2.getPavarde();
                }
                return s1.getVardas() < s2.getVardas();
            });
        } else if(pasirinkimas == "GM"){
            // Rušiavimas pagal galutinį įvertinimą mažėjančiai
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                return s1.getGalutinis() > s2.getGalutinis();
            });
        } else if(pasirinkimas == "GD"){
            // Rušiavimas pagal galutinį įvertinimą didėjančiai
            stud.sort([](const Studentas &s1, const Studentas &s2) {
                return s1.getGalutinis() < s2.getGalutinis();
            });
        }
    }
}


// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
template <typename Container>
void SpausdinimasRez(Container &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p){
    ofstream failasOut;

    for(auto& studentas : stud){
        if(rez_pasirinkimas == "V"){
            studentas.Ivertinimas_vid();
        } else{
            studentas.Ivertinimas_med();
        }
    }

    //Rusiavimas
    Studentu_rusiavimas(stud, rusiavimo_p);

    if(isvedimo_pasirinkimas == "T"){
        Rez_antraste(rez_pasirinkimas, cout, isvedimo_pasirinkimas);

        for (auto &studentas : stud){
            cout << studentas << setw(18) << left << &studentas << endl;
        }

    }
    else if (isvedimo_pasirinkimas == "F" || ivedimo_skaitymo_p == "T"){
        failasOut.open("Rez.txt");

        if(failasOut.is_open()){

            Rez_antraste(rez_pasirinkimas, failasOut, isvedimo_pasirinkimas);

            for (auto &studentas : stud){
            failasOut << studentas << endl;
            }

            failasOut.close();
            cout << "Rezultatas sėkmingai įrašytas į Rez.txt failą!" << endl;
        }
        else{
            cout << "ERROR! Nepavyko atidaryti Rez.txt failo" << endl;
        }
    }
}

template void SpausdinimasRez<vector<Studentas>>(vector<Studentas>&, int, string, string, string, string);
template void SpausdinimasRez<list<Studentas>>(list<Studentas>&, int, string, string, string, string);


// Funkcija, skirta sukurti du naujus kontainerius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas){
    for (const auto& studentas : stud){

        if (studentas.getGalutinis() < 5.0){
            stud_Vargsiukai.push_back(studentas);
        } else {
            stud_Kietiakai.push_back(studentas);
        }

    }
}

// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei studento įvertinimas < 5.0, priskiriamas "Vargšiukų" kontaineriui
// ir studentas ištrinamas iš bendro. Taip bendrame liks tik tie studentai, kurių įvertinimas >= 5.0.
template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai, string pasirinkimas){

    if constexpr (is_same_v<Container, vector<Studentas>>){
        sort(begin(stud), end(stud), [](const Studentas &s1, const Studentas &s2){
            return s1.getGalutinis() > s2.getGalutinis();
        });
    }      
    else if constexpr (is_same_v<Container, list<Studentas>>){
        stud.sort([](const Studentas &s1, const Studentas &s2) {
            return s1.getGalutinis() > s2.getGalutinis();
        });
        
    }

    while(!stud.empty()){
        if(stud.back().getGalutinis() < 5.0){
            stud_Vargsiukai.push_back(move(stud.back()));
            stud.pop_back();
        } else{
            break;
        }
    }


}


// Funkcija, kuri surūšiuoja studentus į dvi grupes, padaryta remiantis 2 strategija (Kategorijos_Priskirimas2). Pritaikyta std::stable_partition() funkcija.
template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas){

    std::stable_partition(stud.begin(), stud.end(), [&](const auto &studentas){
        return studentas.getGalutinis() >= 5.0;
    });

    while(!stud.empty()){
        if(stud.back().getGalutinis() < 5.0){
            stud_Vargsiukai.push_back(move(stud.back()));
            stud.pop_back();
        }
        else{
            break;
        }
    }

}


// Funkcija, kuri įrašo į failą pateiktą kontainerį.
template <typename Container>
void FailasPgalKategorija(Container &studentai, string pasirinkimas, string isvedimo_pasirinkimas, string pav){
    ofstream failas;

    failas.open(pav);

    if (!failas.is_open()){
        cout << "Klaida atidarant failą. " << endl;
    }

    // Antraštė
    Rez_antraste(pasirinkimas, failas, isvedimo_pasirinkimas);

    for(auto &s : studentai){

        failas << s << endl;
    }

    failas.close();

    cout << "Rezultatas sėkmingai įrašytas į "<< pav <<" failą!" << endl;
}

// Funkcija, skirta vartotojui pasirinkti programos vykdymą (Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T).
string pasirinkimas_del_programos_vykdymo(){
    string ivedimo_skaitymo_p;
    cout << "Pasirinkite ar norite duomenis įvesti, nuskaityti juos iš failo, sugeneruoti ar testuoti duomenų failą?(Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T, Demonstruoti = D) ";
    while(true){
        cin >> ivedimo_skaitymo_p;

        // Išimčių tvarkymas skirtas ivedimo ar skaitymo pasirinkimui.
        try{
            std::transform(ivedimo_skaitymo_p.begin(), ivedimo_skaitymo_p.end(), ivedimo_skaitymo_p.begin(), ::toupper);
            if(ivedimo_skaitymo_p != "N" && ivedimo_skaitymo_p != "I" && ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "D" ){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp: 'I', 'N', 'S', 'T', 'D'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    return ivedimo_skaitymo_p;
}

// Funkcija, skirta vartotojui pasirinkti duomenų struktūrą (V - vektorius, S - sąrašas).
string pasirinkimas_del_duom_strukturos(){
    string vektorius_arba_sarasas;
    cout << "Pasirinkite su kokia duomenų struktūra norite dirbti, su vektoriumi ar su sąrašu (V - vektorius, S - sąrašas): ";

    while(true){
        cin >> vektorius_arba_sarasas;

        // Išimčių tvarkymas skirtas vektoriaus arba sąrašo pasirinkimui.
        try{
            std::transform(vektorius_arba_sarasas.begin(), vektorius_arba_sarasas.end(), vektorius_arba_sarasas.begin(), ::toupper);
            if(vektorius_arba_sarasas != "V" && vektorius_arba_sarasas != "S"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V' arba 'S'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }
    return vektorius_arba_sarasas;
}

// Funkcija, skirta vartotojui pasirinkti galutinį įvertinimą, pagal vidurkį arba pagal medianą.
string pasirinkimas_del_galutinio(){
    string rez_pasirinkimas;
    cout << "Pasirinkite, kokį rezultatą norite matyti, įvertinimas pagal vidurkį įrašykite 'V', įvertinimas pagal medianą įrašykite 'M': ";

    while(true){ 
        cin >> rez_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas pasirinko norimą įvertinimą (V/M).
        try{
            std::transform(rez_pasirinkimas.begin(), rez_pasirinkimas.end(), rez_pasirinkimas.begin(), ::toupper);
            if(rez_pasirinkimas != "V" && rez_pasirinkimas != "M"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'V' ir 'M'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }
    return rez_pasirinkimas;
}

// Funkcija, skirta vartotojui pasirinkti pagal ką reikia surūšiuoti studentus.
string pasirinkimas_del_rusiavimo(){

    string rusiavimo_p;
    cout << "Pasirinkite rūšiavimą, pagal vardą ir pavarde - 'VP', pagal pavardę ir vardą - 'PV', pagal galutinį įvertinimą mažėjančia tvarka - 'GM', pagal galutinį įvertinimą didėjančia tvarka - 'GD': ";
    
    while(true){ 
        cin >> rusiavimo_p;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas pasirinko norimą įvertinimą (VP/PV/GM/GD).
        try{
            std::transform(rusiavimo_p.begin(), rusiavimo_p.end(), rusiavimo_p.begin(), ::toupper);
            if(rusiavimo_p != "VP" && rusiavimo_p != "PV" && rusiavimo_p != "GM" && rusiavimo_p != "GD"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'VP', 'PV', 'GM' arba 'GD'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }

    return rusiavimo_p;
}

// Funkcija, skirta vartotojui pasirinkti kur nori matyti rezultatą, ar terminale, ar faile.
string pasirinkimas_isvedimo(){
    string isvedimo_pasirinkimas;
    cout << "Pasirinkite, kur norėtumėte gauti rezultatą, jei terminale įveskite 'T', jei faile įveskite 'F': ";

    while(true){
        cin >> isvedimo_pasirinkimas;

        // Išimčių tvarkymas skirtas patikrinti ar vartotojas teisingai pasirinko, kur bus pateiktas rezultatas (T/F).
        try{
            std::transform(isvedimo_pasirinkimas.begin(), isvedimo_pasirinkimas.end(), isvedimo_pasirinkimas.begin(), ::toupper);
            if(isvedimo_pasirinkimas != "T" && isvedimo_pasirinkimas != "F"){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp 'T' arba 'F'. ");
            }
            break;   // Išeiname iš while ciklo, jei įvestis teisinga.

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }

    }

    return isvedimo_pasirinkimas;
}

// Funkcija, skirta vartotojui pasirinkti pagal kurią strategiją norimą skirstyti studentus į dvi grupes (1, 2, 3).
int pasirinkimas_del_strategijos(){
    int kategorijos_pasirinkimas;
    cout << "Pasirinkite kategorijos priskirimo strategija (1 Strategija - įveskite 1, 2 Strategija - 2, 3 Strategija - 3): ";

    while(true){
        cin >> kategorijos_pasirinkimas;

        if (cin.fail()){
            cin.clear();
            cin.ignore();

            try{
                throw invalid_argument("Įvestis nėra skaičius. Turite pasirinkti tarp: '1', '2', '3' strategijų. ");
            } catch (const invalid_argument &e){
                cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
            }
            continue;
        }
        try{
            if(kategorijos_pasirinkimas != 1 && kategorijos_pasirinkimas != 2 && kategorijos_pasirinkimas != 3){
                throw out_of_range("Netinkama įvestis, turite pasirinkti tarp: '1', '2', '3' strategijų. ");
            }
            break;

        } catch (const out_of_range &e){
            cout << "Klaida: " << e.what() << "Bandykite dar kartą. ";
        }
    }
    return kategorijos_pasirinkimas;
}

// Funkcija skirta duomenų tvarkymui, tai rezultatų įrašymui, kategorijos priskirimui, naujų failų sukūrimui.
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis){
        cout << endl;
        SpausdinimasRez(stud, kiekis, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);
        cout << endl;

        if (kategorijos_strategija == 1){
            // Studentų rūšiavimas į dvi grupes pagal 1 strategiją.
            Timer t1;
            Kategorijos_Priskirimas1(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 2){
            // Studentų rūšiavimas į dvi grupes pagal 2 strategiją.
            Timer t1;
            Kategorijos_Priskirimas2(stud, stud_Vargsiukai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 3){
            // Studentų rūšiavimas į dvi grupes pagal 3 strategiją.
            Timer t1;
            Kategorijos_Priskirimas3(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas);
            cout << "Failo iš "<< kiekis << " įrašų rūšiavimas į dvi grupes laikas: " << t1.elapsed() << " s.\n";
            cout << endl;
        }


        // Surūšiuojami pagal vartotojo pasirinkimą, nes skaidymo metu duomenis buvo sumaišyti.
        Studentu_rusiavimas(stud_Vargsiukai, rusiavimo_p);
        Studentu_rusiavimas(stud, rusiavimo_p);
        

        // Studentai įrašomi į Vargsiukai.txt failą
        Timer t2;
        FailasPgalKategorija(stud_Vargsiukai, rez_pasirinkimas, isvedimo_pasirinkimas, "Vargsiukai.txt");
        cout << "Failo iš "<< kiekis << " įrašų vargšelių įrašymas į failą laikas: " << t2.elapsed() << " s.\n";
        cout << endl;
        
        // Studentai įrašyti i Kietiakai.txt failą
        if (kategorijos_strategija == 1){
            Timer t3;
            FailasPgalKategorija(stud_Kietiakai, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
            cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 2){
            Timer t3;
            FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
            cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
            cout << endl;

        } else if (kategorijos_strategija == 3){
            if constexpr (is_same_v<Container, vector<Studentas>>){
                Timer t3;
                FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
                cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
                cout << endl;
            } else if constexpr (is_same_v<Container, list<Studentas>>){
                Timer t3;
                FailasPgalKategorija(stud, rez_pasirinkimas, isvedimo_pasirinkimas, "Kietiakai.txt");
                cout << "Failo iš "<< kiekis << " įrašų kietiakų įrašymas į failą laikas: " << t3.elapsed() << " s.\n";
                cout << endl;
            }
        }

}

template void Duom_tvarkymas<vector<Studentas>>(vector<Studentas> &stud, vector<Studentas> &stud_Vargsiukai, vector<Studentas> &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);
template void Duom_tvarkymas<list<Studentas>>(list<Studentas> &stud, list<Studentas> &stud_Vargsiukai, list<Studentas> &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

