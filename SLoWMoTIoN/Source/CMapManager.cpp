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

	int CMapManager::GetLoadMap()
	{
		return loadMap;
	}
#pragma endregion

	void CMapManager::ChangeMap(int changeMap)
	{
		nowMap = changeMap;
		loadMap = blockMap[nowMap].loadMap;
	}

	void CMapManager::LoadMapBitmap(int loadMap)
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
		for (int mapIndex = 0; mapIndex < MAX_MAP_NUMBER; mapIndex++) //��l��blockMap���W�U���k�a�ϸ�T�A�W�[�iŪ�ʨϥ�switch�ԭz
		{
			switch (mapIndex)
			{
				//���ǡG�ثe �W �U �� �k �A -1��ܤ��s�b
			case 0:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 1, 2, IDB_MAP0);
				break;

			case 1:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, -1, 0, IDB_MAP1);
				break;

			case 2:
				blockMap[mapIndex] = CBlockMap(mapIndex, -1, -1, 0, -1, IDB_MAP2);
				break;

			default:
				blockMap[mapIndex] = CBlockMap(-1, -1, -1, -1, -1, 0);
				break;
			}
		}
	}
}
