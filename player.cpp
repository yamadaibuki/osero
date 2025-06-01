#include"DxLib.h"
#include"common.h"
#include"player.h"
#include"board.h"

Player::Player()
{
	//�}�E�X�J�[�\������ʂɕ\������
	SetMouseDispFlag(TRUE);
}

Player::~Player()
{
}

//�R�}��u��
void Player::putPieces(Board* board)
{
	//�}�E�X�̍��W���擾���ă}�E�X���N���b�N����Ă��邩�����o
	GetMousePoint(&mouseX_, &mouseY_);
	mouseInput_ = GetMouseInput();

	//�܂����󔒂��}�E�X���N���b�N�����Ƃ������}�X��u��
	for (int i = 0; i < massNumber_; i++)
	{
		for (int j = 0; j < massNumber_; j++)
		{
			//�}�E�X���}�X���W���ɂ��邩
			if (board->massSituation_[j][i] == board->blank_
				&& board->massPositionX_[j][i] < mouseX_
				&& mouseX_< board->massPositionX_[j][i] + massWidth_
				&& board->massPositionY_[j][i] < mouseY_
				&& mouseY_ < board->massPositionY_[j][i] + massHeight_
				&& (mouseInput_ & MOUSE_INPUT_LEFT) == TRUE)
			{
				if (isTurn_)
				{
					//����ɃR�}��1�ȏ゠��Ƃ���������
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
					//����ɃR�}��1�ȏ゠��Ƃ���������
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