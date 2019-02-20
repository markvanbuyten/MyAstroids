#pragma once

#include "MoveComponent.h"
#include <cstdint>

class InputComponent : public MoveComponent
{
public:
	InputComponent(class Actor* owner);

	void ProcessInput(const uint8_t* keyState) override;

	float GetMaxForwardSpeed() const { return mMaxForwardSpeed; }
	void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }

	float GetMaxAngularSpeed() const { return mMaxAngularSpeed; }
	void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }

	int GetForwardKey() const { return mForwardKey; }
	void SetForwardKey(int key) { mForwardKey = key; }

	int GetBackKey() const { return mBackKey; }
	void SetBackKey(int key) { mBackKey = key; }

	int GetClockwiseKey() const { return mClockwiseKey; }
	void SetClockwiseKey(int key) { mClockwiseKey = key; }

	int GetCounterClockwiseKey() const { return mCounterClockwiseKey; }
	void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }

private:
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;
	int mForwardKey;
	int mBackKey;
	int mClockwiseKey;
	int mCounterClockwiseKey;
};