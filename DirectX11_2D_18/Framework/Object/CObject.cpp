#include "Framework.h"
#include "CObject.h"

#include "Geometries/AnimationRect.h"
#include "Utilities/Animator.h"

void CObject::Render()
{
	m_pAnimRect->Render();
}

CObject::CObject()
{
}

CObject::~CObject()
{
}
