#include "Player.h"

Player * Player::me = 0;

Player::Player(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity)
	:MovingObject(node,position,collisionPoints,velocity,CONSTANT_VALUES::PLAYER)
{

}

Player* Player::getPlayer()
{
	if(me == 0)
	{
		vector<Ogre::Vector3> c;
		me = new Player(NULL,Ogre::Vector3(0,0,0),c,Ogre::Vector3(0,0,0));
	}
	return me;
}

void Player::Init(Ogre::SceneNode* node,Ogre::Vector3 position, vector<Ogre::Vector3> collisionPoints, Ogre::Vector3 velocity,OIS::Keyboard* keyboard)
{
	m_object = node;
	m_position = position;
	m_collisionPoints = collisionPoints;
	m_velocity = velocity;
	mKeyboard = keyboard;
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
		moveForward();
		//((Player*)objects[0])->moveBackward();
	}
	if(mKeyboard->isKeyDown(OIS::KC_J))
	{
		moveLeft();
		//((Player*)objects[0])->moveLeft();
	}
	if (mKeyboard->isKeyDown(OIS::KC_K) )
	{
		moveBackward();
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
	Ogre::Vector3 cameraPos = Camera::getCam()->getPosition();
	Ogre::Vector3 ballPos = Ogre::Vector3(m_position.x,0, m_position.z);
	ballPos = ballPos - cameraPos;
	ballPos = ballPos.crossProduct(Ogre::Vector3(0,1,0));
	ballPos.normalise();
	ballPos *= 0.1;
	m_position.z -= ballPos.z;
	m_position.x -= ballPos.x;
}

void Player::moveRight()
{
	Ogre::Vector3 cameraPos = Camera::getCam()->getPosition();
	Ogre::Vector3 ballPos = Ogre::Vector3(m_position.x,0, m_position.z);
	ballPos = ballPos - cameraPos;
	ballPos = ballPos.crossProduct(Ogre::Vector3(0,1,0));
	ballPos.normalise();
	ballPos *= 0.1;
	m_position.z += ballPos.z;
	m_position.x += ballPos.x;
}

void Player::moveForward()
{
	Ogre::Vector3 cameraPos = Camera::getCam()->getPosition();
	Ogre::Vector2 camPos = Ogre::Vector2(cameraPos.x, cameraPos.z);
	Ogre::Vector2 ballPos = Ogre::Vector2(m_position.x, m_position.z);
	ballPos = ballPos - camPos;
	ballPos.normalise();
	ballPos *= 0.1;
	m_position.z += ballPos.y;
	m_position.x += ballPos.x;
}

void Player::moveBackward()
{
	Ogre::Vector3 cameraPos = Camera::getCam()->getPosition();
	Ogre::Vector2 camPos = Ogre::Vector2(cameraPos.x, cameraPos.z);
	Ogre::Vector2 ballPos = Ogre::Vector2(m_position.x, m_position.z);
	ballPos = ballPos - camPos;
	ballPos.normalise();
	ballPos *= 0.1;
	m_position.z -= ballPos.y;
	m_position.x -= ballPos.x;
}

void Player::jump()
{
	m_velocity.y = 0.5;
}