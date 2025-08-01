#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <functional>
#include "BaseObject.h"
#include "ObjectManager.h"
class BaseAllocatorWrapper;
template<typename T>
class AllocatorWrapper;

class ObjectFactory
{
public:
	static ObjectFactory& Instance()
	{
		static ObjectFactory instance;
		return instance;
	}

	template<typename T>
	T* Create()
	{
		/*const std::string key = T::StaticTypeName();
		if (_allocators.find(key) == _allocators.end())
			Register<T>();
		auto allocatorWrapper = static_cast<AllocatorWrapper<T>*>(_allocators[key].get());
		return allocatorWrapper->Allocate();*/
	}

	template<typename T, typename... Args>
	T* CreateWithArgs(Args&&... args)
	{
		/*const std::string key = T::StaticTypeName();
		if (_allocators.find(key) == _allocators.end())
			Register<T>();
		auto allocatorWrapper = static_cast<AllocatorWrapper<T>*>(_allocators[key].get());
		T* obj = allocatorWrapper->Allocate(std::forward<Args>(args)...);
		ObjectManager::Instance().AddObject(obj);
		return obj;*/

		T* obj = new T(std::forward<Args>(args)...);
		ObjectManager::Instance().AddObject(obj);
		return obj;
	}

	template<typename T>
	void Destroy(T* obj)
	{
		/*if (!obj || _destroyedObjects.count(obj)) return;

		_destroyedObjects.insert(obj);
		const std::string key = obj->StaticTypeName();

		auto it = _allocators.find(key);
		if (it != _allocators.end())
		{
			it->second->DeallocateBase(obj);
		} else
		{
			delete obj;
		}

		obj = nullptr;*/

		delete obj;
		obj = nullptr;
	}

	void ClearDestroyedCache()
	{
		_destroyedObjects.clear();
	}

private:
	template<typename T>
	void Register(const std::string& key = T::StaticTypeName())
	{
		//_allocators[key] = std::make_unique<AllocatorWrapper<T>>();
	}

	//std::unordered_map<std::string, std::unique_ptr<BaseAllocatorWrapper>> _allocators;
	std::unordered_set<BaseObject*> _destroyedObjects;
};