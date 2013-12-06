#pragma once
#ifndef __Camera_h_
#define __Camera_h_
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreSceneNode.h>
#include <OISKeyboard.h>
#include <math.h>
class Camera
{
public:
	Camera();
	~Camera(void);
	void Update();
	Ogre::SceneNode* getNode();
	void setPosition(Ogre::Vector3 vec);
	void changePos(Ogre::Vector3 vec);
	float topDownDist();
	void Initiate(Ogre::Camera* cam, Ogre::SceneNode* node, OIS::Keyboard* keyboard);
	static Camera* getCam();
	Ogre::Vector3 getPosition();
private:
	Ogre::Camera* mCamera;
	Ogre::SceneNode* mNode;
	Ogre::Vector3 posAround;
	OIS::Keyboard* mKeyboard;
	int minDist;
	int maxDist;
	Ogre::Vector3 around;
	float dist;
	static Camera* cam;
	double rotSpeed;
};
#endif

