#pragma once

class CObject;
void CreateObj(CObject* _pNewObj, Vector3 _Pos, OBJ_TYPE _Type);
void DeleteObj(CObject* _DeleteObj);
void ChangeScene(SCENE_TYPE _NextScene);