#pragma once

#include "GI.h"

class ProgressBar : public GI
{
public:
	ProgressBar(Vector3 position, Vector3 size, float rotation, Color color, FillType type = GI::LEFT_TO_RIGHT);
	ProgressBar(Vector3 position, Vector3 size, float rotation, wstring path, FillType type = GI::LEFT_TO_RIGHT);
	ProgressBar(Vector3 position, Vector3 size, float rotation, FillType type = GI::LEFT_TO_RIGHT);
	~ProgressBar();

	virtual void Update() override;
	virtual void Render() override;
	
	void UpdateProgressBar(float percent);

	FillType type = NONE;

private:

};