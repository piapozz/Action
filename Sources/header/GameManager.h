#pragma once
#include "DxLib.h"
#include <functional>
#include "Const.h"

/*
 * Sein
 * メインゲームの進行を管理
 */
class GameManager
{
public:

	GameManager();
	~GameManager();

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();
	inline void SetChangeSceneCallback(std::function<void(SceneName)> setCallback){ _ChangeScene = setCallback; };

private:
	std::function<void(SceneName)> _ChangeScene;
};