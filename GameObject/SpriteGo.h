#pragma once
#include "GameObject.h"

class SpriteGo :
    public GameObject
{
protected:

public:
	sf::Sprite sprite;

	SpriteGo(const std::string n = "");
	virtual ~SpriteGo() override;

	//virtual void SetName(const std::string& n);

	virtual void SetPosition(const sf::Vector2f& p) override;
	virtual void SetPosition(float x, float y) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;

	virtual void Init()  override;	//������ ����
	virtual void Release()  override;	//�Ҹ��� ����
	virtual void Reset()  override;	//�ʱ�ȭ ����

	virtual void Update(float dt)  override;
	virtual void Draw(sf::RenderWindow& window)  override;
};

