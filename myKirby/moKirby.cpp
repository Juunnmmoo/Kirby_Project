#include "moKirby.h"
#include "moTime.h"
#include "moInput.h"
#include "moSceneManager.h"
#include "moResources.h"

namespace mo {
	Kirby::Kirby()
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		mImage = Resources::Load<Image>(L"Cuphead", L"..\\Resources\\Idle.bmp");
		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		if (Input::GetKeyState(eKeyCode::Left) == eKeyState::Pressed)
		{
			mPos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Right) == eKeyState::Pressed)
		{
			mPos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Up) == eKeyState::Pressed)
		{
			mPos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::Down) == eKeyState::Pressed)
		{
			mPos.y += 100.0f * Time::DeltaTime();
		}
	}
	void Kirby::Render(HDC mHdc)
	{
		BitBlt(mHdc, mPos.x, mPos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
}