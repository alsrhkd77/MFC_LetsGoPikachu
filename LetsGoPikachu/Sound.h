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
	bool backGround;	//�����, true�� ���
	bool effect;	//ȿ����, true�� ���
};

