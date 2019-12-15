#pragma once
#include "Vector3.h"

// �ж�ͬ��
inline bool sameSide(const Vector3& p1, const Vector3& p2, const Vector3& a, const Vector3& b)
{
	Vector3 v1 = b - a;
	Vector3 v2 = p1 - a;
	Vector3 v3 = v1.cross(v2);

	Vector3 v4 = p2 - a;
	Vector3 v5 = v1.cross(v4);
	// ����ͬ��
	if (v3.dot(v5) >= 0.0f)
		return true;
	return false;
}

// �жϵ��Ƿ���һ����������
// �ô�ʹ��ͬ�߷�
inline bool pointInTriangle(const Vector3& p, const Vector3& a, const Vector3& b, const Vector3& c)
{
	return sameSide(p, a, b, c) && sameSide(p, b, a, c) && sameSide(p, c, a, b);
}

// ��������ϵת�ѿ�������ϵ
// s.x:r �뾶
// s.y:theta ����
// s.z:phi ��λ��
// note:����ʹ����������ϵ
inline Vector3 cartesianCoord2SphericalCoord(const Vector3& s)
{
	Vector3 ret;
	ret.x = s.x * std::sin(s.y) * std::cos(s.z);
	ret.y = s.x * std::cos(s.y);
	ret.z = -(s.x * std::sin(s.y) * std::sin(s.z)); // ע������ĸ���
	return ret;
}

inline Vector3 cartesianCoord2SphericalCoord(float r, float theta, float phi)
{
	Vector3 ret;
	ret.x = r * std::sin(theta) * std::cos(phi);
	ret.y = r * std::cos(theta);
	ret.z = -(r * std::sin(theta) * std::sin(phi)); // ע������ĸ���
	return ret;
}

// �ѿ�������ϵת��������ϵ
inline Vector3 sphericalCoord2CartesianCoord(const Vector3& c)
{
	Vector3 ret;
	ret.x = std::sqrt(c.x*c.x + c.y*c.y + c.z*c.z); //r
	ret.y = std::atan2(-c.z, c.x); //theta
	ret.z = acos(c.y / ret.x); //phi
	
	return ret;
}
