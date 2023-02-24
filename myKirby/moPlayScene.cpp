#include "moPlayScene.h"
#include "moKirby.h"
#include "moInput.h"
#include "moSceneManager.h"

namespace mo {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		mKirby = new Kirby;
		mKirby->SetName(L"Kirby");
		addGameObject(mKirby, eLayerType::Player);

		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down) {
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();
	}
	void PlayScene::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		//mKirby->SetPos(Vector2{ 0.0f, 0.0f });
	}
}