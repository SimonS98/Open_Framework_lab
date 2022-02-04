//
//  bird.hpp
//  Boids_2_2
//
//  Created by Simon Sheng on 2022/2/4.
//

#ifndef bird_hpp
#define bird_hpp

#include <stdio.h>
#include <boid.h>



class Bird : public Boid
{

    
public:
//this is a new constructor for our derived Babies class
 

//here in the new class's header file we announce that we are
//going to change what the inherited draw() function does
    void draw();
    
};
#endif /* bird_hpp */
