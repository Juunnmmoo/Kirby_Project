#pragma once
#include "moEntity.h"
#include "moComponent.h"

namespace mo {
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC mHdc);

		void SetPos(Vector2 pos) { mPos = pos; }

	private:
		Vector2 mPos;
		
		std::vector<Component*> mComponents;
	};

}