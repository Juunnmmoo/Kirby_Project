#include "moKirby.h"
#include "moTime.h"

namespace mo {
	Kirby::Kirby()
	{
	}
	Kirby::~Kirby()
	{
	}
	void Kirby::Initialize()
	{
		GameObject::Initialize();
	}
	void Kirby::Update()
	{
		GameObject::Update();

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mPos.x -= 100.0f * Time::DeltaTime();
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mPos.x += 100.0f * Time::DeltaTime();
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mPos.y -= 100.0f * Time::DeltaTime();
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mPos.y += 100.0f * Time::DeltaTime();
		}
	}
	void Kirby::Render(HDC mHdc)
	{
		GameObject::Render(mHdc);
		// stock 오브젝트
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);
		//Rectangle(mHdc, -1, -1, 1601, 901);

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(mHdc, pen);

		Rectangle(mHdc, mPos.x, mPos.y, mPos.x + 100, mPos.y + 100);

		SelectObject(mHdc, oldPen);
		DeleteObject(pen);
		SelectObject(mHdc, oldBrush);
		DeleteObject(brush);
	}
}