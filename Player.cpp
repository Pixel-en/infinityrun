#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SphereCollider.h"
#include "Engine/SceneManager.h"


namespace {
	const float MOVE_SPEED{ 3.0f };	//プレイヤーの動くスピード
	const float MAX{ 1.5 };			//左右のx座標
}


Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1), Lon_(false), Ron_(false), move_(0.0), roadin_(false),
	secondcnt(0), point(0), upspeed_(0.0f), deadme_(false)
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
		transform_.position_.x -= (MOVE_SPEED - upspeed_) * 1.0 / 60.0;
	if (Ron_)
		transform_.position_.x += (MOVE_SPEED - upspeed_) * 1.0 / 60.0;

	if (Lon_ || Ron_) {
		move_+= (MOVE_SPEED - upspeed_) * 1.0 / 60.0;
		if (move_ >= MAX) {
			Lon_ = false;
			Ron_ = false;
			move_ = 0.0;
		}
		
		if (transform_.position_.x < -MAX)	//左の場所矯正
			transform_.position_.x = -MAX;

		if (transform_.position_.x > MAX)	//右の場所矯正
			transform_.position_.x = MAX;

		if (transform_.position_.x < -1.0f && transform_.position_.x>1.0f)
			transform_.position_.x = 0.0f;
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
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->SetPoint(point);
		deadme_ = true;	
		//KillMe();
	}

	if (pTarget->GetObjectName() == "Road") {
		roadin_ = true;
	}
}
