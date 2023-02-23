#pragma once
#include "moLayer.h"
#include "moEntity.h"

namespace mo {

	class Scene : public Entity
	{
	public:

		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC mHdc);

		void addGameObject(GameObject* obj, eLayerType layerType) {
			mLayers[(UINT)layerType]->addGaemObject(obj);
		}

	private:
		
		std::vector<Layer*> mLayers;
		
	};

}