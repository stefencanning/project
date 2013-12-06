#include "Goal.h"




Goal::Goal(Ogre::SceneNode* node, Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 start)
	: BaseObject(node,position,collisionPoints,CONSTANT_VALUES::GOAL),mStart(start)
{
}

Goal::~Goal(void)
{
}

Ogre::Vector3 Goal::getStart(){
	return mStart;
}
