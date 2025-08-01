#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "CommonModule.h"

enum class ObjectType
{
	INVALID = -1,
	OBJECT3D,
	SCREEN_UI,

	MAX
};
// �l����
enum class DirFour
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,

    MAX
};
// �V�[���̖��O
enum class SceneName
{
	INVALID = -1,
	TITLE,
	MAIN,
	RESULT,
	OPTION,
	EXIT,

	MAX
};
// �\�����C���[
enum class Layer
{
	INVALID = -1,
	BACK,
	MIDDLE,
	FRONT,

	MAX
};

// BGM
enum class BGM
{
	INVALID = -1,
	TITLE,
	MAIN,
	OTHER,

	MAX
};

// SE
enum class SE
{
	INVALID = -1,
	CLICK,
	ALERT,
	ATTACK,
	DEAD,

	MAX
};

// ���C���[�ݒ�\����
typedef struct LayerSetting
{
	bool m_active = true;
	bool m_interact = true;
	Layer m_layer = Layer::BACK;
	// �f�t�H���g�R���X�g���N�^
	LayerSetting(bool active, bool interact, Layer layer): m_active(active), m_interact(interact), m_layer(layer){ }
};

// �F
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_WHITE = GetColor(255, 255, 255);
const int COLOR_ORANGE = GetColor(205, 133, 63);
const int COLOR_YELLOW = GetColor(255, 255, 0);

// �E�B���h�E
const int WINDOW_WIDTH = 1920;
const int WINDOW_HEIGHT = 1080;

// �֗�����
const float RAD2DEG = (float)(180 / DX_PI);

// �t�H���g
const int FONT_SIZE_MAX = 100;

// BGM�̃t�@�C���p�X
const std::vector<std::string> BGMFilePath = {
	"Resources/Sounds/Title.mp3",
	"Resources/Sounds/Main.mp3",
	"Resources/Sounds/Other.mp3"
};
// SE�̃t�@�C���p�X
const std::vector<std::string> SEFilePath = {
	"Resources/Sounds/Decide.mp3",
	"Resources/Sounds/Warning.mp3",
	"Resources/Sounds/Attack.mp3",
	"Resources/Sounds/DeathVoice.mp3",
};
