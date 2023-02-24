#pragma once
#include "moScene.h"

namespace mo {
	class Kirby;
	class BG_Stage1;
	class Stage1 : public Scene
	{
	public:
		Stage1();
		~Stage1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC mHdc) override;

		virtual void OnEnter()override;
		virtual void OnExit()override;

	private:
		Kirby* mKirby;
		BG_Stage1* mStageBG;
	};

}
