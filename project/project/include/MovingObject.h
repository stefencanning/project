#pragma once
#include "BaseObject.h"
class MovingObject :
	public BaseObject
{
protected:
	Ogre::Vector3 m_velocity;
public:
	MovingObject(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity);
	~MovingObject(void);
	void setVelocity(Ogre::Vector3);
	Ogre::Vector3 getVelocity();
	void update(double );
};

