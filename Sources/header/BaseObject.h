#pragma once
#include "../header/CommonModule.h"
#include "../header/Const.h"
/*
* Ishihara
* オブジェクトの基底
*/
class BaseObject
{
public:
	size_t poolIndex = 0;

	BaseObject(){
		objectType = ObjectType::INVALID;
		transform = Transform();
	 }
	BaseObject(Transform setTransform, LayerSetting layerSetting)
		: transform(setTransform), active(layerSetting.m_active),
		interactable(layerSetting.m_interact), layer(layerSetting.m_layer) {
		objectType = ObjectType::INVALID;
		drawHandle = -1;
	}
	BaseObject(const BaseObject& obj)
		: layer(obj.layer),drawHandle(obj.drawHandle){}
	virtual ~BaseObject(){
		transform.parent = nullptr;
	}

	/// <summary>
	/// アップデート
	/// </summary>
	virtual void Proc(){}
	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw(){}
	/// <summary>
	/// 破棄
	/// </summary>
	virtual void Teardown();
	virtual void ClickEvent(){}
	virtual void OnCursor(){}
	virtual void NotOnCursor(){}
	virtual void StartDrack(){}
	virtual void OnDrack(){}
	virtual void EndDrack(){}

	static std::string StaticTypeName() {
		return "BaseObject";
	}

	inline Vector3 GetPosition(){ return transform.position; }
	inline Layer GetLayer() { return layer; }
	inline ObjectType GetType() { return objectType; }
	inline Vector3 GetScale(){ return transform.scale; }
	inline bool GetActive() { return active; }
	inline bool GetInteract() { return interactable; }
	inline Transform GetTransform() { return transform; }
	inline void SetPosition(Vector3 setPosition){ transform.position = setPosition; }
	inline void SetScale(Vector3 setSize){ transform.scale = setSize; }
	virtual void SetActive(bool setActive){ active = setActive; }
	inline void SetInteract(bool setInteract){ interactable = setInteract; }
	inline void SetParent(BaseObject* parent) { transform.parent = parent; }
protected:
	// 基本情報
	Transform transform;
	// アクティブ状態
	bool active;
	// インタラクト可能か
	bool interactable;
	// レイヤー
	Layer layer;
	// 描画用のハンドル
	int drawHandle;
	// どのタイプか
	ObjectType objectType;
};