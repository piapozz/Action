#pragma once
#include "BaseUIScreen.h"
class UIScreenImage:
    public BaseUIScreen
{
public:
	std::string GetTypeName() override {
		return "UIScreenImage";
	}
	UIScreenImage() {
	}
	UIScreenImage(Transform setTransform, bool fill, LayerSetting layerSetting) {
		Init(setTransform, fill, layerSetting);
	}
	UIScreenImage(Layer setLayer)
		: BaseUIScreen(setLayer) {
	}
	UIScreenImage(Layer setLayer, int setDrawHandle)
		: BaseUIScreen(setLayer, setDrawHandle) {
	}
	UIScreenImage(const BaseUIScreen& obj)
		: BaseUIScreen(obj) {
	}
	~UIScreenImage() {
	}

	void Init(Transform setTransform, bool fill, LayerSetting layerSetting);
	void Proc() override;
	void Draw() override;
	void Teardown() override;
	void OnCursor() override;
	void NotOnCursor() override;
	void DrawUIBox();
	inline void SetColor(int color){ _color = color; }
	inline void SetOutLineColor(int color){ _outLineColor = color; }
	inline void SetOnCursorColor(int color){ _onCursorColor = color; }

private:
	bool _fill;
	bool _onCursor;
	int _color;
	int _outLineColor;
	int _onCursorColor;
};

