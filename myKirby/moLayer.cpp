#include "moLayer.h"

namespace mo {
    Layer::Layer()
    {
    }
    Layer::~Layer()
    {
        for (GameObject* gameObj : mGameObjects)
        {
            if (gameObj == nullptr)
                continue;
            delete gameObj;
            gameObj = nullptr;
            
        }
    }
    void Layer::Initialize()
    {
        for (GameObject* gameObj : mGameObjects)
        {
            if (gameObj == nullptr)
                continue;

            gameObj->Initialize();
        }
    }
    void Layer::Update()
    {
        for (GameObject* gameObj : mGameObjects)
        {
            if (gameObj == nullptr)
                continue;

            gameObj->Update();
        }
    }
    void Layer::Render(HDC mHdc)
    {
        for (GameObject* gameObj : mGameObjects)
        {
            if (gameObj == nullptr)
                continue;

            gameObj->Render(mHdc);
        }
    }
}