#include "moKirby.h"
#include "moTime.h"
#include "moInput.h"
#include "moSceneManager.h"
#include "moResources.h"
#include "moTransform.h"
#pragma comment(lib, "msimg32.lib")


namespace mo {
	Kirby::Kirby()
		: mTime(0.0f)
		, mIdx(0)
		, mHalingIdx(0)
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		mImage = Resources::Load<Image>(L"Kirby", L"..\\Resources\\Kirby.bmp");
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

		mTime += Time::DeltaTime();

		

		if (mTime > 0.15f)
		{
			if (Input::GetKeyState(eKeyCode::X) == eKeyState::Pressed)
				mHalingIdx++;
			mIdx++;
			mTime = 0.0f;
		}


		if (mIdx >= 10)
		{
			mIdx = 0;
		}

		if (Input::GetKeyState(eKeyCode::X) == eKeyState::None)
			mHalingIdx = 0;

		if (mHalingIdx >= 10)
		{
			mHalingIdx = 7;
		}

		if (Input::GetKeyState(eKeyCode::Right) == eKeyState::Pressed) {
			TransparentBlt(mHdc, pos.x, pos.y, 130, 130
				, mImage->GetHdc(), 5 + (23 * mIdx), 55, 23, 25, RGB(207, 176, 255));
		}
		else if (Input::GetKeyState(eKeyCode::Left) == eKeyState::Pressed) {
			TransparentBlt(mHdc, pos.x, pos.y, 130, 130
				, mImage->GetHdc(), 446 - (23 * mIdx), 55, 23, 25, RGB(207, 176, 255));
		}
		else if (Input::GetKeyState(eKeyCode::X) == eKeyState::Pressed){
			TransparentBlt(mHdc, pos.x, pos.y, 130, 130
				, mImage->GetHdc(), 6 + (26 * mHalingIdx), 373, 25, 25, RGB(207, 176, 255));
		}
		else {
			TransparentBlt(mHdc, pos.x, pos.y, 130, 130
				, mImage->GetHdc(), 4, 55, 23, 25, RGB(207, 176, 255));
		}
	}
}