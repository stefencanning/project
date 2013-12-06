#pragma once
#ifndef __CollissionReturn_h_
#define __CollissionReturn_h_
#include "BaseApplication.h"
#include "BaseObject.h"

class CollissionReturn
{
public:
	CollissionReturn(bool boolean, double distance, Ogre::Vector3 axis):m_boolean(boolean),m_distance(distance),m_axis(axis){}
	bool m_boolean;
	double m_distance;
	Ogre::Vector3 m_axis;
};

#endif