#include "GameObject.h"

//基底クラスのデストラクタ（virtual宣言しているため、cpp側で空の実装が必要）
//virtual~GameObject()=default;をヘッダーに書いた場合は不要ですが、
//複雑な共通終了処理が必要な場合はここに書きます。