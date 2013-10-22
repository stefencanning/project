#pragma once
#ifndef __CollisionManager_h_
#define __CollisionManager_h_
#include "BaseApplication.h"
#include "BaseObject.h"

class CollisionManager
{
public:
	CollisionManager(void);
	~CollisionManager(void);
	static bool CheckCollision(BaseObject* obj1, BaseObject* obj2);
};

#endif
