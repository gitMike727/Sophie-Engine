#pragma once

#include <array>
#include <bitset>
#include <iostream>

class Entity;
class Component;

using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentTypeID()
{
	static ComponentTypeID lastID = 0u;
	return lastID++;
}

template <typename T>
inline ComponentTypeID getComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
	static const ComponentTypeID typeID = getUniqueComponentTypeID();
	return typeID;
}

constexpr std::size_t maxEntities = 5000;
constexpr std::size_t maxComponents = 32;

using ComponentBitset = std::bitset<maxComponents>;
using ComponentList = std::array<Component*, maxComponents>;