#pragma once

const int massNumber_			= 8;	//�}�X�̐�
const int massWidth_			= 125;	//�}�X�̕�
const int massHeight_			= 125;	//�}�X�̍���
const int _maxDirectionCount	 = 8;	//�ő�����J�E���g



class Board
{
public:
	Board();
	~Board();

	void Draw_();		//�`��
	void checkDirection(int j, int i, bool isTurn);

	int		massPositionX_[8][8];	//�}�X���Wx
	int		massPositionY_[8][8];	//�}�X���Wy
	char	massSituation_[8][8];	//�}�X�̏�

	//char�^�ɓ����(��d�z��)
	enum situation_
	{
		white_,	//��
		black_,	//��
		blank_	//�����Ȃ�
	};

private:
	int		initPositionX_;			//�������Wx
	int		initPositionY_;			//�������Wy

	const int shift_		= 5;	//���炵��
	const int radius_		= 50;	//���a
};