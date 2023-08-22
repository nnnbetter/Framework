#include "Timer.h"

float CTimer::mDeltaTime = 0.f;
float CTimer::mFPS = 0.f;
float CTimer::mFPSTime = 0.f;
int CTimer::mTick = 0;

LARGE_INTEGER CTimer::mSecond = {};
LARGE_INTEGER CTimer::mPrevTime = {};

void CTimer::Init()
{
	// ������ ���ػ� Ÿ�̸��� �ʴ� ���� ���´�.
	QueryPerformanceFrequency(&mSecond);

	// ������ ���ػ� Ÿ�̸��� ���� ���� ���´�.
	QueryPerformanceCounter(&mPrevTime);
}

float CTimer::Update()
{
	LARGE_INTEGER	Time;
	QueryPerformanceCounter(&Time);

	// (���� ���ػ� Ÿ�̸Ӱ� - ���������� ���ػ� Ÿ�̸Ӱ�) / �ʴ� Ÿ�̸Ӱ�
	mDeltaTime = (Time.QuadPart - mPrevTime.QuadPart) / (float)mSecond.QuadPart;

	// ���� �����ӿ����� ������ Ÿ�̸Ӱ��� ������������ Ÿ�̸� ���� �Ǿ��
	// �ϹǷ� mPrevTime�� ���� Ÿ�̸Ӱ����� �������ش�.
	mPrevTime = Time;

	// �ð��� �������Ѽ� �����Ѵ�.
	mFPSTime += mDeltaTime;
	++mTick;

	if (mTick == 60)
	{
		// 60��ŭ �������� �ݺ��ɵ��� ���ʰ� �귶������ �̿��ؼ� 1�ʰ� �귶�����
		// ���Ǵ� ������ ���� ���Ѵ�.
		// ���� ��� 60�������� �带 ���� mFPSTime�� 0.2��� 0.2�ʰ� �귶�ٴ�
		// ���̴�. �׷��ٸ� 1�ʰ� �Ǿ��� �� ������ �� �ִ� �������� 300��������
		// �� ���̴�.
		mFPS = mTick / mFPSTime;
		mFPSTime = 0.f;
		mTick = 0;
	}

	return mDeltaTime;

	//.
}
