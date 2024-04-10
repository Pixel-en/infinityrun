#include "PlayScene.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/Debug.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),x1(0),x2(0),EnemySpeed(7.0)
{
}

void PlayScene::Initialize()
{

	for (int i = 0; i < 2; i++) {
		Road* r = Instantiate<Road>(this);
		r->SetPosition(XMFLOAT3(0, -1, i * 18));
		Roads.push_back(r);
	}
	Instantiate<Road>(this);
	Instantiate<Player>(this);

	Camera::SetPosition(XMFLOAT3(0, 1.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 2));
}

void PlayScene::Update()
{



	Debug::Log((int)Roads.size(), true);


	if (FindChildObject("Enemy") == nullptr) {
		EnemySpeed += 0.5;
		x1 = 0;
		x2 = 0;

		while (x1 == x2) {
			x1 = (rand() % 3) - 1;
			x2 = (rand() % 3) - 1;
		}

		Enemy* e1 = Instantiate<Enemy>(this);
		e1->SetPosition(XMFLOAT3(float(x1) * 1.5, 0, 20.0f));
		e1->SetSpeed(EnemySpeed);
		Enemy* e2 = Instantiate<Enemy>(this);
		e2->SetPosition(XMFLOAT3(float(x2) * 1.5, 0, 20.0f));
		e2->SetSpeed(EnemySpeed);

		Debug::Log(EnemySpeed, true);

	}


}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
