#pragma once

#include <iostream>
#include <string>
#include "BoxCollider2D.h"

using namespace std;

class GameObject
{
private:
	//�⺻�Ӽ�//
	string tag;
	string name;
	bool active;

	//Ʈ������//
	float px;
	float py;

	//��ü�� ������������� ǥ���ϴ� ����
	bool isDead;  //true(���� �����), false(������� �ƴ�)

	//2D �ڽ��ݶ��̴� ���//
	BoxCollider2D* collider;

public:
	//������, �Ҹ���
	GameObject(string tag, string name, bool active, float px, float py);
	virtual ~GameObject();  //���������� �θ� Ŭ������ �Ҹ��ڴ� �׻� ��������..�ۼ���

	//����, ��Ÿ
	string getTag();
	string getName();
	bool   getActive();

	float getPx();
	float getPy();
	bool  getIsDead();

	void setTag(string tag);
	void setName(string name);
	void setActive(bool active);

	void setPx(float px);
	void setPy(float py);
	void setIsDead(bool isDead);

	//�⺻ �����Լ�
	virtual void start();
	virtual void update();
	virtual void draw();

	//�����..�׸��� �Լ�
	void onDrawGizmos();

	//��Ÿ �Լ�//
	void translate(float x, float y);

	//2D �浹ü �߰��Լ�//
	void addBoxCollider2D(BoxCollider2D* box);

	//2D �浹ü ����
	BoxCollider2D * getCollider();

	//�浹(Trigger) �̺�Ʈ ���� �Լ�
	virtual void onTrigger(GameObject * other);

	//��ü ���� �� �����Լ�
	void instantiate(GameObject* o);
	void destroy(GameObject* o);
};