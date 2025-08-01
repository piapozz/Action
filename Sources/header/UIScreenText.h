#pragma once
#include "../header/BaseUIScreen.h"

/*
* ishihara
* UI�X�N���[���e�L�X�g
*/
class UIScreenText : public BaseUIScreen
{
public:
	std::string GetTypeName() override {
		return "UIScreenText";
	}
	UIScreenText() {
	}
	UIScreenText(Transform setTransform, LayerSetting layerSetting) {
		Init(setTransform, layerSetting);
	}
	UIScreenText(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIScreenText(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIScreenText(const UIScreenText& obj)
		: BaseUIScreen(obj) {
	}
	~UIScreenText() {
	}
	void Init(Transform setTransform, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;

	inline void SetTextColor(int color){
		_textColor = color;
	}
	inline void SetText(const std::string& setText){
		_text = setText;
	}
	inline void SetFontSize(int setSize){ _fontSize = setSize; }
	void DrawUIText();

private:
	std::string _text;
	int _textColor;
	int _fontSize;

	const int _DEFAULT_FONT_SIZE = 24;
};
