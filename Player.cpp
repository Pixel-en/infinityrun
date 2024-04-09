#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= -1);
}

void Player::Update()
{
	if (Input::IsKeyDown(DIK_LEFT))
		transform_.position_.x -= 1.5;
	else if (Input::IsKeyDown(DIK_RIGHT))
		transform_.position_.x += 1.5;

	if (transform_.position_.x <= -1.5)
		transform_.position_.x = -1.5;
	if (transform_.position_.x >= 1.5)
		transform_.position_.x = 1.5;
	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
