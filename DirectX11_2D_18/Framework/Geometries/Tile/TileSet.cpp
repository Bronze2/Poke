#include "Framework.h"
#include "TileSet.h"

void TileSet::GUI()
{
	


}

TileSet::TileSet()
{
	Texture2D* tex = new Texture2D(TexturePath + L"Pokemon/Map/MapTile48.png");
	tileSRV = tex->GetSRV();
	SAFE_DELETE(tex);

	tileXCount = 27;
	tileYCount = 24;

	texelTileSize = Vector2(1 / (float)tileXCount, 1 / (float)tileYCount);
}

TileSet::~TileSet()
{
}
