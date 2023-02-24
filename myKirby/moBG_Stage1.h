#pragma once
#include "moGameObject.h"
#include "moImage.h"

namespace mo {

	class BG_Stage1 : public GameObject
	{
	public:
		BG_Stage1();
		~BG_Stage1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC mHdc) override;

	private:

		Image* mImage;
	};

}