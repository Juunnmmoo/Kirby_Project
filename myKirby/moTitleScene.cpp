#include "moTitleScene.h"
#include "moInput.h"
#include "moSceneManager.h"

namespace mo {



	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down) {
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void TitleScene::Render(HDC mHdc)
	{
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
	
}