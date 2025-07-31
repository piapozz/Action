#include "../header/SceneResult.h"
#include "../header/ObjectFactory.h"
#include "../header/UIScreenText.h"
#include "../header/UIScreenButton.h"
#include "../header/DataManager.h"
#include "../header/Camera.h"

SceneResult::SceneResult()
{

}

SceneResult::~SceneResult()
{

}

void SceneResult::Init()
{
	InputManager& inputManager = InputManager::Instance();
	inputManager.SetOnCursorCallback([this](Vector2 pos){ this->OnCursorProc(pos); });
	inputManager.SetLPushCallback([this](Vector2 pos){ this->LPushInputProc(pos); });
	inputManager.SetLDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->LDrackInputProc(pos, oldPos); });
	inputManager.SetLReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->LReleaseInputProc(pos, oldPos); });
	inputManager.SetRPushCallback([this](Vector2 pos){ this->RPushInputProc(pos); });
	inputManager.SetRDrackCallback([this](Vector2 pos, Vector2 oldPos){ this->RDrackInputProc(pos, oldPos); });
	inputManager.SetRReleaseCallback([this](Vector2 pos, Vector2 oldPos){ this->RReleaseInputProc(pos, oldPos); });
	inputManager.SetWheelRotCallback([this](Vector2 pos, int rot){ this->WheelRotInputProc(pos, rot); });
	inputManager.SetEscapeCallback([this](){ this->EscapeInputProc(); });

	Transform trans = Transform(TITLE_POS, TITLE_SIZE);

	UIScreenText* uiTitle = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(TITLE_POS, TITLE_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	uiTitle->SetText("�Q�[���N���A");
	uiTitle->SetFontSize(TITLE_FONT_SIZE);
	UIScreenText* uiDays = ObjectFactory::Instance().CreateWithArgs<UIScreenText>(Transform(DAYS_POS, DAYS_SIZE), LayerSetting{true, false, Layer::MIDDLE});
	int days = DataManager::Instance().GetEnergy();
	std::string daysText = std::to_string(MAX_DAY) + "���ڂ����z����" ;
	uiDays->SetText(daysText);
	uiDays->SetFontSize(50);

	trans = Transform(BACK_POS, BACK_SIZE);
	LayerSetting layer = {true, true, Layer::BACK};
	UIScreenButton* backButton = ObjectFactory::Instance().CreateWithArgs<UIScreenButton>(trans, true, layer);
	backButton->SetText("�^�C�g���ɖ߂�");
	backButton->SetCallback([this]() {
		if (ChangeScene != nullptr) ChangeScene(SceneName::TITLE);
	});

	// �J��������
	_pCamera = new Camera();
}

void SceneResult::OnCursorProc(Vector2 pos)
{
	// �ȑO����Ă����I�u�W�F�N�g������Ă��Ȃ�����
	BaseObject* onCursorObj = InputManager::Instance().GetOnCursorObject();
	if (onCursorObj != nullptr)
	{
		onCursorObj->NotOnCursor();
	}

	// �X�N���[��UI
	// UI�̎擾
	BaseObject* screenUI = ObjectManager::Instance().FindPosObject(pos);
	if (screenUI != nullptr)
	{
		screenUI->OnCursor();
		InputManager::Instance().SetOnCursorObject(screenUI);
		return;
	}
}

void SceneResult::LPushInputProc(Vector2 pos)
{

}

void SceneResult::RPushInputProc(Vector2 pos)
{

}

void SceneResult::LDrackInputProc(Vector2 pos, Vector2 oldPos)
{

}

void SceneResult::RDrackInputProc(Vector2 pos, Vector2 oldPos)
{
}

void SceneResult::LReleaseInputProc(Vector2 pos, Vector2 oldPos)
{
	// �N���b�N�������ꂽ�Ȃ�
	if (InputManager::Instance().IsLeftClick(pos))
	{
		// �X�N���[��UI
		BaseObject* object = ObjectManager::Instance().FindPosObject(pos);
		if (object != nullptr)
		{
			object->ClickEvent();
			return;
		}
	}
}

void SceneResult::RReleaseInputProc(Vector2 pos, Vector2 oldPos)
{

}

void SceneResult::WheelRotInputProc(Vector2 pos, int rot)
{

}

void SceneResult::EscapeInputProc()
{

}
