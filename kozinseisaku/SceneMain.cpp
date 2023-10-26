#include "SceneMain.h"
#include "DxLib.h"
#include "Player.h"
#include "Pad.h"
#include "Rect.h"
#include <cassert>

//登場する敵
#include "EnemyBase.h"
#include "EnemyLeft.h"

namespace
{
	//一度に登場できる最大の数
	constexpr int kEnemyMax = 64;
	//何フレーム沖に敵が登場するか
	constexpr int kEnemyInterval = 60;

	//画面内に一度に出てくる弾の最大数
	constexpr int kShotMax = 256;
}

SceneMain::SceneMain() :
	m_enemyInterval(0)
{
	//グラフィックのロード
	m_playerHandle = LoadGraph(L"data/player.png");
	assert(m_playerHandle != -1);
	m_enemyHandle = LoadGraph(L"data/Enemy.png");
	
	//プレイヤーのメモリ確保
	m_pPlayer = new Player{ this };
	m_pPlayer->SetHandle(m_playerHandle);	//Playerにグラフィックハンドルを渡す

	//敵の準備
	//m_pEnemy(vector)何もしなければサイズは0
	//resize関数でkEnemyMaxだけデータを保存できるようにする
	m_pEnemy.resize(kEnemyMax);

	//初期状態ではメモリを確保していないことがわかるようにしておく
	//未使用状態にする　nullptrを入れておく
	//size()で現在使用可能な要素数を取得可能
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		m_pEnemy[i] = nullptr;

		//m_pEnemyのなかにはLeft,Right,ToPlayerのどれかが入る
		//現時点ではどれが入るのか決定できない
	}
}

SceneMain::~SceneMain()
{
	//メモリからグラフィックを削除
	DeleteGraph(m_playerHandle);
	DeleteGraph(m_enemyHandle);
	

	//プレイヤーのメモリ解放
	delete m_pPlayer;
	m_pPlayer = nullptr;

	//メモリが確保されている敵を探して解放していく
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		//nullptr以外のものが入っているということはそこにはポインタが入っている
		if (m_pEnemy[i] != nullptr)
		{
			delete m_pEnemy[i];
			m_pEnemy[i] = nullptr;
		}
	}

}

void SceneMain::Init()
{
	assert(m_pPlayer);	//m_pPlayer == nullptr の場合止まる

	m_pPlayer->Init();
}

void SceneMain::End()
{

}

void SceneMain::Update()
{
	m_pPlayer->Update();

	Rect playerRect = m_pPlayer->GetColRect();

	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])	//nullptrではないチェック
		{
			m_pEnemy[i]->Update();

			//使用済みの敵キャラクタを削除する必要がある
			if (!m_pEnemy[i]->isExist())
			{
				//メモリを解放する
				delete m_pEnemy[i];
				m_pEnemy[i] = nullptr;	//使っていないとわかるように
			}
			else
			{
				////存在している敵とプレイヤーの当たり判定
				//Rect enemyRect = m_pEnemy[i]->GetColRect();
				//if (playerRect.IsCollision(enemyRect))
				//{
				//	//test
				//	//printfDx("当たっている\n");

				//	m_pPlayer->OnDamage();
				//}

			}
		}
	}

	m_enemyInterval++;
	if (m_enemyInterval >= kEnemyInterval)
	{
		m_enemyInterval = 0;

		//ランダムに敵を選択
		switch (GetRand(2))		//0 or 1 or 2
		{
		case 0:		//Left
			CreateEnemyLeft();

			break;
		//case 1:		//Right
		//	CreateEnemyRight();

		//	break;

		//default:	assert(false);		//breakなし
		//case 2:		//ToPlayer
		//	CreateEnemyToPlayer();

		//	break;
		}
	}

}

void SceneMain::Draw()
{
	m_pPlayer->Draw();

	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (m_pEnemy[i])	//nullptrではないチェック
		{
			m_pEnemy[i]->Draw();
		}
	}
}

void SceneMain::CreateEnemyLeft()
{
	//使われていない箱を探してそこにアドレスを保存する
	for (int i = 0; i < m_pEnemy.size(); i++)
	{
		if (!m_pEnemy[i])	//nullptrであることをチェックする
		{
			m_pEnemy[i] = new EnemyLeft;
			m_pEnemy[i]->Init();
			m_pEnemy[i]->SetHandle(m_enemyHandle);
			m_pEnemy[i]->Start();
			return;	//メモリを確保したら以降はチェックしない
		}
	}
}
