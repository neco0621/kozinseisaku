#pragma once

//クラスのプロトタイプ宣言
class SceneMain;
class Input;
class Scene;

class SceneManager
{
private:
	Scene* scene_ = nullptr;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	SceneMain* m_pMain;

};