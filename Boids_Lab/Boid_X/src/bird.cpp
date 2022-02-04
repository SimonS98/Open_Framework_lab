//
//  bird.cpp
//  Boids_2_2
//
//  Created by Simon Sheng on 2022/2/4.
//

#include "bird.hpp"




void Bird::draw()
{
    //ofSetColor(255-getPosition().x/3, 255-getPosition().y/4, getPosition().x*getPosition().y/1200);
    //ofSetColor(138, 3, 3);
    ofSetColor(140, 140, 140);
    
    
    /*
    //just dots
    ofCircle(getPosition().x, getPosition().y, 5);
    
    //triangle
    ofVec3f plusSpeed=getVelocity();
    if(getVelocity().x>0||getVelocity().y>0)
    {
        plusSpeed.x = getVelocity().x;
    }
    else if(getVelocity().x<0||getVelocity().y<0)
    {
        plusSpeed.x = getVelocity().x*2.5;
        plusSpeed.y = getVelocity().y*2.5;

    }
    //ofTriangle(getPosition().x+plusSpeed.x*2.2,getPosition().y+plusSpeed.y*2.2,getPosition().x+cos(60.0)*15,getPosition().y+sin(60.0)*15,getPosition().x+sin(60.0)*15,getPosition().y+cos(60.0)*15);
    
    //butterfly effect
    //ofTriangle(getPosition().x,getPosition().y,getPosition().x+cos(ofRandom(55.0, 60.0))*20,getPosition().y+sin(ofRandom(55.0, 60.0))*20,getPosition().x+sin(ofRandom(55.0, 60.0))*20,getPosition().y+cos(ofRandom(55.0, 60.0))*20);
    */
    
    
    
    
    ofCircle(getPosition().x, getPosition().y, 5);
    
    //triangle
    ofVec3f plusSpeed=getVelocity();
    if(getVelocity().x>0||getVelocity().y>0)
    {
        plusSpeed.x = getVelocity().x;
    }
    else if(getVelocity().x<0||getVelocity().y<0)
    {
        plusSpeed.x = getVelocity().x*2.5;
        plusSpeed.y = getVelocity().y*2.5;

    }

    ofTriangle(getPosition().x,getPosition().y,getPosition().x+cos(60.0)*15-plusSpeed.x*2.2,getPosition().y+sin(60.0)*15-plusSpeed.y*2.2,getPosition().x+sin(60.0)*15-plusSpeed.x*2.2,getPosition().y+cos(60.0)*15-plusSpeed.y*2.2);
     
}
