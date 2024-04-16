#include "ResultScene.h"
#include "Engine/Image.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

ResultScene::ResultScene(GameObject* parent)
	:GameObject(parent,"ResultScene"),hImage_(-1), pText(nullptr)
{
}

void ResultScene::Initialize()
{
	hImage_ = Image::Load("");
	//assert(hImage_ >= 0);

	pText = new Text;
	pText->Initialize();
}

void ResultScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE)) {
		SceneManager* s = (SceneManager*)FindObject("SceneManager");
		s->ChangeScene(SCENE_ID_TITLE);
	}
}

void ResultScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);

	//pText->Draw(400, 300, point);
}

void ResultScene::Release()
{
}
