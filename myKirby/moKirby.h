#pragma once
#include "moGameObject.h"

namespace mo {

	class Kirby	: public GameObject
	{
	public:
		Kirby();
		~Kirby();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC mHdc) override;

	private:
	};

}