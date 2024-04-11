#include "PlayScene.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Road.h"
#include "Spawn.h"
#include "Engine/Debug.h"
#include "Engine/BoxCollider.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),x1(0),x2(0),EnemySpeed(21.0),framecnt(0),Spawnbuffer(false)
{
}

void PlayScene::Initialize()
{

	Road* r=Instantiate<Road>(this);
	p = Instantiate<Player>(this);
	Instantiate<Spawn>(this);

	Camera::SetPosition(XMFLOAT3(0, 1.5, -3));
	Camera::SetTarget(XMFLOAT3(0, 0, 2));


}

void PlayScene::Update()
{

	if (p->GetRoadIn()) {
		FindChildObject("Road")->ClearCollider();
		Road* r = Instantiate<Road>(this);
		r->SetPosition(XMFLOAT3(0, 0, 15));	//z18-コライダーの位置
		p->SetRoadIn(false);
	}

	if (FindChildObject("Enemy") == nullptr || (FindObject("Spawn") == nullptr && !Spawnbuffer)) {
		EnemySpawn();
		Spawnbuffer = true;
	}

	if (Spawnbuffer) {
		framecnt++;
		if (framecnt >= 60-(EnemySpeed-7)) {
			Instantiate<Spawn>(this);
			Spawnbuffer = false;
			framecnt = 0;
		}
	}

}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}

void PlayScene::EnemySpawn()
{

	EnemySpeed += 0.25;
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
}
