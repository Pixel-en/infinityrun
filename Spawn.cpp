#include "Spawn.h"
#include "Engine/BoxCollider.h"

Spawn::Spawn(GameObject* parent)
	:GameObject(parent,"Spawn")
{
}

Spawn::~Spawn()
{
}

void Spawn::Initialize()
{

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 6), XMFLOAT3(6, 1, 1.0f));
	AddCollider(collision);
}

void Spawn::Update()
{
}

void Spawn::Draw()
{
}

void Spawn::Release()
{
}

void Spawn::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
		KillMe();
}
