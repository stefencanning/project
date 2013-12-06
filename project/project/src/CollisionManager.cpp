#include "CollisionManager.h"


CollisionManager::CollisionManager(void)
{
}


CollisionManager::~CollisionManager(void)
{
}

	static Ogre::Vector3 edgeA,edgeB,axis;
	static CollissionReturn colReturn(true,LONG_MAX,Ogre::Vector3());
	static int sideA, sideB, i;
	static Ogre::Vector3 edgeOne, edgeTwo;
	static double temporaryValue, minA, maxA ,minB, maxB;
	static CollissionReturn colCheckReturn(true,0,Ogre::Vector3());

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

CollissionReturn CollisionManager::CheckSAT(BaseObject* a, BaseObject* b)
{ 
	colReturn = CollissionReturn(true,LONG_MAX,Ogre::Vector3(0,0,0));
	//*
	CheckAxis(a,b,b->lastAxis);
	if(!colCheckReturn.m_boolean)
	{
		a->lastAxis = colCheckReturn.m_axis;
		b->lastAxis = colCheckReturn.m_axis;
		return colCheckReturn;
	}
	else
	{
		if(abs(colCheckReturn.m_distance)<abs(colReturn.m_distance))
		{
			colReturn = colCheckReturn;
		}
	}
	CheckAxis(a,b,a->lastAxis);
	if(!colCheckReturn.m_boolean)
	{
		a->lastAxis = colCheckReturn.m_axis;
		b->lastAxis = colCheckReturn.m_axis;
		return colCheckReturn;
	}
	else
	{
		if(abs(colCheckReturn.m_distance)<abs(colReturn.m_distance))
		{
			colReturn = colCheckReturn;
		}
	}
	//*/
	double tmp;
	
	int lengthA = a->getPoints().size();
	if (lengthA%2 == 0)
	{
		lengthA /= 2;
	}
	int lengthB = b->getPoints().size();
	if (lengthB%2 == 0)
	{
		lengthB /= 2;
	}
	for(sideA = 0; sideA < lengthA; sideA++)
	{
		edgeA.x = a->getPoints()[sideA+1].x - a->getPoints()[sideA].x;
		edgeA.y = a->getPoints()[sideA+1].y - a->getPoints()[sideA].y;
		edgeA.z = a->getPoints()[sideA+1].z - a->getPoints()[sideA].z;
		
		for(sideB = 0; sideB<lengthB;sideB++)
		{
			edgeB.x = b->getPoints()[sideB+1].x - a->getPoints()[sideB].x;
			edgeB.y = b->getPoints()[sideB+1].y - a->getPoints()[sideB].y;
			edgeB.z = b->getPoints()[sideB+1].z - a->getPoints()[sideB].z;


			axis.x = ((edgeA.y * edgeB.z) - (edgeA.z * edgeB.y));
			axis.y = ((edgeA.z * edgeB.x) - (edgeA.x * edgeB.z));
			axis.z = ((edgeA.x * edgeB.y) - (edgeA.y * edgeB.x));
			tmp = sqrt((axis.x * axis.x) + (axis.y * axis.y) + (axis.z * axis.z));
			axis.x /= tmp;
			axis.y /= tmp;
			axis.z /= tmp;
			CheckAxis(a,b,axis);
			if(!colCheckReturn.m_boolean)
			{
		a->lastAxis = colCheckReturn.m_axis;
		b->lastAxis = colCheckReturn.m_axis;
				return colCheckReturn;
			}
			else
			{
				if(abs(colCheckReturn.m_distance)<abs(colReturn.m_distance))
				{
					colReturn = colCheckReturn;
				}
			}
		}
	}
	for(i = 0; i < lengthA; i++)
	{
		edgeOne.x = a->getPoints()[i+1].x - a->getPoints()[i].x;
		edgeOne.y = a->getPoints()[i+1].y - a->getPoints()[i].y;
		edgeOne.z = a->getPoints()[i+1].z - a->getPoints()[i].z;

		edgeTwo.x = a->getPoints()[i+2].x - a->getPoints()[i+1].x;
		edgeTwo.y = a->getPoints()[i+2].y - a->getPoints()[i+1].y;
		edgeTwo.z = a->getPoints()[i+2].z - a->getPoints()[i+1].z;

		axis.x = ((edgeOne.y * edgeTwo.z) - (edgeOne.z * edgeTwo.y));
		axis.y = ((edgeOne.z * edgeTwo.x) - (edgeOne.x * edgeTwo.z));
		axis.z = ((edgeOne.x * edgeTwo.y) - (edgeOne.y * edgeTwo.x));
		tmp = sqrt((axis.x * axis.x) + (axis.y * axis.y) + (axis.z * axis.z));
		axis.x /= tmp;
		axis.y /= tmp;
		axis.z /= tmp;
			CheckAxis(a,b,axis);
			if(!colCheckReturn.m_boolean)
			{
		a->lastAxis = colCheckReturn.m_axis;
		b->lastAxis = colCheckReturn.m_axis;
				return colCheckReturn;
			}
			else
			{
				if(abs(colCheckReturn.m_distance)<abs(colReturn.m_distance))
				{
					colReturn = colCheckReturn;
				}
			}
	}

	for(i = 0; i < lengthB; i++)
	{
		edgeOne.x = b->getPoints()[i+1].x - b->getPoints()[i].x;
		edgeOne.y = b->getPoints()[i+1].y - b->getPoints()[i].y;
		edgeOne.z = b->getPoints()[i+1].z - b->getPoints()[i].z;

		edgeTwo.x = b->getPoints()[i+2].x - b->getPoints()[i+1].x;
		edgeTwo.y = b->getPoints()[i+2].y - b->getPoints()[i+1].y;
		edgeTwo.z = b->getPoints()[i+2].z - b->getPoints()[i+1].z;

		axis.x = ((edgeOne.y * edgeTwo.z) - (edgeOne.z * edgeTwo.y));
		axis.y = ((edgeOne.z * edgeTwo.x) - (edgeOne.x * edgeTwo.z));
		axis.z = ((edgeOne.x * edgeTwo.y) - (edgeOne.y * edgeTwo.x));
		tmp = sqrt((axis.x * axis.x) + (axis.y * axis.y) + (axis.z * axis.z));
		axis.x /= tmp;
		axis.y /= tmp;
		axis.z /= tmp;
			CheckAxis(a,b,axis);
			if(!colCheckReturn.m_boolean)
			{
		a->lastAxis = colCheckReturn.m_axis;
		b->lastAxis = colCheckReturn.m_axis;
				return colCheckReturn;
			}
			else
			{
				if(abs(colCheckReturn.m_distance)<abs(colReturn.m_distance))
				{
					colReturn = colCheckReturn;
				}
			}
	}


	return colReturn;
}

void CollisionManager::CheckAxis(BaseObject* a, BaseObject* b, Ogre::Vector3 axis)
{
	colCheckReturn = CollissionReturn(true,0,Ogre::Vector3(0,1,0));
	minA = maxA = (a->getPoints()[0].x * axis.x) + (a->getPoints()[0].y * axis.y) + (a->getPoints()[0].z * axis.z);
	int length = a->getPoints().size();
	for (int i = 1; i < length; i++)
	{
		temporaryValue = (a->getPoints()[i].x * axis.x) + (a->getPoints()[i].y * axis.y) + (a->getPoints()[i].z * axis.z);
		if(temporaryValue>maxA)
		{
			maxA = temporaryValue;
		}
		else if(temporaryValue<minA)
		{
			minA = temporaryValue;
		}
	}
	temporaryValue = (a->getPosition().x * axis.x) + (a->getPosition().y * axis.y) + (a->getPosition().z * axis.z);
	minA += temporaryValue;
	maxA += temporaryValue;
	
	minB = maxB = (b->getPoints()[0].x * axis.x) + (b->getPoints()[0].y * axis.y)+(b->getPoints()[0].z * axis.z);
	length = b->getPoints().size();
	for (int i = 1; i < length; i++)
	{
		temporaryValue = (b->getPoints()[i].x * axis.x) + (b->getPoints()[i].y * axis.y) + (b->getPoints()[i].z * axis.z);
		if(temporaryValue>maxB)
		{
			maxB = temporaryValue;
		}
		else if(temporaryValue<minB)
		{
			minB = temporaryValue;
		}
	}
	temporaryValue = (b->getPosition().x * axis.x) + (b->getPosition().y * axis.y) + (b->getPosition().z * axis.z);
	minB += temporaryValue;
	maxB += temporaryValue;

	if(maxA < minB || minA > maxB)
	{
		colCheckReturn.m_boolean = false;
	}
	else
	{
		colCheckReturn.m_axis = axis;
		if( abs(maxA - minB)<abs(maxB - minA))
		{
			colCheckReturn.m_distance = maxA - minB;
		}
		else
		{
			colCheckReturn.m_distance = maxB - minA;
		}
	}
}


void CollisionManager::CollissionMove(MovingObject* a, BaseObject* b, CollissionReturn cr)
{
		double centerA, centerB;
		centerA = (a->getPosition().x * cr.m_axis.x) + (a->getPosition().y * cr.m_axis.y) + (a->getPosition().z * cr.m_axis.z);
		centerB = (b->getPosition().x * cr.m_axis.x) + (b->getPosition().y * cr.m_axis.y) + (b->getPosition().z * cr.m_axis.z);
		if( centerB-centerA > 0)
		{
			cr.m_distance = -(abs(cr.m_distance)+0.1f);
		}
		else
		{
			cr.m_distance += 0.1f;
		}
		Ogre::Vector3 v((cr.m_axis.x*cr.m_distance),(cr.m_axis.y*cr.m_distance),(cr.m_axis.z*cr.m_distance));
		a->setPosition(a->getPosition() + v);
		int temp = 1;
		if( centerB-centerA < 0)
		{
			temp = -1;
		}
		a->setVelocity(temp*0.7*cr.m_axis*a->getVelocity());
}