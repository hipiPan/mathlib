#pragma once
#include "Vector3.h"

struct Ray
{
	Vector3 orig;
	Vector3 dir;
};

struct BBox
{
	Vector3 min;
	Vector3 max;
};

inline bool intersect(const Ray& ray, const BBox& bbox)
{
	// ӳ�䵽2Dƽ����
	float txmin = (bbox.min.x - ray.orig.x) / ray.dir.x;
	float txmax = (bbox.max.x - ray.orig.x) / ray.dir.x;
	if (txmin > txmax) swap(txmin, txmax);

	float tymin = (bbox.min.y - ray.orig.y) / ray.dir.y;
	float tymax = (bbox.max.y - ray.orig.y) / ray.dir.y;
	if (tymin > tymax) swap(tymin, tymax);

	if ((txmin > tymax) || (tymin > txmax))
		return false;

	float tzmin = (bbox.min.z - ray.orig.z) / ray.dir.z;
	float tzmax = (bbox.max.z - ray.orig.z) / ray.dir.z;
	if (tzmin > tzmax) swap(tzmin, tzmax);

	if ((txmin > tzmax) || (tzmin > txmax))
		return false;

	return true;
}

// ��ȡһ����Ͷ�䵽һ���߶��ϵ�ͶӰ��
Vector3 pointOnSegment(const Vector3& p, const Vector3& a, const Vector3& b)
{
    Vector3 d0 = p - a;
    Vector3 d1 = b - a;
    float l = d1.length();
    d1.normalize();
    float t = d1.dot(d0);
    if (t < 0.0f)
        return a;

    if (t > l)
        return b;

    return a + d1 * t;
}