#include "Player.h"


Player::Player(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity,OIS::Keyboard* keyboard)
	:MovingObject(node,position,collisionPoints,velocity),mKeyboard(keyboard)
{
}


Player::~Player(void)
{
}


void Player::update(double a)
{
	if (mKeyboard->isKeyDown(OIS::KC_SPACE))
	{
		//((Player*)objects[0])->jump();
		jump();
	}
	if (mKeyboard->isKeyDown(OIS::KC_L))
	{
		//((Player*)objects[0])->moveRight();
		moveRight();
	}
	if(mKeyboard->isKeyDown(OIS::KC_I)) 
	{
		moveBackward();
		//((Player*)objects[0])->moveBackward();
	}
	if(mKeyboard->isKeyDown(OIS::KC_J))
	{
		moveLeft();
		//((Player*)objects[0])->moveLeft();
	}
	if (mKeyboard->isKeyDown(OIS::KC_K) )
	{
		moveForward();
		//((Player*)objects[0])->moveForward();
	}
	/*
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
	*/
	MovingObject::update(a);
}

void Player::moveLeft()
{
	m_position.x -= 0.1;
}

void Player::moveRight()
{
	m_position.x += 0.1;
}

void Player::moveForward()
{
	m_position.z += 0.1;
}

void Player::moveBackward()
{
	m_position.z -= 0.1;
}

void Player::jump()
{
	m_velocity.y = 0.5;
}