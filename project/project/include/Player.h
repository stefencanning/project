#pragma once
#include "MovingObject.h"
#include <OISKeyboard.h>

class Player :
	public MovingObject
{
protected:
    OIS::Keyboard* mKeyboard;
public:
	Player(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity,OIS::Keyboard* keyboard);
	~Player(void);
	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackward();
	void jump();
	void update(double );
};
