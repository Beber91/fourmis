#include "projet.h"

void afficheMLV(Grille g){
    MLV_clear_window(MLV_COLOR_WHITE);
    
    for (unsigned int i = 0; i<g.grille.size(); i++){
        for (unsigned int j =0; j<g.grille.size(); j++){
            MLV_draw_filled_rectangle( TAILLECASE*i, TAILLECASE*j, TAILLECASE, TAILLECASE, MLV_rgba(0,255,0,255*g.grille[i][j].pheroNid));
            if (g.grille[i][j].indiceFourmi != -1){
                MLV_draw_filled_rectangle( TAILLECASE*i, TAILLECASE*j, TAILLECASE, TAILLECASE, MLV_COLOR_BLACK);
            } else if (g.grille[i][j].sucre != 0){
                MLV_draw_filled_rectangle( TAILLECASE*i, TAILLECASE*j, TAILLECASE, TAILLECASE, MLV_COLOR_ORANGE);
            } else if (g.grille[i][j].nid == true){
                MLV_draw_filled_rectangle( TAILLECASE*i, TAILLECASE*j, TAILLECASE, TAILLECASE, MLV_COLOR_BLUE);
            } else if (g.grille[i][j].pheroSucre != 0){
                MLV_draw_filled_rectangle( TAILLECASE*i, TAILLECASE*j, TAILLECASE, TAILLECASE, MLV_rgba(255,0,0,g.grille[i][j].pheroSucre));
            }
        }
    }
    MLV_update_window();
    MLV_wait_seconds( 0 );
}
/**
int main(){
    vector<vector<char>> t(5);
    for (unsigned int i = 0; i<t.size(); i++){
        t[i] = vector<char>(5);
        for (unsigned int j = 0; j<t[i].size(); j++){
            t[i][j] = ' ';
        }
    }

    afficheMLV(t);
}
**/



