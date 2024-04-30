#include "Road.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"

Road::Road(GameObject* parent)
	:GameObject(parent,"Road"),hModel_(-1),speed_(5.0)
{
}

Road::~Road()
{
}

void Road::Initialize()
{
	hModel_ = Model::Load("Model\\Road\\Road6.fbx");
	assert(hModel_ >= 0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 1, 5), XMFLOAT3(6, 1, 0.001f));
	AddCollider(collision);
}

void Road::Update()
{
	//transform_.position_.y = -1;
	transform_.position_.z -= speed_ * 1 / 60;

	if (transform_.position_.z <= -30) {
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
