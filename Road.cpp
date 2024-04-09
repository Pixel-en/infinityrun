#include "Road.h"
#include "Engine/Model.h"

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
}

void Road::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Road::Release()
{
}
