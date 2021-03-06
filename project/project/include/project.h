/*
-----------------------------------------------------------------------------
Filename:    project.h
-----------------------------------------------------------------------------


This source file is generated by the
   ___                   _              __    __ _                  _ 
  /___\__ _ _ __ ___    /_\  _ __  _ __/ / /\ \ (_)______ _ _ __ __| |
 //  // _` | '__/ _ \  //_\\| '_ \| '_ \ \/  \/ / |_  / _` | '__/ _` |
/ \_// (_| | | |  __/ /  _  \ |_) | |_) \  /\  /| |/ / (_| | | | (_| |
\___/ \__, |_|  \___| \_/ \_/ .__/| .__/ \/  \/ |_/___\__,_|_|  \__,_|
      |___/                 |_|   |_|                                 
      Ogre 1.7.x Application Wizard for VC10 (July 2011)
      http://code.google.com/p/ogreappwizards/
-----------------------------------------------------------------------------
*/
#ifndef __project_h_
#define __project_h_

#include "BaseApplication.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif


class project : public BaseApplication
{
public:
    project(void);
    virtual ~project(void);

protected:
    virtual void createScene(void);
	void CreatePlatform(Ogre::Vector3 position, Ogre::Vector3 scale);
	void CreatePlayer(Ogre::Vector3 position, Ogre::Vector3 scale);
	void CreateEnemy(Ogre::Vector3 position, Ogre::Vector3 scale);
	void CreateGoal(Ogre::Vector3 position, Ogre::Vector3 scale);
};

#endif // #ifndef __project_h_
