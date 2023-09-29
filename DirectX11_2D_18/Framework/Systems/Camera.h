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

	// �ݵ�� Render() �� �������� ������
	void SetPosition(Vector3 position) { this->position = position; }

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

