#pragma once
class Sound:public SingletonBase<Sound>
{
public:
	friend SingletonBase<Sound>;
};

