#pragma once

#include <vector>

using namespace std;

class Object
{
public:
	Object();
	Object(int order);
	Object(Object* parent, int order = 0);
	~Object();
	virtual void Update();
	virtual void Draw();
	virtual void Draw(float cameraX, float cameraY);

	void Parent(Object* parent);	// �e�I�u�W�F�N�g
	Object* Parent();				// �e�I�u�W�F�N�g
	Object* GetChild(int num);		// �q�I�u�W�F�N�g�̎擾
	const int GetChildCount();		// �q�I�u�W�F�N�g�̐��̎擾

	string GetTag() { return tag; }

	#pragma region Priority
	void Priority(int order);		// �D�揇��
	int Priority();					// �D�揇��
	#pragma endregion

	#pragma region Graph
	void GraphWidth(float width);	// �`��摜�T�C�Y
	float GraphWidth();				// �`��摜�T�C�Y
	void GraphHeight(float height);	// �`��摜�T�C�Y
	float GraphHeight();			// �`��摜�T�C�Y
	#pragma endregion

	#pragma region Transform
	void SetPosition(float posX, float posY);		//���W�̃Z�b�g
	void SetLocalPosition(float posX, float posY);	//���W�̃Z�b�g

	void PositionX(float posX);			// X���̈ʒu(���)
	float PositionX();					// X���̈ʒu(���)
	void LocalPositionX(float posX);	// X���̈ʒu(����)
	float LocalPositionX();				// X���̈ʒu(����)

	void PositionY(float posY);			// Y���̈ʒu(���)
	float PositionY();					// Y���̈ʒu(���)
	void LocalPositionY(float posX);	// X���̈ʒu(����)
	float LocalPositionY();				// X���̈ʒu(����)

	void Rotation(double degree);		// ��](���)
	double Rotation();					// ��](���)
	void LocalRotation(double degree);	// ��](����)
	double LocalRotation();				// ��](����)

	void Scale(double rate);			// �g�嗦(���)
	double Scale();						// �g�嗦(���)
	void LocalScale(double rate);		// �g�嗦(����)
	double LocalScale();				// �g�嗦(����)
	#pragma endregion

protected:

	string tag;						//���[�U�[��`�̃f�[�^

	void GraphHandle(int graph);	// �`��摜
	int GraphHandle();				// �`��摜

private:
	Object* _parent;			// �e�I�u�W�F�N�g
	vector<Object*> _child;		// �q�I�u�W�F�N�g
	int _handle;				// �`��摜
	int _priority;				// �D�揇��
	int _gWidth, _gHeight;		// �摜�T�C�Y(�s�N�Z��)
	float _x, _y;				// ���W(����)
	double _rotation;			// ��](����)
	double _scale;				// �g�嗦(����)

	void Initialize(int order = 0);	//�����p������

	//���W�ϊ��n
	float ConvertToWorldX();
	float ConvertToWorldY();
	float ConvertToWorldRotation();
	double ConvertToWorldScale();
};