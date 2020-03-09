#include "projet.h"

int main(){
    srand(time(NULL));
    tabFourmis ensFourmi;
    Grille exemple;
    initialisation(exemple, ensFourmi);
    recupAffichage(exemple);
    MLV_create_window("test","test",HAUTEUR*TAILLECASE,LARGEUR*TAILLECASE);
    linearisationPheroNid(exemple);
    //~ recupAffichage(exemple);
    //~ dessinerGrille(exemple);
    while(true){
        int x, y;
        evaporationPheroSucre(exemple);
        for (int j = 0; j<NOMBREFOURMI; j++){
            deplaceFourmi(exemple, ensFourmi.tab[j]);
        }
        //~ recupAffichage(exemple);
        afficheMLV(exemple);
        if (MLV_get_mouse_button_state( MLV_BUTTON_LEFT ) == MLV_PRESSED ){
            MLV_get_mouse_position(&x,&y);
            creerSucre(x/TAILLECASE,y/TAILLECASE,exemple);
        }
        usleep(20000);
    }
    return 0;
}
    
