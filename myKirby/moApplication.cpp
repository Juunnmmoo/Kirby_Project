#include "moApplication.h"
#include "moSceneManager.h"
#include "moTime.h"

namespace mo {
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		Time::Initiailize();
		SceneManager::Initialize();	
	}
	void Application::Run()
	{
		Update();
		Render();
	}
	void Application::Update()
	{

		Time::Update();
		SceneManager::Update();
	}
	void Application::Render()
	{

		Time::Render(mHdc);
		SceneManager::Render(mHdc);
	}
}
