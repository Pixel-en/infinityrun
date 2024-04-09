#include "TestScene.h"
#include "Road.h"
#include "Player.h"
#include "Engine/Camera.h"

TestScene::TestScene(GameObject* parent)
{
}

void TestScene::Initialize()
{
	Instantiate<Road>(this);
	Instantiate<Player>(this);

	Camera::SetPosition(XMFLOAT3(0, 1.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 2));
}

void TestScene::Update()
{
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
