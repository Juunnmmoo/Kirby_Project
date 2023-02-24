#include "moStage1.h"
#include "moInput.h"
#include "moSceneManager.h"
#include "moKirby.h"
#include "moBG_Stage1.h"

namespace mo {
	Stage1::Stage1()
	{
	}

	Stage1::~Stage1()
	{
	}

	void Stage1::Initialize()
	{
		
		mStageBG = new BG_Stage1;
		mStageBG->SetName(L"BG_Stage1");
		addGameObject(mStageBG, eLayerType::BG);
		mKirby = new Kirby;
		mKirby->SetName(L"Kirby");
		addGameObject(mKirby, eLayerType::Player);

		Scene::Initialize();
	}

	void Stage1::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down) {
			SceneManager::LoadScene(eSceneType::Title);
		}
		Scene::Update();
	}

	void Stage1::Render(HDC mHdc)
	{
		Scene::Render(mHdc);
	}

	void Stage1::OnEnter()
	{
	}

	void Stage1::OnExit()
	{
	}

}