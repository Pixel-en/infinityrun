#pragma once
#include "Engine/GameObject.h"

class Player;

class PlayScene : public GameObject
{

	int x1, x2;

	float EnemySpeed;

	Player *p;

	bool Spawnbuffer;
	int pdownbuffer;


public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void EnemySpawn();

	float GetEnemySpeed() { return EnemySpeed; }
};