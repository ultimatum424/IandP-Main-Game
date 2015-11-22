#include <SFML\Graphics.hpp>
const int length_map = 8;
const int quantity_subject = 7;

struct subject {
	std::string Name;
	int Effect_type;
	float Effect;
	int Key;
} keytab[quantity_subject] = { // 0 - ������ 1 - �������� �� HP 2 - ������� �� % ����� 3 - ������� �� % ������
	"�����", 0, 0, 0,
	"�������", 1, 10, 1,
	"���� �����", 2, 0.1, 2,
	"������ ���", 3, 0.3, 3,
	"��������� �����", 3, -0.15, 4,
	"��", 1, -10, 5,
	"150 ������� ����� ", 0, 150, 6,
};
char TileMap[length_map]
{
	'e', 'c', 'c', 'c', 'c', 'c', 'c', 'e'
};
struct box {
	int key;
	float quantity;
} Chest[length_map] =
{
	0, 0,
	4, 3,
	6, 1,
	4, 1,
	1, 1,
	4, 1,
	4, 1,
	0, 0,
};

 
 

