
#include <d3dx9.h>
#include <iostream>
#include <vector>
#include "BaseMesh.h"


BaseMesh::BaseMesh( int triangles, int vetices, _D3DXMESH meshType, int veticesFormatType, IDirect3DDevice9* Device )
{
	HRESULT hr = D3DXCreateMeshFVF(
		triangles, // 三角形个数
		vetices,   // 定点个数
		meshType,  // 网格类型
		veticesFormatType, // 定点格式
		Device, // directx 设备指针
		&_pMesh);

	if (FAILED(hr)) 
	{
		::MessageBox(0, L"D3DXCreateMeshFVF() - FAILED", 0, 0);
	}
}

bool BaseMesh::init( int triangles, int vetices, _D3DXMESH meshType, int veticesFormatType, IDirect3DDevice9* Device )
{
	HRESULT hr = D3DXCreateMeshFVF(
		triangles, // 三角形个数
		vetices,   // 定点个数
		meshType,  // 网格类型
		veticesFormatType, // 定点格式
		Device, // directx 设备指针
		&_pMesh);

	if (FAILED(hr)) 
	{
		::MessageBox(0, L"D3DXCreateMeshFVF() - FAILED", 0, 0);
		return false;
	}
	return true;
}

BaseMesh::BaseMesh()
:_pMesh(0)
{

}

void BaseMesh::fillBox()
{

	// set vertex
	Vertex* v = 0;
	_pMesh->LockVertexBuffer(0, (void**)&v);

	// fill in the front face vertex data
	v[0] = Vertex(-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f);
	v[1] = Vertex(-1.0f,  1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f);
	v[2] = Vertex( 1.0f,  1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f);
	v[3] = Vertex( 1.0f, -1.0f, -1.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f);

	// fill in the back face vertex data
	v[4] = Vertex(-1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	v[5] = Vertex( 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
	v[6] = Vertex( 1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	v[7] = Vertex(-1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f);

	// fill in the top face vertex data
	v[8]  = Vertex(-1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
	v[9]  = Vertex(-1.0f, 1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	v[10] = Vertex( 1.0f, 1.0f,  1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f);
	v[11] = Vertex( 1.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);

	// fill in the bottom face vertex data
	v[12] = Vertex(-1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f);
	v[13] = Vertex( 1.0f, -1.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f);
	v[14] = Vertex( 1.0f, -1.0f,  1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f);
	v[15] = Vertex(-1.0f, -1.0f,  1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);

	// fill in the left face vertex data
	v[16] = Vertex(-1.0f, -1.0f,  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[17] = Vertex(-1.0f,  1.0f,  1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[18] = Vertex(-1.0f,  1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[19] = Vertex(-1.0f, -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// fill in the right face vertex data
	v[20] = Vertex( 1.0f, -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	v[21] = Vertex( 1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	v[22] = Vertex( 1.0f,  1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	v[23] = Vertex( 1.0f, -1.0f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	_pMesh->UnlockVertexBuffer();

	// set index 
	WORD* i = 0;
	_pMesh->LockIndexBuffer(0, (void**)&i);

	// fill in the front face index data
	i[0] = 0; i[1] = 1; i[2] = 2;
	i[3] = 0; i[4] = 2; i[5] = 3;

	// fill in the back face index data
	i[6] = 4; i[7]  = 5; i[8]  = 6;
	i[9] = 4; i[10] = 6; i[11] = 7;

	// fill in the top face index data
	i[12] = 8; i[13] =  9; i[14] = 10;
	i[15] = 8; i[16] = 10; i[17] = 11;

	// fill in the bottom face index data
	i[18] = 12; i[19] = 13; i[20] = 14;
	i[21] = 12; i[22] = 14; i[23] = 15;

	// fill in the left face index data
	i[24] = 16; i[25] = 17; i[26] = 18;
	i[27] = 16; i[28] = 18; i[29] = 19;

	// fill in the right face index data
	i[30] = 20; i[31] = 21; i[32] = 22;
	i[33] = 20; i[34] = 22; i[35] = 23;

	_pMesh->UnlockIndexBuffer();


	// 设置属性
	DWORD* attributeBuffer = 0;
	_pMesh->LockAttributeBuffer(0, &attributeBuffer);

	for(int a = 0; a < 4; a++)
		attributeBuffer[a] = 0;

	for(int b = 4; b < 8; b++)
		attributeBuffer[b] = 1;

	for(int c = 8; c < 12; c++)
		attributeBuffer[c] = 2;

	_pMesh->UnlockAttributeBuffer();

	//  Optimize the mesh to generate an attribute table.
	std::vector<DWORD> adjacencyBuffer(_pMesh->GetNumFaces() * 3);
	_pMesh->GenerateAdjacency(0.0f, &adjacencyBuffer[0]);

	_pMesh->OptimizeInplace(		
		D3DXMESHOPT_ATTRSORT |
		D3DXMESHOPT_COMPACT  |
		D3DXMESHOPT_VERTEXCACHE,
		&adjacencyBuffer[0],
		0, 0, 0);

}

void BaseMesh::drawMesh( int index )
{
	if (_pMesh)
	{
		_pMesh->DrawSubset( index );
	}

}

BaseMesh::~BaseMesh()
{

}


