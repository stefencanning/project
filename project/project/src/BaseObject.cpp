#include "BaseObject.h"


BaseObject::BaseObject(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints,int type)
	:m_object(node),
	m_position(position),
	m_collisionPoints(collisionPoints),
	lastAxis(1,0,0),
	m_type(type),
	m_radius(0)
{
	for(int i = 0; i < m_collisionPoints.size(); i++)
	{
		if(m_collisionPoints[i].length() > m_radius)
		{
			m_radius=m_collisionPoints[i].length();
		}
	}
}


BaseObject::~BaseObject(void)
{
}

Ogre::SceneNode* BaseObject::getNode()
{
	return m_object;
}

Ogre::Vector3 BaseObject::getPosition()
{
	return m_position;
}


void BaseObject::setPosition(Ogre::Vector3 position)
{
	m_position = position;
}
///*
void BaseObject::update(double a)
{
	m_object->setPosition(m_position);
}
//*/

vector<Ogre::Vector3> BaseObject::getPoints()
{
	return m_collisionPoints;
}
