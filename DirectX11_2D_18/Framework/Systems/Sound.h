#pragma once
using namespace FMOD;
class Sounds:public SingletonBase<Sounds>
{
private:
	System* system;
	Sound** sound;
	Channel** channel;
	UINT count;
	map<string, Sound**> sounds;
	map<string, Sound**>::iterator iter;

	float Volume;
private:
	Sounds();
	~Sounds();
public:
	void Init();
	void Update();
	void AddSound(string name, wstring file, bool bLoop = false);
	void Play(string name, float volume = 1.f);

	void Stop(string name);
	void Pause(string name);
	void Resume(string name);

	bool IsPlaying(string name);
	bool IsPaused(string name);

	void SetVolume(string name, float volume);
	float GetVolume(string name);

public:
	friend SingletonBase<Sounds>;

	
};

