#pragma once

//#define�Œ������O��Z�����ނ悤�ɂ���
#define winmainSetting HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow                                //winmain�̈���
#define gameRoopSetting ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0//�Q�[�����[�v�̈���

//�֐��̃v���g�^�C�v�錾
void screenSetting();