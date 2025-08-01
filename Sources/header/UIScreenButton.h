#pragma once
#include "UIScreenImage.h"
#include "UIScreenText.h"
#include <functional>
/*
* Ishihara
* UI�X�N���[���{�^��
*/
class UIScreenButton : public BaseUIScreen
{
public:
	UIScreenButton() {
		/*_pText = nullptr;
		_pImage = nullptr;
		_callback = []() {};*/
	}
	UIScreenButton(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIScreenButton(Layer setLayer)
		: BaseUIScreen(setLayer) {}
	UIScreenButton(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {}
	UIScreenButton(const UIScreenButton& obj)
		: BaseUIScreen(obj) {}
	~UIScreenButton() {}
	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void ClickEvent() override { _callback(); }

	std::string GetTypeName() override {
		return "UIScreenButton";
	}

	void SetText(std::string str) {
		_pText->SetText(str);
	}

	void SetTextColor(int color) {
		_pText->SetTextColor(color);
	}

	void SetActive(bool active) override {
		BaseObject::SetActive(active);
		_pImage->SetActive(active);
		_pText->SetActive(active);
	}

	void OnCursor() override {
		_pImage->OnCursor();
	};
	void NotOnCursor() override {
		_pImage->NotOnCursor();
	};
	inline void SetFontSize(int setSize){ _pText->SetFontSize(setSize); }

	/// <summary>
	/// �R�[���o�b�N�̐ݒ�
	/// </summary>
	/// <param name="callback"></param>
	void SetCallback(std::function<void()> callback) { _callback = callback; }
private:
	UIScreenText* _pText;
	UIScreenImage* _pImage;
	// �R�[���o�b�N
	std::function<void()> _callback;
};
