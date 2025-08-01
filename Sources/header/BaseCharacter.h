#pragma once
#include "BaseObject.h"

class BaseCharacter : public BaseObject
{
public:
	BaseCharacter() {};
	~BaseCharacter() {};

	void Init() {};
	void Draw() override;
protected:
	void Move(Vector2 moveVec);
private:
	int _modelHandle;
};
