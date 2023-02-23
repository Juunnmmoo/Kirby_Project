#include "moScene.h"

namespace mo {
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{	
	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{	
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::Render(HDC mHdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(mHdc);
		}
	}
}
