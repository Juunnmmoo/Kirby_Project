#pragma once
#include "moComponent.h"


namespace mo {
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;

		void setPos(Vector2 pos) { mPos = pos; }
		void setSize(Vector2 size) { mSize = size; }
		Vector2 getPos() { return mPos; }
		Vector2 getSize() { return mSize; }
	private:
		Vector2 mPos;
		Vector2 mSize;

	};
}