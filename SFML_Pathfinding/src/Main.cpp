#include <iostream>
#include "AStar.hpp"
using namespace AStar;
#include "Cartographie.h"
#include "Movement.h"

using namespace std;

int orientation;
int state=1;
unsigned int* position_temp;

//simulate the sensors :
// 0 = no walls
// 2 = wall left
// 3 = wall right
// 4 = wall left and right
// 5 = wall front and left
// 6 = wall front and right
// 7 = wall front and left and right

int sensors[137]={2,4,5,4,4,4,4,4,6,4, //10
                          4,4,2,4,6,4,4,4,0,4,
                          5,4,6,4,6,4,5,4,5,4,
                          3,4,3,4,2,4,5,4,6,4,
                          6,4,2,2,0,0,1,5,2,6,
                          3,6,3,6,3,3,4,5,4,5,
                          4,6,4,1,4,5,4,6,4,5,
                          4,3,4,7,4,2,4,6,4,5,
                          4,6,4,4,4,6,4,4,4,3,
                          4,2,4,7,4,3,4,1,4,4,
                          4,4,4,4,4,4,4,6,4,3,
                          4,4,4,4,4,4,4,3,4,0,
                          4,4,4,5,4,3,4,4,4,5,
                          4,4,4,4,4,6,4};


int main()
{
int count=0;
Vec2i final_point;  //point we aim to reach : center of the Maze
Vec2i current_point; // current point during the simulation
Vec2i point_aux;
Vec2i rightWall;
Vec2i leftWall;
Vec2i frontWall;
Generator generator;    //used to compute A* algorithm
Movement move;
Cartographie Maze(&generator);  //use to "memorise" walls


    final_point.x = 10;
    final_point.y = 10;

    current_point.x = 1;
    current_point.y = 1;


	while (count<138)
	{
            //if (count<138)
    std::cout << "Current point : " <<  current_point.x << " " << current_point.y << "\n";

        if (state==1){  //first state : aim the center of the maze
            final_point.x = 10;
            final_point.y = 10;
        }

        else if (state==2){ // second state : after reaching the center,
                            // we go back to the inital point
            final_point.x = 1;
            final_point.y = 1;
        }

        if ((current_point.x != final_point.x)||(current_point.y != final_point.y)){
            //while the final point is not reached :

                orientation=move.getOrientation();  //get the orientation of
                //the robot : 0 when it looks to the right (because we make it
                //start looking at the right)

                //deduce from the orientation where is the "right" "left"
                //and "front" of the robot
                if (orientation==90){
                rightWall.x = current_point.x;
    			rightWall.y = current_point.y + 1;
    			frontWall.x = current_point.x - 1;
    			frontWall.y = current_point.y;
    			leftWall.x = current_point.x;
    			leftWall.y = current_point.y - 1;
                }

                if (orientation==180){
                rightWall.x = current_point.x - 1;
    			rightWall.y = current_point.y;
    			frontWall.x = current_point.x ;
    			frontWall.y = current_point.y - 1;
    			leftWall.x = current_point.x + 1;
    			leftWall.y = current_point.y;
                }

                if (orientation==270){
                rightWall.x = current_point.x;
                rightWall.y = current_point.y - 1;
                frontWall.x = current_point.x + 1;
                frontWall.y = current_point.y;
                leftWall.x = current_point.x;
                leftWall.y = current_point.y + 1;
                }

                if (orientation==0){
                rightWall.x = current_point.x + 1;
                rightWall.y = current_point.y;
                frontWall.x = current_point.x;
                frontWall.y = current_point.y + 1;
                leftWall.x = current_point.x - 1;
                leftWall.y = current_point.y;
                }

                //add walls and move depending on the sensors value
                if (sensors[count]==4)
                        {
                            Maze.addWall(leftWall);
                            Maze.addWall(rightWall);


                            //update current point depending on the next
                            //movement
                            position_temp=move.getNextPosition(current_point.x, current_point.y,'f');
                            current_point.x = position_temp[0];
                            current_point.y = position_temp[1];

                            move.go('f');   //go forward
                        }

            else if (sensors[count]==6)
                        {

                            Maze.addWall(rightWall);
                            Maze.addWall(frontWall);

                            position_temp=move.getNextPosition(current_point.x, current_point.y,'l');
                            current_point.x = position_temp[0];
                            current_point.y = position_temp[1];

                            move.go('l');   //go left
                        }

            else if (sensors[count]==5)
                        {
                            Maze.addWall(leftWall);
                            Maze.addWall(frontWall);

                            position_temp=move.getNextPosition(current_point.x, current_point.y,'r');
                            current_point.x = position_temp[0];
                            current_point.y = position_temp[1];

                            move.go('r');      //go right
                        }

            else if (sensors[count]==7)
                        {
                            Maze.addWall(leftWall); //gauche
                            Maze.addWall(frontWall); //face
                            Maze.addWall(rightWall); //droite

                            position_temp=move.getNextPosition(current_point.x, current_point.y,'b');
                            current_point.x = position_temp[0];
                            current_point.y = position_temp[1];

                            move.go('b');   //go down
                        }


            else        //we use A* to know the following direction
                        {

                            if (sensors[count]==2)
                                Maze.addWall(leftWall); //gauche
                            else if (sensors[count]==3)
                                Maze.addWall(rightWall); //droite
                            else if (sensors[count]==1)
                                Maze.addWall(frontWall); //face



                            //using A*
                            auto path = generator.findPath(final_point,current_point);


                            //get the next point to go
                            point_aux=path[1];
                            //deduce from this point the direction to go
                            char nextDirection = move.getNextDirection(current_point.x,current_point.y,point_aux.x,point_aux.y);
                            move.go(nextDirection);

                            current_point=point_aux;
                        }
                }

                else
                    //if the center is reached, we aim the initial point
                    state=2;

                count++;


    }      //end while
	return 0;
}
