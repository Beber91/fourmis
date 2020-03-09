#include "projet.h"
/** une fonction qui indique si la coordonnee se situe dans le tableau
 * @param une Coord Coord
 * @return true si la coordonnee se situe dans le tableau
**/
bool dansTableau(Coord c){
    if (c.x<0 or c.x>=HAUTEUR or c.y<0 or c.y>=LARGEUR)return false;
    return true;
}

/** une fonction qui indique si la fourmi cherche du sucre
 * @param une Fourmi f
 * @return true si la fourmi ne porte pas de sucre et false sinon
**/
bool chercheSucre(Fourmi f){
    return (f.sucre == 0);
}

/** une fonction qui indique si la fourmi rentre au nid
 * @param une Fourmi F
 * @return true si la fourmi porte du sucre et false sinon
**/
bool rentreNid( Fourmi f){
    return(f.sucre != 0);
}

/** une fonction qui indique si la place contient du sucre
 * @param une Place p
 * @return true si la place contient du sucre et false sinon
**/
bool contientSucre(Place p){
    return(p.sucre != 0);
}

/** une fonction qui indique si la place contient un nid
 * @param une Place p
 * @return true si la place contient un nid et false sinon
**/
bool contientNid(Place p){
    return p.nid;
}

/** une fonction qui indique si la place contient une fourmi
 * @param une Place p
 * @return true si la place contient du sucre et false sinon
**/
bool contientFourmi(Place p){
    return (!(p.indiceFourmi == -1));
}

/** une fonction qui indique si la place est vide
 * @param une Place p 
 * @return true si la place ne contient ni fourmi, ni nid, ni sucre et false sinon
**/
bool vide (Place p){
    return (!contientFourmi(p) and !contientNid(p) and !contientSucre(p));
}

/** une fonction qui indique si la place est sur une piste d'une fourmi avec un sucre
 * @param une Place p
 * @return true si la place contient du pheromone de sucre et false sinon
**/
bool surUnePiste(Place p){
    return(!(p.pheroSucre == 0));
}

/** une fonction qui indique si la place p1 est plus proche du nid que la place p2
 * @param une Place p1
 * @param une Place p2
 * @return true si la place p1 a plus de pheromone de nid que la place p2
**/
bool plusProcheNid(Place p1, Place p2){
    return(p1.pheroNid>=p2.pheroNid);
}

/** une fonction qui indique si la place p1 est plus loin du nid que la place p2
 * @param une Place p1
 * @param une Place p2
 * @return true si la place p1 est plus loin du nid que la place p2
**/
bool plusLoinNid(Place p1, Place p2){
    return (!(plusProcheNid(p1,p2)));
}

/**une fonction qui cree un nid aux coordonnee choisies
 * @param[out] une Grille
 * @param un entier x
 * @param un entier y
**/
void creerNid(Grille &g, int x, int y){
    if (dansTableau(creerCoord(x,y))){
        if (vide(g.grille[x][y])){
            g.grille[x][y].nid = true;
            g.grille[x][y].pheroNid = 1;
        }
    }
}
/**une fonction quie cree un sucre aux coordonnees choisies
 * @param un entier x
 * @param un entier y
 * @param[out] une Grille
**/
void creerSucre(int x, int y, Grille &g){
    if(dansTableau(creerCoord(x,y))){
        if(vide(g.grille[x][y])){
            g.grille[x][y].sucre = 255; 
        }
    }
}
/**une fonction qui cree une fourmi au coordonee choisies
 * @param un entier x
 * @param un entier y
 * @param[in/out] un tableau de Fourmis
 * @param[out] une Grille
 * @param un entier ind
**/
void creerFourmi(int x, int y, tabFourmis &t, Grille &g, int ind){
    if(dansTableau(creerCoord(x,y))){
        if(vide(g.grille[x][y])){
            if (ind < NOMBREFOURMI){
                g.grille[x][y].indiceFourmi = ind;
                t.tab [ind].c = g.grille[x][y].c;
            }
        }
    }
}

/** une fonction qui initialise une Grille et un tableau de Fourmis
 * @param[out] une Grille 
 * @param[out] un tableau de Fourmis
**/
void initialisation(Grille &retour, tabFourmis &t){
    //Initialisation des indices du tableau de fourmis
    for (unsigned int i = 0; i<12; i++){
        t.tab [i].indice = i+1;
        t.tab [i].sucre = 0;
    }
    //Allocation et initialisation des deux tableaux de Grilles
    retour.grille = vector<vector<Place>>(LARGEUR);
    retour.affichage = vector<vector<char>>(HAUTEUR);
    for (unsigned int i = 0; i<retour.grille.size(); i++){
        retour.grille[i] = vector<Place>(LARGEUR);
        retour.affichage[i] = vector<char>(HAUTEUR);
    }
    for (unsigned int i = 0; i<retour.grille.size(); i++){
        for (unsigned int j = 0; j<retour.grille.size(); j++){
            retour.grille[i][j].c.x = i;
            retour.grille[i][j].c.y = j;
            retour.grille[i][j].indiceFourmi = -1;
            retour.grille[i][j].sucre = 0;
            retour.grille[i][j].nid = false;
            retour.grille[i][j].pheroSucre = 0;
            retour.grille[i][j].pheroNid = 0;
        }
    }
    //Remplissage des nids
    creerNid(retour, 9, 9);
    creerNid(retour, 9, 10);
    creerNid(retour, 10, 9);
    creerNid(retour, 10, 10);
    creerNid(retour, 91, 91);
    creerNid(retour, 90, 90);
    creerNid(retour, 91, 90);
    creerNid(retour, 90, 91);
    //Remplissage des fourmis
    creerFourmi(8,8,t,retour,0);
    creerFourmi(8,9,t,retour,1);
    creerFourmi(8,10,t,retour,2);
    creerFourmi(8,11,t,retour,3);
    creerFourmi(11,8,t,retour,4);
    creerFourmi(11,9,t,retour,5);
    creerFourmi(11,10,t,retour,6);
    creerFourmi(11,11,t,retour,7);
    creerFourmi(9,8,t,retour,8);
    creerFourmi(9,11,t,retour,9);
    creerFourmi(10,8,t,retour,10);
    creerFourmi(10,11,t,retour,11);
    creerFourmi(92,92,t,retour,12);
    creerFourmi(92,91,t,retour,13);
    creerFourmi(92,90,t,retour,14);
    creerFourmi(91,92,t,retour,15);
    creerFourmi(90,92,t,retour,16);
    creerFourmi(92,89,t,retour,17);
    creerFourmi(89,92,t,retour,18);
    creerFourmi(89,89,t,retour,19);
    creerFourmi(89,90,t,retour,20);
    creerFourmi(89,91,t,retour,21);
    creerFourmi(90,89,t,retour,22);
    creerFourmi(91,89,t,retour,23);
    //Remplissage du sucre
    creerSucre(0,9,retour);
    creerSucre(18,18,retour);
}

/** une fonction qui fait correspondre le vector<vector<char>> d'une Grille avec son vector<vector<Place>> 
 * @param[in/out] une Grille g
**/
void recupAffichage(Grille &g){
    for (unsigned int i = 0; i<g.grille.size(); i++){
        for (unsigned int j = 0; j<g.grille[i].size(); j++){
            if (g.grille[i][j].indiceFourmi != -1){
                g.affichage[i][j] = 'F';
            } else if (g.grille[i][j].sucre != 0){
                g.affichage[i][j] = 'S';
            } else if (g.grille[i][j].nid == true){
                g.affichage[i][j] = 'N';
            } else if (g.grille[i][j].pheroSucre != 0){
                g.affichage[i][j] = 's';
            } else if (g.grille[i][j].pheroNid != 0){
                g.affichage[i][j] = 'n';
            } else {
                g.affichage[i][j] = ' ';
            }
        }
    }
}

/** une fonction qui affiche le vector<vector<char>> d'une Grille
 * @param une Grille g
**/
void dessinerGrille(Grille g){
    cout << "##################################################################################################################################################################" << endl;
    for (unsigned int i = 0; i<g.affichage.size(); i++){
        cout << "#";
        for (unsigned int j = 0; j<g.affichage.size(); j++){
            cout << " " << g.grille[i][j].pheroNid << " #";
        }
        cout << endl;
        cout << "##################################################################################################################################################################" << endl;
    }
}

/**une fonction qui rajoute une coordonnee a un ensemble de coordonnee
 * @param une Coord c
 * @param[out] un ensCoord ec
**/
void ajouteEnsCoord(Coord c, ensCoord &ec){
    ec.ens.push_back(c);
    ec.taille++;
}

/**une fonction qui fait décroitre les phéromones de sucres a la place p
 * @param[in/out] une place p
**/
void decroissancePheroSucre(Place &p){
    p.pheroSucre -= 5;
}

/**une fonction qui creer une Coord au point donne
 * @param un entier x
 * @param un entier y
 * @return une Coord retour
**/
Coord creerCoord(int x, int y){
    Coord retour;
    retour.x = x;
    retour.y = y;
    return retour;
}


/** une fonction qui determine tout les voisins d'une Coord c
 * @param une Coord c
 * @return un ensCoord retour de toutes les coordonnees voisins de c
**/
ensCoord trouverVoisin(Coord c){
    ensCoord retour;
    if (dansTableau(creerCoord(c.x-1,c.y))){
        ajouteEnsCoord(creerCoord(c.x-1,c.y),retour);
    }
    if (dansTableau(creerCoord(c.x+1,c.y))){
        ajouteEnsCoord(creerCoord(c.x+1,c.y),retour);
    }
    if (dansTableau(creerCoord(c.x-1,c.y-1))){
        ajouteEnsCoord(creerCoord(c.x-1,c.y-1),retour);
    }
    if (dansTableau(creerCoord(c.x,c.y-1))){
        ajouteEnsCoord(creerCoord(c.x,c.y-1),retour);
    }
    if (dansTableau(creerCoord(c.x+1,c.y-1))){
        ajouteEnsCoord(creerCoord(c.x+1,c.y-1),retour);
    }
    if (dansTableau(creerCoord(c.x-1,c.y+1))){
        ajouteEnsCoord(creerCoord(c.x-1,c.y+1),retour);
    }
    if (dansTableau(creerCoord(c.x,c.y+1))){
        ajouteEnsCoord(creerCoord(c.x,c.y+1),retour);
    }
    if (dansTableau(creerCoord(c.x+1,c.y+1))){
        ajouteEnsCoord(creerCoord(c.x+1,c.y+1),retour);
    }
    return retour;
}

/** une fonction qui return le maximum entre deux nombres
 * @param un float a
 * @param un float b
 * @return le plus grand des deux float
**/
float max(float a, float b){
    if (a>b){
        return a;
    } return b;
}

/** une fonction permettant de lineariser les Pheromones de Nid sur la grille
 * @param[out] une Grille g
**/
void linearisationPheroNid(Grille &g){
    int t = max(HAUTEUR,LARGEUR);
    for (int compteur = 0; compteur <t; compteur++){
        for (unsigned int i = 0; i<g.grille.size();i++){
            for (unsigned int j = 0; j<g.grille[i].size();j++){
                if (g.grille[i][j].pheroNid < 1){
                    ensCoord voisin = trouverVoisin(g.grille[i][j].c);
                    float m = 0;
                    for (unsigned int k = 0; k<voisin.ens.size(); k++){
                        if (g.grille[voisin.ens[k].x][voisin.ens[k].y].pheroNid>m){
                            m = g.grille[voisin.ens[k].x][voisin.ens[k].y].pheroNid;
                        }
                    }
                    g.grille[i][j].pheroNid = max((m-(1/float(t))),0.);
                }
            }
        }
    }
}

/** une fonction permettant de choisir une direction au hasard
 * @param un vector d'entiers
 * @param[out] un entier x 
 * @param[out] un entier y 
 * @return un entier direction, une direction
**/
int choixDirection(vector<int>t, int &x, int &y){
    int direction = rand()%8;
    switch(t[direction]){
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            y--;
            break;
        case 5:
            y--;
            x--;
            break;
        case 6:
            y--;
            x++;
            break;
        case 7:
            y++;
            x++;
            break;
        case 8:
            y++;
            x--;
            break;
        
        default:
            break;
    }
    return direction;
}

/**une fonction qui fait charger la fourmi avec du sucre, et depose une pheromone de sucre sur p si la fonction renvoie true
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si la fourmi cherche du sucre et que la place contient du sucre
**/
bool regle1(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (chercheSucre(f)){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(contientSucre(g.grille[x][y])){
                    g.grille[x][y].sucre-=5;
                    f.sucre++;
                    return true;
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction qui fait deposer le sucre de la fourmi dans le nid si la fonction return true
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si la fourmi peut rentrer dans le nid et que la place contienne un nid
**/
bool regle2(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (rentreNid(f)){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(contientNid(g.grille[x][y])){
                    f.sucre--;
                    return true;
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction qui fait deplacer la fourmi sur la place et depose une pheromone de sucre sur cette meme place
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si f peut rentrer dans le nid, si la place place est vide, et si la premiere place est plus proche que la 2eme ((x,y) et (f.c.x,f.c.y))
**/
bool regle3(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (rentreNid(f)){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(vide(g.grille[x][y])){
                    if(plusProcheNid(g.grille[x][y], g.grille[f.c.x][f.c.y])){
                        g.grille[x][y].indiceFourmi = f.indice;
                        g.grille[f.c.x][f.c.y].indiceFourmi = -1;
                        f.c = g.grille[x][y].c;
                        return true;
                    }
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction qui fait deplacer f sur la place si la fonction renvoie true
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si la fourmi cherche du sucre, si sur la place p1 il y a une pheromone, si p2 est vide, si p2 est plus loin du nid que p1 et que p2 aussi contient une pheromone de sucre
**/
bool regle4(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (chercheSucre(f) && surUnePiste(g.grille[f.c.x][f.c.y])){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(vide(g.grille[x][y])){
                    if(plusLoinNid(g.grille[x][y], g.grille[f.c.x][f.c.y]) && surUnePiste(g.grille[x][y])){
                        g.grille[x][y].indiceFourmi = f.indice;
                        g.grille[f.c.x][f.c.y].indiceFourmi = -1;
                        f.c = g.grille[x][y].c;
                        return true;
                    }
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction qui fait deplacer la fourmi sur la place si la fonction renvoie true
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si la fourmi cherche du sucre, si la place contient une pheromone de sucre et si la place est vide
**/
bool regle5(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (chercheSucre(f)){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(vide(g.grille[x][y])){
                    if(surUnePiste(g.grille[x][y])){
                        g.grille[x][y].indiceFourmi = f.indice;
                        g.grille[f.c.x][f.c.y].indiceFourmi = -1;
                        f.c = g.grille[x][y].c;
                        return true;
                    }
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction qui fait deplacer la fourmi sur la place si la fonction return true
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
 * @return true si la fourmi cherche du sucre et que la place est vide
**/
bool regle6(Grille &g, Fourmi &f){
    vector<int> choix = {1,2,3,4,5,6,7,8};
    vector<int> t = {0,0,0,0,0,0,0,0};
    if (chercheSucre(f)){
        while(choix != t){
            int x = f.c.x;
            int y = f.c.y;
            int direction = choixDirection(choix,x,y);
            if ( (x < HAUTEUR && x>=0) && (y<LARGEUR && y>=0)){
                if(vide(g.grille[x][y])){
                    g.grille[x][y].indiceFourmi = f.indice;
                    g.grille[f.c.x][f.c.y].indiceFourmi = -1;
                    f.c = g.grille[x][y].c;
                    return true;
                }
            }
            choix[direction] = 0;
            
        }
    }
    return false;
}

/**une fonction permettant de reduire les pheromones de sucres
 * @param[in/out] une Grille g
**/
void evaporationPheroSucre(Grille &g){
    for (unsigned int i = 0; i<g.grille.size(); i++){
        for (unsigned int j = 0; j<g.grille[i].size(); j++){
            if (surUnePiste(g.grille[i][j])){
                decroissancePheroSucre(g.grille[i][j]);
                if(g.grille[i][j].pheroSucre <0){
                    g.grille[i][j].pheroSucre = 0;
                }
            }
        }
    }
}

/**une fonction qui déplace une fourmi dans une grille
 * @param[in/out] une Grille g
 * @param[in/out] une Fourmi f
**/
void deplaceFourmi(Grille &g, Fourmi &f){
    if(!regle1(g,f)){ 
        if(!regle2(g,f)){
            if(!regle3(g,f)){
                if(!regle4(g,f)){
                    if(!regle5(g,f)){
                        if(!regle6(g,f)){
                        }
                    }
                }
            }
        }
    }
    if (rentreNid(f)){
        g.grille[f.c.x][f.c.y].pheroSucre = 255;
    }
}



