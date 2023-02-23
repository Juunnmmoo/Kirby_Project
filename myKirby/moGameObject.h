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
	protected:
		Vector2 mPos;

	private:
		
		std::vector<Component*> mComponents;
	};

}