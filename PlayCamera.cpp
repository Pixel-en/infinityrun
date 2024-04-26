#include "PlayCamera.h"
#include "Engine/Camera.h"
#include "Engine/Input.h"


PlayCamera::PlayCamera(GameObject* parent)
	:GameObject(parent,"PlayCamera"),target(0,0,2)
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
	if (Input::IsKey(DIK_V)) {
		VerticalVibration();
		HorizontalVibration();
	}
}

void PlayCamera::Draw()
{
}

void PlayCamera::Release()
{
}

void PlayCamera::VerticalVibration()
{
	target.y = (float(rand() % 5)-2) / 100.0f;
	Camera::SetTarget(target);
}

void PlayCamera::HorizontalVibration()
{

	target.x = (float(rand() % 5)-2) / 100.0f;
	Camera::SetTarget(target);
}
