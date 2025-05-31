#pragma once

class Board;

class Player
{
public:
	Player();
	~Player();

	void putPieces(Board* board);	//コマを置く

private:
	int		mouseX_ = 0;		//マウス座標x
	int		mouseY_ = 0;		//マウス座標y
	int		mouseInput_ = 0;	//マウス入力用
	bool	isTurn_ = true;		//ターンフラグ(true:黒、false:白)
};
