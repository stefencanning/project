#pragma once
#include "Enemy.h"

Enemy::Enemy(Ogre::SceneNode* node,Ogre::Vector3 position,vector<Ogre::Vector3> collisionPoints,Ogre::Vector3 velocity)
	:MovingObject(node,position,collisionPoints,velocity,CONSTANT_VALUES::ENEMY)
{
		isAgressive=false;
}

void Enemy::update(double a){
	Ogre::Vector3 pPos = Player::getPlayer()->getPosition();
	if (isAlive)
	{
		calculateDistance(pPos);
		if (isAgressive == true)
		{
			attackPlayer(pPos);
		}

		else if (isAgressive == false)
		{
		}
	}

	MovingObject::update(a);
}

void Enemy::calculateDistance(Ogre::Vector3 p) //Check if should be agressive
{
	double d;
	d = sqrt(((m_position.x-p.x) * (m_position.x-p.x)) + ((m_position.z - p.z) * (m_position.z - p.z))); 
//Currently ignores the y values as i don't want enemies attacking if they're not on platforms of the same height
	//will modify to be with in a range.

	if ( d < 50)
	{
		isAgressive = true;
	}
	else
		isAgressive = false;
}

void Enemy::attackPlayer(Ogre::Vector3 p)
{
	if (m_position.x > p.x)
	{
		m_position.x -= 0.05;
	}
	else if(m_position.x < p.x)
	{
		m_position.x += 0.05;
	}

	if (m_position.z > p.z)
	{
		m_position.z -= 0.05;
	}
	else if(m_position.z < p.z)
	{
		m_position.z += 0.05;
	}
}

