#pragma once
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>
class BaseObject;

// 二次元ベクトル
struct Vector2
{
public:
	float x;
	float y;

	Vector2 operator+(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x + vec.x;
		temp.y = y + vec.y;

		return temp;
	}

	Vector2 operator-(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x - vec.x;
		temp.y = y - vec.y;

		return temp;
	}

	Vector2 operator*(const Vector2& vec) const
	{
		Vector2 temp;

		temp.x = x * vec.x;
		temp.y = y * vec.y;

		return temp;
	}

	Vector2 operator+(const float& num) const
	{
		Vector2 temp;

		temp.x = x + num;
		temp.y = y + num;

		return temp;
	}

	Vector2 operator-(const float& num) const
	{
		Vector2 temp;

		temp.x = x - num;
		temp.y = y - num;

		return temp;
	}

	Vector2 operator*(const float& num) const
	{
		Vector2 temp;

		temp.x = x * num;
		temp.y = y * num;

		return temp;
	}

	Vector2 operator/(const float& num) const
	{
		Vector2 temp;

		temp.x = x / num;
		temp.y = y / num;

		return temp;
	}

	void operator+=(const float& num)
	{
		x += num;
		y += num;
	}

	void operator-=(const float& num)
	{
		x -= num;
		y -= num;
	}

	void operator*=(const float& num)
	{
		x *= num;
		y *= num;
	}

	void operator/=(const float& num)
	{
		x /= num;
		y /= num;
	}

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(const float& X,const float& Y)
	{
		x = X;
		y = Y;
	}

	Vector2(const Vector2& vec)
	{
		x = vec.x;
		y = vec.y;
	}

	inline static Vector2 zero()
	{
		Vector2 temp;
		temp.x = 0;
		temp.y = 0;
		return temp;
	}

	inline static Vector2 one()
	{
		Vector2 temp;
		temp.x = 1;
		temp.y = 1;
		return temp;
	}

	static float Distance(const Vector2& vec1,const Vector2& vec2)
	{
		return Size(vec1 - vec2);
	}

	inline float size() const
	{
		return sqrtf(powf(x,2) + powf(y,2));
	}

	inline static float Size(const Vector2& vec)
	{
		return sqrtf(powf(vec.x,2) + powf(vec.y,2));
	}

	void normalize()
	{
		float distance = size();

		if(distance == 0) return;

		x /= distance;
		y /= distance;
	}

	inline static Vector2 Normalize(const Vector2& vec)
	{
		Vector2 temp;
		float distance = vec.size();

		temp.x = vec.x / distance;
		temp.y = vec.y / distance;

		return temp;
	}

	inline static float Dot(const Vector2& vec1,const Vector2& vec2)
	{
		return vec1.x * vec2.x + vec2.y * vec1.y;
	}

	inline static float Cross(const Vector2& vec1,const Vector2& vec2)
	{
		return vec1.x * vec2.y - vec2.x * vec1.y;
	}
};

/// <summary>
/// スクリーン座標からステージ座標に変換する
/// </summary>
/// <param name="screenPos"></param>
/// <param name="cameraHeight"></param>
/// <param name="cameraPos"></param>
/// <returns></returns>
Vector2 GetScreen2StagePos(Vector2 screenPos, float cameraHeight, Vector2 cameraPos);

// 3次元ベクトル
struct Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3 operator+(const Vector3& vec) const
	{
		Vector3 temp;

		temp.x = x + vec.x;
		temp.y = y + vec.y;
		temp.z = z + vec.z;

		return temp;
	}

	Vector3 operator-(const Vector3& vec) const
	{
		Vector3 temp;

		temp.x = x - vec.x;
		temp.y = y - vec.y;
		temp.z = z - vec.z;

		return temp;
	}

	Vector3 operator*(const Vector3& vec) const
	{
		Vector3 temp;

		temp.x = x * vec.x;
		temp.y = y * vec.y;
		temp.z = z * vec.z;

		return temp;
	}

	Vector3 operator+(const float& num) const
	{
		Vector3 temp;

		temp.x = x + num;
		temp.y = y + num;
		temp.z = z + num;

		return temp;
	}

	Vector3 operator-(const float& num) const
	{
		Vector3 temp;

		temp.x = x - num;
		temp.y = y - num;
		temp.z = z - num;

		return temp;
	}

	Vector3 operator*(const float& num) const
	{
		Vector3 temp;

		temp.x = x * num;
		temp.y = y * num;
		temp.z = z * num;

		return temp;
	}

	Vector3 operator/(const float& num) const
	{
		Vector3 temp;

		temp.x = x / num;
		temp.y = y / num;
		temp.z = z / num;

		return temp;
	}

	void operator+=(const float& num)
	{
		x += num;
		y += num;
		z += num;
	}

	void operator-=(const float& num)
	{
		x -= num;
		y -= num;
		z -= num;
	}

	void operator*=(const float& num)
	{
		x *= num;
		y *= num;
		z *= num;
	}

	void operator/=(const float& num)
	{
		x /= num;
		y /= num;
		z /= num;
	}

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(const float& X, const float& Y, const float& Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	Vector3(const Vector3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	inline static Vector3 zero()
	{
		Vector3 temp;
		temp.x = 0;
		temp.y = 0;
		temp.z = 0;
		return temp;
	}

	inline static Vector3 one()
	{
		Vector3 temp;
		temp.x = 1;
		temp.y = 1;
		temp.z = 1;
		return temp;
	}

	static float Distance(const Vector3& vec1, const Vector3& vec2)
	{
		return Size(vec1 - vec2);
	}

	inline float size() const
	{
		return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
	}

	inline static float Size(const Vector3& vec)
	{
		return sqrtf(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2));
	}

	void normalize()
	{
		float distance = size();

		if (distance == 0) return;

		x /= distance;
		y /= distance;
		z /= distance;
	}

	inline static Vector3 Normalize(const Vector3& vec)
	{
		Vector3 temp;
		float distance = vec.size();

		temp.x = vec.x / distance;
		temp.y = vec.y / distance;
		temp.z = vec.z / distance;

		return temp;
	}

	inline static float Dot(const Vector3& vec1, const Vector3& vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	inline static Vector3 Cross(const Vector3& vec1, const Vector3& vec2)
	{
		Vector3 temp;
		temp.x = vec1.y * vec2.z - vec1.z * vec2.y;
		temp.y = vec1.z * vec2.x - vec1.x * vec2.z;
		temp.z = vec1.x * vec2.y - vec1.y * vec2.x;
		return temp;
	}
};

// オブジェクトの基本情報
struct Transform
{
public:
	Vector3 position;
	Vector3 scale;
	BaseObject* parent;

	Transform()
	{
		position = Vector3::zero();
		scale = Vector3::zero();
		parent = nullptr;
	}

	Transform(Vector3 setPosition, Vector3 setScale, BaseObject* setParent = nullptr)
		: position(setPosition), scale(setScale), parent(setParent){}
	Transform GetWorldTransform();
	inline bool IsChild() { return parent != nullptr; }
};

/// <summary>
/// 浮動点小数の精度を設定する
/// </summary>
/// <returns></returns>
inline std::string SetPrecision(float value, int precision = 1)
{
	std::ostringstream oss;
	float precisionFactor = powf(10.0f, -precision);
	if (std::abs(value - static_cast<int>(value)) < precisionFactor)
		oss << static_cast<int>(value);
	else
		oss << std::fixed << std::setprecision(precision) << value;

	return oss.str();
}

enum class AttachDirection {
	Top,
	Bottom,
	Left,
	Right
};

enum class Align {
	Start,
	Center
};

void Attach2DArray(std::vector<std::vector<int>>& base,
				   const std::vector<std::vector<int>>& patch,
				   AttachDirection direction,
				   Align align = Align::Start);

/// <summary>
/// 指定座標がオブジェクトに含まれるか
/// </summary>
/// <param name="objectPos"></param>
/// <param name="checkPos"></param>
/// <returns></returns>
bool IsSamePos(Transform objectTransform, Vector2 checkPos)
{
	Vector3 position = objectTransform.position;
	Vector3 scale = objectTransform.scale;

	// 位置が同じかどうか
	float posMinX = position.x - scale.x / 2;
	float posMaxX = position.x + scale.x / 2;
	float posMinY = position.y - scale.y / 2;
	float posMaxY = position.y + scale.y / 2;
	return (checkPos.x >= posMinX && checkPos.x <= posMaxX && checkPos.y >= posMinY && checkPos.y <= posMaxY);
}