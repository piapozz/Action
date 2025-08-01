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
	// 現在のシーンが空じゃなかったら、シーンの情報を破棄する
	delete(_scene);

	ObjectManager::Instance().AllClear();
	InputManager::Instance().Teardown();

	// 引数のシーンに切り替える
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
	// コールバックを設定
	_scene->SetCallback([this](SceneName nextScene) { this->ChangeScene(nextScene); });
	// 初期化をしておく
	_scene->Init();
	InputManager::Instance().Init();
}