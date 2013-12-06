 #include "Camera.h"

Camera*  Camera::cam = 0;

Camera* Camera::getCam(){
	if(cam == 0){
		cam = new Camera();
	}
	return cam;
}


void Camera::Initiate(Ogre::Camera* cam, Ogre::SceneNode* node, OIS::Keyboard* keyboard)
{
	mCamera = cam;
	mNode = node;
	posAround = Ogre::Vector3(0,50,100);
	mKeyboard = keyboard;
	around = mCamera->getPosition() - mNode->getPosition();
	minDist = 50;
	maxDist = 250;
	rotSpeed = 0.01;
	//dist = Ogre::Vector3(mCamera->getPosition() - mNode->getPosition()).length();
}

Camera::Camera()
{
}

Camera::~Camera(void)
{
}

Ogre::SceneNode* Camera::getNode(){
	return mNode;
}

void Camera::Update(){
	if (mKeyboard->isKeyDown(OIS::KC_W))
	{
		dist--;
		//if(Ogre::Vector3(mCamera->getPosition() - mNode->getPosition()).length() < 50)dist = 50;
		Ogre::Vector3 temp = mCamera->getPosition() - mNode->getPosition();
		temp.normalise();
		if(topDownDist() > minDist)
			mCamera->setPosition(mCamera->getPosition()-temp);

		around = mCamera->getPosition() - mNode->getPosition();
	}
	else if(mKeyboard->isKeyDown(OIS::KC_S))
	{
		dist++;
		//if(topDownDist() > 250)dist = 250;
		Ogre::Vector3 temp = mCamera->getPosition() - mNode->getPosition();
		temp.normalise();
		if(topDownDist() < maxDist)
			mCamera->setPosition(mCamera->getPosition()+temp);

		around = mCamera->getPosition() - mNode->getPosition();
	}
	if(mKeyboard->isKeyDown(OIS::KC_A)) 
	{
		/*Ogre::Vector3 accel = mCamera->getRight();
		accel = -accel;
		accel.normalise();
		mCamera->setPosition(mCamera->getPosition() + accel);
		Ogre::Vector3 temp = mCamera->getPosition() - mNode->getPosition();
		temp.normalise();
		temp*dist;*/

		Ogre::Matrix3 mat = Ogre::Matrix3(cos(rotSpeed),0,sin(rotSpeed),
											0,1,0,
										-sin(rotSpeed),0,cos(rotSpeed));

		Ogre::Vector3 accel = mCamera->getPosition() - mNode->getPosition();
		accel = accel * mat;
		accel = accel + mNode->getPosition();
		mCamera->setPosition(accel);
		around = mCamera->getPosition() - mNode->getPosition();
	}
	else if (mKeyboard->isKeyDown(OIS::KC_D) )
	{
		/*Ogre::Vector3 accel = mCamera->getRight();
		accel.normalise();
		mCamera->setPosition(mCamera->getPosition() + accel);
		Ogre::Vector3 temp = mCamera->getPosition() - mNode->getPosition();
		temp.normalise();
		temp*dist;*/

		
		Ogre::Matrix3 mat = Ogre::Matrix3(cos(-rotSpeed),0,sin(-rotSpeed),
											0,1,0,
										-sin(-rotSpeed),0,cos(-rotSpeed));

		Ogre::Vector3 accel = mCamera->getPosition() - mNode->getPosition();
		accel = accel * mat;
		accel = accel + mNode->getPosition();
		mCamera->setPosition(accel);

		around = mCamera->getPosition() - mNode->getPosition();
		//mCamera->setPosition(mNode->getPosition()+temp);
		//accel += mCamera->getRight();
	}
	//around.y = 0;
	//mCamera->
	mCamera->setPosition(mNode->getPosition().x+around.x,mCamera->getPosition().y,mNode->getPosition().z+around.z);
	if(mCamera->getPosition().y != mNode->getPosition().y + posAround.y)
	{
		if(mCamera->getPosition().y < mNode->getPosition().y + posAround.y)
			mCamera->setPosition(mCamera->getPosition().x, mCamera->getPosition().y + 0.1, mCamera->getPosition().z);
		else
			mCamera->setPosition(mCamera->getPosition().x, mCamera->getPosition().y - 0.1, mCamera->getPosition().z);
	}
	//posAround = mNode->getPosition() - mCamera->getPosition();
	//mCamera->setPosition(mNode->getPosition().x - mCamera->getDirection().x*50, mCamera->getPosition().y, mNode->getPosition().z- mCamera->getDirection().z*50);
	mCamera->lookAt(mNode->getPosition());
}

Ogre::Vector3 Camera::getPosition()
{
	return mCamera->getPosition();
}

void Camera::setPosition(Ogre::Vector3 vec){
	mCamera->setPosition(vec);
}

void Camera::changePos(Ogre::Vector3 vec){
	posAround = vec;
}

float Camera::topDownDist(){
	Ogre::Vector2 vec1 = Ogre::Vector2(mNode->getPosition().x, mNode->getPosition().z);
	Ogre::Vector2 vec2 = Ogre::Vector2(mCamera->getPosition().x, mCamera->getPosition().z);
	vec1 = vec1 - vec2;
	return vec1.length();
}