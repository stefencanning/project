#include "CollisionManager.h"


CollisionManager::CollisionManager(void)
{
}


CollisionManager::~CollisionManager(void)
{
}


bool CollisionManager::CheckCollision(BaseObject*obj1, BaseObject* obj2)
{
	int length1 = obj1->getPoints().size();
	int length2 = obj2->getPoints().size();
	Ogre::Vector3 pos1 = obj1->getPosition();
	Ogre::Vector3 pos2 = obj2->getPosition();
	for(int i = 0; i < length1; i++)
	{
		if(pos1.x+obj1->getPoints()[i].x >= pos2.x+obj2->getPoints()[0].x && pos1.y+obj1->getPoints()[i].y >= pos2.y+obj2->getPoints()[0].y && pos1.z+obj1->getPoints()[i].z >= pos2.z+obj2->getPoints()[0].z)
		{
			if(pos1.x+obj1->getPoints()[i].x <= pos2.x+obj2->getPoints()[5].x && pos1.y+obj1->getPoints()[i].y <= pos2.y+obj2->getPoints()[5].y && pos1.z+obj1->getPoints()[i].z <= pos2.z+obj2->getPoints()[5].z)
			{
				obj1->setPosition(Ogre::Vector3(obj1->getPosition().x,obj2->getPosition().y+obj2->getPoints()[5].y-obj1->getPoints()[i].y,obj1->getPosition().z));
				((MovingObject*)obj1)->setVelocity(Ogre::Vector3((((MovingObject*)obj1)->getVelocity().x*0.7),-(((MovingObject*)obj1)->getVelocity().y*0.7),(((MovingObject*)obj1)->getVelocity().z*0.7)));
				return true;
			}
		}
	}
	return false;
}