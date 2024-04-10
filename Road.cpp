#include "Road.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"

Road::Road(GameObject* parent)
	:GameObject(parent,"Road"),hModel_(-1)
{
}

Road::~Road()
{
}

void Road::Initialize()
{
	hModel_ = Model::Load("Model\\floor.fbx");
	assert(hModel_ >= 0);
}

void Road::Update()
{
	transform_.position_.y = -1;
	transform_.position_.z -= 5.0 * 1 / 60;

	if (transform_.position_.z <= -20) {
		KillMe();
	}
}

void Road::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Road::Release()
{
}
