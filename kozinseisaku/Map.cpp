#include "Map.h"
#include "Dxlib.h"
#include "Game.h"

// �t�@�C���̏o�͂Ɏg�p����
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

namespace
{
	//�}�b�v�`�b�v�̏��
	constexpr int kChipWidth = 32;
	constexpr int kChipHeight = 32;

	//�`�b�v��u����   �c�P�T�@���Q�O��
	constexpr int kChipNumX = Game::kScreenWidth / kChipWidth;
	constexpr int kChipNumY = Game::kScreenHeight / kChipHeight;

	//�}�b�v�`�b�v�̔z�u���
	constexpr int kChipData[kChipNumY][kChipNumX] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,3,0,0,0,4,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,20,21,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,36,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
}

Map::Map() :
	m_handle(-1),
	m_graphChipNumX(0),
	m_graphChipNumY(0)
{
	//�}�b�v�`�b�v�z�u�f�[�^�̏�����
	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			m_chipData[y][x] = kChipData[y][x];
		}
	}
}

Map::~Map()
{
}

void Map::Init()
{
	//�}�b�v�`�b�v�̐��𐔂���
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_handle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipWidth;
	m_graphChipNumY = graphH / kChipHeight;

	//�f�o�b�O�\��
	//printfDx("ChipNumX:%d\n", m_graphChipNumX);
	//printfDx("ChipNumY:%d\n", m_graphChipNumY);

	//�}�b�v�`�b�v�z�u�f�[�^�̓ǂݍ���
	fstream file;
	//�o�C�i�����[�h�ŊJ��
	file.open(L"data/map/map.bin", ios::in | ios::binary);
	//�t�@�C�����J���̂Ɏ��s�����ꍇ�̏���
	if (!file.is_open())
	{
		//�t�@�C�����J���̂Ɏ��s�����ꍇ�̏���
		printfDx(L"�t�@�C�����J���̂Ɏ��s���܂���\n");
	}
	else
	{
		//�t�@�C���̃I�[�v���ɐ�������
		//�t�@�C���̒��g����������ɃR�s�[����
		file.read(reinterpret_cast<char*> (&(m_chipData[0][0])), sizeof(int) * kChipNumX * kChipNumY);
		file.close();
	}
}

void Map::Update()
{
}

void Map::Draw()
{
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			//���̔ԍ��̃`�b�v�ŕ~���l�߂�
			int chipNo = m_chipData[y][x];

			//�}�b�v�`�b�v�̃O���t�B�b�N�؂�o�����W
			int srcX = kChipWidth * (chipNo % m_graphChipNumX);
			int srcY = kChipHeight * (chipNo / m_graphChipNumX);

			//DrawGraph(0, 0, m_handle, true);

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				srcX, srcY, kChipWidth, kChipHeight, m_handle, true);

		}

	}
}
