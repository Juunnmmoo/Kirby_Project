#include "moKirby.h"
#include "moTime.h"
#include "moInput.h"
#include "moSceneManager.h"
#include "moResources.h"
#include "moTransform.h"

namespace mo {
	Kirby::Kirby()
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		mImage = Resources::Load<Image>(L"IceKirby", L"..\\Resources\\IceKirby.bmp");
		//mImage = Resources::Load<Image>(L"Cuphead", L"..\\Resources\\Idle.bmp");
		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		Transform* tr = getComponent<Transform>();
		Vector2 pos = tr->getPos();

		if (Input::GetKeyState(eKeyCode::Left) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Right) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Up) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Down) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->setPos(pos);
	}
	void Kirby::Render(HDC mHdc)
	{
		GameObject::Render(mHdc);
		Transform* tr = getComponent<Transform>();
		Vector2 pos = tr->getPos();
		BitBlt(mHdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
}