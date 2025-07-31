#include "../header/SceneManager.h"
#include "../header/InputManager.h"
#include "../header/Objectmanager.h"

SceneManager::SceneManager() 
{
	_scene = nullptr;
}

SceneManager::~SceneManager() 
{
	delete _scene;
}

void SceneManager::Init() 
{

}

void SceneManager::ChangeScene(SceneName scene)
{
	if (scene == SceneName::INVALID) return;
	// ���݂̃V�[�����󂶂�Ȃ�������A�V�[���̏���j������
	delete(_scene);

	ObjectManager::Instance().AllClear();
	InputManager::Instance().Teardown();

	// �����̃V�[���ɐ؂�ւ���
	switch (scene)
	{
	case SceneName::TITLE:
		_scene = new SceneTitle();
		break;
	case SceneName::MAIN:
		_scene = new SceneMain();
		break;
	case SceneName::RESULT:
		_scene = new SceneResult();
		break;
	case SceneName::EXIT:
		DxLib_End();
		return;
	default:
		break;
	}
	// �R�[���o�b�N��ݒ�
	_scene->SetCallback([this](SceneName nextScene) { this->ChangeScene(nextScene); });
	// �����������Ă���
	_scene->Init();
	InputManager::Instance().Init();
}