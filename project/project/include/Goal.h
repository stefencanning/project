#pragma once
#ifndef __Goal_h_
#define __Goal_h_

#include "BaseObject.h"
#include <OgreEntity.h>
#include <OgreSceneNode.h>

class Goal  : public BaseObject
{
public:
	Goal(Ogre::SceneNode* node, Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 start);
	~Goal(void);
	Ogre::Vector3 getStart();
private:
	Ogre::Vector3 mStart;
};

#endif

