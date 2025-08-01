#include "DxLib.h"
#include "../header/SceneManager.h"
#include "../header/ObjectManager.h"
#include "../header/AudioManager.h"

// プログラム開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウインドウモードで起動
	ChangeWindowMode(true);

	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);

	// 解像度を設定
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		// エラーが起きたら直ちに終了
		return -1;
	}

	AudioManager::Instance().Init();
	AudioManager::Instance().SetVolume(255);

	// シーンマネージャー生成
	SceneManager* sceneManager = new SceneManager();
	sceneManager->ChangeScene(SceneName::TITLE);

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	// カメラの位置と向きを設定
	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 250.0f, -250.0f), VGet(0.0f, 0.0f, 0.0f));

	// カメラのクリッピング距離を設定
	SetCameraNearFar(16.0f, 10000.0f);

	// 背景の色を灰色にする
	SetBackgroundColor(0, 0, 0);

	// Zバッファを使用する
	SetUseZBufferFlag(false);
	SetWriteZBufferFlag(false);

	// メインループ(何かキーが押されたらループを抜ける)
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// 現在のカウントを取得する
		int time = GetNowCount();

		// 入力処理
		InputManager::Instance().Update();

		// オブジェクト処理
		ObjectManager::Instance().Update();

		// オブジェクト描画
		ObjectManager::Instance().Draw();

		// 17ミリ秒待つ
		while (GetNowCount() - time < 17)
		{
		}
	}

	// シーンマネージャーの削除
	delete sceneManager;

	ObjectManager::Instance().AllClear();	// 全てのオブジェクトを削除
	AudioManager::Instance().DeleteSound();	// 音の削除

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}