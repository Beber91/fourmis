#include "projet.h"

int main(){
    srand(time(NULL));
    testChercheSucre();
    testContientFourmi();
    testContientNid();
    testContientSucre();
    testDansTableau();
    testDistanceNid();
    testRentreNid();
    testSurUnePiste();
    testVide();
    testInitialisation();
    testAjouteEnsCoord();
    testDecroissancePheroSucre();
    testCreerCoord();
    testTrouverVoisin();
    testMax();
    testEvaporationPheroSucre();
    return 0;
}
