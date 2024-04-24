#pragma once
#include "Engine/GameObject.h"


class PlayCamera : public GameObject
{

public:
    //�R���X�g���N�^
    PlayCamera(GameObject* parent);

    //�f�X�g���N�^
    ~PlayCamera();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};