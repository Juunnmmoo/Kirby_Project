#pragma once
#include "moScene.h"

namespace mo {
	class Kirby;
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC mHdc) override;
	
		virtual void OnEnter()override;
		virtual void OnExit()override;

	private:
		Kirby* mKirby;
	};

}
