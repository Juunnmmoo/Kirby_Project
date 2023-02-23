#pragma once
#include "moGameObject.h"
#include "moEntity.h"

namespace mo {
	class Layer : public Entity
	{
	public:

		Layer();
		virtual ~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC mHdc);

	private:

		std::vector<GameObject*> mGameObjects;
	};

}