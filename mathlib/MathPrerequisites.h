#pragma once
#include <cmath>
// std::sin,std::cos���Ի���Ϊ��λ
#define PI 3.1415926
// �Ƕ�ת����
inline float radians(float degrees)
{
	return (PI / 180.0f) * degrees;
}

// ����ת�Ƕ�
inline float degrees(float radians)
{
	return (radians * 180.0) / PI;
}