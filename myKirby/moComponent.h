#pragma once
#include "moEntity.h"

namespace mo {
	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		eComponentType getType() { return mType; }

	private:
		const eComponentType mType;

	};
}
