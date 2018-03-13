#include "DxLib.h"
#include "Select.h"
#include "AudioManager.h"
#include "FileManager.h"
#include "ObjectManager.h"
#include "Input.h"
#include "Label.h"
#include "Camera.h"

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
int stageNum = 0;

Select::Select()
{
	LoadFile();

	// �������W�̐ݒ�
	BoardPos = 120;
	ArrowPos[0] = 32;
	ArrowPos[1] = 576;

	/*auto StageSelect_back = new Label(FileManager::Instance()->GetFileHandle(STAGESELECT_BACK), 0, 0);
	auto Select_LeftArrow = new Label(FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW), ArrowPos[0], 200);
	auto Select_RightArrow = new Label(FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW), ArrowPos[1] - ArrowPos[0], 200);
	auto StageSelect_text = new Label(FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT), 160, 10);
	auto Stage_board = new Label(FileManager::Instance()->GetFileHandle(STAGE_BOARD), BoardPos, 90);
	auto Stage_board2 = new Label(FileManager::Instance()->GetFileHandle(STAGE_BOARD), BoardPos + 640, 90);
	auto Stage1_image = new Label(FileManager::Instance()->GetFileHandle(STAGE1_IMAGE), BoardPos + 40, 150);
	auto Stage2_image = new Label(FileManager::Instance()->GetFileHandle(STAGE2_IMAGE), BoardPos + 680, 150);*/

	// �ǂݍ��ݏI������珉����
	Initialize();
}

Select::~Select()
{
	UnLoadFile();
}

// �Z���N�g�V�[���Ŏg�p����t�@�C���̓ǂݍ���
void Select::LoadFile()
{

}

// �Z���N�g�V�[���Ŏg�p�����t�@�C���̔j��
void Select::UnLoadFile()
{
	FileManager::Instance()->Initialize();
}

// ������
void Select::Initialize()
{
	AudioManager::Instance()->playBGM(GAME_BGM);

	isMove = FALSE;
}

// �X�V
void Select::Update()
{
	//ObjectManager::Instance()->Update();

	if (Input::Instance()->ButtonDown(KEY_INPUT_RETURN)) {
		switch (stageNum) {
		case 0:
			// �V�[���t�F�[�h���Ă���V�[�����Q�[���ɕύX
			Scene::SceneFade(Scene::GAME, stageNum);
			break;
		case 1:
			// �V�[���t�F�[�h���Ă���V�[�����Q�[���ɕύX
			Scene::SceneFade(Scene::GAME, stageNum);
			break;
		}
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_RIGHT) && stageNum == 0) {
		// �ړ����łȂ����
		if (!isMove) {
			stageNum = 1;
			isMove = TRUE;
		}
	}

	if (Input::Instance()->ButtonDown(KEY_INPUT_LEFT) && stageNum == 1) {
		// �ړ����łȂ����
		if (!isMove) {
			stageNum = 0;
			isMove = TRUE;
		}
	}

	if (isMove) {
		switch (stageNum) {
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
	//ObjectManager::Instance()->Draw();

	DrawGraph(0, 0, FileManager::Instance()->GetFileHandle(STAGESELECT_BACK), TRUE);
	DrawGraph(ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_LEFTARROW), TRUE);
	DrawGraph(ArrowPos[1] - ArrowPos[0], 200, FileManager::Instance()->GetFileHandle(SELECT_RIGHTARROW), TRUE);
	DrawGraph(160, 10, FileManager::Instance()->GetFileHandle(STAGESELECT_TEXT), TRUE);
	DrawGraph(160, 406, FileManager::Instance()->GetFileHandle(START_TEXT), TRUE);
	DrawGraph(BoardPos, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos - 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos + 640, 90, FileManager::Instance()->GetFileHandle(STAGE_BOARD), TRUE);
	DrawGraph(BoardPos + 40, 150, FileManager::Instance()->GetFileHandle(STAGE1_IMAGE), TRUE);
	DrawGraph(BoardPos + 680, 150, FileManager::Instance()->GetFileHandle(STAGE2_IMAGE), TRUE);
}