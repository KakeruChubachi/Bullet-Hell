#pragma once
#include "DxLib.h"
//ゲーム内のオブジェクトの基底クラス
class GameObject
{
protected:
	double x, y; //オブジェクトの座標
	double vx, vy; //オブジェクトの速度
	double radius; //オブジェクトの当たり判定の半径
	bool active; //生存フラグ（falseになるとリストから除外）
public:
	GameObject()
		: x(0), y(0), vx(0), vy(0), radius(0), active(true) {
	}
	virtual ~GameObject() {
	}
	//毎フレームの更新処理(純粋仮想関数：継承先で必ず書く)
	virtual void Update() = 0;
	//描画処理(純粋仮想関数)
	virtual void Draw() = 0;

	//ゲッター・セッター
	bool IsActive() const { return active; }
	void Kill() { active = false; }
	double GetX() const { return x; }
	double GetY() const { return y; }
	double GetRadius() const { return radius; }

};

