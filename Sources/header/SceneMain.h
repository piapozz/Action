#pragma once
#include "../header/BaseScene.h"
class GameManager;
/*
* Ishihara
* メインシーン
*/
class SceneMain : public BaseScene
{
public:
    SceneMain();
    ~SceneMain();

    /// <summary>
    /// 初期化
    /// </summary>
    void Init();

private:
	GameManager* _pGameManager;
};

