#include "UI.h"
#include "DxLib.h"

/////////////////////////////////////////////////////
//����			:�摜�̃p�X�A�����W�A�����W�A,�\����\��(�f�t�H���g�͕\��(true))�A��](�f�t�H���g�͉�]����)�A�T�C�Y(�f�t�H���g�͓��g)�A�`��̗D��x(�f�t�H���g��20)
//�߂�l		:�Ȃ�
//����			:�l�̏�����
/////////////////////////////////////////////////////
UI::UI(string s, float x, float y, bool drawFlg, double rotation, double scale, int priority)
{
	//������
	GraphHandle(FileManager::Instance()->GetFileHandle(s));
	PositionX(x);
	PositionY(y);
	DisplayFlg(drawFlg);
	Rotation(rotation);
	Scale(scale);
	Priority(priority);
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�摜�̕`��
/////////////////////////////////////////////////////
void UI::Draw()
{
	if (Rotation() != 0 || Scale() != 1.0)
		DrawRotaGraphF(PositionX(), PositionY(), Scale(), Rotation(), GraphHandle(), TRUE);
	else
		DrawGraphF(PositionX(), PositionY(), GraphHandle(), TRUE);
}

/////////////////////////////////////////////////////
//����			:�`�悷��A���Ȃ��𔻒f����t���O(�f�t�H���g��true(�\��))
//�߂�l		:�Ȃ�
//����			:�摜�̕\����\��
/////////////////////////////////////////////////////
void UI::DrawDisplay(bool drawFlg)
{
	DisplayFlg(drawFlg);

	if (DisplayFlg())
	{
		Draw();
	}
}

/////////////////////////////////////////////////////
//����			:�����W�A�����W�A�\����\��(�f�t�H���g�͕\��(true))�A��](�f�t�H���g�͉�]����)�A�T�C�Y(�f�t�H���g�͓��g)�A�`��̗D��x(�f�t�H���g��20)
//�߂�l		:�Ȃ�
//����			:�ʒu�̍X�V
/////////////////////////////////////////////////////
void UI::UIMove(float x, float y, double rotation, double scale, int priority)
{
	PositionX(x);
	PositionY(y);
	Rotation(rotation);
	Scale(scale);
	Priority(priority);
}

/////////////////////////////////////////////////////
//����			:�Ȃ�
//�߂�l		:�Ȃ�
//����			:�摜�f�[�^���폜
/////////////////////////////////////////////////////
void UI::Delete()
{
	DeleteGraph(GraphHandle());
}

/////////////////////////////////////////////////////
//�v���p�e�B
/////////////////////////////////////////////////////
void UI::DisplayFlg(bool drawFlg) { _display = drawFlg; }
bool UI::DisplayFlg() { return _display; }