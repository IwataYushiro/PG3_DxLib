#include "DxLib.h"
#include "SceneManager.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "xx2x_xx_�i�}�G: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
const int WIN_HEIGHT = 400;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	enum Scene
	{
		title,
		newgame,
		gameplay,
		gameclear,
	};
	int scene = title;

	//�C���X�^���X���擾
	SceneManager* sm = SceneManager::GetInstance();

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = {0};

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = {0};

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		switch (scene)
		{
		case title:

			if (keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE])
			{
				sm->SceneChange(scene);
				scene = newgame;
				break;
			}
			break;
		case newgame:
			if (keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE])
			{
				sm->SceneChange(scene);
				scene = gameplay;
				break;
			}
			break;
		case gameplay:
			if (keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE])
			{
				sm->SceneChange(scene);
				scene = gameclear;
				break;
			}
			break;
		case gameclear:
			if (keys[KEY_INPUT_SPACE] && !oldkeys[KEY_INPUT_SPACE])
			{
				sm->SceneChange(scene);
				scene = title;
				break;
			}
			break;
		}

		// �`�揈��
		switch (scene)
		{
		case title:
			DrawString(300, 300, "title\n", GetColor(255, 255, 255));
			DrawBox(100, 100, 200, 200, GetColor(255, 0, 0), true);
			break;
		case newgame:
			DrawString(300, 300, "new game\n", GetColor(255, 255, 255));
			DrawBox(100, 100, 200, 200, GetColor(0, 255, 0), true);
			break;
		case gameplay:
			DrawString(300, 300, "game play\n", GetColor(255, 255, 255));
			DrawBox(100, 100, 200, 200, GetColor(0, 0, 255), true);
			break;
		case gameclear:
			DrawString(300, 300, "game clear\n", GetColor(255, 255, 255));
			DrawBox(100, 100, 200, 200, GetColor(255, 255, 255), true);
			break;

		}
		
		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}