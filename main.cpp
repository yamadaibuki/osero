#include"DxLib.h"
#include"setting.h" 
#include"board.h"
#include"player.h"

//���C���֐�
int WINAPI WinMain(winmainSetting)
{
    //�X�N���[���ݒ�֐����Ăяo��
    screenSetting();

    //���C�u�����������ŃG���[�N������I��
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    Board* board    =  new Board();
    Player* player  = new Player();

    //�Q�[�����[�v
    while (gameRoopSetting)
    {
        //��ʂɕ`���ꂽ��������(�Q�[�����[�v�̍ŏ��ɌĂ�)
        ClearDrawScreen();

        board->Draw_();

        player->putPieces(board);

        // ����ʂ̓��e��\��ʂɔ��f(�Q�[�����[�v�̍Ō�ɌĂ�)
        ScreenFlip();
    }
    DxLib_End();
    return 0;
}