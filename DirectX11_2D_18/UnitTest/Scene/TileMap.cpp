#include "stdafx.h"
#include "TileMap.h"

#include "Geometries/Tile/TMap.h"

void TileMap::Init()
{
	uint spacing = 48;
	uint width = WinMaxWidth / spacing;
	uint height = WinMaxHeight / spacing;
	tm = new TMap(width, height, spacing);
}

void TileMap::Destroy()
{
	SAFE_DELETE(tm);
}

void TileMap::Update()
{
	string s;
	
	if (PRESS(VK_LCONTROL) && PRESS('S'))
	{
		cin >> s;
		tm->Save(TilePath + s);
	}

	if (PRESS(VK_LCONTROL) && PRESS('L'))
	{
		cin >> s;
		tm->Load(TilePath + s);
	}

	tm->Update();
}

void TileMap::Render()
{
	tm->Render();
}

void TileMap::PostRender()
{
}

void TileMap::GUI()
{
	tm->GUI();
}
