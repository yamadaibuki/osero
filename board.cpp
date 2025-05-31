#include"DxLib.h"
#include"board.h"
#include"common.h"

int green = GetColor(50, 200, 50);
int white = GetColor(255, 255, 255);
int black = GetColor(0, 0, 0);

Board::Board()
{
	for (int i = 0; i < massNumber_; i++)
	{
		initPositionX_ = shift_ * 45 + i * (massWidth_ + shift_);
		for (int j = 0; j < massNumber_; j++)
		{
			initPositionY_ = j * (massHeight_ + shift_);
			massPositionX_[j][i] = initPositionX_;
			massPositionY_[j][i] = initPositionY_;
			massSituation_[j][i] = blank_;
		}
	}

	massSituation_[3][3] = white_;
	massSituation_[4][4] = white_;
	massSituation_[3][4] = black_;
	massSituation_[4][3] = black_;
}

Board::~Board()
{
}

//描画
void Board::Draw_()
{
	for (int i = 0; i < massNumber_; i++)
	{
		for (int j = 0; j < massNumber_; j++)
		{
			DrawBox(massPositionX_[j][i], massPositionY_[j][i],
				massPositionX_[j][i] + massWidth_, massPositionY_[j][i] + massHeight_, green, TRUE);

			//ボードの状態によって描画するコマを変える
			if (massSituation_[j][i] == white_)
			{
				DrawCircle(massPositionX_[j][i] + massWidth_ / 2, massPositionY_[j][i] + massHeight_ / 2,
					radius_, white, TRUE);
			}
			else if (massSituation_[j][i] == black_)
			{
				DrawCircle(massPositionX_[j][i] + massWidth_ / 2, massPositionY_[j][i] + massHeight_ / 2,
					radius_, black, TRUE);
			}
		}
	}
}
//
////ひっくり返す
//void Board::reverse_()
//{
//	for ( int dy = -1; dy <= 1; dy++)
//	{
//		for (int dx = -1; dx <= 1; dx++)
//		{
//			if (!dx && !dy)
//			{
//				continue;
//			}
//
//
//		}
//	}
//}
//
//int vec_y[] = { -1,-1,0,1,1,1,0,-1 };
//int vec_x[] = { 0,1,1,1,0,-1,-1,-1 };
//
////ひっくり返すチェック
//bool Board::checkFlip(int y, int x, bool turn, int vec)
//{
//	int flag = false;
//	while (true) {
//		y += vec_y[vec];
//		x += vec_x[vec];
//
//		//盤面の外に出ていたら終了
//		if (x < 0 || y < 0 || x > massNumber_ - 1 || y > massNumber_ - 1)
//		{
//			return false;
//		}
//
//		//空きマスだったら終了
//		if (massSituation_[y][x] == blank_)
//		{
//			return false;
//		}
//
//		//相手のコマがあったらフラグを立てる
//		if (massSituation_[y][x] == (turn ? white_ : black_))
//		{
//			flag = true;
//			continue;
//		}
//
//		//もしフラグがたっていればループ脱出。いなければ終了
//		if (flag)
//		{
//			break;
//		}
//		return false;
//	}
//	return true;
//}
//
////その場所に置くことができるかを確認する関数
//int Board::check(int y, int x, bool turn)
//{
//	int vec;
//
//	//どれか一方向でもひっくり返るか確認
//	for (vec = 0; vec < 8; ++vec)
//	{
//		if (checkFlip(y, x, turn, vec) == 1)
//		{
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
////実際に裏返す関数
//void Board::flip(int y, int x, bool turn, int vec)
//{
//	while (true) {
//		y += vec_y[vec];
//		x += vec_x[vec];
//
//		//自分のコマがあったら終了
//		if (massSituation_[y][x] == (turn ? white_ : black_))
//		{
//			break;
//		}
//
//		//それ以外なら自分のコマで塗りつぶす
//		massSituation_[y][x] = (turn ? white_ : black_);
//	}
//}
//
////入力を受けて裏返せるか確かめる関数
//int Board::put(int y, int x, bool turn)
//{
//	int vec, flag = 0;
//
//	//空白でなければ終了
//	if (massSituation_[y][x] != blank_)
//	{
//		return 0;
//	}
//
//	//全方向について確認
//	for (vec = 0; vec < 8; ++vec)
//	{
//		if (checkFlip(y, x, turn, vec) == 1)
//		{
//			//裏返す
//			flip(y, x, turn, vec);
//			flag = 1;
//		}
//	}
//	if (flag == 1) {
//		//この場所にコマを置く
//		massSituation_[y][x] = (turn ? white_ : black_);
//		return 1;
//	}
//
//	return 0;
//}

//特定のマスの周り8方向を調べる
void Board::checkDirection(int j, int i, bool isTurn)
{
	for (int a = 0; a < _maxDirectionCount; a++)
	{
		switch (a)
		{
		case 0:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j - b;
				int tempI = i - b;

				//マスより外側を見ようとしたらぬける
				if (tempJ < 0 || tempI < 0)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
				//次のマスが置いた色と同じだったらぬける
				if (massSituation_[tempJ][tempI] == (isTurn ? black_ : white_))
				{
					//ひっくり返す
					/*for (int c = 0; c < b; c++)
					{

					}*/
					break;
				}
			}
			break;

		case 1:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j - b;
				//マスより外側を見ようとしたらぬける
				if (tempJ < 0)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][i] == blank_)
				{
					break;
				}
			}
			break;

		case 2:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j - b;
				int tempI = i + b;
				//マスより外側を見ようとしたらぬける
				if (tempJ < 0 || tempI >= _maxDirectionCount)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
			}
			break;

		case 3:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempI = i + b;
				//マスより外側を見ようとしたらぬける
				if (tempI >= _maxDirectionCount)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[j][tempI] == blank_)
				{
					break;
				}
			}
			break;

		case 4:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				int tempI = i + b;
				//マスより外側を見ようとしたらぬける
				if (tempJ >= _maxDirectionCount || tempI >= _maxDirectionCount)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
			}
			break;

		case 5:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				//マスより外側を見ようとしたらぬける
				if (tempJ >= _maxDirectionCount)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][i] == blank_)
				{
					break;
				}
			}
			break;

		case 6:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				int tempI = i - b;
				//マスより外側を見ようとしたらぬける
				if (tempI < 0 || tempJ >= _maxDirectionCount)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
			}
			break;

		case 7:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempI = i - b;
				//マスより外側を見ようとしたらぬける
				if (tempI < 0)
				{
					break;
				}
				//次のマスが空白だったら抜ける
				if (massSituation_[j][tempI] == blank_)
				{
					break;
				}
			}
			break;
		}
	}
}