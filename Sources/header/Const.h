#pragma once
#include <vector>
#include <string>
#include "DxLib.h"
#include "CommonModule.h"

enum class ObjectType
{
	INVALID = -1,
	SECTION,
	CHARACTER,
	UI,
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
// �t�F�[�Y�̖��O
enum class PhaseName
{
	INVALID = -1,
	SELECT,
	STANDBY,
	MAIN,
	RESULT,
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
// �����̎��
enum class SectionType
{
	INVALID = -1,
	NONE,
	RESPAWN,
	ROOM,
	CORRIDOR,
	CONNECT,
	SECURE,

	MAX
};
// ���
enum class Type
{
	INVALID = -1,
	RED,
	WHITE,
	BLACK,
	PALE,
	MAX
};

enum class OfficerType
{
	NONE = -1,
	PLAYER,
	MOB,

	MAX
};

enum class CharacterStateID
{
	NONE = -1,
	IDLE,
	MOVE,
	OPERATION,
	OPERATION_MOVE,
	FIGHT,
	FIGHT_MOVE,
	PANIC,
	DEAD,

	MAX
};

enum class CharacterGroup
{
	INVALID = -1,
	OFFICER,
	ENTITY,
	OTHER,
};

enum class Level
{
	INVALID = -1,
	I,
	II,
	III,
	IV,
	V,
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

// �G���e�B�e�B�̊Ǘ��f�[�^
struct EntityManagementData
{
	int ID;
	int roomID;
	int operationCount;
	bool isLockInformation;
	bool isLockOperation[(int)Type::MAX];
	bool isLockManagement;
	bool isLockRunaway;
	bool isLockWeapon;
	bool isLockSuit;
};

const std::vector<std::string> nameList =
{
	"Sakakura",
	"Toshihiro",
	"Piapozz",
	"Saranath",
	"Kalastathar",
	"Ansamath",
	"Valantal",
	"Jalanal",
	"Adanathar",
	"Kavalan",
};

// �E���̃f�[�^
struct OfficerInitData
{
	OfficerInitData()
	{
		int index = GetRand(nameList.size() - 1);
		name = nameList[index];
	}

	std::string name = "";
	Vector2 position = Vector2(0, 0);
	int health = 100;
	int mental = 100;

	int suitID = -1;
	int weaponID = -1;
	OfficerType type = OfficerType::NONE;
	int param[(int)Type::MAX] ={
		10, 10, 10, 10
	};
};

// �X�e�[�W
const int SECTION_SIZE_X = 150;
const int SECTION_SIZE_Y = 100;
// �X�e�[�W�̃T�C�Y
const int STAGE_SIZE = 7;

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

// �X�e�[�^�X�֌W
const int MINIMUM_HEALTH = 0;
const int MINIMUM_MENTAL = 0;

// �J�[�\��
const int CURSOR_SIZE = 20;

// �t�H���g
const int FONT_SIZE_MAX = 100;

// �ő����
const int MAX_DAY = 24;

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

// ������ɕϊ�
inline std::string ToString(Type type)
{
	switch (type)
	{
		case Type::RED:    return "Red";
		case Type::WHITE:  return "White";
		case Type::BLACK:  return "Black";
		case Type::PALE:   return "Pale";
		case Type::INVALID:return "Invalid";
		default:           return "Unknown";
	}
}

// �F�Ƃ��Ă̕ϊ�
inline int ToColor(Type type)
{
	switch (type)
	{
		case Type::RED:    return GetColor(255, 100, 100);
		case Type::WHITE:  return GetColor(255, 255, 255);
		case Type::BLACK:  return GetColor(200, 100, 200);
		case Type::PALE:   return GetColor(100, 200, 200);
		default:           return GetColor(128, 128, 128);
	}
}

// ���x�������[�}�����ɕϊ�
inline std::string ToRomanNumber(Level level)
{
	switch (level)
	{
		case Level::I:		return "I";
		case Level::II:		return "II";
		case Level::III:	return "III";
		case Level::IV:		return "IV";
		case Level::V:		return "V";
		default:			return "Unknown";
	}
}

// �^�C�v����Ƃ̕�����֕ϊ�
inline std::string ToOperation(Type type)
{
	switch (type)
	{
		case Type::RED:    return "���b";
		case Type::WHITE:  return "�ώ@";
		case Type::BLACK:  return "�ڐG";
		case Type::PALE:   return "��Q";
		default:           return "";
	}
}
