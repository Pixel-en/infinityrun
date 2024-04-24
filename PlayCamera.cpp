#include "PlayCamera.h"
#include "Engine/Camera.h"


PlayCamera::PlayCamera(GameObject* parent)
{
}

PlayCamera::~PlayCamera()
{
}

void PlayCamera::Initialize()
{
	Camera::SetPosition(XMFLOAT3(0, 1.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 2));
}

void PlayCamera::Update()
{
}

void PlayCamera::Draw()
{
}

void PlayCamera::Release()
{
}
