#include "funkc.h"
int main()
{
int studsk = 10;
int tempint = 0;
string tempstring;
srand(time(NULL));

vector <laikai> laikaii (3);

deque <studentas> studentaideq (1);
vector <studentas> studentaivec (1);
list <studentas> studentaili;

deque <studentas> vargsiukaideq;
deque <studentas> kietekaideq;
vector <studentas> vargsiukaivec;
vector <studentas> kietekaivec;
list <studentas> vargsiukailist;
list <studentas> kietekailist;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);

tempint = input("Iveskite studentu skaiciu: ", 1);


laikaii[0].studsk = tempint;
laikaii[1].studsk = tempint;
laikaii[2].studsk = tempint;

generatefile(tempint, "kursiokai.txt");

laikaii[0].konteineriotipas = "vector";
playPause();
addfromfile(studentaivec, "kursiokai.txt");
playPause();
laikaii[0].laikas[0] = timee;
timee = 0;
playPause();
sortf(studentaivec);
playPause();
laikaii[0].laikas[1] = timee;
timee = 0;
playPause();
filtertomassive(studentaivec, vargsiukaivec, kietekaivec, 1);
playPause();
laikaii[0].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaivec, vargsiukaivec, kietekaivec, 2);
playPause();
laikaii[0].laikas[3] = timee;
timee = 0;
laikaii[0].printlaikai(cout);
studentaivec.clear();
vargsiukaivec.clear();
kietekaivec.clear();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

laikaii[1].konteineriotipas = "deque";
playPause();
addfromfile(studentaideq, "kursiokai.txt");
playPause();
laikaii[1].laikas[0] = timee;
timee = 0;
playPause();
sortf(studentaideq);
playPause();
laikaii[1].laikas[1] = timee;
timee = 0;
playPause();
filtertomassive(studentaideq, vargsiukaideq, kietekaideq, 1);
playPause();
laikaii[1].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaideq, vargsiukaideq, kietekaideq, 2);
playPause();
laikaii[1].laikas[3] = timee;
timee = 0;
laikaii[1].printlaikai(cout);
studentaideq.clear();
vargsiukaideq.clear();
kietekaivec.clear();
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

laikaii[2].konteineriotipas = "list";
playPause();
addfromfile(studentaili, "kursiokai.txt");
playPause();
laikaii[2].laikas[0] = timee;
timee = 0;
playPause();
sortf(studentaili);
playPause();
laikaii[2].laikas[1] = timee;
timee = 0;
playPause();
filtertomassive(studentaili, vargsiukailist, kietekailist, 1);
playPause();
laikaii[2].laikas[2] = timee;
timee = 0;
playPause();
filtertomassive(studentaili, vargsiukailist, kietekailist, 2);
playPause();
laikaii[2].laikas[3] = timee;
timee = 0;
laikaii[2].printlaikai(cout);
studentaili.clear();
vargsiukailist.clear();
kietekailist.clear();
    system("PAUSE");
    return 0;
}
