#include "moApplication.h"
#include "moSceneManager.h"
#include "moTime.h"
#include "moInput.h"

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
		Input::Initialize();
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
		Input::Update();
		SceneManager::Update();
	}
	void Application::Render()
	{

		Time::Render(mHdc);
		Input::Render(mHdc);
		SceneManager::Render(mHdc);
	}
}
