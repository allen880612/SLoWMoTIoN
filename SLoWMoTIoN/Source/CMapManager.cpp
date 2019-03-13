#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "CMapManager.h"
namespace game_framework
{
	CMapManager::CMapManager()
	{
		InitializeCBlockMap();
		nowMap = 0;
		loadMap = blockMap[0].loadMap;
	}


	CMapManager::~CMapManager()
	{
	}

#pragma region - GetMap -

	int CMapManager::GetNowMap()
	{
		return nowMap;
	}

	int CMapManager::GetUpMap()
	{
		return blockMap[nowMap].upMap;
	}

	int CMapManager::GetDownMap()
	{
		return blockMap[nowMap].downMap;
	}

	int CMapManager::GetLeftMap()
	{
		return blockMap[nowMap].leftMap;
	}

	int CMapManager::GetRightMap()
	{
		return blockMap[nowMap].rightMap;
	}
#pragma endregion

	void CMapManager::ChangeMap(int changeMap)
	{
		nowMap = changeMap;
	}

	void CMapManager::LoadBitmap(int loadMap)
	{
		bmp.LoadBitmap(loadMap);
	}

	void CMapManager::onShow()
	{
		bmp.SetTopLeft(0, 0);
		bmp.ShowBitmap();
	}

	void CMapManager::InitializeCBlockMap()
	{
		for (int mapIndex = 0; mapIndex < MAX_MAP_NUMBER; mapIndex++) //初始化blockMap的上下左右地圖資訊，增加可讀性使用switch敘述
		{
			switch (mapIndex)
			{
				//順序：目前 上 下 左 右 ， -1表示不存在
			case 0:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 1, 2, 132);
				break;

			case 1:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, -1, 0, 111);
				break;

			case 2:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 0, -1, 123);
				break;

			default:
				blockMap[mapIndex] = CBlockMap(-1, -1, -1, -1, -1, 0);
				break;
			}
		}
	}
}
