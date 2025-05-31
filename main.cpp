#include"DxLib.h"
#include"setting.h" 
#include"board.h"
#include"player.h"

//メイン関数
int WINAPI WinMain(winmainSetting)
{
    //スクリーン設定関数を呼び出す
    screenSetting();

    //ライブラリ初期化でエラー起きたら終了
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    Board* board    =  new Board();
    Player* player  = new Player();

    //ゲームループ
    while (gameRoopSetting)
    {
        //画面に描かれた物を消す(ゲームループの最初に呼ぶ)
        ClearDrawScreen();

        board->Draw_();

        player->putPieces(board);

        // 裏画面の内容を表画面に反映(ゲームループの最後に呼ぶ)
        ScreenFlip();
    }
    DxLib_End();
    return 0;
}