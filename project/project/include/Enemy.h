#pragma once
#ifndef __Enemy_h_
#define __Enemy_h_

#include "MovingObject.h"
class Player;
class Enemy: public MovingObject{
protected:
	bool isAgressive;
	bool isAlive;
public:
	Enemy(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints,Ogre::Vector3 velocity);
	~Enemy(void);
	void update(double);
	void calculateDistance(Ogre::Vector3);
	void attackPlayer(Ogre::Vector3);
};
#endif
#include "Player.h"