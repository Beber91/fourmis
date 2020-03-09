#include <iostream>
#include <vector>
#include <stdexcept>
#include <MLV/MLV_all.h>
#include <stdexcept>
#include <unistd.h>

#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ \
				       << " line " << __LINE__ << ": " #test << endl

using namespace std;

const int HAUTEUR = 50;
const int LARGEUR = 50;
const int NOMBREFOURMI = 12;
const int TAILLECASE = 20;

struct Coord {
    int x;
    int y;
};

struct Fourmi {
    int indice;
    int sucre;
    Coord c;
};

struct ensCoord{
    int taille = 0;
    vector<Coord> ens = vector<Coord>(0);
};
struct Place {
    int indiceFourmi;
    int sucre;
    bool nid;
    int pheroSucre;
    float pheroNid;
    Coord c;
};

struct Grille {
    vector<vector<Place>> grille;
    vector<vector<char>> affichage;
};

struct tabFourmis {
    Fourmi tab [NOMBREFOURMI];
};


//fichier fonctions.cpp
bool chercheSucre(Fourmi f);
bool rentreNid( Fourmi f);
bool contientSucre(Place p);
bool contientNid(Place p);
bool contientFourmi(Place p);
bool vide (Place p);
bool surUnePiste(Place p);
bool plusProcheNid(Place p1, Place p2);
bool plusLoinNid(Place p1, Place p2);
void initialisation(Grille &retour, tabFourmis &t);
void recupAffichage(Grille &g);
void deplaceFourmi(Grille &g, Fourmi &f);
void dessinerGrille(Grille g);

void linearisationPheroNid(Grille &g);
float max(float a, float b);
ensCoord trouverVoisin(Coord c);
bool dansTableau(Coord c);
Coord creerCoord(int x, int y);
void decroissancePheroSucre(Place &p);
void ajouteEnsCoord(Coord c, ensCoord &ec);
void evaporationPheroSucre(Grille &g);
void creerSucre(int x, int y, Grille &g);
void creerFourmi(int x, int y,tabFourmis &t, Grille &g, int ind);
void creerNid(Grille &g, int x, int y); 

//fichier mlv.cpp
void afficheMLV(Grille g);

//fichier test.cpp
void testChercheSucre();
void testContientFourmi();
void testContientNid();
void testContientSucre();
void testDansTableau();
void testDistanceNid();
void testRentreNid();
void testSurUnePiste();
void testVide();
void testInitialisation();
void testAjouteEnsCoord();
void testDecroissancePheroSucre();
void testCreerCoord();
void testTrouverVoisin();
void testMax();
void testEvaporationPheroSucre();
