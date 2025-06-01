#include"DxLib.h"
#include"common.h"
#include"player.h"
#include"board.h"

Player::Player()
{
	//マウスカーソルを画面に表示する
	SetMouseDispFlag(TRUE);
}

Player::~Player()
{
}

//コマを置く
void Player::putPieces(Board* board)
{
	//マウスの座標を取得してマウスがクリックされているかを検出
	GetMousePoint(&mouseX_, &mouseY_);
	mouseInput_ = GetMouseInput();

	//ますが空白かつマウスをクリックしたときだけマスを置く
	for (int i = 0; i < massNumber_; i++)
	{
		for (int j = 0; j < massNumber_; j++)
		{
			//マウスがマス座標内にあるか
			if (board->massSituation_[j][i] == board->blank_
				&& board->massPositionX_[j][i] < mouseX_
				&& mouseX_< board->massPositionX_[j][i] + massWidth_
				&& board->massPositionY_[j][i] < mouseY_
				&& mouseY_ < board->massPositionY_[j][i] + massHeight_
				&& (mouseInput_ & MOUSE_INPUT_LEFT) == TRUE)
			{
				if (isTurn_)
				{
					//周りにコマが1個以上あるときだけおく
					if (board->massSituation_[j - 1][i - 1] == board->white_
						|| board->massSituation_[j - 1][i] == board->white_
						|| board->massSituation_[j - 1][i + 1] == board->white_
						|| board->massSituation_[j][i - 1] == board->white_
						|| board->massSituation_[j][i + 1] == board->white_
						|| board->massSituation_[j + 1][i - 1] == board->white_
						|| board->massSituation_[j + 1][i] == board->white_
						|| board->massSituation_[j + 1][i + 1] == board->white_)
					{
						board->massSituation_[j][i] = board->black_;
						board->checkDirection(j, i, isTurn_);
						isTurn_ = false;
					}
				}
				else
				{
					//周りにコマが1個以上あるときだけおく
					if (board->massSituation_[j - 1][i - 1] == board->black_
						|| board->massSituation_[j - 1][i] == board->black_
						|| board->massSituation_[j - 1][i + 1] == board->black_
						|| board->massSituation_[j][i - 1] == board->black_
						|| board->massSituation_[j][i + 1] == board->black_
						|| board->massSituation_[j + 1][i - 1] == board->black_
						|| board->massSituation_[j + 1][i] == board->black_
						|| board->massSituation_[j + 1][i + 1] == board->black_)
					{

						board->massSituation_[j][i] = board->white_;
						board->checkDirection(j, i, isTurn_);
						isTurn_ = true;
					}
				}
			}
		}
	}
}