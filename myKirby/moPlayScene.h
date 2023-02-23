#pragma once
#include "moScene.h"

namespace mo {
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC mHdc) override;
	};

}
