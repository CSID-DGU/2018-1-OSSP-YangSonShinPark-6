#include "stdafx.h"

void CObject::Update()
{
	//!< Set Position & State to Image
	_vImage[_nState]->SetPosition(_stPos);
	_vImage[_nState]->SetDirection((eDir)_nDir);
}

void CObject::Render()
{
	_vImage[_nState]->Draw();
}

void CObject::Exit()
{
	for (int i = 0; i < _vImage.size(); i++)
	{
		_vImage[i]->Exit();
		delete _vImage[i];
	}

	_vImage.clear();
}
