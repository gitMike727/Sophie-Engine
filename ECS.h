#pragma once

#include <array>
#include <bitset>
#include <iostream>

class Entity;
class Component;

using ComponentID = std::size_t;

inline ComponentID GetComponentTypeID()
{
	static ComponentID lastID = 0u;
	return lastID++;
}

template<typename T>
inline ComponentID GetComponentTypeID() noexcept
{
	static_assert(std::is_base_of<Component, T>::value, "T must inherit from Component");
	static const ComponentID typeID = GetComponentTypeID();
	return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitSet = std::bitset<MAX_COMPONENTS>;
using ComponentArray = std::array<Component*, MAX_COMPONENTS>;
