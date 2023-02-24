#pragma once
#include "moScene.h"

namespace mo {

	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC mHdc);
		static void Release();
	
		static void LoadScene(eSceneType sceneType);

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};

}
