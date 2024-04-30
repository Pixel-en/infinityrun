#include "PlayCamera.h"
#include "Engine/Camera.h"


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

	//if (Input::IsKey(DIK_V)) {
	//	VerticalVibration();
	//	HorizontalVibration();
	//}
}

void PlayCamera::Draw()
{
}

void PlayCamera::Release()
{
}

void PlayCamera::VerticalVibration()
{
	target.y = (float(rand() % 10) - (10 / 2)) / 100.0f;
	Camera::SetTarget(target);
}

void PlayCamera::VerticalVibration(float _Vsize)
{
	target.y = (float(rand() % 40) - (40 / 2)) / _Vsize;
	Camera::SetTarget(target);
}

void PlayCamera::HorizontalVibration()
{

	target.x = (float(rand() % 10) - (10 / 2)) / 100.0f;
	Camera::SetTarget(target);
}

void PlayCamera::HorizontalVibration(float _Vsize)
{
	target.x = (float(rand() % 40) - (40 / 2)) / _Vsize;
	Camera::SetTarget(target);
}
