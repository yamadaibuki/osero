#pragma once

class Board;

class Player
{
public:
	Player();
	~Player();

	void putPieces(Board* board);	//�R�}��u��

private:
	int		mouseX_ = 0;		//�}�E�X���Wx
	int		mouseY_ = 0;		//�}�E�X���Wy
	int		mouseInput_ = 0;	//�}�E�X���͗p
	bool	isTurn_ = true;		//�^�[���t���O(true:���Afalse:��)
};
