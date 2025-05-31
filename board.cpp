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
	directionCount_	= 0;
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

//�Ђ�����Ԃ�
void Board::reverse_()
{
	for ( int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			if (!dx && !dy)
			{
				continue;
			}


		}
	}
}

int vec_y[] = { -1,-1,0,1,1,1,0,-1 };
int vec_x[] = { 0,1,1,1,0,-1,-1,-1 };

//�Ђ�����Ԃ��`�F�b�N
bool Board::checkFlip(int y, int x, bool turn, int vec)
{
	int flag = false;
	while (true) {
		y += vec_y[vec];
		x += vec_x[vec];

		//�Ֆʂ̊O�ɏo�Ă�����I��
		if (x < 0 || y < 0 || x > massNumber_ - 1 || y > massNumber_ - 1)
		{
			return false;
		}

		//�󂫃}�X��������I��
		if (massSituation_[y][x] == blank_)
		{
			return false;
		}

		//����̃R�}����������t���O�𗧂Ă�
		if (massSituation_[y][x] == (turn ? white_ : black_))
		{
			flag = true;
			continue;
		}

		//�����t���O�������Ă���΃��[�v�E�o�B���Ȃ���ΏI��
		if (flag)
		{
			break;
		}
		return false;
	}
	return true;
}

//���̏ꏊ�ɒu�����Ƃ��ł��邩���m�F����֐�
int Board::check(int y, int x, bool turn)
{
	int vec;

	//�ǂꂩ������ł��Ђ�����Ԃ邩�m�F
	for (vec = 0; vec < 8; ++vec)
	{
		if (checkFlip(y, x, turn, vec) == 1)
		{
			return 1;
		}
	}

	return 0;
}

//���ۂɗ��Ԃ��֐�
void Board::flip(int y, int x, bool turn, int vec)
{
	while (true) {
		y += vec_y[vec];
		x += vec_x[vec];

		//�����̃R�}����������I��
		if (massSituation_[y][x] == (turn ? white_ : black_))
		{
			break;
		}

		//����ȊO�Ȃ玩���̃R�}�œh��Ԃ�
		massSituation_[y][x] = (turn ? white_ : black_);
	}
}

//���͂��󂯂ė��Ԃ��邩�m���߂�֐�
int Board::put(int y, int x, bool turn)
{
	int vec, flag = 0;

	//�󔒂łȂ���ΏI��
	if (massSituation_[y][x] != blank_)
	{
		return 0;
	}

	//�S�����ɂ��Ċm�F
	for (vec = 0; vec < 8; ++vec)
	{
		if (checkFlip(y, x, turn, vec) == 1)
		{
			//���Ԃ�
			flip(y, x, turn, vec);
			flag = 1;
		}
	}
	if (flag == 1) {
		//���̏ꏊ�ɃR�}��u��
		massSituation_[y][x] = (turn ? white_ : black_);
		return 1;
	}

	return 0;
}