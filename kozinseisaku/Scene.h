#pragma once
class Input;
class SceneManager;
/// <summary>
/// シーン基底クラス
/// いろんなシーンの基になるクラス
/// </summary>
class Scene
{
protected:
	//生成される前からSceneManagerを知っていることにする
	//シーン管理クラスの参照
	SceneManager& manager_;
public:
	/// <summary>
	/// 生成時にSceneManagerの参照を受け取っておく
	/// </summary>
	/// <param name="manager">SCeneManegerの参照</param>
	Scene(SceneManager& manager);

	/// <summary>
	/// シーンの更新
	/// </summary>
	/// <param name="input">入力オブジェクト</param>

	/// 純粋仮想関数:頭にvirtual 最後に = 0;をつける
	virtual void Update(Input& input) = 0;

	/// <summary>
	/// シーンの描画
	/// </summary>
	virtual void Draw() = 0;

};

