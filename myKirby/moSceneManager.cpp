#include "moSceneManager.h"
#include "moPlayScene.h"
#include "moTitleScene.h"

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

		mActiveScene = mScenes[(UINT)eSceneType::Title];

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