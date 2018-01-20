#pragma once

#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"

using namespace DirectX;
using namespace DirectX::PackedVector;

struct VertexPos
{
	XMFLOAT3 Pos;
};

struct VertexColor
{
	XMFLOAT4 Color;
};

class Shapes
{
public:
	static std::unique_ptr<StaticMeshGeometry> BuildStaticBox(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList);
	static std::unique_ptr<StaticMeshGeometry> BuildStaticPyramid(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList);
	static std::unique_ptr<StaticMeshGeometry> BuildBoxPyramidTEST(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList);
};