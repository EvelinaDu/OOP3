#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED

#include "Mylib.h"
#include "Studentas.h"


// Funkcija, skirta studento duomenų įvedimui rankiniu būdu.
template <typename Container>
void Duom_ivedimas(Container &stud, string vardas, string pavarde);

// Funkcija, kurioje klausiama kiek studentų vartotojas norėtų įtraukti, klausiama studentų vardų bei pavardžių, 
// klausiama koks įvertinimų įvedimas(rankinis ar generavimas) ir pagal tai įvykdoma. 
template <typename Container>
void Info_ivedimas_ranka(Container &stud, int n);

// Funkcija skirta nuskaityti studento įvertinimus iš failo.
template <typename Container>
// void Duom_is_failo(Container &stud, Studentas &s);
void Duom_is_failo(Container &stud);

// Funkcija skirta failo generavimui pagal įrašų kiekį.
void Stud_failu_generavimas(int kiekis);

// Funkcija, skirta atspausdinti antraštei pagal vartoto įvertinimo pasirinkimą.
void Rez_antraste(string pasirinkimas, ostream &out, string isvedimo_pasirinkimas);

// Funkcija skirta studentų rūšiavimui.
template <typename Container>
void Studentu_rusiavimas(Container &stud, string pasirinkimas);

// Funkcija skirta rezultatams atspausdinti į terminalą (vartotojui pasirinkus 'T') arba įrašyti į failą (vartotojui pasirinkus 'F').
template <typename Container>
void SpausdinimasRez(Container &stud, int n, string isvedimo_pasirinkimas, string rez_pasirinkimas, string rusiavimo_p, string ivedimo_skaitymo_p);

// Funkcija, skirta sukurti du naujus kontainerius vargšiukams ir kietiakams, taip studentai yra surūšiuojami į dvi grupes.
template <typename Container>
void Kategorijos_Priskirimas1(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

// Funkcija, kuri surūšiuoja studentus į dvi grupes, jei studento įvertinimas < 5.0, priskiriamas "Vargšiukų" kontaineriui
// ir studentas ištrinamas iš bendro. Taip bendrame liks tik tie studentai, kurių įvertinimas >= 5.0.
template <typename Container>
void Kategorijos_Priskirimas2(Container &stud, Container &stud_Vargsiukai, string pasirinkimas);

// Funkcija, kuri surūšiuoja studentus į dvi grupes, padaryta remiantis 2 strategija (Kategorijos_Priskirimas2). Pritaikyta std::stable_partition() funkcija.
template <typename Container>
void Kategorijos_Priskirimas3(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string pasirinkimas);

// Funkcija, kuri įrašo į failą pateiktą kontainerį.
template <typename Container>
void FailasPgalKategorija(Container &studentai, string pasirinkimas, string isvedimo_pasirinkimas, string pav);

// Funkcija, skirta vartotojui pasirinkti programos vykdymą (Įvesti - I, Nuskaityti - N, Sugeneruoti - S, Testuoti - T).
string pasirinkimas_del_programos_vykdymo();

// Funkcija, skirta vartotojui pasirinkti duomenų struktūrą (V - vektorius, S - sąrašas).
string pasirinkimas_del_duom_strukturos();

// Funkcija, skirta vartotojui pasirinkti galutinį įvertinimą, pagal vidurkį arba pagal medianą.
string pasirinkimas_del_galutinio();

// Funkcija, skirta vartotojui pasirinkti pagal ką reikia surūšiuoti studentus.
string pasirinkimas_del_rusiavimo();

// Funkcija, skirta vartotojui pasirinkti kur nori matyti rezultatą, ar terminale, ar faile.
string pasirinkimas_isvedimo();

// Funkcija, skirta vartotojui pasirinkti pagal kurią strategiją norimą skirstyti studentus į dvi grupes (1, 2, 3).
int pasirinkimas_del_strategijos();

// Funkcija skirta duomenų tvarkymui, tai rezultatų įrašymui, kategorijos priskirimui, naujų failų sukūrimui.
template <typename Container>
void Duom_tvarkymas(Container &stud, Container &stud_Vargsiukai, Container &stud_Kietiakai, string rez_pasirinkimas, string rusiavimo_p, string isvedimo_pasirinkimas, string ivedimo_skaitymo_p, int kategorijos_strategija, int kiekis);

#endif