#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Spawn : public GameObject
{

public:
    //コンストラクタ
    Spawn(GameObject* parent);

    //デストラクタ
    ~Spawn();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void OnCollision(GameObject* pTarget) override;
};