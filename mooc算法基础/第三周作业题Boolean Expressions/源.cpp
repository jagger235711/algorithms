/*����
�㽫�����ĳ����Ŀ���Ǽ��㲼�����ʽ����ͼ��ʾ:
���ʽ:(V | V) & F & (F | V)
����VΪ�棬FΪ�١����ʽ���ܰ������²�����:!for not�� & for and�� | for or��Ҳ����ʹ��Բ���Ž��в������顣
Ҫִ�б��ʽ�ļ��㣬��������Ϊ�ǲ����������ȼ���û����ߵĲ�����������͵Ĳ������������������V��F����Ϊ�����ļ���ÿ�����ʽ�Ľ����
����
���ʽ�ĳ����ǿɱ�ģ������ᳬ��100�����š����ſ��������������Ŀո�ָ���Ҳ������ȫû�пո���ˣ����ʽ���ܳ���(��Ϊ�ַ�������)��δ֪�ġ�
�����ļ��еı��ʽ�����ǿɱ�ģ�������Զ�������20��ÿ�����ʽ��һ����������ʾ��������ʾ��
���
����ÿ�����Ա��ʽ����ӡ�����ʽ���������кš�:�����Լ���Ӧ���Ա��ʽ�Ľ��ֵ�������зָ��������Ա��ʽ�������
ʹ��������ʾ�������ͬ�ĸ�ʽ��
��������
(V | V) & F & (F| V)
V | V & V & !F & (F | V) & (!F | F | !V & V)
V (F&F | | ! V ! F (F | F&V))
�������
���ʽ1:F
���ʽ2:V
���ʽ3:V*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char s[100005] = { 0 };
int cnt = 0;
bool expression_bool();
bool term_bool();
bool factor_bool();
int main()
{
    int k = 0;
    while (cin.getline(s, 100000))
    {
        char t[100001] = { 0 };
        int len = strlen(s);
        for (int i = 0, k = 0; i < len; i++)
        {
            if (s[i] != ' ')
                t[k++] = s[i];
        }

        len = strlen(t);
        for (int i = 0; i < len; i++)
            s[i] = t[i];
        s[len] = '\0';

        cout << "Expression " << ++k << ": " << (expression_bool() ? "V" : "F") << endl;
        cnt = 0;
        memset(s, 0, sizeof(s));
    }
    return 0;
}
bool expression_bool()
{
    bool result = term_bool();
    bool more = true;
    while (more)
    {
        char op = s[cnt];
        if (op == '&' || op == '|')
        {
            cnt++;
            bool value = term_bool();
            if (op == '&')
                result = result & value;
            else
                result = result | value;
        }
        else
            more = false;
    }
    return result;

}
bool term_bool()
{
    bool result;
    char op = s[cnt];
    if (op == '!')
    {
        cnt++;
        result = !factor_bool();
    }
    else
        result = factor_bool();
    return result;
}
bool factor_bool()
{
    bool result;
    char c = s[cnt];
    if (c == '(')
    {
        cnt++;
        result = expression_bool();
        cnt++;
    }
    else if (c == 'V')
    {
        result = true;
        cnt++;
    }
    else if (c == 'F')
    {
        result = false;
        cnt++;
    }
    else if (c == '!')
        result = term_bool();

    return result;
}