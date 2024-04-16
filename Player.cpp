#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Engine/SphereCollider.h"
#include "ResultScene.h"

namespace {
	const float MOVE_SPEED{ 3.0f };	//プレイヤーの動くスピード
	const float MAX{ 1.5 };			//左右のx座標
}


Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), Lon_(false),Ron_(false),temp_(0.0),roadin_(false), secondcnt(0), point(0)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= -1);

	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.3, 0.05), 0.3f);
	AddCollider(collision);
}

void Player::Update()
{
	if (Input::IsKeyDown(DIK_LEFT) && !Ron_)
		Lon_ = true;
	if (Input::IsKeyDown(DIK_RIGHT) && !Lon_)
		Ron_ = true;

	if (Lon_)
		transform_.position_.x -= MOVE_SPEED * 1.0 / 60.0;
	if (Ron_)
		transform_.position_.x += MOVE_SPEED * 1.0 / 60.0;

	if (Lon_ || Ron_) {
		temp_ += MOVE_SPEED * 1 / 60;
		if (temp_ >= MAX) {
			Lon_ = false;
			Ron_ = false;
			temp_ = 0.0;
		}
		
		if (transform_.position_.x < -MAX)	//左の場所矯正
			transform_.position_.x = -MAX;

		if (transform_.position_.x > MAX)	//右の場所矯正
			transform_.position_.x = MAX;
	}

	secondcnt++;

	if (secondcnt >= 60) {
		secondcnt = 0;
		point++;
	}

}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy") {
		//ResultScene* r = (ResultScene*)FindObject("ResultScene");
		//r->Setpoint(point);
		KillMe();
	}

	if (pTarget->GetObjectName() == "Road") {
		roadin_ = true;
	}
}
