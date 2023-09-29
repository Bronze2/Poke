#pragma once

class CObject;
class AnimationRect;
void CreateObj(CObject* _pNewObj, Vector3 _Pos, OBJ_TYPE _Type);
void DeleteObj(CObject* _DeleteObj);
void ChangeScene(SCENE_TYPE _NextScene);

bool TimeCheck(float fduration, chrono::steady_clock::time_point b);
static AnimationRect* FontRect;
void FontCreate();