#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class TestObject : public GameObject
{

public:
    //�R���X�g���N�^
    TestObject(GameObject* parent);

    //�f�X�g���N�^
    ~TestObject();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};