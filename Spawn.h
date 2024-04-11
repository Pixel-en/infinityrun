#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Spawn : public GameObject
{

public:
    //�R���X�g���N�^
    Spawn(GameObject* parent);

    //�f�X�g���N�^
    ~Spawn();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
};