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
	"��", 1, -10, 3,
	"������ ���", 3, 0.3, 4,
	"��������� �����", 3, -0.15, 5,
	"150 ������� ����� ", 0, 150, 6,

};

char TileMap[length_map]
{
	'e', 'c', 'c', '0', 'c', '0', '0', 'e'
};
int Chest[length_map]
{
	0, 1, 5, 0, 6, 0, 0, 0
};
/*std::string name_subject[quantity_subject]
{
	"�������",
	"��������� �����",
	"��"
};*/
