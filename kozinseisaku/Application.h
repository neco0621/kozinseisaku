#pragma once
#include <iostream>
/// <summary>
/// �A�v���P�[�V�����S�̂��Ǘ�����N���X
/// �V���O���g���N���X
/// </summary>
class Application
{
private:
	//�V���O���g���̂��߂ɃR���X�g���N�^��private��
	Application() {};

	//�R�s�[&����̋֎~
	//�R�s�[�R���X�g���N�^�̔p�~
	Application(const Application& app) = delete;
	//
	void operator = (const Application& app) = delete;

	/// <summary>
	/// �㏈�����s��
	/// </summary>
	void Terminate();
public:
	/// <summary>
	/// Application�̃V���O���g���C���X�^���X�̎Q�Ƃ�Ԃ�
	/// </summary>
	/// <returns>Application�C���X�^���X</returns>
	/// GetInstance���Ă΂ꂽ�Ƃ��ɐ��������
	/// ��
	static Application& GetInstance() {
		static Application instance;
		return instance;
	}
	bool Init();
	void Run();

};

