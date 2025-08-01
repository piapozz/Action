#include "../header/BaseObject.h"

void BaseObject::Teardown()
{
	DeleteGraph(drawHandle);
	layer = Layer::INVALID;
	transform.position = Vector3::zero();
}