#pragma once

#include "Object.h"
#include "FileManager.h"
#include "Collision.h"
#include "FireworkObject.h"
#include "Time.h"
#include "Input.h"

class GoalObject : public Object{

	Collision *collider;

	Collision *destroy;

	void OnHit(Collision *other);

public:
	GoalObject(float x, float y, int order = 0);
	~GoalObject();

	virtual void Update() override;
};

