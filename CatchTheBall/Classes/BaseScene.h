#pragma once

#define FADE_IMAGE "test1.png"

// �V�[���̂��ƂƂȂ�N���X(�p��������)
class BaseScene
{
public:
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
