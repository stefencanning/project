#pragma once
#ifndef __CollisionManager_h_
#define __CollisionManager_h_
#include "BaseApplication.h"
#include "BaseObject.h"
#include "CollissionReturn.h"

class CollisionManager
{
protected:
	static void CheckAxis(BaseObject* a, BaseObject* b, Ogre::Vector3 axis);
public:
	CollisionManager(void);
	~CollisionManager(void);
	static bool CheckCollision(BaseObject* obj1, BaseObject* obj2);
	static CollissionReturn CheckSAT(BaseObject* a, BaseObject* b);
	static void CollissionMove(MovingObject* a, BaseObject* b, CollissionReturn cr);
	
};

#endif
