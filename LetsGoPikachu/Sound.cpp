#include "stdafx.h"
#include "Sound.h"
#include <Windows.h>
#include <mmsystem.h>
//민광아 프로젝트 - 속성 - 링커 - 입력에 winmm.lib 추가해야된다.
#define Battle "./sound/Battle.wav"
#define StartBattle "./sound/StartBattle.wav"
#define Heal "./sound/Heal.wav"
#define Hit "./sound/Hit.wav"
#define Login "./sound/Login.wav"
#define Main "./sound/Main.wav"
#define Map "./sound/Map.wav"
#define Pcenter "./sound/Pcenter.wav"
#define Win "./sound/Win.wav"

Sound::Sound()
{
	backGround = true;
	effect = true;
}

void Sound::LoginOn()
{
	//PlaySound(TEXT(Login), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(Login), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP);
	}
}

void Sound::MainOn()
{
	//PlaySound(TEXT(Main), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(Main), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP);
	}
}

void Sound::BattleOn()
{
	//PlaySound(TEXT(Battle), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(Battle), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP);
	}
}

void Sound::StartBattleOn()
{
	//PlaySound(TEXT(StartBattle), NULL, SND_ASYNC | SND_ALIAS | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(StartBattle), NULL, SND_ASYNC | SND_ALIAS);
	}
}

void Sound::MapOn()
{
	//PlaySound(TEXT(Map), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(Map), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP);
	}
}

void Sound::HealOn()
{
	//PlaySound(TEXT(Heal), NULL, SND_ASYNC | SND_ALIAS | SND_NOSTOP);
	if (effect) {
		PlaySound(TEXT(Heal), NULL, SND_ASYNC | SND_ALIAS);
	}
}

void Sound::HitOn()
{
	//PlaySound(TEXT(Hit), NULL, SND_ASYNC | SND_ALIAS | SND_NOSTOP);
	if (effect) {
		PlaySound(TEXT(Hit), NULL, SND_ASYNC | SND_ALIAS);
	}
}

void Sound::PcenterOn()
{
	//PlaySound(TEXT(Pcenter), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP | SND_NOSTOP);
	if (backGround) {
		PlaySound(TEXT(Pcenter), NULL, SND_ASYNC | SND_ALIAS | SND_LOOP);
	}
}

void Sound::WinOn()
{
	//PlaySound(TEXT(Win), NULL, SND_ASYNC | SND_ALIAS | SND_NOSTOP);
	if (effect) {
		PlaySound(TEXT(Win), NULL, SND_ASYNC | SND_ALIAS);
	}
}

void Sound::Off()
{
	PlaySound(0, 0, 0);
}


Sound::~Sound()
{
}
