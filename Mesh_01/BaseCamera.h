
#ifndef __BASE_CAMERA_H__
#define __BASE_CAMERA_H__

#include <d3dx9.h>

class BaseCamera 
{
public:
	enum BaseCameraType{
		AIRCRAFT,     // 飞行模式:在空间中完全自由移动
		LANDOBJECT    // 沿地表行走
	};

	BaseCamera();
	BaseCamera(BaseCameraType type);
	~BaseCamera();


	void getViewMatrix(D3DXMATRIX *V);


	void pitch(float angle);
	void yaw(float angle);
	void roll(float angle);

	void walk(float units);
	void strafe(float units);
	void fly(float units);


	void CameraVectorNormalize();
	void resetCameraVector();

private:
	BaseCameraType _cameraType;
	D3DXVECTOR3 _right;
	D3DXVECTOR3 _up;
	D3DXVECTOR3 _look;
	D3DXVECTOR3 _pos;
};



#endif // __BASE_CAMERA_H__



