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

		mWidth = 1400;
		mHeight = 600;
				
		//��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ ������ش�.
		RECT rect = { 0, 0, mWidth , mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


		// ������ ũ�� ����� ��� ����
		SetWindowPos(mHwnd
			, nullptr, 50, 50
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(hWnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

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
		// clear
		Rectangle(mBackHDC, -1, -1, 1402, 602);

		Time::Render(mBackHDC);
		Input::Render(mBackHDC);
		SceneManager::Render(mBackHDC);

		// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
}
