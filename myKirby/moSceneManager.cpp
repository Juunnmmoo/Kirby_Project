#include "moSceneManager.h"

namespace mo {

	std::vector<Scene*> SceneManager::mScenes;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Max);

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}
	}
	void SceneManager::Update()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Update();
		}
	}
	void SceneManager::Render(HDC mHdc)
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Render(mHdc);
		}
	}
	void SceneManager::Release()
	{
	}
}