To understand the code, here is what the context :

I want to simulate the behavior of a robot. Its goal is to reach the center of the maze (10,10 in the scheme "path.png") as fast as possible. But the maze is unknown so in order to do that, the robot needs in a first time to do an exploration phase : go through the maze, memorize the walls around it, find the center and come back in the initial point (1,1).
This code simulate this exploration phase. The results are in the scheme "path.png". The idea is to use the algorithm "AStar" (or A*) to know where the robot should go next.
Using this method, the robot will get closer and closer to the center memorizing all the walls in the path. To be sure that a shorter path does not exist, the same methode will be used to go back to the initial point (state=2 in the code)

I hope this is quite clear, I am really sorry because my code is messy and unnecessary complex but if you have any question you can send me an email at "vincent.daniele7@gmail.com" for a fast response, or a private message on Reddit.

Thanks you a lot for looking at my code
