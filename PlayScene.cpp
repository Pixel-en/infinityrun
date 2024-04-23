#include "PlayScene.h"
#include "Engine/Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Road.h"
#include "Spawn.h"
#include "Engine/BoxCollider.h"
#include "Engine/SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),x1(0),x2(0),EnemySpeed(7.0),framecnt(0),Spawnbuffer(false), pdownbuffer(0)
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

	//Debug::Log(GetChildListSize(), true);

	Debug::Log(FindChildObjectCount("Enemy"), true);

	//道を出現させる
	if (p->GetRoadIn()) {
		FindChildObject("Road")->ClearCollider();
		Road* r = Instantiate<Road>(this);
		r->SetPosition(XMFLOAT3(0, 0, 15));	//z18-コライダーの位置
		p->SetRoadIn(false);
	}


	//敵をスポーンさせる
	if (FindChildObject("Enemy") == nullptr || (FindObject("Spawn") == nullptr && !Spawnbuffer)) {
		EnemySpawn();
		Spawnbuffer = true;
	}

	//スポーンラインを出す
	if (Spawnbuffer) {
		//framecnt++;
		//if (framecnt >= 60-(EnemySpeed-7)*2) {
		if (FindChildObjectCount("Enemy") <= 2) {
			Instantiate<Spawn>(this);
			Spawnbuffer = false;
		}
	}

	//プレイヤーが倒れてからリザルトまでのバッファをとる
	if (FindChildObject("Player") == nullptr) {
		if (pdownbuffer <= 0) {
			SetFlagAllChildren(true, true, true);
		}
		pdownbuffer++;
		if (pdownbuffer >= 60) {
			SceneManager* s = (SceneManager*)FindObject("SceneManager");
			s->ChangeScene(SCENE_ID_RESULT);
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
	if (EnemySpeed < 40.0) {
		EnemySpeed += 0.25;
		p->Setupspeed(p->Getupspeed() - 0.025);
	}

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
