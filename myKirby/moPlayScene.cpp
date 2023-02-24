#include "moPlayScene.h"
#include "moKirby.h"

namespace mo {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		Kirby* kirby = new Kirby;
		addGameObject(kirby, eLayerType::Player);

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}
}