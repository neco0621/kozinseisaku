#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"
#include "Pad.h"
#include "Rect.h"
#include "Map.h"
#include <cassert>

namespace
{
	//一度に登場できる最大の数
	constexpr int kEnemyMax = 64;
	//何フレーム沖に敵が登場するか
	constexpr int kEnemyInterval = 60;

	//画面内に一度に出てくる弾の最大数
	constexpr int kShotMax = 256;
}

SceneMain::SceneMain()
{
	//グラフィックのロード
	m_playerHandle = LoadGraph(L"data/player.png");
	assert(m_playerHandle != -1);
	m_mapHandle = LoadGraph(L"data/map.png");
	assert(m_playerHandle != -1);
	//プレイヤーのメモリ確保
	m_pPlayer = new Player{ this };
	m_pPlayer->SetHandle(m_playerHandle);	//Playerにグラフィックハンドルを渡す

	//マップのメモリ確保
	m_pMap = new Map;
	m_pMap->SetHandle(m_mapHandle);
}

SceneMain::~SceneMain()
{
	//メモリからグラフィックを削除
	DeleteGraph(m_playerHandle);
	

	//プレイヤーのメモリ解放
	delete m_pPlayer;
	m_pPlayer = nullptr;

	//マップのメモリ開放
	delete m_pMap;
	m_pMap = nullptr;
}

void SceneMain::Init()
{
	assert(m_pPlayer);	//m_pPlayer == nullptr の場合止まる

	m_pPlayer->Init();
	m_pMap->Init();
}

void SceneMain::End()
{

}

void SceneMain::Update()
{
	m_pPlayer->Update();
	m_pMap->Update();

	Rect playerRect = m_pPlayer->GetColRect();
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	m_pMap->Draw();
}
