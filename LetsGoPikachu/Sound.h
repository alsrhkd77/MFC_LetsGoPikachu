#pragma once

class Sound
{
public:
	Sound();
	void LoginOn();
	void MainOn();
	void BattleOn();
	void StartBattleOn();
	void MapOn();
	void HealOn();
	void HitOn();
	void PcenterOn();
	void WinOn();
	void Off();
	~Sound();
	bool backGround;	//배경음, true면 재생
	bool effect;	//효과음, true면 재생
};

