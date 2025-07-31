#pragma once
#include "../header/BaseScene.h"

#include "../header/SceneTitle.h"
#include "../header/SceneMain.h"
#include "../header/SceneResult.h"

class InputManager;
/*
* Ishihara
* �V�[���̊Ǘ�
*/
class SceneManager
{
public:

	SceneManager();
	~SceneManager();
	
	/// <summary>
	/// ������
	/// </summary>
	void Init();
	/// <summary>
	/// �V�[���̐؂�ւ�
	/// </summary>
	/// <param name="scene"></param>
	void ChangeScene(SceneName scene);
private:
	// �V�[���̏����i�[
	BaseScene* _scene;
};

