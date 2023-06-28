#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"
#include "ResourceMgr.h"


Scene::Scene(SceneId id) : sceneId(id)
{
}

Scene::~Scene()
{
	Release();
}

GameObject* Scene::FindGo(const std::string& name)
{
	//���ٽ� ǥ�� - ���� �ʿ�
	auto compare = [name](GameObject* go) { return go->GetName() == name; };
	//find()�� ���� ǥ������ ����� ��� find_if�� �����
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), compare);
	if (it == gameObjects.end())
	{
		return nullptr;
	}
	return *it;
	

	//�ٸ� ���
	/*for (auto go : gameObjects)
	{
		if (go->GetName() == name)
		{
			return go;
		}
	}
	return nullptr;*/
}

void Scene::FindGo(std::list<GameObject*>& list, const std::string& name)
{
	//list.clear();
	for (auto go : gameObjects)
	{
		if (go->GetName() == name)
		{
			list.push_back(go);
		}
	}
}

//����Ȯ��
bool Scene::Exist(GameObject* go)
{
	return std::find(gameObjects.begin(), gameObjects.end(), go) != gameObjects.end();
}

//�ߺ�Ȯ�� �� ����
void Scene::AddGo(GameObject* go)
{
	if (!Exist(go))
	{
		gameObjects.push_back(go);
	}
}

void Scene::RemoveGo(GameObject* go)
{
	gameObjects.remove(go);
	//delete go
}

void Scene::SortGos()
{
	gameObjects.sort([](GameObject* lhs, GameObject* rhs) {
		if (lhs->sortLayer != rhs->sortLayer)
			return lhs->sortLayer < rhs->sortLayer;

		return lhs->sortOrder < rhs->sortOrder; });
}

void Scene::Init()
{
}

void Scene::Release()
{
}

void Scene::Enter()
{
	RESOURCE_MGR.Load(resources);

	for (auto go : gameObjects)
	{
		go->Reset();
	}
}

void Scene::Exit()
{
	RESOURCE_MGR.Load(resources);

}

void Scene::Update(float dt)
{
	for (auto go : gameObjects)
	{
		if (go->GetActive())
		{
			go->Update(dt);
		}
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	SortGos();

	for (auto go : gameObjects)
	{
		if (go->GetActive())
		{
			go->Draw(window);
		}
	}
}


