#pragma once
#include "Engine/GameObject.h"

class Enemy : public GameObject
{

    int hModel_;
    float speed_;

    std::string a;

public:

    //�R���X�g���N�^
    Enemy(GameObject* parent);

    //�f�X�g���N�^
    ~Enemy();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetSpeed(float _speed) { speed_ = _speed; }


};