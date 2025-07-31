#pragma once
#include "DxLib.h"
#include "../header/PhaseManager.h"

/*
 * Sein
 * ���C���Q�[���̐i�s���Ǘ�
 */
class GameManager
{
public:

	GameManager();
	~GameManager();

	/// <summary>
	/// ������
	/// </summary>
	void Init();
	inline void SetChangeSceneCallback(std::function<void(SceneName)> setCallback){ _ChangeScene = setCallback; };

private:
	PhaseManager* _pPhaseManager;
	std::function<void(SceneName)> _ChangeScene;
};