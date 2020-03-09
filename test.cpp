#include "projet.h"

void testDansTableau(){
    Coord cTrue1, cFalse1, cFalse2, cFalse3;
    cTrue1.x = HAUTEUR-1;
    cTrue1.y = LARGEUR-1;
    cFalse1.x = HAUTEUR+1;
    cFalse1.y = LARGEUR-1;
    cFalse2.x =HAUTEUR-1;
    cFalse2.y = LARGEUR+1;
    cFalse3.x = HAUTEUR+1;
    cFalse3.y = LARGEUR+1;
    ASSERT(dansTableau(cTrue1));
    ASSERT(!dansTableau(cFalse1));
    ASSERT(!dansTableau(cFalse2));
    ASSERT(!dansTableau(cFalse3));
}

void testChercheSucre(){
    Fourmi fTrue, fFalse;
    fTrue.sucre = 0;
    fFalse.sucre = 1;
    ASSERT(chercheSucre(fTrue));
    ASSERT(!chercheSucre(fFalse));
}

void testRentreNid(){
    Fourmi fTrue, fFalse;
    fTrue.sucre = 1;
    fFalse.sucre = 0;
    ASSERT(rentreNid(fTrue));
    ASSERT(!rentreNid(fFalse));
}

void testContientSucre(){
    Place pTrue, pFalse;
    pTrue.sucre = 1;
    pFalse.sucre = 0;
    ASSERT(contientSucre(pTrue));
    ASSERT(!contientSucre(pFalse));
}

void testContientNid(){
    Place pTrue, pFalse;
    pTrue.nid = true;
    pFalse.nid = false;
    ASSERT(contientNid(pTrue));
    ASSERT(!contientNid(pFalse));
}

void testContientFourmi(){
    Place pTrue, pFalse;
    pTrue.indiceFourmi = 1;
    pFalse.indiceFourmi = -1;
    ASSERT(contientFourmi(pTrue));
    ASSERT(!contientFourmi(pFalse));
}

void testVide(){
    Place pTrue, pFalse1, pFalse2, pFalse3, pFalse4, pFalse5, pFalse6, pFalse7;
    //Place vide
    pTrue.sucre = 0;
    pTrue.nid = false;
    pTrue.indiceFourmi = -1;
    //Place avec une fourmi
    pFalse1.sucre = 0; 
    pFalse1.nid = false;
    pFalse1.indiceFourmi = 1;
    //Place avec un nid
    pFalse2.sucre = 0;
    pFalse2.nid = true;
    pFalse2.indiceFourmi = -1;
    //Place avec un sucre
    pFalse3.sucre = 1;
    pFalse3.nid = false;
    pFalse3.indiceFourmi = -1; 
    //Place avec un sucre et un nid
    pFalse4.sucre = 1;
    pFalse4.nid = true;
    pFalse4.indiceFourmi = -1; 
    //Place avec un sucre et une fourmi
    pFalse5.sucre = 1;
    pFalse5.nid = false;
    pFalse5.indiceFourmi = 1; 
    //Place avec un nid et une fourmi
    pFalse6.sucre = 0;
    pFalse6.nid = true;
    pFalse6.indiceFourmi = 1; 
    //Place avec un sucre, un nid et une fourmi
    pFalse7.sucre = 1;
    pFalse7.nid = true;
    pFalse7.indiceFourmi = 1;
    //tests
    ASSERT(vide(pTrue));
    ASSERT(!vide(pFalse1));
    ASSERT(!vide(pFalse2));
    ASSERT(!vide(pFalse3));
    ASSERT(!vide(pFalse4));
    ASSERT(!vide(pFalse5));
    ASSERT(!vide(pFalse6));
    ASSERT(!vide(pFalse7));
}

void testSurUnePiste(){
    Place pTrue, pFalse;
    //Place avec de la pheromone de sucre
    pTrue.pheroSucre = 255;
    //Place sans pheromone de sucre
    pFalse.pheroSucre = 0;
    //tests
    ASSERT(surUnePiste(pTrue));
    ASSERT(!surUnePiste(pFalse));
}

void testDistanceNid(){
    Place pProche, pLoin, pEgal;
    //Place plus proche que pLoin
    pProche.pheroNid = 0.2;
    //Place plus loin que pProche
    pLoin.pheroNid = 0.1;
    //Place a distance egale avec pProche
    pEgal.pheroNid = pProche.pheroNid;
    //tests
    ASSERT(plusProcheNid(pProche,pLoin));
    ASSERT(plusProcheNid(pProche,pLoin));
    ASSERT(plusLoinNid(pLoin,pProche));
    ASSERT(plusLoinNid(pLoin,pEgal));
}

void testInitialisation(){
    Grille g;
    tabFourmis t;
    initialisation(g,t);
    ASSERT(g.grille.size() == LARGEUR);
    ASSERT(g.grille[0].size() == HAUTEUR);
}

void testAjouteEnsCoord(){
    ensCoord ec;
    Coord c;
    c.x = 1;
    c.y = 1;
    ajouteEnsCoord(c,ec);
    ASSERT(ec.ens[0].x == c.x);
    ASSERT(ec.ens[0].y == c.y);
    ASSERT(ec.taille == 1);
}

void testDecroissancePheroSucre(){
    Place p;
    p.pheroSucre = 255;
    decroissancePheroSucre(p);
    ASSERT(p.pheroSucre == 250);
}

void testCreerCoord(){
    Coord c;
    int x = 10, y = 10;
    c = creerCoord(x,y);
    ASSERT(c.x == x);
    ASSERT(c.y = y);
}

void testTrouverVoisin(){
    ensCoord ecTrue;
    ensCoord test;
    Coord c = creerCoord(2,2); 
    ecTrue.taille = 8;
    ecTrue.ens = vector<Coord>(8);
    ecTrue.ens[0] = creerCoord(1,2);
    ecTrue.ens[1] = creerCoord(3,2);
    ecTrue.ens[2] = creerCoord(1,1);
    ecTrue.ens[3] = creerCoord(2,1);
    ecTrue.ens[4] = creerCoord(3,1);
    ecTrue.ens[5] = creerCoord(1,3);
    ecTrue.ens[6] = creerCoord(2,3);
    ecTrue.ens[7] = creerCoord(3,3);
    test = trouverVoisin(c);
    for(size_t i = 0; i<test.ens.size();i++){
        ASSERT(test.ens[i].x == ecTrue.ens[i].x);
        ASSERT(test.ens[i].y == ecTrue.ens[i].y);
    }
    ASSERT(test.taille == ecTrue.taille);
}

void testMax(){
    ASSERT(max(3,4) == 4);
    ASSERT(max(4,3) == 4);
    ASSERT(max(3,3) == 3);
}

void testEvaporationPheroSucre(){
    Grille g;
    g.grille = vector<vector<Place>>(LARGEUR);
    for (size_t i = 0; i<LARGEUR; i++){
        g.grille[i] = vector<Place>(HAUTEUR);
    }
    g.grille[2][3].pheroSucre = 255;
    g.grille[3][3].pheroSucre = 255;
    g.grille[4][3].pheroSucre = 255;
    evaporationPheroSucre(g);
    g.grille[2][3].pheroSucre = 250;
    g.grille[2][3].pheroSucre = 250;
    g.grille[2][3].pheroSucre = 250;
}
