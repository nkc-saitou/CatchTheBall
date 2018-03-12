#pragma once
#include "Object.h"
#include "Collision.h"
#include "FileManager.h"
#include "Gravity.h"
#include "Time.h"
#include "EffectManager.h"

class FireworkObject : public Object, Gravity {

	Collision *collider;
	EffectObject *child;

	EffectType playEffectType;

	float force;
	float moveVecX;
	float moveVecY;

	float _t = 0;

	void OnHit(Collision *other);

	void CheckEffect();

public:

	static const string GetTagName() { return "Firework"; }

	FireworkObject();
	~FireworkObject();

	#pragma region Property
	float GetForce() { return force; }

	float GetMoveVecX() { return moveVecX; }

	float GetMoveVecY() { return moveVecX; }
	#pragma endregion

	virtual void Update() override;

	void SetForce(float force, float moveVecX, float moveVecY);

};

