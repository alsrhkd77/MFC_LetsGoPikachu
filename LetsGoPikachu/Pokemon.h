#pragma once

/* ���ϸ� Ŭ����(��ü ������ �� ��) */
class Pokemon {
public:
	Pokemon();
	~Pokemon() {};
	bool exist;	//��������
	int listNo;	//������ȣ
	int baseStat;	//������
	int level;	//����
	int hPoint;	//�� ü��
	int nowHP;	//���� ü��
	int skill[4];	//��� 1,2,3,4�� ����
	CString *skillName = new CString[4];	//��� 1,2,3,4�� �̸�
	CString koName;
	CString enName;
	CString backPath;
	CString forwardPath;
	int att;	//���ݷ�
	int def;	//����
	void getStat();	//�� �о����

protected:
	void setAtt();	//���ݷ� ����
	void setDef();	//���� ����
	void setHPoint();	//�� ü�� ����
	//TODO ���漳��, ü�¼��� ������ȣ�� ���� �޾ƿ��鼭 �������ֱ�
};
