#pragma once
#ifndef __Player_h_
#define __Player_h_
#include "MovingObject.h"
#include <OISKeyboard.h>
class Camera;
class Player :
	public MovingObject
{
protected:
    OIS::Keyboard* mKeyboard;
	static Player* me;
public:
	static Player* getPlayer();
	void Init(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity,OIS::Keyboard* keyboard);
	Player(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity);
	~Player(void);
	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBackward();
	void jump();
	void update(double a);
};
#endif

#include "Camera.h"
