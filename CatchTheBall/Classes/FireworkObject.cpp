#include "FireworkObject.h"

FireworkObject::FireworkObject() {
	force = 0;
	moveVecX = 0;
	moveVecY = 0;

	_t = 0;

	playEffectType = EffectType::ExplosionFireworkClear;
	CheckEffect();
	
	GraphHandle(FileManager::Instance()->GetFileHandle("FireWorkBall.png"));

	collider = new Collision(16, 16, 32, 32, CollisionType::Circle, this, [this](Collision* other) { OnHit(other); });

	tag = GetTagName();
}


FireworkObject::~FireworkObject() {
	delete collider;
}

void FireworkObject::Update() {

	_t += Time::GetDeltaTime();
	if (_t > 5) return;

	//重力の更新
	ObjGravity();
	moveVecY = Fall_y();

	//移動後の位置を計算
	PositionX(PositionX() + moveVecX * Time::GetDeltaTime());
	PositionY(PositionY() + moveVecY * Time::GetDeltaTime());

	//向き計算
	if (child != nullptr) {

		//移動ベクトルを計算
		VECTOR in;
		in.x = moveVecX;
		in.y = moveVecY;
		in.z = 0;

		VECTOR out;

		VectorNormalize(&out, &in);

		auto sita = acos(out.x);
		auto rot = sita * 180.0 / 3.141519;
		if (in.y < 0) rot += 180;
		child->Rotation(rot);
	}
}

void FireworkObject::SetForce(float force, float moveVecX, float moveVecY) {

	VECTOR in;
	in.x = moveVecX;
	in.y = moveVecY;
	in.z = 0;

	VECTOR out;

	VectorNormalize(&out, &in);

	FireworkObject::moveVecX = out.x * force;
	FireworkObject::moveVecY = out.y * force;
	FireworkObject::force = force;

	//重力をリセット
	GravityReset();
	Fall_y(FireworkObject::moveVecY);

	CheckEffect();
}

void FireworkObject::CheckEffect() {

	EffectType type;
	if (force < 10) {
		type = EffectType::FireworkTrailLv1;
	}
	else if (force < 20) {
		type = EffectType::FireworkTrailLv2;
	}
	else {
		type = EffectType::FireworkTrailLv3;
	}

	if (type == playEffectType) return;
	playEffectType = type;

	if (child != nullptr) delete child;
	child = EffectManager::CreateEffect(playEffectType, 0, 0, false);
	child->Parent(this);
	child->SetLocalPosition(16, 16);
}

void FireworkObject::OnHit(Collision *other) {

	if (other->getObject()->GetTag() == "Wall") {
		//壁にヒットした場合はゲームオーバー

	}
}