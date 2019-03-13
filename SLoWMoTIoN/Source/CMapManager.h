#pragma once
#include "CBlockMap.h"
namespace game_framework
{
	class CMapManager
	{
	public:
		CMapManager();
		~CMapManager();
		int GetNowMap();
		int GetUpMap();
		int GetDownMap();
		int GetLeftMap();
		int GetRightMap();

		void ChangeMap(int);
		void onShow();
		void LoadBitmap(int);

	protected:
		CMovingBitmap bmp;

	private:
		const int MAX_MAP_NUMBER = 3;
		int nowMap;
		int loadMap;
		CBlockMap blockMap[3];

		void InitializeCBlockMap();
	};
}