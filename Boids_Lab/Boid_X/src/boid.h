/*

 *
 */

#ifndef _BOID
#define _BOID
#include <vector>
#include "ofMain.h"


class Boid
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:	
	ofVec3f position;
	ofVec3f velocity;
    ofVec3f Color;
	
	float separationWeight;
	float cohesionWeight;
	float alignmentWeight;
    float groupSepWeight;
	
	float separationThreshold;
	float neighbourhoodSize;
    float groupDetect;
	
	ofVec3f separation(std::vector<Boid *> &otherBoids);
	ofVec3f cohesion(std::vector<Boid *> &otherBoids);
	ofVec3f alignment(std::vector<Boid *> &otherBoids);

	
// all the methods and variables after the
// public keyword can only be used by anyone
public:	
	Boid();
	Boid(ofVec3f &pos, ofVec3f &vel);
    ofVec3f groupSep(std::vector<Boid *> &otherBoids);
	~Boid();
	
	ofVec3f getPosition();
	ofVec3f getVelocity();
    ofVec3f getBird();
    ofVec3f setVelocity(float x,float  y);
	
	
	float getSeparationWeight();
	float getCohesionWeight();
	float getAlignmentWeight();
	
	float getSeparationThreshold();
	float getNeighbourhoodSize();
	
	void setSeparationWeight(float f);
	void setCohesionWeight(float f);
	void setAlignmentWeight(float f);
	
	void setSeparationThreshold(float f);
	void setNeighbourhoodSize(float f);
	
	void update(std::vector<Boid *> &otherBoids,std::vector<Boid *> &otherBirds, ofVec3f &min, ofVec3f &max);
	
	void walls(ofVec3f &min, ofVec3f &max);
	
    virtual void draw();

};





#endif
