#include "Application.h"
#include <DxLib.h>



// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application& application = Application::GetInstance();

	//�_���ȗ�
	//��
	//Application application2 = Application::GetInstance();

	//���͕\�������`���ɂ͂Q���̃X�N���[��������܂�
	//����������Ńt���b�v(����ւ���)���s�����Ƃ�
	// ��ʂ̂�������Ȃ����Ă��܂�
	// SetDrawScreen���̊֐���DXLib_Init()�̌�łȂ���
	// �L���ł͂Ȃ����ߒ��ӂ��Ă�������
	if (!application.Init())
	{
		return -1;
	}
	//���C�����[�v�̊J�n
	application.Run();

	return 0;				// �\�t�g�̏I�� 
}