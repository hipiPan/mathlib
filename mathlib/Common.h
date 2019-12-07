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
