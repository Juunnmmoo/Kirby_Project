#include "moSceneManager.h"
#include "moPlayScene.h"
#include "moTitleScene.h"
#include "moStage1.h"

namespace mo {

	std::vector<Scene*> SceneManager::mScenes;
	Scene* SceneManager::mActiveScene;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		mScenes[(UINT)eSceneType::Title] = new TitleScene;
		mScenes[(UINT)eSceneType::Title]->SetName(L"TitleScene");

		mScenes[(UINT)eSceneType::Play] = new PlayScene;
		mScenes[(UINT)eSceneType::Play]->SetName(L"PlayeScene");

		mScenes[(UINT)eSceneType::Stage1] = new Stage1;
		mScenes[(UINT)eSceneType::Stage1]->SetName(L"Stage1");


		mActiveScene = mScenes[(UINT)eSceneType::Stage1];

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}
	}
	void SceneManager::Update()
	{
		mActiveScene->Update();
	}
	void SceneManager::Render(HDC mHdc)
	{
		mActiveScene->Render(mHdc);	
	}
	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;
			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType sceneType)
	{
		mActiveScene->OnExit();
		mActiveScene = mScenes[(UINT)sceneType];
		mActiveScene->OnEnter();
	}
}