#ifndef MOVEMENT_H
#define MOVEMENT_H


class Movement {
public:
    // Constructeur
    Movement();

    //récupère l'état des moteurs
    int getState();

    //met à jour l'état des moteurs
    void setState(int value);

    //met à jour le tableau de commande
    void go(char direction);
    //'f' pour tout droit (forward)
    //'l' pour left (à gauche)
    //'r' pour right (à droite)
    //'b' pour backward (demi tour)

    //renvoie la valeur du tableau à "point"
    int commande(int point);

    //récupère la position courante
    int getOrientation();

    // Stop
    void stop();

    //va tout droit pendant "distance" mm à "vitesse" en rad/s
    void forward();

    //Tourne de "theta" rad vers la droite à "vitesse" en rad/s
    void turnRight();

    //Tourne de "theta" rad vers la gauche à "vitesse" en rad/s
    void turnLeft();

    //Tourne de 180° vers la gauche
    void demiTour();

    //se déplace en fonction du résultat de AStar
    char getNextDirection(unsigned int point_courantX, unsigned int point_courantY, unsigned int point_suivantX, unsigned int point_suivantY);

    //trouve la nouvelle position en fonction du déplacement
    unsigned int* getNextPosition(unsigned int point_courantX, unsigned int point_courantY, char direction);


private:
    int state=0;
    int commandes[4]={9,9,9,9};
    int orientation=0;
    float proportionnalRatioLeft=1;
    float proportionnalRatioRight=1;
};

#endif
