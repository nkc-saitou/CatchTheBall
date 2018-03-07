#include "DxLib.h"
#include "Select.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "Input.h"

// ��ʂ̉��T�C�Y
#define SCREEN_WIDTH 640
// �{�[�h��1�񂲂Ƃ̈ړ���
#define BOARD_MOVE 8
// ���̈ړ����E
#define ARROW_LIMIT 42
// ���̌��_
#define ARROW_ORIGIN 16
// ���̈ړ���
#define ARROW_MOVE 0.5f

// ���̍��W
float ArrowPos[2];
// �{�[�h�̍��W
int BoardPos;
// �{�[�h�̈ړ���
int MoveDistance;

// �ړ��������ǂ���
bool isMove;
// �ړ����� (0 �� ���A1 �� �E)
int direction;

Select::Select()
{
	LoadFile();
}

Select::~Select()
{
	UnLoadFile();
}

// �Z���N�g�V�[���Ŏg�p����t�@�C���̓ǂݍ���
void Select::LoadFile()
{
	FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT);
	FileManager::Instance()->GetFileHandle(STAGESELECT_BACK);
	FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW);
	FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW);
	FileManager::Instance()->GetFileHandle(STAGE_BOARD);
	FileManager::Instance()->GetFileHandle(START_TEXT);

	// �ǂݍ��ݏI������珉����
	Initialize();
}

// �Z���N�g�V�[���Ŏg�p�����t�@�C���̔j��
void Select::UnLoadFile()
{
	FileManager::Instance()->ResetData();
}

// ������
void Select::Initialize()
{
	AudioManager::Instance()->playBGM(SELECT_BGM);

	isMove = FALSE;

	// �������W�̐ݒ�
	BoardPos = 120;
	ArrowPos[0] = 32;
	ArrowPos[1] = 576;
}

// �X�V
void Select::Update()
{
	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		// �V�[���t�F�[�h���Ă���V�[�����Q�[���ɕύX
		Scene::SceneFade(Scene::GAME);
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_RIGHT)) {
		// �ړ����łȂ����
		if (!isMove) {
			direction = 1;
			isMove = TRUE;
		}
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_LEFT)) {
		// �ړ����łȂ����
		if (!isMove) {
			direction = 0;
			isMove = TRUE;
		}
	}

	if (isMove){
		switch (direction) {
		// ���ړ�
		case 0:
			// �ړ��ʂ��v��
			MoveDistance += BOARD_MOVE;
			// ���ۂ̍��W�̕ύX
			BoardPos += BOARD_MOVE;
			// �ړ��ʂ��X�N���[��1���𒴂�����ړ��I��
			if (MoveDistance >= SCREEN_WIDTH) {
				MoveDistance = 0;
				isMove = FALSE;
			}
			break;
		// �E�ړ�
		case 1:
			// �ړ��ʂ��v��
			MoveDistance -= BOARD_MOVE;
			// ���ۂ̍��W�̕ύX
			BoardPos -= BOARD_MOVE;
			// �ړ��ʂ��X�N���[��1���𒴂�����ړ��I��
			if (MoveDistance <= -SCREEN_WIDTH) {
				MoveDistance = 0;
				isMove = FALSE;

			}
			break;
		}
	}

	ArrowPos[0] += ARROW_MOVE;
	if (ArrowPos[0] >= ARROW_LIMIT) {
		ArrowPos[0] = ARROW_ORIGIN;
	}
}

// �`��
void Select::Draw()
{
	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(STAGESELECT_BACK), TRUE);
	DrawGraph(ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW), TRUE);
	DrawGraph(ArrowPos[1] - ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW), TRUE);
	DrawGraph(160, 10, FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT), TRUE);
	DrawGraph(160, 406, FileManager::Instance()->GetFileHandle(START_TEXT), TRUE);
	DrawGraph(BoardPos, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos - 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos + 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
}