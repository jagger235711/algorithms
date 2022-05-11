/*
@Author: �Ŷ���
@Date:   2022��4��28��
@Function:����������ɿ������Զ������㷨������⣬д���㷨��������
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

//ְ��
const int JIAOSHOU = 5;	  //����
const int FUJIAOSHOU = 4; //������
const int JIANGSHI = 3;	  //��ʦ
const int JIAOSHOU2 = 2;//�����^��ʦ��ְλ 
const int JIANGSHI2 = 2;//�����ʦ��ְλ 

//�о�����
const int JAVA = 1;
const int C = 2;
const int CSHARP = 3; //C#
const int PYTHON = 4;
const int ASP = 5;
const int JS = 6;
const int WEB_HTML = 7;	 //ǰ��
const int NET = 8; //NET
const int CPP = 9;
const int H5 = 10; //html5
const int VB = 11;

//�о���������
const char* research_str[] = { "NULL", "Java", "C", "C#", "Python", "ASP", "JS","ǰ�˱��", "NET", "C++","HTML5","VB" };

struct Teacher
{
	int index;		  //id
	string name;	  //����
	int level;		  //ְ��
	int* research;	  //�о�����
	int research_cnt; //�о��������
	int student_cnt;  //ѧ������
};

//��ְ������
bool cmp(const Teacher& a, const Teacher& b)
{
	return a.level > b.level;
}

//��� С������
const int maxgroupcnt = 10;
//��� ѧ������
const int student_count = 150;

//��ʦ����
const int teacher_count = 9;
//С������
const int group_count = 2;

//������ʦ��Ϣ
Teacher t[teacher_count + 1];

//����滮��Ϣ
int dp[teacher_count + 10][student_count + 10];

//��ʼ����ʦ��Ϣ
void init_teacher();
//��̬�滮���飨����ѧ������������٣�
void dp_group();

struct GroupInfo
{
	//��¼���е���ʦID
	vector<int> group;
	//С���ʦ����
	int teacher_cnt;
	//С��ѧ������
	int student_cnt;
	//ְ��
	map<int, int> title;
	//�о�����
	map<int, int> research;
} gi[group_count + 1];

//��С�鰴��ʦ��������
bool cmp_g(const GroupInfo& a, const GroupInfo& b)
{
	return a.teacher_cnt < b.teacher_cnt;
}

//���½�ʦID��ʹID�������±����Ӧ
void updateIndex()
{
	for (int i = 1; i <= teacher_count; i++)
		t[i].index = i;
}

int main()
{
	//��ʼ����ʦ��Ϣ
	init_teacher();
	//����ְ�������ʦ��Ϣ
	sort(t + 1, t + teacher_count, cmp);
	updateIndex();

	cout << "----------����Ϊ���н�ʦ����Ϣ��----------" << endl;
	printf("%-4s %-12s %-10s %-5s", "���", "����", "ѧ������", "�о�����\n");
	for (int i = 1; i <= teacher_count; i++)
	{
		printf("%-4d %-12s %-11d", i, t[i].name.c_str(), t[i].student_cnt);

		for (int j = 0; j < t[i].research_cnt; j++)
		{
			if (j == 0)
				printf("%s ", research_str[t[i].research[j]]);
			else
				printf(", %s ", research_str[t[i].research[j]]);
		}
		printf("\n");
	}
	cout << "------------------------------------------" << endl;

	//��ѧ����������
	dp_group();
	return 0;
}

//��ʼ����ʦ��Ϣ
void init_teacher()
{
	t[1].index = 1;
	t[1].name = "�Ž��ɽ���";
	t[1].level = JIAOSHOU;
	t[1].research_cnt = 1;
	t[1].research = new int[t[0].research_cnt];
	t[1].research[0] = JAVA;
	t[1].student_cnt = 16;

	t[2].index = 2;
	t[2].name = "��һƼ������";
	t[2].level = FUJIAOSHOU;
	t[2].research_cnt = 2;
	t[2].research = new int[t[2].research_cnt];
	t[2].research[0] = C;
	t[2].research[1] = CPP;
	t[2].student_cnt = 15;


	t[3].index = 3;
	t[3].name = "����꿽���";
	t[3].level = JIAOSHOU2;
	t[3].research_cnt = 2;
	t[3].research = new int[t[3].research_cnt];
	t[3].research[0] = JAVA;
	t[3].research[1] = ASP;
	t[3].student_cnt = 20;


	t[4].index = 4;
	t[4].name = "���θ�����";
	t[4].level = FUJIAOSHOU;
	t[4].research_cnt = 2;
	t[4].research = new int[t[4].research_cnt];
	t[4].research[0] = JAVA;
	t[4].research[1] = CSHARP;
	t[4].student_cnt = 15;

	t[5].index = 5;
	t[5].name = "������������";
	t[5].level = FUJIAOSHOU;
	t[5].research_cnt = 4;
	t[5].research = new int[t[5].research_cnt];
	t[5].research[0] = CSHARP;
	t[5].research[1] = ASP;
	t[5].research[2] = H5;
	t[5].research[3] = VB;
	t[5].student_cnt = 15;

	t[6].index = 6;
	t[6].name = "��ΰ��ʦ";
	t[6].level = JIANGSHI;
	t[6].research_cnt = 2;
	t[6].research = new int[t[6].research_cnt];
	t[6].research[0] = JAVA;
	t[6].research[1] = JS;
	t[6].student_cnt = 10;

	t[7].index = 7;
	t[7].name = "��Ͻ�ʦ";
	t[7].level = JIANGSHI2;
	t[7].research_cnt = 2;
	t[7].research = new int[t[7].research_cnt];
	t[7].research[0] = PYTHON;
	t[7].research[1] = CSHARP;
	t[7].student_cnt = 10;

	t[8].index = 8;
	t[8].name = "���������";
	t[8].level = JIAOSHOU;
	t[8].research_cnt = 2;
	t[8].research = new int[t[8].research_cnt];
	t[8].research[0] = JAVA;
	t[8].research[1] = PYTHON;
	t[8].student_cnt = 0;

	t[9].index = 9;
	t[9].name = "��褸�����";
	t[9].level = FUJIAOSHOU;
	t[9].research_cnt = 2;
	t[9].research = new int[t[9].research_cnt];
	t[9].research[0] = NET;
	t[9].research[1] = WEB_HTML;
	t[9].student_cnt = 0;
}

//���������Ϣ
void printGroup()
{
	for (int g = 1; g <= group_count; g++)
	{
		printf("��%d��:", g);
		int isum = 0;
		int lvmax = 0, lvmaxid = 0;
		int lvmin = 0x3f3f3f3f, lvminid = 0;
		for (int i = 0; i < gi[g].teacher_cnt; i++)
		{
			Teacher tmp = t[gi[g].group[i]];
			isum += tmp.student_cnt;
			printf("%s[%d]  ", tmp.name.c_str(), tmp.student_cnt);

			if (tmp.level > lvmax)
			{
				lvmax = tmp.level;
				lvmaxid = tmp.index;
			}
			if (tmp.level <= lvmin)
			{
				lvmin = tmp.level;
				lvminid = tmp.index;
			}
		}
		printf("С��������:%d  �鳤��%s  ���飺%s\n", isum, t[lvmaxid].name.c_str(), t[lvminid].name.c_str());
	}
}

//����ѧ����������
void dp_group()
{
	//��¼ѧ������Ϊ0����ʦ��������滮���飩�������ܰ�����Ԯ��ʦ
	//δ���������ô�ӳ����и������չ�������Զ��岻�������滮����ʦ�ȵ�
	map<int, bool> ban_t;
	//���治����滮����Ľ�ʦ���
	vector<int> ban_vec;
	//ѧ��������
	int sum = 0;
	for (int i = 1; i <= teacher_count; i++)
	{
		sum += t[i].student_cnt;

		if (t[i].student_cnt == 0)
		{
			ban_t[i] = true;
			ban_vec.push_back(i);
		}
	}

	for (int i = 1; i <= teacher_count; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			dp[i][j] = dp[i - 1][j];

			//���������滮����ʦֱ����������ʵ������Ҳ��Ӱ������
			if (ban_t[i])
				continue;

			if (j >= t[i].student_cnt)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i].student_cnt] + t[i].student_cnt);
			}
		}
	}

	//��¼��ʦ�Ƿ���ɷ���
	map<int, bool> finish;
	//�����ÿ������
	int diff = sum / group_count;
	//���ݹ滮�������ÿ��С���������Щ��ʦ
	for (int g = 1; g <= group_count; g++)
	{
		int i = teacher_count, j = diff * g;

		if (g == group_count)
			j = sum;

		while (i > 0 && j > 0)
		{
			//���������滮����ʦ�����������������
			if (ban_t[i])
			{
				i--;
				continue;
			}

			if (dp[i][j] == dp[i - 1][j - t[i].student_cnt] + t[i].student_cnt)
			{
				if (!finish[i])
				{
					gi[g].group.push_back(i);
					finish[i] = true;

					Teacher tmp = t[i];
					//��¼�������ְ����
					gi[g].title[tmp.level]++;

					//��¼�����ʦ�о�����
					for (int r = 0; r < tmp.research_cnt; r++)
						gi[g].research[tmp.research[r]]++;
				}

				j -= t[i].student_cnt;
			}
			i--;
		}

		gi[g].teacher_cnt = gi[g].group.size();
	}

	printf("1�� ��ѧ����������С�ó��ķ������£�\n");
	printf("\n");
	printGroup();

	cout << "------------------------------------------" << endl;

	//����ʦ����������ǰ���С���ʦ��������
	sort(gi + 1, gi + group_count, cmp_g);

	//ʣ�������Ľ�ʦ����
	int remain_cnt = ban_vec.size();
	while (remain_cnt > 0)
	{
		for (int g = 1; g <= group_count; g++)
		{
			//����֮���ʦ�������+1
			int tdiff = 1;
			if (g + 1 < group_count)
				tdiff = gi[g + 1].teacher_cnt - gi[g].teacher_cnt + 1;

			//��ְ�Ʒ�����
			while (tdiff--)
			{
				if (remain_cnt <= 0)
					break;

				int i = 0;
				//�ڴ������ʦ��������һ���ڸ����ڲ�����ĳְ�ƵĽ�ʦ
				do
				{
					//��ȡ��ǰ������Ľ�ʦְ�Ʋ��ж���gi[g]�����Ƿ����
					Teacher ban_t_tmp = t[ban_vec[i]];
					int lv = ban_t_tmp.level;

					//�����ڲ����ڸý�ʦְ���򽫸ý�ʦ�������
					if (gi[g].title[lv] == 0)
						break;

					i++;
				} while (i < remain_cnt);

				//����������ʦ���������н�ʦְ���ڸ����ڶ����ڣ���ȡ��һ����ʦ
				if (i >= remain_cnt)
					i = 0;

				//����ʦ������鲢ˢ�����ڽ�ʦ����
				gi[g].group.push_back(ban_vec[i]);
				gi[g].teacher_cnt = gi[g].group.size();

				//ɾ���������ʦ�����еĽ�ʦID
				ban_vec.erase(std::begin(ban_vec) + i);

				remain_cnt--;
			}
		}
	}

	printf("2�� ������Ԯ��ʦ�ó��ķ������£�\n");
	printf("\n");
	printGroup();

	cout << "------------------------------------------" << endl;

	for (int i = 1; i <= group_count; i++)
	{
		//�о���������1 - 11
		for (int r = 1; r <= 11; r++)
		{
			//�������ĳ������û�н�ʦ���Ͳ���һ���������Ƿ��ж�����о�����Ľ�ʦ
			if (gi[i].research[r] == 0)
			{
				for (int it1 = 0; it1 < gi[i].teacher_cnt; it1++)
				{
					Teacher iT1 = t[gi[i].group[it1]];

					for (int j = 1; j <= group_count; j++)
					{
						if (i == j)
							continue;

						//���ڶ�����о�����Ľ�ʦ
						//��һ�����ĸ���ʦ�������ж�һ���Ƿ����ѧ��������ͬ����ͬ�򽻻�һ����ʦ
						if (gi[j].research[r] > 1)
						{
							//���������ʦ
							for (int it2 = 0; it2 < gi[j].teacher_cnt; it2++)
							{
								Teacher iT2 = t[gi[j].group[it2]];

								bool findit = false;
								for (int r2 = 0; r2 < iT2.research_cnt; r2++)
								{
									if (iT2.research[r2] == r && (iT1.student_cnt == iT2.student_cnt))
									{
										findit = true;
										break;
									}
								}

								//�ҵ���
								if (findit)
								{
									gi[i].research[r]++;
									gi[j].research[r]--;

									//��������С�������еĽ�ʦID�����н���
									int index1 = 0, index2 = 0;

									vector<int>::iterator iter1 = find(gi[i].group.begin(), gi[i].group.end(), iT1.index);
									if (iter1 != gi[i].group.end())
										index1 = *iter1;

									vector<int>::iterator iter2 = find(gi[j].group.begin(), gi[j].group.end(), iT2.index);
									if (iter2 != gi[j].group.end())
										index2 = *iter2;

									if (index1 && index2)
									{
										*iter1 = index2;
										*iter2 = index1;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("3�� �����Ż������ʦ�о������ó��ķ������£�\n");
	printf("\n");
	printGroup();
}