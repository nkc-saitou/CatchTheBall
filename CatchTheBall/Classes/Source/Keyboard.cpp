#include "DxLib.h"

static int m_Key[256];  // �L�[�̓��͏�Ԋi�[�p�ϐ�

// �L�[�̓��͏�ԍX�V
void Keyboard_Update()
{
	// ���݂̃L�[�̓��͏�Ԃ��i�[����
    char tmpKey[256];             
	// �S�ẴL�[�̓��͏�Ԃ𓾂�
    GetHitKeyStateAll( tmpKey );  

    for( int i=0; i<256; i++ ){
		// i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
        if( tmpKey[i] != 0 ){ 
            m_Key[i]++;   // ���Z
        } 
		// ������Ă��Ȃ����
		else {
            m_Key[i] = 0; // 0�ɂ���
        }
    }
}

// KeyCode�̃L�[�̓��͏�Ԃ��擾����
int Keyboard_Get( int KeyCode ){
	// KeyCode�̓��͏�Ԃ�Ԃ�
    return m_Key[ KeyCode ]; 
}
