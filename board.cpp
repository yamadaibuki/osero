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

//�`��
void Board::Draw_()
{
	for (int i = 0; i < massNumber_; i++)
	{
		for (int j = 0; j < massNumber_; j++)
		{
			DrawBox(massPositionX_[j][i], massPositionY_[j][i],
				massPositionX_[j][i] + massWidth_, massPositionY_[j][i] + massHeight_, green, TRUE);

			//�{�[�h�̏�Ԃɂ���ĕ`�悷��R�}��ς���
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

//����̃}�X�̎���8�����𒲂ׂ�
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

				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempJ < 0 || tempI < 0)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][tempI] == (isTurn ? black_ : white_) && tempJ != j && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ + c][tempI + c] == (isTurn ? white_ : black_) &&
							tempJ + c != j && tempI + c != i)
						{
							massSituation_[tempJ + c][tempI + c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 1:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j - b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempJ < 0)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][i] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][i] == (isTurn ? black_ : white_) && tempJ != j)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ + c][i] == (isTurn ? white_ : black_))
						{
							massSituation_[tempJ + c][i] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 2:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j - b;
				int tempI = i + b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempJ < 0 || tempI >= _maxDirectionCount)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][tempI] == (isTurn ? black_ : white_) && tempJ != j && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ + c][tempI - c] == (isTurn ? white_ : black_))
						{
							massSituation_[tempJ + c][tempI - c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 3:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempI = i + b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempI >= _maxDirectionCount)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[j][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[j][tempI] == (isTurn ? black_ : white_) && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[j][tempI - c] == (isTurn ? white_ : black_))
						{
							massSituation_[j][tempI - c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 4:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				int tempI = i + b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempJ >= _maxDirectionCount || tempI >= _maxDirectionCount)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][tempI] == (isTurn ? black_ : white_) && tempJ != j && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ - c][tempI - c] == (isTurn ? white_ : black_))
						{
							massSituation_[tempJ - c][tempI - c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 5:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempJ >= _maxDirectionCount)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][i] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][i] == (isTurn ? black_ : white_) && tempJ != j)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ - c][i] == (isTurn ? white_ : black_))
						{
							massSituation_[tempJ - c][i] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 6:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempJ = j + b;
				int tempI = i - b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempI < 0 || tempJ >= _maxDirectionCount)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[tempJ][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[tempJ][tempI] == (isTurn ? black_ : white_) && tempJ != j && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[tempJ - c][tempI + c] == (isTurn ? white_ : black_))
						{
							massSituation_[tempJ - c][tempI + c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;

		case 7:
			for (int b = 0; b < _maxDirectionCount; b++)
			{
				int tempI = i - b;
				//�}�X���O�������悤�Ƃ�����ʂ���
				if (tempI < 0)
				{
					break;
				}
				//���̃}�X���󔒂������甲����
				if (massSituation_[j][tempI] == blank_)
				{
					break;
				}
				//���̃}�X���u�����F�Ɠ�����������ʂ���
				if (massSituation_[j][tempI] == (isTurn ? black_ : white_) && tempI != i)
				{
					//�Ђ�����Ԃ�
					for (int c = 0; c < b; c++)
					{
						if (massSituation_[j][tempI + c] == (isTurn ? white_ : black_))
						{
							massSituation_[j][tempI + c] = (isTurn ? black_ : white_);
						}
					}
					break;
				}
			}
			break;
		}
	}
}