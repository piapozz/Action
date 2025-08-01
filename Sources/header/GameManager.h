#pragma once
#include "DxLib.h"
#include <functional>
#include "Const.h"

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
	std::function<void(SceneName)> _ChangeScene;
};