#pragma once
class Input;
class SceneManager;
/// <summary>
/// �V�[�����N���X
/// �����ȃV�[���̊�ɂȂ�N���X
/// </summary>
class Scene
{
protected:
	//���������O����SceneManager��m���Ă��邱�Ƃɂ���
	//�V�[���Ǘ��N���X�̎Q��
	SceneManager& manager_;
public:
	/// <summary>
	/// ��������SceneManager�̎Q�Ƃ��󂯎���Ă���
	/// </summary>
	/// <param name="manager">SCeneManeger�̎Q��</param>
	Scene(SceneManager& manager);

	/// <summary>
	/// �V�[���̍X�V
	/// </summary>
	/// <param name="input">���̓I�u�W�F�N�g</param>

	/// �������z�֐�:����virtual �Ō�� = 0;������
	virtual void Update(Input& input) = 0;

	/// <summary>
	/// �V�[���̕`��
	/// </summary>
	virtual void Draw() = 0;

};

