#pragma once
class Player;
class Camera : public SingletonBase<Camera>
{
public:
	friend class SingletonBase<Camera>;

	void Update();
	void Render();

	void Move();
	void UpdateView();

	const Vector3 GetPosition() { return position; }

	// 반드시 Render() 맨 마지막에 넣을것
	void SetPosition(Vector3 position) { this->position = position; }
	void SetProjection(float _Value, float _Value2);
	void UnProjection(Vector3* out, Vector3 source, Matrix world);
	void SetPlayer(Player* _Player) { m_Player = _Player; }
private:

	Player* m_Player;
	Camera();
	~Camera();

	VPBuffer* vpb = nullptr;
	Matrix view, proj;

	Vector3 position = Values::ZeroVec3;
	float cameraSpeed = 100.0f;
};

