#include "SceneManager.h"
#include "SceneMain.h"

SceneManager::SceneManager()
{
	//クラスのメモリを確保する
	m_pMain = new SceneMain;
}

SceneManager::~SceneManager()
{
	//クラスのメモリを解放する
	delete m_pMain;
	m_pMain = nullptr;
}

void SceneManager::Init()
{
	m_pMain->Init();
	//m_pMapEdit->Init();
}

void SceneManager::End()
{
	m_pMain->End();
	//m_pMapEdit->End();
}

void SceneManager::Update()
{
	m_pMain->Update();
	//m_pMapEdit->Update();
}

void SceneManager::Draw()
{
	m_pMain->Draw();
	//m_pMapEdit->Draw();
}
