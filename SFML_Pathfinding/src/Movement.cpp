#include "Movement.h"


bool Test=true;

unsigned int next_point[2]={0,0};

Movement::Movement(){
}

int Movement::getState(){
    return state;
}

void Movement::setState(int value){
    state=value;
}

void Movement::go(char direction){
    switch (direction){
        case 'f' :  //va dans la case du haut
            commandes[0]=2;
            commandes[1]=1;
            commandes[2]=9;
            commandes[3]=9;
            break;
        case 'r':  //va dans la case de droite
            commandes[0]=3;
            commandes[1]=1;
            commandes[2]=2;
            commandes[3]=1;
            orientation -= 90;
            break;
        case 'l':   //va dans la case de gauche
            commandes[0]=4;
            commandes[1]=1;
            commandes[2]=2;
            commandes[3]=1;
            orientation += 90;
            break;
        case 'b':   //va dans la case du bas
            commandes[0]=5;
            commandes[1]=1;
            commandes[2]=2;
            commandes[3]=1;
            orientation += 180;
            break;
        }
        if (orientation > 270){
            orientation -= 360;
        }
        else if (orientation < 0){
            orientation += 360;
        }
}

int Movement::commande(int point){
    return commandes[point];
}

int Movement::getOrientation(){
    return orientation;
}

char Movement::getNextDirection(unsigned int point_courantX, unsigned int point_courantY, unsigned int next_pointX, unsigned int next_pointY){
    if (next_pointX==point_courantX+1 && next_pointY==point_courantY){  //va dans la case à droite
        switch (orientation){
            case 0 :
                return 'r';
                break;
            case 90 :
                return 'b';
                break;
            case 180 :
                return 'l';
                break;
            case 270 :
                return 'f';
                break;
            }
    }

    else if (next_pointX==point_courantX-1 && next_pointY==point_courantY){  //va dans la case à gauche
        switch (orientation){
            case 0 :
                return 'l';
                break;
            case 90 :
                return 'f';
                break;
            case 180 :
                return 'r';
                break;
            case 270 :
                return 'b';
                break;
            }
    }
    else if (next_pointX==point_courantX && next_pointY==point_courantY+1){  //va dans la case au dessus
        switch (orientation){
            case 0 :
                return 'f';
                break;
            case 90 :
                return 'r';
                break;
            case 180 :
                return 'b';
                break;
            case 270 :
                return 'l';
                break;
            }
    }
    else if (next_pointX==point_courantX && next_pointY==point_courantY-1){  //va dans la case en bas
        switch (orientation){
            case 0 :
                return 'b';
                break;
            case 90 :
                return 'l';
                break;
            case 180 :
                return 'f';
                break;
            case 270 :
                return 'r';
                break;
            }
    }
    return 'n';
}


unsigned int* Movement::getNextPosition(unsigned int point_courantX, unsigned int point_courantY, char direction){

    next_point[0]=point_courantX;
    next_point[1]=point_courantY;

    if (direction=='f'){
        switch (orientation){
            case 0 :
                next_point[1]++; //va dans la case à droite
                break;
            case 90 :
                next_point[0]--; //va dans la case au dessus
                break;
            case 180 :
                next_point[1]--; ///va dans la case à gauche
                break;
            case 270 :
                next_point[0]++; //va dans la case en bas
                break;
            }
    }
    else if (direction=='l'){
        switch (orientation){
            case 0 :
                next_point[0]--; //va dans la case au dessus
                break;
            case 90 :
                next_point[1]--; ///va dans la case à gauche
                break;
            case 180 :
                next_point[0]++; //va dans la case en bas
                break;
            case 270 :
                next_point[1]++; //va dans la case à droite
                break;
                    }
    }

    else if (direction=='r'){
        switch (orientation){
            case 0 :
                next_point[0]++; //va dans la case en bas
                break;
            case 90 :
                next_point[1]++; //va dans la case à droite
                break;
            case 180 :
                next_point[0]--; //va dans la case au dessus
                break;
            case 270 :
                next_point[1]--; ///va dans la case à gauche
                break;
                    }
    }

    else if (direction=='b'){
        switch (orientation){
            case 0 :
                next_point[1]--; ///va dans la case à gauche
                break;
            case 90 :
                next_point[0]++; //va dans la case en bas
                break;
            case 180 :
                next_point[1]++; //va dans la case à droite
                break;
            case 270 :
                next_point[0]--; //va dans la case au dessus
                break;
                    }
    }


    return next_point;
}
