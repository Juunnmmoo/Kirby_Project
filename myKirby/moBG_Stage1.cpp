#include "moBG_Stage1.h"
#include "moResources.h"
#include "moApplication.h"

extern mo::Application application;

namespace mo {
	BG_Stage1::BG_Stage1()
	{
	}
	BG_Stage1::~BG_Stage1()
	{
	}
	void BG_Stage1::Initialize()
	{
		mImage = Resources::Load<Image>(L"BG_Stage1", L"..\\Resources\\KirbyWorld01.bmp");
		GameObject::Initialize();
	}
	void BG_Stage1::Update()
	{
		GameObject::Update();
	}
	void BG_Stage1::Render(HDC mHdc)
	{
		GameObject::Render(mHdc);
		BitBlt(mHdc, -1, -1, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}
}