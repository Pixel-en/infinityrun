#pragma once
#include "Engine/GameObject.h"
#include <vector>

using std::vector;
class Player;

class PlayScene : public GameObject
{

	int x1, x2;

	float EnemySpeed;

	Player *p;

	int framecnt;
	bool Spawnbuffer;

public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void EnemySpawn();
};