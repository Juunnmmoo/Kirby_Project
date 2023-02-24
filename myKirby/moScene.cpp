#include "moScene.h"

namespace mo {
	Scene::Scene()
	{
		mLayers.resize((UINT)eLayerType::End);
		mLayers[(UINT)eLayerType::Player] = new Layer;
	}
	Scene::~Scene()
	{	
		for (Layer* layer : mLayers) {
			if (layer == nullptr)
				continue;
			delete layer;
			layer = nullptr;
		}
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
	void Scene::addGameObject(GameObject* obj, eLayerType layerType)
	{
		mLayers[(UINT)layerType]->addGaemObject(obj);
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
}
