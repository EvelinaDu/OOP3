#include "../include/Mylib.h"
#include "../include/Stud.h"
#include "../include/timer.h"
#include "../include/Studentas.h"


int main() {
    int n;                              // Skirtas išsaugoti studentų kiekį

    ifstream failasIn;                  //Skirtas failo nuskaitymui
    string f_pav;                       //Failo pavadinimas

    string rez_pasirinkimas;
    string rusiavimo_p;
    string isvedimo_pasirinkimas;
    string vektorius_arba_sarasas;
    int skaidymo_strategija;

    vektorius_arba_sarasas = pasirinkimas_del_duom_strukturos();

    string ivedimo_skaitymo_p = pasirinkimas_del_programos_vykdymo();

    if (vektorius_arba_sarasas == "V"){
        vector<Studentas> stud;
        vector<Studentas> stud_Vargsiukai, stud_Kietiakai;
        vector<int> kiekis; 

        if(ivedimo_skaitymo_p == "N"){
            Duom_is_failo(stud);
        }
        else if(ivedimo_skaitymo_p == "I"){
            Info_ivedimas_ranka(stud, n);
        }
        else if(ivedimo_skaitymo_p == "S"){
            kiekis = {1000, 10000, 100000, 1000000, 10000000};
            cout << endl;
            for (int k: kiekis){
                Timer t;

                Stud_failu_generavimas(k);

                cout << "Failo su "<< k << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
                stud.clear();
                cout << endl;
            }
        }
        else if(ivedimo_skaitymo_p == "T"){
            skaidymo_strategija = pasirinkimas_del_strategijos();
            rez_pasirinkimas = pasirinkimas_del_galutinio();
            rusiavimo_p = pasirinkimas_del_rusiavimo();

            Duom_is_failo(stud);

            n = stud.size();
            Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, skaidymo_strategija, n);
        }
        else if(ivedimo_skaitymo_p == "D"){
            // Zmogus z;
            Studentas s1, s2;
            stringstream example("Vardas1 Pavarde1 6 10 2 6 2 2 4 10 9 6 9 10 6 4 8 7");

            cout << "Naudojamas įvesties operatorius" << endl;
            cin >> s1;
            s1.Ivertinimas_vid();

            example >> s2;
            s2.Ivertinimas_vid();

            cout << "\nNaudojamas išvesties operatorius: " << endl;
            cout << s1 << endl;
            cout << s2 << endl;

            ofstream testas("Testas.txt");
            testas << s2;
            testas.close();

            cout << "\nNaudojamas kopijavimo konstruktorius: " << endl;
            Studentas s3(s1);
            cout << s1 << endl;
            cout << s3 << endl;

            cout << "\nNaudojamas kopijavimo operatorius: " << endl;
            s1 = s2;
            cout << s1 << endl;
            cout << s2 << endl;
            

            // ifstream in("test_data.txt");
            // Studentas t;
            // in >> t;
            // t.Ivertinimas_vid();
            // ofstream failas("rez_t.txt");
            // failas << t;
            system("pause");
            return 1;
        }
        
        if(ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "D"){
            rez_pasirinkimas = pasirinkimas_del_galutinio();
            rusiavimo_p = pasirinkimas_del_rusiavimo();
            isvedimo_pasirinkimas = pasirinkimas_isvedimo();
            n = stud.size();
            SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);
        }

    } 
    else{
        list<Studentas> stud;
        list<Studentas> stud_Vargsiukai, stud_Kietiakai;
        list<int> kiekis;

        if(ivedimo_skaitymo_p == "N"){
            Duom_is_failo(stud);
        }
        else if(ivedimo_skaitymo_p == "I"){
            Info_ivedimas_ranka(stud, n);
        }    
        else if(ivedimo_skaitymo_p == "S"){
            kiekis = {1000, 10000, 100000, 1000000, 10000000};
            cout << endl;
            for (int k: kiekis){

                Timer t;

                Stud_failu_generavimas(k);

                cout << "Failo su "<< k << " įrašų generavimo laikas: " << t.elapsed() << " s.\n";
                stud.clear();
                cout << endl;

            }
        }
        else if(ivedimo_skaitymo_p == "T"){
            skaidymo_strategija = pasirinkimas_del_strategijos();
            rez_pasirinkimas = pasirinkimas_del_galutinio();
            rusiavimo_p = pasirinkimas_del_rusiavimo();

            Duom_is_failo(stud);

            n = stud.size();
            Duom_tvarkymas(stud, stud_Vargsiukai, stud_Kietiakai, rez_pasirinkimas, rusiavimo_p, isvedimo_pasirinkimas, ivedimo_skaitymo_p, skaidymo_strategija, n);
        }
        else if(ivedimo_skaitymo_p == "D"){
            Studentas s1, s2;
            stringstream example("Vardas1 Pavarde1 6 10 2 6 2 2 4 10 9 6 9 10 6 4 8 7");

            cout << "Naudojamas įvesties operatorius" << endl;
            cin >> s1;
            s1.Ivertinimas_vid();

            example >> s2;
            s2.Ivertinimas_vid();

            cout << "Naudojamas išvesties operatorius" << endl;
            cout << s1 << endl;
            cout << s2 << endl;

            ofstream testas("Testas.txt");
            testas << s2;
            testas.close();

            cout << "Naudojamas kopijavimo konstruktorius" << endl;
            Studentas s3 = s1;
            cout << s1 << endl;
            cout << s3 << endl;

            cout << "Naudojamas kopijavimo operatorius" << endl;
            s1 = s2;
            cout << s1 << endl;
            cout << s2 << endl;
            
            system("pause");
            return 1;
        }

        
        if(ivedimo_skaitymo_p != "S" && ivedimo_skaitymo_p != "T" && ivedimo_skaitymo_p != "D"){
        rez_pasirinkimas = pasirinkimas_del_galutinio();
        rusiavimo_p = pasirinkimas_del_rusiavimo();
        isvedimo_pasirinkimas = pasirinkimas_isvedimo();
        n = stud.size();
        SpausdinimasRez(stud, n, isvedimo_pasirinkimas, rez_pasirinkimas, rusiavimo_p, ivedimo_skaitymo_p);

        }
    }

    system("pause");
    return 0;
}
