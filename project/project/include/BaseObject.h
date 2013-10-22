#pragma once
#ifndef __BaseObject_h_
#define __BaseObject_h_
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <vector>
using namespace std;
class BaseObject
{
protected:
	Ogre::Vector3 m_position;
	Ogre::SceneNode *m_object;
	vector<Ogre::Vector3> m_collisionPoints;

public:
	BaseObject(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints);
	~BaseObject(void);
	Ogre::SceneNode* getNode();
	Ogre::Vector3 getPosition();
	vector<Ogre::Vector3> getPoints();
	void setPosition(Ogre::Vector3);
	virtual void update(double );
};

#endif