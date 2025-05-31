#pragma once

const int massNumber_			= 8;	//マスの数
const int massWidth_			= 125;	//マスの幅
const int massHeight_			= 125;	//マスの高さ
const int _maxDirectionCount	 = 8;	//最大方向カウント



class Board
{
public:
	Board();
	~Board();

	void Draw_();		//描画
	//void reverse_();	//ひっくり返す
	/*bool checkFlip(int y, int x, bool turn, int vec);
	int check(int y, int x, bool turn);
	void flip(int y, int x, bool turn, int vec);
	int put(int y, int x, bool turn);*/
	void checkDirection(int j, int i, bool isTurn);

	int		massPositionX_[8][8];	//マス座標x
	int		massPositionY_[8][8];	//マス座標y
	char	massSituation_[8][8];	//マスの状況

	//char型に入れる(二重配列)
	enum situation_
	{
		white_,	//白
		black_,	//黒
		blank_	//何もない
	};

private:
	int		initPositionX_;			//初期座標x
	int		initPositionY_;			//初期座標y

	const int shift_		= 5;	//ずらし量
	const int radius_		= 50;	//半径
};