#include "../header/UIScreenText.h"
#include "../header/UIManager.h"

void UIScreenText::Init(Transform setTransform, LayerSetting layerSetting)
{
	BaseUIScreen::Init(setTransform, layerSetting);
	_text = "";
	_textColor = GetColor(255, 255, 255);
	_fontSize = _DEFAULT_FONT_SIZE;
}

void UIScreenText::Proc()
{
	// �A�b�v�f�[�g
	BaseUIScreen::Proc();
}

void UIScreenText::Draw()
{
	// �`��
	BaseUIScreen::Draw();
	DrawUIText();
}

void UIScreenText::Teardown()
{
	// �j��
	BaseUIScreen::Teardown();
}

void UIScreenText::DrawUIText()
{
	if (_text.empty()) return;

	// ���[���h���W�擾
	Transform transformWorld = transform.GetWorldTransform();
	Vector2 position = transformWorld.position;

	// �e�L�X�g�T�C�Y�擾
	int fontHandle = UIManager::Instance().GetFontHandle(_fontSize);
	int textWidth = GetDrawFormatStringWidthToHandle(fontHandle, _text.c_str());

	// ���������̂��߂�x���W��␳
	int anchorX = position.x - textWidth / 2;
	int anchorY = position.y;

	DrawFormatStringToHandle(anchorX, anchorY, _textColor, fontHandle, _text.c_str());
}