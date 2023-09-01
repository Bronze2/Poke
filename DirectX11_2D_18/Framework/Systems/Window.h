#pragma once

struct DXDesc
{
	wstring AppName;
	HINSTANCE instance;
	HWND handle;
	UINT width; //������ â�� ���� ���� ũ��
	UINT height;
};

class Window
{
public:
	Window(DXDesc desc);
	~Window();

	WPARAM Run(IObject* mainObj); //���ӷ��� �Լ�
private:
	//�Լ�ȣ�� �Ծ�
	//stdcall
	//cdecl
	static LRESULT CALLBACK WndProc //�޼��� ó���Լ�
	(
		HWND handle,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
	);
	void MainRender()
	{
		if (ImGui::GetIO().WantCaptureMouse == false)
		{
			Mouse::Get()->Update();
			Keyboard::Get()->Update();
		}

		Time::Get()->Update();
		Gui::Get()->Update();

		//	mainObj->Update();
		SceneMgr::Get()->Update();
		Camera::Get()->Update();
		Graphics::Get()->Begin();
		{
			//mainObj->Render();
			SceneMgr::Get()->Render();
		

			Gui::Get()->Render();
			EventMgr::Get()->Update();
		}
		Graphics::Get()->End();

	}

	static DXDesc desc;
	IObject* mainObj = nullptr;
};

