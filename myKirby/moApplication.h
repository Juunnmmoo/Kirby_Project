#pragma once
#include "momoEngine.h"

namespace mo {
	class Application
	{
	public:
		Application();
		~Application();
		
		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();
		
		HDC getHdc() { return mHdc; }
		HWND getHwnd() { return mHwnd; }
		UINT getWidth() { return mWidth; }
		UINT getHeight() { return mHeight; }


	private:

		HDC mHdc;
		HWND mHwnd;
	
		//¹é¹öÆÛ
		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;
	};
}

