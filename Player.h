#pragma once
#include "Engine/GameObject.h"

class Player : public GameObject
{

    int hModel_;
    bool Lon_;
    bool Ron_;
    float move_;

    bool roadin_;

    int secondcnt;
    int point;

    float upspeed_;
    bool deadme_;
public:


    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    bool GetRoadIn() { return roadin_; }
    void SetRoadIn(bool _set) { roadin_ = _set; }

    float Getupspeed() { return upspeed_; }
    void Setupspeed(float _set) { upspeed_ = _set; }

    bool GetDeadMe() { return deadme_; }
    void SetDeadMe(bool _set) { deadme_ = _set; }
};