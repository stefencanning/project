#include "MovingObject.h"


MovingObject::MovingObject(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity, int type)
	:BaseObject(node,position,collisionPoints,type),m_velocity(velocity)
{
}


MovingObject::~MovingObject(void)
{
}

void MovingObject::setVelocity(Ogre::Vector3 velocity)
{
	m_velocity = velocity;
}
Ogre::Vector3 MovingObject::getVelocity()
{
	return m_velocity;
}

void MovingObject::update(double a)
{
	m_velocity.y -= 1*a;
	m_position+=m_velocity;
	for(int i = 0; i < m_collisionPoints.size();i++)
	{
		if(m_position.y + m_collisionPoints[i].y < 0)
		{
			m_position.y = -m_collisionPoints[i].y;
			m_velocity.y = -(m_velocity.y*0.7);
			m_velocity.x = (m_velocity.x*0.7);
			m_velocity.z = (m_velocity.z*0.7);
		}
	}
	BaseObject::update(a);
}