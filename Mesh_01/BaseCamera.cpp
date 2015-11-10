
#include "BaseCamera.h"

void BaseCamera::CameraVectorNormalize()
{
	/* 
		���¼���up,look,right����,ʹ���໥��ֱ(��������ϵ)
		up    = look * right;
		look  = up   * right;
		right = up   * look;
	*/
	
	D3DXVec3Normalize(&_look, &_look);
	D3DXVec3Cross(&_up, &_look, &_right);
	D3DXVec3Normalize(&_up, &_up);
	D3DXVec3Cross(&_right, &_up, &_look);
	D3DXVec3Normalize(&_right, &_right);
}

void BaseCamera::getViewMatrix( D3DXMATRIX *V )
{
	/*
		������ͼת������
		��ͼ�任:����������ϵת�������������ϵ
	*/
	CameraVectorNormalize();

	float x = -D3DXVec3Dot(&_right, &_pos);
	float y = -D3DXVec3Dot(&_up,    &_pos);
	float z = -D3DXVec3Dot(&_look,  &_pos);

	(*V)(0,0) = _right.x; (*V)(0, 1) = _up.x; (*V)(0, 2) = _look.x; (*V)(0, 3) = 0.0f;
	(*V)(1,0) = _right.y; (*V)(1, 1) = _up.y; (*V)(1, 2) = _look.y; (*V)(1, 3) = 0.0f;
	(*V)(2,0) = _right.z; (*V)(2, 1) = _up.z; (*V)(2, 2) = _look.z; (*V)(2, 3) = 0.0f;
	(*V)(3,0) = x;        (*V)(3, 1) = y;     (*V)(3, 2) = z;       (*V)(3, 3) = 1.0f;
}

void BaseCamera::resetCameraVector()
{
	_pos   = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	_right = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	_up    = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	_look  = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
}

void BaseCamera::pitch( float angle )
{
	/*
		��б:����x��(right��)��ת
	*/

	D3DXMATRIX T;

	// ����任����T
	D3DXMatrixRotationAxis(&T, &_right, angle);

	// ����任���up���look��(look��up����Χ����right����תangle�Ƕ�)
	D3DXVec3TransformCoord(&_up, &_up, &T );
	D3DXVec3TransformCoord(&_look, &_look, &T );
}

void BaseCamera::yaw( float angle )
{
	/*
		ƫ��:����up��(y��)��ת
	*/

	D3DXMATRIX T;

	// ����任����T

	if (_cameraType==AIRCRAFT) 
	{
		D3DXMatrixRotationAxis(&T, &_up, angle);
	}
	else if (_cameraType==LANDOBJECT)
	{
		D3DXMatrixRotationY(&T, angle);
	}

	// look��right����Χ����up����תangle�Ƕ�
	D3DXVec3TransformCoord(&_look, &_look, &T );
	D3DXVec3TransformCoord(&_right, &_right, &T );
}

void BaseCamera::roll( float angle )
{
	/*
		��ת:����look��(z��)��ת
	*/

	// LANDOBJECTģʽ��������z��(look��)��ת
	if (_cameraType==AIRCRAFT) 
	{
		D3DXMATRIX T;

		// ����任����T
		D3DXMatrixRotationAxis(&T, &_look, angle);

		// ����任���up���look��(look��up����Χ����right����תangle�Ƕ�)
		D3DXVec3TransformCoord(&_up, &_up, &T );
		D3DXVec3TransformCoord(&_right, &_right, &T );
	}
}

void BaseCamera::walk( float units )
{
	/*
		����z��(����)��ǰ��
	*/
	if (_cameraType==AIRCRAFT) 
	{
		_pos += _look*units;
	}
	else if (_cameraType==LANDOBJECT) 
	{
		 _pos += D3DXVECTOR3(_look.x, 0, _look.z)*units;
	}
}

void BaseCamera::strafe( float units )
{
	/*
		����x���ƶ�
	*/

	if (_cameraType==AIRCRAFT) 
	{
		_pos += _right*units;
	}
	else if (_cameraType==LANDOBJECT) 
	{
		_pos += D3DXVECTOR3(_right.x, 0, _right.z)*units;
	}
}

void BaseCamera::fly( float units )
{
	/*
		����y���ƶ�
	*/

	if (_cameraType==AIRCRAFT) 
	{
		_pos += _up*units;
	}
	else if (_cameraType==LANDOBJECT) 
	{
		_pos.y += units;
	}
}

BaseCamera::~BaseCamera()
{

}

BaseCamera::BaseCamera()
:_cameraType(AIRCRAFT)
{
	resetCameraVector();
}

BaseCamera::BaseCamera( BaseCameraType type )
{
	_cameraType=type;
	resetCameraVector();
}

