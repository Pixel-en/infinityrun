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


    //コンストラクタ
    Player(GameObject* parent);

    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;

    bool GetRoadIn() { return roadin_; }
    void SetRoadIn(bool _set) { roadin_ = _set; }

    float Getupspeed() { return upspeed_; }
    void Setupspeed(float _set) { upspeed_ = _set; }

    bool GetDeadMe() { return deadme_; }
    void SetDeadMe(bool _set) { deadme_ = _set; }
};