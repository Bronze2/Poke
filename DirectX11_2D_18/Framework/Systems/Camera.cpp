#include "Framework.h"
#include "Camera.h"
#include "Object/Player.h"
#include "Geometries/AnimationRect.h"


void Camera::Update()
{
	Move();
}

void Camera::Render()
{
	UpdateView();
	vpb->SetVSBuffer(1);
}

void Camera::Move()
{
	if (nullptr != m_Player) {
		if (BATTLE_STATE::NONE == m_Player->GetBattleState()) {
			position = m_Player->GetAnimRect()->GetPosition();
			position.x -= WinMaxWidth / 2;
			position.y -= WinMaxHeight / 2;
		}
	}
	UpdateView();
}

void Camera::UpdateView()
{

	D3DXMatrixLookAtLH(&view, &position, &(position + Values::FwdVec), &Values::UpVec);
	vpb->SetView(view);
}

void Camera::UnProjection(Vector3* out, Vector3 source, Matrix world)
{
	Vector3 position = source;

	out->x = (position.x * 2.0f / WinMaxWidth) - 1.0f;
	out->y = (position.y * 2.0f / WinMaxHeight) - 1.0f;
	out->z = position.z;

	Matrix wvp = world * view * proj;
	D3DXMatrixInverse(&wvp, nullptr, &wvp);
	D3DXVec3TransformCoord(out, out, &wvp);
}

Camera::Camera()
{
	vpb = new VPBuffer();
	D3DXMatrixLookAtLH(&view, &Vector3(0, 0, 0), &Vector3(0, 0, 1), &Vector3(0, 1, 0));
	D3DXMatrixOrthoOffCenterLH(&proj, 0.0f, (float)WinMaxWidth, 0.0f, (float)WinMaxHeight, 0, 1);
	vpb->SetView(view);
	vpb->SetProjection(proj);
}

Camera::~Camera()
{
	SAFE_DELETE(vpb);
}
