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
		Scene::Initialize();

		Kirby* kirby = new Kirby;
		addGameObject(kirby, eLayerType::Player);

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