#include<iostream>
#include<cmath>
using namespace std;
constexpr auto pi = 3.1415;;
constexpr auto uD1 = 0.02;;
constexpr auto uD2 = 0.02;;
constexpr auto uH =  0.02;;

int main()
{
    float a, b, c, d, e, f, v;
    cout << "������������" << endl;
    cin >> v;
    cout << endl;
   /* cout << "�������h" << endl;
    cin >> a >> b >> c >> d >> e >> f;
    cout << endl;
    float g, h, i, j, k, l;
    cout << "�������ھ�d" << endl;
    cin >> g >> h >> i >> j >> k >> l;
    cout << endl;
    float m, n, o, p, q, r;
    cout << "�������⾶d" << endl;
    cin >> m >> n >> o >> p >> q >> r;
    cout << endl;*/
    double s, t, u;
    cin >> s;  //(a + b + c + d + e + f) / 6;
    cin >> t;  //(g + h + i + j + k + l) / 6;
    cin >> u;  //(m + n + o + p + q + r) / 6;
    cout << "�ߵ�ƽ��ֵΪ��" << s << "  �ھ���ƽ��ֵΪ��" << t << "  �⾶��ƽ��ֵΪ��" << u << endl;
    double V, D1, D2, H,E, uV;
    H = s - v; D2 = t - v; D1 = u - v;
    V = pi / 4 * (D1 * D1 - D2 * D2) * H;
    
    E = (2 * D2 * uD2 / (D2 * D2 - D1 * D1)) * (2 * D2 * uD2 / (D2 * D2 - D1 * D1)) + (-2 * D1 * uD1 / (D2 * D2 - D1 * D1)) * (-2 * D1 * uD1 / (D2 * D2 - D1 * D1)) + (uH / H) * (uH / H);
    uV = E * V * V;

    cout << "�ߵ���������ֵΪ��" << H << "  �ھ�����������ֵΪ��" << D2 << "  �⾶����������ֵΪ��" << D1 << endl << "  ����Բ�����Ϊ��" << V << "  �������Բ�ȷ���ȵ�ƽ��Ϊ��" << E << endl << "   ����Ĳ�ȷ���ȵ�ƽ��Ϊ" << uV << endl;
    cout << "��ע�ⲻȷ������ƽ������Ҫ���Լ�������" << endl;
}