#include "Shapes.h"

std::unique_ptr<StaticMeshGeometry> Shapes::BuildStaticBox(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList)
{
	std::array<VertexPos, 8> verticesPos =
	{
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, +1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, +1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, +1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, +1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, +1.0f) })
	};

	std::array<VertexColor, 8> verticesColor =
	{
		VertexColor({ XMFLOAT4(Colors::White) }),
		VertexColor({ XMFLOAT4(Colors::Black) }),
		VertexColor({ XMFLOAT4(Colors::Red) }),
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Blue) }),
		VertexColor({ XMFLOAT4(Colors::Yellow) }),
		VertexColor({ XMFLOAT4(Colors::Cyan) }),
		VertexColor({ XMFLOAT4(Colors::Magenta) })
	};

	std::array<std::uint16_t, 36> indices =
	{
		// front face
		0, 1, 2,
		0, 2, 3,

		// back face
		4, 6, 5,
		4, 7, 6,

		// left face
		4, 5, 1,
		4, 1, 0,

		// right face
		3, 2, 6,
		3, 6, 7,

		// top face
		1, 5, 6,
		1, 6, 2,

		// bottom face
		4, 0, 3,
		4, 3, 7
	};

	const UINT vbByteSizePos = (UINT)verticesPos.size() * sizeof(VertexPos);
	const UINT vbByteSizeColor = (UINT)verticesColor.size() * sizeof(VertexColor);
	const UINT ibByteSize = (UINT)indices.size() * sizeof(std::uint16_t);

	auto boxGeo = std::make_unique<StaticMeshGeometry>();
	boxGeo->Name = "boxGeo";

	StaticMeshVertexBuffer positionVertexBuffer = StaticMeshVertexBuffer(verticesPos.data(), vbByteSizePos, sizeof(VertexPos));
	StaticMeshVertexBuffer colorVertexBuffer = StaticMeshVertexBuffer(verticesColor.data(), vbByteSizeColor, sizeof(VertexColor));;
	StaticMeshIndexBuffer indexBuffer = StaticMeshIndexBuffer(indices.data(), ibByteSize);
	positionVertexBuffer.CopyToGPU(device, cmdList);
	colorVertexBuffer.CopyToGPU(device, cmdList);
	indexBuffer.CopyToGPU(device, cmdList);

	boxGeo->VertexBuffers["position"] = positionVertexBuffer;
	boxGeo->VertexBuffers["color"] = colorVertexBuffer;
	boxGeo->IndexBuffer = indexBuffer;

	SubmeshGeometry submesh;
	submesh.IndexCount = (UINT)indices.size();
	submesh.StartIndexLocation = 0;
	submesh.BaseVertexLocation = 0;

	boxGeo->DrawArgs["box"] = submesh;

	return boxGeo;
}

std::unique_ptr<StaticMeshGeometry> Shapes::BuildStaticPyramid(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList)
{
	std::array<VertexPos, 5> verticesPos =
	{
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(+0.0f, +1.0f, +0.0f) })
	};

	std::array<VertexColor, 5> verticesColor =
	{
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Red) }),
	};

	std::array<std::uint16_t, 18> indices =
	{
		// front face
		0, 4, 1,

		// back face
		2, 3, 4,

		// left face
		2, 4, 0,

		// right face
		1, 4, 3,

		// bottom face
		0, 1, 2,
		1, 3, 2
	};

	const UINT vbByteSizePos = (UINT)verticesPos.size() * sizeof(VertexPos);
	const UINT vbByteSizeColor = (UINT)verticesColor.size() * sizeof(VertexColor);
	const UINT ibByteSize = (UINT)indices.size() * sizeof(std::uint16_t);

	auto pyramidGeo = std::make_unique<StaticMeshGeometry>();
	pyramidGeo->Name = "pyramidGeo";

	StaticMeshVertexBuffer positionVertexBuffer = StaticMeshVertexBuffer(verticesPos.data(), vbByteSizePos, sizeof(VertexPos));
	StaticMeshVertexBuffer colorVertexBuffer = StaticMeshVertexBuffer(verticesColor.data(), vbByteSizeColor, sizeof(VertexColor));;
	StaticMeshIndexBuffer indexBuffer = StaticMeshIndexBuffer(indices.data(), ibByteSize);
	positionVertexBuffer.CopyToGPU(device, cmdList);
	colorVertexBuffer.CopyToGPU(device, cmdList);
	indexBuffer.CopyToGPU(device, cmdList);

	pyramidGeo->VertexBuffers["position"] = positionVertexBuffer;
	pyramidGeo->VertexBuffers["color"] = colorVertexBuffer;
	pyramidGeo->IndexBuffer = indexBuffer;

	SubmeshGeometry submesh;
	submesh.IndexCount = (UINT)indices.size();
	submesh.StartIndexLocation = 0;
	submesh.BaseVertexLocation = 0;

	pyramidGeo->DrawArgs["pyramid"] = submesh;

	return pyramidGeo;
}

std::unique_ptr<StaticMeshGeometry> Shapes::BuildBoxPyramidTEST(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList)
{
	std::array<VertexPos, 9> verticesPos =
	{
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, +0.5f, -1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, +0.5f, -1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, -1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, -1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3(-1.0f, +0.5f, +1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, +0.5f, +1.0f) }),
		VertexPos({ XMFLOAT3(+1.0f, -1.0f, +1.0f) }),
		VertexPos({ XMFLOAT3( 0.0f, +1.0f,  0.0f) })
	};

	std::array<VertexColor, 9> verticesColor =
	{
		VertexColor({ XMFLOAT4(Colors::White) }),
		VertexColor({ XMFLOAT4(Colors::Black) }),
		VertexColor({ XMFLOAT4(Colors::Red) }),
		VertexColor({ XMFLOAT4(Colors::Green) }),
		VertexColor({ XMFLOAT4(Colors::Blue) }),
		VertexColor({ XMFLOAT4(Colors::Yellow) }),
		VertexColor({ XMFLOAT4(Colors::Cyan) }),
		VertexColor({ XMFLOAT4(Colors::Magenta) }),
		VertexColor({ XMFLOAT4(Colors::White) })
	};

	std::array<std::uint16_t, 54> indices =
	{
		// BOX
		// front face
		0, 1, 2,
		0, 2, 3,

		// back face
		4, 6, 5,
		4, 7, 6,

		// left face
		4, 5, 1,
		4, 1, 0,

		// right face
		3, 2, 6,
		3, 6, 7,

		// top face
		1, 5, 6,
		1, 6, 2,

		// bottom face
		4, 0, 3,
		4, 3, 7,


		// PYRAMID
		// front face
		0, 8, 3,

		// back face
		4, 7, 8,

		// left face
		4, 8, 0,

		// right face
		3, 8, 7,

		// bottom face
		0, 3, 4,
		3, 7, 4
	};

	const UINT vbByteSizePos = (UINT)verticesPos.size() * sizeof(VertexPos);
	const UINT vbByteSizeColor = (UINT)verticesColor.size() * sizeof(VertexColor);
	const UINT ibByteSize = (UINT)indices.size() * sizeof(std::uint16_t);

	auto boxPyrGeo = std::make_unique<StaticMeshGeometry>();
	boxPyrGeo->Name = "boxPyrGeo";

	StaticMeshVertexBuffer positionVertexBuffer = StaticMeshVertexBuffer(verticesPos.data(), vbByteSizePos, sizeof(VertexPos));
	StaticMeshVertexBuffer colorVertexBuffer = StaticMeshVertexBuffer(verticesColor.data(), vbByteSizeColor, sizeof(VertexColor));;
	StaticMeshIndexBuffer indexBuffer = StaticMeshIndexBuffer(indices.data(), ibByteSize);
	positionVertexBuffer.CopyToGPU(device, cmdList);
	colorVertexBuffer.CopyToGPU(device, cmdList);
	indexBuffer.CopyToGPU(device, cmdList);

	boxPyrGeo->VertexBuffers["position"] = positionVertexBuffer;
	boxPyrGeo->VertexBuffers["color"] = colorVertexBuffer;
	boxPyrGeo->IndexBuffer = indexBuffer;

	SubmeshGeometry submeshBox;
	submeshBox.IndexCount = 36;
	submeshBox.StartIndexLocation = 0;
	submeshBox.BaseVertexLocation = 0;

	SubmeshGeometry submeshPyr;
	submeshPyr.IndexCount = 18;
	submeshPyr.StartIndexLocation = 36;
	submeshPyr.BaseVertexLocation = 0;

	boxPyrGeo->DrawArgs["box"] = submeshBox;
	boxPyrGeo->DrawArgs["pyr"] = submeshPyr;

	return boxPyrGeo;
}