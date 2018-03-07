#pragma once

#define FADE_IMAGE "test1.png"

#pragma region DivFile

struct DivFile {
	DivFile(char* name, int nAll, int nX, int nY, int sX, int sY);

	char* name;
	int numAll, numX, numY;
	int sizeX, sizeY;
};
DivFile::DivFile(char* name, int nAll, int nX, int nY, int sX, int sY) {
	numAll = nAll; numX = nX; numY = nY;
	sizeX = sX; sizeY = sY;
}

#pragma endregion

// �V�[���̂��ƂƂȂ�N���X(�p��������)
class BaseScene
{
public:
	// �ǂݍ���
	virtual void LoadFile() = 0;
	// �ǂݍ��񂾃t�@�C���̔j��
	virtual void UnLoadFile() = 0;
	// ������
	virtual void Initialize() = 0; 
	// �X�V
	virtual void Update() = 0;
	// �`��
	virtual void Draw() = 0;
};

// �V�[�����Ǘ�����N���X
class Scene
{
public:
	Scene();
	~Scene();

	// �V�[���^�C�v
	enum SCENE {
		TITLE,
		SELECT,
		GAME
	};

	// �V�[���ύX
	static void ChangeScene(SCENE scene);
	// �V�[���t�F�[�h
	static void SceneFade(SCENE nextScene);
	// �X�V
	static void Update();
	// �`��
	static void Draw();
private:
	// ���݂̃V�[��
	static BaseScene* c_Scene;
};
