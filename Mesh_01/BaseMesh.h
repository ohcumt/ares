

#ifndef __BASE_MESH_H__
#define __BASE_MESH_H__

#include "d3dUtility.h"


class BaseMesh
{
public:

	BaseMesh(int triangles, int vetices, _D3DXMESH meshType, int veticesFormatType, IDirect3DDevice9* Device);
	BaseMesh();
	~BaseMesh();


	bool init(int triangles, int vetices, _D3DXMESH meshType, int veticesFormatType, IDirect3DDevice9* Device);
	void fillBox();

	void drawMesh(int index);

	


private:
	ID3DXMesh* _pMesh;

};



#endif // __BASE_MESH_H__


