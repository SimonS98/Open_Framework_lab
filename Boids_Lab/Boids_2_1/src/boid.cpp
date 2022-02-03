/*
 *  boid.cpp
 *  boids
 *
 *  Created by Marco Gillies on 05/10/2010.
 *  Copyright 2010 Goldsmiths, University of London. All rights reserved.
 *
 */

#include "boid.h"
#include "ofMain.h"


Boid::Boid()
{
	separationWeight = 1.0f;
	cohesionWeight = 0.4f;
	alignmentWeight = 0.1f;
	
	separationThreshold = 20;
	neighbourhoodSize = 100;
	
	position = ofVec3f(ofRandom(0, 20), ofRandom(0, 20));
	velocity = ofVec3f(ofRandom(-10, 1), ofRandom(-10, 1));
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
	separationWeight = 1.0f;
	cohesionWeight = 0.3f;
	alignmentWeight = 0.2f;
	
	separationThreshold = 20;
	neighbourhoodSize = 100;
	
	position = pos;
	velocity = vel;
}

Boid::~Boid()
{
	
}

float Boid::getSeparationWeight()
{
	return separationWeight;
}
float Boid::getCohesionWeight()
{
	return cohesionWeight;
}

float Boid::getAlignmentWeight()
{
	return alignmentWeight;
}


float Boid::getSeparationThreshold()
{
	return separationThreshold;
}

float Boid::getNeighbourhoodSize()
{
	return neighbourhoodSize;
}


void Boid::setSeparationWeight(float f)
{
	separationWeight = f;
}
void Boid::setCohesionWeight(float f)
{
	cohesionWeight = f;
}

void Boid::setAlignmentWeight(float f)
{
	alignmentWeight = f;
}


void Boid::setSeparationThreshold(float f)
{
	separationThreshold = f;
}

void Boid::setNeighbourhoodSize(float f)
{
	neighbourhoodSize = f;
}


ofVec3f Boid::getPosition()
{
	return position;
}

ofVec3f Boid::getVelocity()
{
	return velocity;
}

ofVec3f Boid::setVelocity(float x,float  y)
{
    velocity=ofVec3f(ofRandom(-x, y), ofRandom(-x, y));
}

ofVec3f Boid::separation(std::vector<Boid *> &otherBoids)
{
	// finds the first collision and avoids that
	// should probably find the nearest one
	// can you figure out how to do that?
	for (int i = 0; i < otherBoids.size(); i++)
	{	
		if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
		{
			ofVec3f v = position -  otherBoids[i]->getPosition();
			v.normalize();
			return v;
		}
	}
}


ofVec3f Boid::cohesion(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getPosition();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - position;
	v.normalize();
	return v;
}

ofVec3f Boid::alignment(std::vector<Boid *> &otherBoids)
{
	ofVec3f average(0,0,0);
	int count = 0;
	for (int i = 0; i < otherBoids.size(); i++)
	{
		if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
		{
			average += otherBoids[i]->getVelocity();
			count += 1;
		}
	}
	average /= count;
	ofVec3f v =  average - velocity;
	v.normalize();
	return v;
}

void Boid::update(std::vector<Boid *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
	velocity += separationWeight*separation(otherBoids);
	velocity += cohesionWeight*cohesion(otherBoids);
	velocity += alignmentWeight*alignment(otherBoids);
	
	walls(min, max);
	position += velocity;
}

void Boid::walls(ofVec3f &min, ofVec3f &max)
{
	if (position.x < min.x){
		position.x = max.x;
		velocity.x *= 0.1;
	} else if (position.x > max.x){
		position.x = min.x;
		velocity.x *= 0.1;
	}
	
	if (position.y < min.y){
		position.y = max.y;
		velocity.y *= 0.1;
	} else if (position.y > max.y){
		position.y = min.y;
		velocity.y *= 0.1;
	}
	
	
}

void Boid::drawboids()
{
	ofSetColor(255-position.y/3, 255-position.x/4, position.x*position.y/1200);
	
    //just dots
    ofCircle(position.x, position.y, 5);
    
    //triangle
    ofTriangle(position.x,position.y,position.x+cos(60.0)*15,position.y+sin(60.0)*15,position.x+sin(60.0)*15,position.y+cos(60.0)*15);
}
void Boid::drawbirds()
{
    ofSetColor(255-position.x/4, 255-position.y/3, position.x*position.y/1200);
    
    //just dots
    //ofCircle(position.x, position.y, 10);
    
    //triangle
    ofTriangle(position.x+velocity.x*2.2,position.y+velocity.y*2.2,position.x+cos(60.0)*15,position.y+sin(60.0)*15,position.x+sin(60.0)*15,position.y+cos(60.0)*15);
    
    //butterfly effect
    //ofTriangle(position.x,position.y,position.x+cos(ofRandom(55.0, 60.0))*20,position.y+sin(ofRandom(55.0, 60.0))*20,position.x+sin(ofRandom(55.0, 60.0))*20,position.y+cos(ofRandom(55.0, 60.0))*20);

}
