#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class TestObject : public GameObject
{

public:
    //コンストラクタ
    TestObject(GameObject* parent);

    //デストラクタ
    ~TestObject();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};