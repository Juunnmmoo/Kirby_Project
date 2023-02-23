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
	
	private:

		HDC mHdc;
		HWND mHwnd;
	};
}

