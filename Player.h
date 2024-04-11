#pragma once
#include "Engine/GameObject.h"


class Player : public GameObject
{

    int hModel_;
    bool Lon_;
    bool Ron_;
    float temp_;

    bool roadin_;

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
};